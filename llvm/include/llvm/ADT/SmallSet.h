//===- llvm/ADT/SmallSet.h - 'Normally small' sets --------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file defines the SmallSet class.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_ADT_SMALLSET_H
#define LLVM_ADT_SMALLSET_H

#include "llvm/ADT/ADL.h"
#include "llvm/ADT/STLForwardCompat.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/iterator.h"
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <set>
#include <utility>

namespace llvm {

/// SmallSetIterator - This class implements a const_iterator for SmallSet by
/// delegating to the underlying SmallVector or Set iterators.
template <typename T, unsigned N, typename C>
class SmallSetIterator
    : public iterator_facade_base<SmallSetIterator<T, N, C>,
                                  std::forward_iterator_tag, T> {
private:
  using SetIterTy = typename std::set<T, C>::const_iterator;
  using VecIterTy = typename SmallVector<T, N>::const_iterator;
  using SelfTy = SmallSetIterator<T, N, C>;

  /// Iterators to the parts of the SmallSet containing the data. They are set
  /// depending on isSmall.
  union {
    SetIterTy SetIter;
    VecIterTy VecIter;
  };

  bool IsSmall;

public:
  SmallSetIterator(SetIterTy SetIter) : SetIter(SetIter), IsSmall(false) {}

  SmallSetIterator(VecIterTy VecIter) : VecIter(VecIter), IsSmall(true) {}

  // Spell out destructor, copy/move constructor and assignment operators for
  // MSVC STL, where set<T>::const_iterator is not trivially copy constructible.
  ~SmallSetIterator() {
    if (IsSmall)
      VecIter.~VecIterTy();
    else
      SetIter.~SetIterTy();
  }

  SmallSetIterator(const SmallSetIterator &Other) : IsSmall(Other.IsSmall) {
    if (IsSmall)
      VecIter = Other.VecIter;
    else
      // Use placement new, to make sure SetIter is properly constructed, even
      // if it is not trivially copy-able (e.g. in MSVC).
      new (&SetIter) SetIterTy(Other.SetIter);
  }

  SmallSetIterator(SmallSetIterator &&Other) : IsSmall(Other.IsSmall) {
    if (IsSmall)
      VecIter = std::move(Other.VecIter);
    else
      // Use placement new, to make sure SetIter is properly constructed, even
      // if it is not trivially copy-able (e.g. in MSVC).
      new (&SetIter) SetIterTy(std::move(Other.SetIter));
  }

  SmallSetIterator& operator=(const SmallSetIterator& Other) {
    // Call destructor for SetIter, so it gets properly destroyed if it is
    // not trivially destructible in case we are setting VecIter.
    if (!IsSmall)
      SetIter.~SetIterTy();

    IsSmall = Other.IsSmall;
    if (IsSmall)
      VecIter = Other.VecIter;
    else
      new (&SetIter) SetIterTy(Other.SetIter);
    return *this;
  }

  SmallSetIterator& operator=(SmallSetIterator&& Other) {
    // Call destructor for SetIter, so it gets properly destroyed if it is
    // not trivially destructible in case we are setting VecIter.
    if (!IsSmall)
      SetIter.~SetIterTy();

    IsSmall = Other.IsSmall;
    if (IsSmall)
      VecIter = std::move(Other.VecIter);
    else
      new (&SetIter) SetIterTy(std::move(Other.SetIter));
    return *this;
  }

  bool operator==(const SmallSetIterator &RHS) const {
    if (IsSmall != RHS.IsSmall)
      return false;
    if (IsSmall)
      return VecIter == RHS.VecIter;
    return SetIter == RHS.SetIter;
  }

  SmallSetIterator &operator++() { // Preincrement
    if (IsSmall)
      ++VecIter;
    else
      ++SetIter;
    return *this;
  }

  const T &operator*() const { return IsSmall ? *VecIter : *SetIter; }
};

/// SmallSet - This maintains a set of unique values, optimizing for the case
/// when the set is small (less than N).  In this case, the set can be
/// maintained with no mallocs.  If the set gets large, we expand to using an
/// std::set to maintain reasonable lookup times.
template <typename T, unsigned N, typename C = std::less<T>>
class SmallSet {
  /// Use a SmallVector to hold the elements here (even though it will never
  /// reach its 'large' stage) to avoid calling the default ctors of elements
  /// we will never use.
  SmallVector<T, N> Vector;
  std::set<T, C> Set;

  // In small mode SmallPtrSet uses linear search for the elements, so it is
  // not a good idea to choose this value too high. You may consider using a
  // DenseSet<> instead if you expect many elements in the set.
  static_assert(N <= 32, "N should be small");

public:
  using key_type = T;
  using size_type = size_t;
  using value_type = T;
  using const_iterator = SmallSetIterator<T, N, C>;

  SmallSet() = default;
  SmallSet(const SmallSet &) = default;
  SmallSet(SmallSet &&) = default;

