// save as regular2.cpp
// run make regular2 to compile
#include <experimental/ranges/concepts>
#include <iostream>
#include <memory>

namespace ranges = std::experimental::ranges::v1;

struct Foobar {
   Foobar() = default;
   Foobar(int i, double d) : foo{i}, bar{d} {}

   int foo{0};
   double bar{0.0};
};

template <ranges::Regular... Args>
std::unique_ptr<ranges::Semiregular> make_unique(Args&&... args)
{
   return std::unique_ptr<ranges::Semiregular>(new ranges::Semiregular{std::forward<Args>(args)...});
}

int main()
{
   auto p = make_unique<Foobar>(10, 2.1);
   std::cout << p->foo << ' ' << p->bar << '\n';
}