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

int main()
{
   auto a = Bad_list<int>{1, 2, 3, 4, 5};
   auto b = a;
   assert(a == b);
   assert(!(a != b));

   a.push_back(4);
   assert(a != b);
   assert(!(a == b));

   a.pop_back();
   assert(a == b);

   a.back() = 10;
   assert(a != b);
   assert(!(a == b));
}