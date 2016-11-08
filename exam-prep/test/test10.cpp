#include "Bad_list.hpp"
#include <cassert>

int main()
{
   auto a = Bad_list<int>{1, 2, 3, 4, 5};
   auto b = a;
   assert(a.size() == b.size());
   std::copy(a.cbegin(), a.cend(), std::back_inserter(b));
   assert(a.size() < b.size());
   a.swap(b);
   assert(a.size() > b.size());
   swap(a, b);
   assert(a.size() < b.size());
}