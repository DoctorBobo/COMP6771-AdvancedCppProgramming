#include "Bad_list.hpp"
#include <cassert>

int main()
{
   auto l = Bad_list<int>{1, 2, 3, 4, 5};
   assert(!l.empty());
   l.clear();
   assert(l.empty());
}