  template <typename IterT> SmallSet(IterT Begin, IterT End) {
    insert(Begin, End);
  }

  template <typename Range>
  SmallSet(llvm::from_range_t, Range &&R)
      : SmallSet(adl_begin(R), adl_end(R)) {}

  SmallSet(std::initializer_list<T> L) { insert(L.begin(), L.end()); }

  SmallSet &operator=(const SmallSet &) = default;
  SmallSet &operator=(SmallSet &&) = default;

  [[nodiscard]] bool empty() const { return Vector.empty() && Set.empty(); }

  size_type size() const {
    return isSmall() ? Vector.size() : Set.size();
  }

  /// count - Return 1 if the element is in the set, 0 otherwise.
  size_type count(const T &V) const { return contains(V) ? 1 : 0; }

  /// insert - Insert an element into the set if it isn't already there.
  /// Returns a pair. The first value of it is an iterator to the inserted
  /// element or the existing element in the set. The second value is true
  /// if the element is inserted (it was not in the set before).
  std::pair<const_iterator, bool> insert(const T &V) { return insertImpl(V); }

  std::pair<const_iterator, bool> insert(T &&V) {
    return insertImpl(std::move(V));
  }

  template <typename IterT>
  void insert(IterT I, IterT E) {
    for (; I != E; ++I)
      insert(*I);
  }

  template <typename Range> void insert_range(Range &&R) {
    insert(adl_begin(R), adl_end(R));
  }

  bool erase(const T &V) {
    if (!isSmall())
      return Set.erase(V);
    auto I = vfind(V);
    if (I != Vector.end()) {
      Vector.erase(I);
      return true;
    }
    return false;
  }

  void clear() {
    Vector.clear();
    Set.clear();
  }

  const_iterator begin() const {
    if (isSmall())
      return {Vector.begin()};
    return {Set.begin()};
  }

  const_iterator end() const {
    if (isSmall())
      return {Vector.end()};
    return {Set.end()};
  }

  /// Check if the SmallSet contains the given element.
  bool contains(const T &V) const {
    if (isSmall())
      return vfind(V) != Vector.end();
    return Set.find(V) != Set.end();
  }

private:
  bool isSmall() const { return Set.empty(); }

  template <typename ArgType>
  std::pair<const_iterator, bool> insertImpl(ArgType &&V) {
    static_assert(std::is_convertible_v<ArgType, T>,
                  "ArgType must be convertible to T!");
    if (!isSmall()) {
      auto [I, Inserted] = Set.insert(std::forward<ArgType>(V));
      return {const_iterator(I), Inserted};
    }

    auto I = vfind(V);
    if (I != Vector.end()) // Don't reinsert if it already exists.
      return {const_iterator(I), false};
    if (Vector.size() < N) {
      Vector.push_back(std::forward<ArgType>(V));
      return {const_iterator(std::prev(Vector.end())), true};
    }
    // Otherwise, grow from vector to set.
    Set.insert(std::make_move_iterator(Vector.begin()),
               std::make_move_iterator(Vector.end()));
    Vector.clear();
    return {const_iterator(Set.insert(std::forward<ArgType>(V)).first), true};
  }

  // Handwritten linear search. The use of std::find might hurt performance as
  // its implementation may be optimized for larger containers.
  typename SmallVector<T, N>::const_iterator vfind(const T &V) const {
    for (auto I = Vector.begin(), E = Vector.end(); I != E; ++I)
      if (*I == V)
        return I;
    return Vector.end();
  }
};

/// If this set is of pointer values, transparently switch over to using
/// SmallPtrSet for performance.
template <typename PointeeType, unsigned N>
class SmallSet<PointeeType*, N> : public SmallPtrSet<PointeeType*, N> {};

/// Equality comparison for SmallSet.
///
/// Iterates over elements of LHS confirming that each element is also a member
/// of RHS, and that RHS contains no additional values.
/// Equivalent to N calls to RHS.count.
/// For small-set mode amortized complexity is O(N^2)
/// For large-set mode amortized complexity is linear, worst case is O(N^2) (if
/// every hash collides).
template <typename T, unsigned LN, unsigned RN, typename C>
bool operator==(const SmallSet<T, LN, C> &LHS, const SmallSet<T, RN, C> &RHS) {
  if (LHS.size() != RHS.size())
    return false;

  // All elements in LHS must also be in RHS
  return all_of(LHS, [&RHS](const T &E) { return RHS.count(E); });
}

/// Inequality comparison for SmallSet.
///
/// Equivalent to !(LHS == RHS). See operator== for performance notes.
template <typename T, unsigned LN, unsigned RN, typename C>
bool operator!=(const SmallSet<T, LN, C> &LHS, const SmallSet<T, RN, C> &RHS) {
  return !(LHS == RHS);
}

} // end namespace llvm

#endif // LLVM_ADT_SMALLSET_H
