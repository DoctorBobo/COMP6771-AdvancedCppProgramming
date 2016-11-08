#include "Bad_list.hpp"
#include <cassert>

int main()
{
   auto l = Bad_list<int>{};
   assert(l.size() == 0);
   assert(l.empty());
}