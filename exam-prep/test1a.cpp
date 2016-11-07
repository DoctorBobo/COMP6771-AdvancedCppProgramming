#include "Bad_list.hpp"
#include <cassert>
#include <memory>
#include <string>

int main()
{
   using namespace std::string_literals;
   const auto first  = ""s;
   const auto second = "hello"s;
   const auto third  = "foo"s;
   const auto fourth = "bar"s;

   auto l = Bad_list<std::string>{first, second, third, fourth};
   auto i = l.begin();
   assert(i == l.begin());
   assert(std::addressof(*i) == std::addressof(*l.begin()));
   assert(i != l.end());
   assert(std::addressof(*i) != std::addressof(*l.end()));
   assert(i->empty());
   assert(*i == first);
   assert(++i != l.begin());
   assert(std::addressof(*i) != std::addressof(*l.begin()));
   assert(*i++ == second);
   assert(*++i == fourth);
   assert(std::addressof(*i) != std::addressof(*l.end()));
   assert(++i == l.end());
}