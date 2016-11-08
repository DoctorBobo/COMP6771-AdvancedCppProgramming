#include "Bad_list.hpp"
#include <algorithm>
#include <cassert>
#include <numeric>

int main()
{
   auto l = Bad_list<int>{};
   for (auto i = 0; i < 100; ++i)
      l.push_back(i);
   assert(std::transform(l.cbegin(), l.cend(), l.begin(),
   [&l](const auto& i) {
      return i + l.size();
   }) == l.end());
   assert(std::find_if(l.cbegin(), l.cend(),
   [&l](const auto& i) {
      return i < l.size() || i > 2 * l.size();
   }) == l.end());
   assert(std::accumulate(l.begin(), l.end(), 0) == ((l.size() / 2) * (l.front() + l.back())));
}