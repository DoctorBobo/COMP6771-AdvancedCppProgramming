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
#include "copyable.hpp"

int main()
{
   auto a = Bad_list<Copyable>{};
   a.push_front(Copyable());
   assert(a.size() == 1);
   assert(Copyable::default_ctor() == 3);
   assert(Copyable::copy_ctor() == 0);
   assert(Copyable::copy_assign() == 0);
   assert(Copyable::move_ctor() == 7);
   assert(Copyable::move_assign() == 0);
}
