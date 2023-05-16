/* Fast open-addressing concurrent hash table.
 *
 * Copyright 2023 Christian Mazakas.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See https://www.boost.org/libs/unordered for library home page.
 */

/* Reference:
 * https://github.com/joaquintides/concurrent_hashmap_api#proposed-synopsis
 */

#ifndef BOOST_UNORDERED_CONCURRENT_FLAT_MAP_FWD_HPP
#define BOOST_UNORDERED_CONCURRENT_FLAT_MAP_FWD_HPP

#include <boost/container_hash/hash_fwd.hpp>

#include <functional>
#include <memory>

namespace boost {
  namespace unordered {

    template <class Key, class T, class Hash = boost::hash<Key>,
      class Pred = std::equal_to<Key>,
      class Allocator = std::allocator<std::pair<Key const, T> > >
    class concurrent_flat_map;

    template <class Key, class T, class Hash, class KeyEqual, class Allocator>
    bool operator==(
      concurrent_flat_map<Key, T, Hash, KeyEqual, Allocator> const& lhs,
      concurrent_flat_map<Key, T, Hash, KeyEqual, Allocator> const& rhs);

    template <class Key, class T, class Hash, class KeyEqual, class Allocator>
    bool operator!=(
      concurrent_flat_map<Key, T, Hash, KeyEqual, Allocator> const& lhs,
      concurrent_flat_map<Key, T, Hash, KeyEqual, Allocator> const& rhs);

    template <class Key, class T, class Hash, class Pred, class Alloc>
    void swap(concurrent_flat_map<Key, T, Hash, Pred, Alloc>& x,
      concurrent_flat_map<Key, T, Hash, Pred, Alloc>& y)
      noexcept(noexcept(x.swap(y)));

    template <class K, class T, class H, class P, class A, class Predicate>
    typename concurrent_flat_map<K, T, H, P, A>::size_type erase_if(
      concurrent_flat_map<K, T, H, P, A>& c, Predicate pred);

  } // namespace unordered

  using unordered::concurrent_flat_map;
  using unordered::swap;
  using unordered::operator==;
  using unordered::operator!=;
} // namespace boost

#endif // BOOST_UNORDERED_CONCURRENT_FLAT_MAP_HPP
