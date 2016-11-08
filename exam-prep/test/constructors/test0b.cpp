#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>

int main()
{
   constexpr auto size = 10;
   auto l = Bad_list<double>(size);
   assert(l.size() == size);
   assert(!l.empty());
   assert(std::count(l.begin(), l.end(), double{}) == size);
}
