#include "Bad_list.hpp"
#include <cassert>

int main()
{
   auto a = Bad_list<int>{1, 2, 3, 4, 5};
   auto b = a;
   assert(a == b);
   assert(!(a != b));

   a.push_back(4);
   assert(a != b);
   assert(!(a == b));

   a.pop_back();
   assert(a == b);

   a.back() = 10;
   assert(a != b);
   assert(!(a == b));
}