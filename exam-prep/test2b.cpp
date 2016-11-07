#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>

int main()
{
   constexpr auto value = 20;
   auto a = Bad_list<decltype(value)>(100, value);
   auto b = decltype(a){};
   b = a;
   assert(a == b);
   assert(!(a != b));
   assert(a.front() == value);
   assert(a.front() == b.front());
   assert(std::addressof(a.front()) != std::addressof(b.front()));
   assert(a.back() == value);
   assert(std::addressof(a.back()) != std::addressof(b.back()));
   assert(a.begin() != b.begin());
   assert(std::addressof(*a.begin()) != std::addressof(*b.begin()));
   assert(*a.begin() == *b.begin());
   assert(a.end() != b.end());
   assert(a.rbegin() != b.rbegin());
   assert(std::addressof(*a.rbegin()) != std::addressof(*b.rbegin()));
   assert(*a.rbegin() == *b.rbegin());
   assert(a.rend() != b.rend());
}
