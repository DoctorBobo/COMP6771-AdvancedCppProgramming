#ifndef COMP6771_BOOK_HPP_INCLUDED
#define COMP6771_BOOK_HPP_INCLUDED
#include <cstdint>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

namespace comp6771 {
class book
{
public:
   book() = default;

   book(const std::string& t, const std::string& a, const std::int64_t i, const double p)
      : author_{a}, title_{t}, isbn_{i}, price_{p}
   {
   }

   const std::string& author() const { return author_; }
   const std::string& title() const { return title_; }
   std::int64_t isbn() const { return isbn_; }
   double price() const { return price_; }

   explicit operator std::string()
   {
      using namespace std::literals;
      return author_ + ","s + title_;
   }
private:
   std::string author_{"<unknown>"};
   std::string title_{"<unknown>"};
   std::int64_t isbn_{0U};
   double price_{0.0};
};

bool operator==(const book&, const book&);
bool operator<(const book&, const book&);
std::ostream& operator<<(std::ostream&, const book&);

inline bool operator!=(const book& a, const book& b)
{
   return !(a == b);
}

using library_t = std::vector<book>;
} // namespace comp6771
#endif // COMP6771_BOOK_HPP_INCLUDED
