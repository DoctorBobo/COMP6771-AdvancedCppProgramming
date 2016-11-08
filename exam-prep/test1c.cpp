#include "Bad_list.hpp"
#include <cassert>
#include <memory>
#include <numeric>
#include "types.hpp"
#include <vector>

int main()
{
   const auto v = std::vector<int>{0, 1, 2, 3, 4, 5};
   const auto l = Bad_list<value_type_t<decltype(v)>>{v};

   assert(static_cast<difference_type_t<decltype(l)>>(v.size()) == l.size());
   assert(std::equal(v.begin(), v.end(), l.begin(), l.end()));
   assert(std::addressof(*v.begin()) != std::addressof(*l.begin()));
   assert(std::accumulate(l.begin(), l.end(), 0U) == (v.size() / 2) * (v.back() + v.front()));
}
