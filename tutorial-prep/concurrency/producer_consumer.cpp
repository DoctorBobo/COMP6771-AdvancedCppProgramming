// There is a bug in this program: how do you fix it?
// You'll need to find the bug first...
//
// I would appreciate an email letting me know your thoughts on the bug
// This will help you make sure you're correct.
//
// Sending me answers to the questions in these files is also a great way for you to test your
// knowledge and understanding.
#include <iostream>
#include "Locked_queue.hpp"
#include <mutex>
#include <random>
#include <thread>
#include <utility>

class Library {
   std::mutex ostream_exclusion; // when should you use this?
                                 // when shouldn't you use it?
   using Ostream_lock = std::lock_guard<decltype(ostream_exclusion)>;
public:
   static constexpr auto ceiling = 1'000; // what is the difference between 1000 and 1'000?
   using thread_count_t = decltype(std::thread::hardware_concurrency());

   void producer(const thread_count_t p)
   {
      using namespace std;          // why are these using directives okay?
      using namespace std::chrono;
      auto generator = mt19937(system_clock::now().time_since_epoch().count());
      auto distribute = uniform_int_distribution<>{};
      for (auto i = 0; i < ceiling; ++i) {
         auto value = distribute(generator);
         buffer.push(value);
         Ostream_lock lock{ostream_exclusion}; // why not auto lock = lock_guard?
         cout << "producer " << p << ": " << value << '\n';
      }
   }

   void consumer(const thread_count_t c)
   {
      for (auto i = 0; i < ceiling; ++i) {
         auto value = 0;
         buffer.wait_pop(value);
         Ostream_lock lock{ostream_exclusion}; // why not auto lock = lock_guard?
         std::cout << "consumer " << c << ": " << value << '\n';
      }
   }
private:
   Locked_queue<int> buffer{};
};

int main()
{
   std::vector<std::thread> pool{}; // mandel.cpp used a pointer to a thread, because a thread
                                    // object cannot be copied. Why are we able to use a vector of
                                    // threads instead?
   Library l;
   for (auto i = Library::thread_count_t{}; i < std::thread::hardware_concurrency(); ++i) {
      pool.emplace_back(Library::producer, &l, i);
      pool.emplace_back(Library::consumer, &l, i);
   }

   for (auto& i : pool)
      i.join();
}