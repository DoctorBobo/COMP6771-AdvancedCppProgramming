#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>
#include "types.hpp"
#include <vector>

int main()
{
   auto d = std::vector<std::vector<int>>{};
   auto l = Bad_list<value_type_t<decltype(d)>>{};
   for (auto i = 0; i < 100; ++i) {
      d.emplace_back(i, 0);
      l.emplace_back(i, 0);
      assert(l.back() == d.back());
   }

   assert(l.size() == difference_type_t<decltype(l)>(d.size()));
   for (; !l.empty(); d.pop_back(), l.pop_back())
      assert(l.back() == d.back());
}
