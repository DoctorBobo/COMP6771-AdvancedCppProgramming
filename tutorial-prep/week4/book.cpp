#include <algorithm>
#include "book.hpp"
#include <iomanip>
#include <iostream>
#include <iterator>

namespace comp6771 {
bool operator==(const book& a, const book& b)
{
   return a.author() == b.author() &&
          a.title()  == b.title()  &&
          a.price()  == b.price()  &&
          a.isbn()   == b.isbn();
}

bool operator<(const book& a, const book& b)
{
   return a.isbn() < b.isbn();
}

std::ostream& operator<<(std::ostream& o, const book& b)
{
   o << '{' << b.author() << '.'
            << b.title()  << '.'
            << b.isbn()   << ". $"
            << b.price()
    << '}';
   return o;
}
} // namespace comp6771
