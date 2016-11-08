#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>
#include <deque>
#include "types.hpp"

int main()
{
   auto d = std::deque<int>{};
   for (auto i = 0; i < 100; ++i)
      d.push_front(i);
   auto l = Bad_list<int>{};
   for (auto i : d) {
      l.push_back(i);
      assert(l.front() == d.front());
   }

   assert(l.size() == difference_type_t<decltype(l)>(d.size()));
   for (; !l.empty(); d.pop_front(), l.pop_front())
      assert(l.front() == d.front());
}
