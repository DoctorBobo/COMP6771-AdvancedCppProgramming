#include "Bad_list.hpp"
#include <cassert>
#include <numeric>

int main()
{
   const auto l = Bad_list<int>{};
   for (auto i = 0; i < 100; ++i)
      l.push_back(i);
   for (auto i = l.begin(); i != l.end(); ++i)
      *i += 100;
   assert(std::accumulate(l.begin(), l.end(), 0) == ((l.size() / 2) * (l.front() + l.back())));
}