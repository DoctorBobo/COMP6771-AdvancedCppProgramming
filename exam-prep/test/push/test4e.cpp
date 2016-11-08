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
