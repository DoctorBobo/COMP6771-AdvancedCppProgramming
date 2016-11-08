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
#include <numeric>

int main()
{
   auto l = Bad_list<int>{};
   for (auto i = 0; i < 100; ++i)
      l.push_back(i);
   for (auto i = l.begin(); i != l.end(); ++i)
      *i += 100;
   assert(std::accumulate(l.begin(), l.end(), 0) == ((l.size() / 2) * (l.front() + l.back())));
}