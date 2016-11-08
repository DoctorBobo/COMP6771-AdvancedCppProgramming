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
#include <numeric>
#include "types.hpp"
#include <vector>

int main()
{
   const auto v = std::vector<int>{0, 1, 2, 3, 4, 5};
   const auto l = Bad_list<value_type_t<decltype(v)>>{v};

   assert(static_cast<difference_type_t<decltype(l)>>(v.size()) == l.size());
   assert(std::equal(v.begin(), v.end(), l.begin(), l.end()));
   assert(std::addressof(*v.begin()) != std::addressof(*l.begin()));
   assert(std::accumulate(l.begin(), l.end(), 0U) == (v.size() / 2) * (v.back() + v.front()));
}
