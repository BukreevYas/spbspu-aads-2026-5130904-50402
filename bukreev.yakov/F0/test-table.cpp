#include <boost/test/unit_test.hpp>
#include "table.hpp"
#include <string>

using namespace bukreev;

BOOST_AUTO_TEST_SUITE(TableTests)

BOOST_AUTO_TEST_CASE(test_constructor)
{
  HashTable< std::string, int, std::hash< int > > t(19);

  BOOST_CHECK_EQUAL(t.capacity(), 19);
  BOOST_CHECK_EQUAL(t.size(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
