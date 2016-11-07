#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>

int main()
{
   auto a = Bad_list<int>{};
   constexpr auto size = 100;
   for (auto i = 1; i < size; ++i)
      a.push_back(i);

   auto n = 11;
   for (auto& i : a) {
      i += 10;
      assert(i == n++);
   }
}
