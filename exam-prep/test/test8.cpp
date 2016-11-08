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
#include <string>
#include "types.hpp"
#include <vector>

int main()
{
   using namespace std::string_literals;
   auto v = std::vector<std::string>{};
   for (auto i = "a"s; v.size() < 100; i += "a")
      v.push_back(i);

   auto l = Bad_list<value_type_t<decltype(v)>>{v};
   assert(std::equal(v.crbegin(), v.crend(), l.crbegin(), l.crend()));
}