/* Copyright 2016 Christopher Di Bella
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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