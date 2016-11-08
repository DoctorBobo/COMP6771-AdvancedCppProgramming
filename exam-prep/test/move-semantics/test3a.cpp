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
#include <algorithm>
#include <cassert>

int main()
{
   constexpr auto value = 20;
   const auto a = Bad_list<decltype(value)>(100, value);
   auto b = a;
   auto c = std::move(b);

   assert(a == c);
   assert(b.empty());
   assert(b != a);
   assert(b != c);
   assert(b.size() == 0);
   assert(b.begin() == b.end());
   assert(b.begin() != c.begin());
   assert(b.end() != c.end());
   assert(b.rbegin() == b.rend());
   assert(b.rbegin() != c.rbegin());
   assert(b.rend() != c.rend());
}
