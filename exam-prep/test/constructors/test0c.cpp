#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>

int main()
{
   constexpr auto size = 10;
   constexpr auto value = 1.23e4;
   auto l = Bad_list<double>(size, value);
   assert(l.size() == size);
   assert(!l.empty());
   assert(std::count(l.begin(), l.end(), value) == size);
}
