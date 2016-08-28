#ifndef UTILITY_HPP_INCLUDED
#define UTILITY_HPP_INCLUDED
#include <algorithm>
#include "book.hpp"
#include <iterator>

constexpr double operator"" _aud(const unsigned long long d)
{
   return static_cast<double>(d) * 1.31124;
}

constexpr double operator"" _usd(const unsigned long long d)
{
   return static_cast<double>(d);
}

constexpr double operator"" _aud(const long double d)
{
   return d * 1.31124;
}

constexpr double operator"" _usd(const long double d)
{
   return d;
}

void copy_ostream(const comp6771::library_t& l, std::ostream& o)
{
   std::copy(l.cbegin(),
             l.cend(),
             std::ostream_iterator<comp6771::book>{o, "\n"});
}


#endif //UTILITY_HPP_INCLUDED
