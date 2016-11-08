#include "Bad_list.hpp"
#include <algorithm>
#include <numeric>
#include <cassert>
#include <iostream>

int main()
{
   auto a = Bad_list<int>{};
   for (auto i = 0; i < 100; ++i)
      a.push_back(i);

   assert(std::accumulate(a.begin(), a.end(), 0) == ((a.size() / 2) * (a.front() + a.back())));
}
