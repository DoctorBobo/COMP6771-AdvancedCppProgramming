#include "copyable.hpp"

int Copyable::default_ctor_{0};
int Copyable::copy_ctor_{0};
int Copyable::copy_assign_{0};
int Copyable::move_ctor_{0};
int Copyable::move_assign_{0};