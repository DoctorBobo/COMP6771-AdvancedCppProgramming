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
#ifndef COPYABLE_HPP
#define COPYABLE_HPP
class Copyable {
public:
   Copyable() noexcept
   {
      ++default_ctor_;
   }

   Copyable(const Copyable&) noexcept
   {
      ++copy_ctor_;
   }

   Copyable(Copyable&&) noexcept
   {
      ++move_ctor_;
   }

   Copyable& operator=(const Copyable&) noexcept
   {
      ++copy_assign_;
      return *this;
   }

   Copyable& operator=(Copyable&&) noexcept
   {
      ++move_assign_;
      return *this;
   }

   static int default_ctor() noexcept
   {
      return default_ctor_;
   }

   static int copy_ctor() noexcept
   {
      return copy_ctor_;
   }

   static int copy_assign() noexcept
   {
      return copy_assign_;
   }

   static int move_ctor() noexcept
   {
      return move_ctor_;
   }

   static int move_assign() noexcept
   {
      return move_assign_;
   }
private:
   static int default_ctor_;
   static int copy_ctor_;
   static int copy_assign_;
   static int move_ctor_;
   static int move_assign_;
};
#endif // COPYABLE_HPP