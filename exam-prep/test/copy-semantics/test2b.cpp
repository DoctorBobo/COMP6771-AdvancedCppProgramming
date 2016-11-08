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
   auto a = Bad_list<decltype(value)>(100, value);
   auto b = decltype(a){};
   b = a;
   assert(a == b);
   assert(!(a != b));
   assert(a.front() == value);
   assert(a.front() == b.front());
   assert(std::addressof(a.front()) != std::addressof(b.front()));
   assert(a.back() == value);
   assert(std::addressof(a.back()) != std::addressof(b.back()));
   assert(a.begin() != b.begin());
   assert(std::addressof(*a.begin()) != std::addressof(*b.begin()));
   assert(*a.begin() == *b.begin());
   assert(a.end() != b.end());
   assert(a.rbegin() != b.rbegin());
   assert(std::addressof(*a.rbegin()) != std::addressof(*b.rbegin()));
   assert(*a.rbegin() == *b.rbegin());
   assert(a.rend() != b.rend());
}
