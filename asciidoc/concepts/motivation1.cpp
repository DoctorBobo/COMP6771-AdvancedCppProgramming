#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T, typename U>
std::vector<double> make_vector(T first, const U last)
{
   auto v = std::vector<double>{};
   while (first != last)
      v.push_back(*first++);
   return v;
}

std::vector<double> make_vector(const std::size_t size, const double magnitude)
{
   return std::vector<double>(size, magnitude);
}

int main()
{
   auto v = make_vector(10LLU, 20.0);
   std::copy(v.cbegin(), v.cend(), std::ostream_iterator<decltype(v)::value_type>{std::cout, " "});
   std::cout << '\n';
}
