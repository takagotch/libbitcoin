#include <boost/test/unit_test.hpp>
#include <bitcoin/system.hpp>

using namespace bc::system;
using namespace bc::system::chain;

BOOST_AUTO_TEST_SUITE(payment_record_tests)

BOOST_AUTO_TEST_CASE(payment_record__constructor_1__always__invalid)
{
  payment_record instance;
  BOOST_REQUIRE(!instance.is_valid());
}

BOOST_AUTO_TEST_SUITE_END()

