#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>
#include <deque>
#include "types.hpp"

int main()
{
   auto d = std::deque<int>{};
   for (auto i = 0; i < 100; ++i)
      d.push_back(i);
   auto l = Bad_list<int>{};
   for (auto i : d) {
      l.push_back(i);
      assert(l.back() == i);
   }

   assert(l.size() == difference_type_t<decltype(l)>(d.size()));
   for (; !l.empty(); d.pop_back(), l.pop_back())
      assert(l.back() == d.back());
}
