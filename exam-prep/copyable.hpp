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