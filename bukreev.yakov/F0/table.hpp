#ifndef TABLE_HPP
#define TABLE_HPP

#include <utility>
#include <cstdlib>
#include <stdexcept>

namespace bukreev
{
  template< class K, class V, class H >
  class HashTable
  {
  public:
    HashTable(size_t capacity = 17);
    void put(K key, V val);
    size_t size() const noexcept;
    size_t capacity() const noexcept;

  private:
    size_t hash1(const K& key) const;
    size_t hash2(const K& key) const;

  private:
    size_t mCapacity;
    size_t mSize;

    using Pair = std::pair< K, V >;
    Pair* mPairs;
    bool* mOccupied;
  };

  template< class K, class V, class H >
  HashTable< K, V, H >::HashTable(size_t capacity)
  {
    mCapacity = capacity;
    mPairs = new Pair[capacity];

    try
    {
      mOccupied = new bool[capacity];
    }
    catch (const std::bad_alloc& e)
    {
      delete[] mPairs;
      throw;
    }

    for (size_t i = 0; i < capacity; i++)
    {
      mOccupied[i] = false;
    }

    mSize = 0;
  }

  template< class K, class V, class H >
  void HashTable< K, V, H >::put(K key, V val)
  {
    size_t h1 = hash1(key);
    size_t h2 = hash2(key);

    size_t i = 0;
    size_t id = h1;
    while (mOccupied[id] && i < mCapacity)
    {
      if (mPairs[id].first == key)
      {
        mPairs[id].second = val;
        return;
      }

      i++;
      id = (h1 + i * h2) % mCapacity;
    }

    if (i >= mCapacity)
    {
      return;
    }

    mPairs[id].first = key;
    mPairs[id].second = val;
    mOccupied[id] = true;

    mSize++;
  }

  template< class K, class V, class H >
  size_t HashTable< K, V, H >::hash1(const K& key) const
  {
    H h;
    return h(key) % mCapacity;
  }

  template< class K, class V, class H >
  size_t HashTable< K, V, H >::hash2(const K& key) const
  {
    size_t h = hash1(key);
    return (h % (mCapacity - 1)) + 1;
  }

  template< class K, class V, class H >
  size_t HashTable< K, V, H >::size() const noexcept
  {
    return mSize;
  }

  template< class K, class V, class H >
  size_t HashTable< K, V, H >::capacity() const noexcept
  {
    return mCapacity;
  }
}

#endif
