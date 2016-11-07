#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>

int main()
{
   auto a = Bad_list<int>{};
   constexpr auto size = 100;
   for (auto i = 0; i < size; ++i)
      a.push_back(i);
   assert(a.size() == size);
   for (auto i = 0; i < size; ++i, a.pop_front())
      assert(i == a.front());
}
