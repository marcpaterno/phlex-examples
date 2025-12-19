#include "phlex/module.hpp"
#include "my_add.hpp"

#include <cassert>

using namespace phlex::experimental;

PHLEX_EXPERIMENTAL_REGISTER_ALGORITHMS(m)
{
  m.provide("provide_i", [](data_cell_index const& id) -> int { return id.number(); })
    .output_product("i"_in("event"));
  m.provide("provide_j", [](data_cell_index const& id) -> int { return -id.number(); })
    .output_product("j"_in("event"));
  m.transform("add", examples::add, concurrency::unlimited)
    .input_family("i"_in("event"), "j"_in("event"))
    .output_products("sum");
  m.observe(
     "verify", [](int actual) { assert(actual == 0); }, concurrency::unlimited)
    .input_family("sum"_in("event"));
}
