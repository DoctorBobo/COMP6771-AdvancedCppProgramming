#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>
#include <deque>
#include "types.hpp"
#include <vector>

int main()
{
   auto d = std::deque<std::vector<int>>{};
   auto l = Bad_list<value_type_t<decltype(d)>>{};
   for (auto i = 0; i < 100; ++i) {
      d.emplace_front(i, 0);
      l.emplace_front(i, 0);
      assert(l.front() == d.front());
   }

   assert(l.size() == difference_type_t<decltype(l)>(d.size()));
   for (; !l.empty(); d.pop_front(), l.pop_front())
      assert(l.front() == d.front());
}
