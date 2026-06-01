#ifndef TABLE_HPP
#define TABLE_HPP

#include <utility>
#include <cstdlib>

namespace bukreev
{
  template< class K, class V, class H >
  class HashTable
  {
  public:
    HashTable(size_t capacity = 17);
    size_t size() const noexcept;
    size_t capacity() const noexcept;

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
  size_t HashTable< K, V, H >::size()
  {
    return mSize;
  }

  template< class K, class V, class H >
  size_t HashTable< K, V, H >::capacity()
  {
    return mCapacity;
  }
}

#endif
