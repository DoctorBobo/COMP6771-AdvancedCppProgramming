#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>

int main()
{
   constexpr auto value = 20;
   const auto a = Bad_list<decltype(value)>(100, value);
   auto b = a;
   auto c = a;
   c = std::move(b);

   assert(a == c);
   assert(b.empty());
   assert(b != a);
   assert(b != c);
   assert(b.size() == 0);
   assert(b.begin() == b.end());
   assert(b.begin() != c.begin());
   assert(b.end() != c.end());
   assert(b.rbegin() == b.rend());
   assert(b.rbegin() != c.rbegin());
   assert(b.rend() != c.rend());
}
