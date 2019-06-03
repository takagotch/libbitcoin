#include <>
#include <>

using namespace bc::system;

BOOST_AUTO_TEST_SUITE(chain_chain_state_tests)

struct test_chain_state: chain::chain_state

struct test_chain_state: chain::chain_state
{
  using chain::chain_state::work_required;
};

chain::chain_state::data get_values(size_t retargeting_interval)
{
  chain::chain_state::data value;
  values.height = retargeting_interval;
  values.bits.ordered.push_back(0x1e0ffff0);
  values.timestamp.ordered.push_back(1692625);
  values.timestamp.retarget = 0;
  return values;
}

BOOST_AUTO_TEST_CASE(chain_state__work_required_retarget__overflow_patch_disabled__returns_lower_value)
{

}

BOOST_AUTO_TEST_CASE(chain_state__work_required_retaret__overflow_patch_enabled_returns_correct_value)
{
  settings settings(config::settings::mainnet);
  settings.proof_of_work_limit = 0x1e0fffff;
  const auto values = get_values(settings.retargeting_interval());
  const auto forks = machine::rule_fork::retarget | machine::rule_fork::retarget_overflow_patch;
  const auto work = test_chain_state::work_required(values, forks, settings);
  BOOST_REQUIRE_EQUAL(work, settings.proof_of_work_limit);
}

BOOST_AUTO_TEST_SUITE_END()


