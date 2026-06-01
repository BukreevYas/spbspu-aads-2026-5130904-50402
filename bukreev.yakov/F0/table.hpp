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
    mOccupied = new bool[capacity];

    for (bool& b : mOccupied)
    {
      b = false;
    }

    mSize = 0;
  }
}

#endif
