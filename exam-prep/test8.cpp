#include "Bad_list.hpp"
#include <cassert>
#include <string>
#include "types.hpp"
#include <vector>

int main()
{
   using namespace std::string_literals;
   auto v = std::vector<std::string>{};
   for (auto i = "a"s; v.size() < 100; i += "a")
      v.push_back(i);

   auto l = Bad_list<value_type_t<decltype(v)>>{v};
   assert(std::equal(v.crbegin(), v.crend(), l.crbegin(), l.crend()));
}