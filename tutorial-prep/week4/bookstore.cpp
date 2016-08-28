#include <algorithm>
#include "book.hpp"
#include <iomanip>
#include <iostream>
#include <ios>
#include <iterator>
#include "utility.hpp"
#include <vector>

int main()
{
   auto store = comp6771::library_t{};

   {
      constexpr const auto* bjarne = "Stroustrup, B";
      store.emplace_back("A Tour of C++", bjarne, 9780321958310, 20_aud); // ficticious price
      store.emplace_back("Programming -- Principles and Practice Using C++",
                           bjarne,
                           9780321992789,
                           40_aud); // ficticious price
      store.emplace_back("The C++ Programming Language", bjarne, 9780321563842, 40.0_usd);
      store.emplace_back("The Design and Evolution of C++", bjarne, 785342543308, 57.04_usd);
   }
   {
      constexpr const auto* meyers = "Meyers, S";
      store.emplace_back("Effective C++", meyers, 785342334876, 43.44_usd);
      store.emplace_back("More Effective C++", meyers, 785342633719, 37.06_usd);
      store.emplace_back("Effective STL", meyers, 9780201749625, 48.75_usd);
      store.emplace_back("Effective Modern C++", meyers, 9781491903995, 44.95_usd);
   }
   {
      constexpr const auto* sutter = "Sutter, H";
      store.emplace_back("Exceptional C++", sutter, 9780201615623, 44.6_usd);
      store.emplace_back("More Exceptional C++", sutter, 785342704341, 45.63_usd);
      store.emplace_back("Exceptional C++ Style", sutter, 785342760422, 40.83_usd);

      using namespace std::literals;
      store.emplace_back("C++ Coding Standards",
                         std::string{sutter} + "; Alexandrescu, A"s,
                         9780321113580,
                         49.94_usd);
   }

   auto foo = std::string{store[0]};
   std::cout << foo << '\n';

   std::sort(store.begin(), store.end());
   copy_ostream(store, std::cout);
   std::cout << '\n';
}
