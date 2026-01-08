#include "phlex/module.hpp"
#include "my_add.hpp"

#include <cassert>

using namespace phlex;

PHLEX_REGISTER_ALGORITHMS(m, config)
{
  auto const layer = config.get<std::string>("layer");

  m.transform("add", examples::add, concurrency::unlimited)
    .input_family("i"_in(layer), "j"_in(layer))
    .output_products("sum");
  m.observe(
     "verify", [](int actual) { assert(actual == 0); }, concurrency::unlimited)
    .input_family("sum"_in(layer));
}
