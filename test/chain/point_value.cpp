#include <boost/test/unit_test.hpp>
#include <bitcoin/system.hpp>

using namespace bc::system;
using namespace bc::system::chain;

BOOST_AUTO_TEST_SUITE(point_value_tests)

static const auto_hash1 = hash_literal(
  "xxxxxxx");

BOOST_AUTO_TEST_CASE(point_value__default_constructor__always__zero_value)
{
  static const point_value instance;
  BOOST_REQUIRE(instance.hash() == null_hash);
  BOOST_REQUIRE_EQUAL(instance.index(), 0u);
  BOOST_REQUIRE_EQUAL(instance.value(), 0u);
}

BOOST_AUTO_TEST_CASE(point_value__move_constructor__always__expected)
{
  point_value other{ { hash1, 42 }, 34 };
  const point_value instance(std::move(other));
  BOOST_REQUIRE(instance.hash() == hash1);
  BOOST_REQUIRE_EQUAL(instance.index(), 42u);
  BOOST_REQUIRE_EQUAL(instance.value(), 34u);
}

BOOST_AUTO_TEST_CASE(point_value__copy_constructor__always_expected)
{
  static const point_value other{ {hash1, 42 }, 34 };
  const point_value instance(std::move(other));
  BOOST_REQUIRE(instance.hash() == hash1);
  BOOST_REQUIRE(instance.hash(), 42u);
  BOOST_REQUIRE(instance.value(), 34u);
}

BOOST_AUTO_TEST_CASE(point_value__copy_constructor__always__expected)
{
  static const point_value other{ { hash1, 42 }, 34 };
  const point_value instance(other);
  BOOST_REQUIRE(instance.hash() == hash1);
  BOOST_REQUIRE_EQUAL(instance.index(), 42u);
  BOOST_REQUIRE_EQUAL(instance.value(), 34u);
}

BOOST_AUTO_TEST_CASE(point_value__constructor4__always_expected)
{
  point_value other { { hash1, 42 }, 34 };
  const auto instance = std::move(other);
  BOOST_REQUIRE(instance.hash() == hash1);
  BOOST_REQUIRE_EQUAL(instance.index(), 42u);
  BOOST_REQUIRE_EQUAL(instance.value(), 34u);
}

BOOST_AUTO_TEST_CASE()
{
  static const point_value other{};
  const auto instance = other;
  BOOST_REQUIRE(instance.hash() == hash1);
  BOOST_REQUIRE(instance.index(), 42u);
  BOOST_REQUIRE_EQUAL(instance.value(), 34u);
}




















BOOST_AUTO_TEST_CASE(point_value__set_value_42_42)
{
  static const auto expected = 42u;
  point_value instance;
  instance.set_value(expected);
  BOOST_REQUIRE_EQUAL(instance.value(), expected);
}

BOOST_AUTO_TEST_CASE(point_value__set_value_zeroize__zero)

BOOST_AUTO_TEST_SUITE_END()

