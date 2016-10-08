// Code largely taken from Anthony Williams' book,
// 'C++ Concurrency in Action'
#ifndef LOCKED_QUEUE_HPP_INCLUDED
#define LOCKED_QUEUE_HPP_INCLUDED
#include <condition_variable>
#include <future>
#include <mutex>
#include <queue>
#include <utility>

template <typename T>
   // requires Semiregular<T>()
class Locked_queue {
   mutable std::mutex exclusion_;
   using Lock_guard  = std::lock_guard<decltype(exclusion_)>;
   using Unique_lock = std::unique_lock<decltype(exclusion_)>;
public:
   using adaptor         = std::queue<T>;
   using container_type  = typename adaptor::container_type;
   using value_type      = typename adaptor::value_type;
   using size_type       = typename adaptor::size_type;
   using reference       = typename adaptor::reference;
   using const_reference = typename adaptor::const_reference;

   Locked_queue() = default;
   Locked_queue(const Locked_queue& o)
      : data_{o.lock_and_copy()}
   {
   }

   Locked_queue& operator=(const Locked_queue& o)
   {
      Locked_queue{o}.swap(*this);
      return *this;
   }

   void push(const T& t)
   {
      _push(t);
   }

   void push(T&& t)
   {
      _push(t);
   }

   template <typename... Args>
   void emplace(Args&&... a)
   {
      Lock_guard lock{exclusion_};
      data_.emplace(std::forward<Args>(a)...);
      alert_.notify_one();
   }

   bool try_pop(T& t)
   {
      Lock_guard lock{exclusion_};
      if (data_.empty())      // why data_.empty() and not this->empty()?
         return false;
      t = data_.front();
      data_.pop();
      return true;
   }

   std::unique_ptr<T> try_pop()
   {
      Lock_guard lock{exclusion_};
      if (data_.empty())
         return {};
      auto f = std::make_unique<T>(data_.front());
      data_.pop();
      return f;
   }

   void wait_pop(T& t)
   {
      Unique_lock lock{exclusion_};
      alert_.wait(lock, [this]{ return !data_.empty(); }); // what does this achieve?
      t = data_.front();
      data_.pop();
   }

   std::unique_ptr<T> wait_pop()
   {
      Unique_lock lock{exclusion_};
      alert_.wait(lock, [this]{ return !data_.empty(); }); // what does this?
      auto f = std::make_unique<T>(data_.front());
      data_.pop();
      return f;
   }

   constexpr size_type size() const noexcept
   {
      Lock_guard lock{exclusion_};
      return data_.size();
   }

   constexpr bool empty() const noexcept
   {
      return !size();      // why do we define it like this?
   }
private:
   adaptor data_;
   std::condition_variable alert_;

   // what is special about _push?
   template <typename U>
   void _push(U&& u)
   {
      Lock_guard lock{exclusion_};
      data_.push(std::forward<U>(u));
      alert_.notify_one();
   }

   adaptor lock_and_copy() const
   {
      Lock_guard lock{exclusion_};
      return data_;
   }

   void swap(Locked_queue& o) noexcept
   {
      Lock_guard{exclusion_}; // why don't we lock o.exclusion_?
      using std::swap;
      swap(data_, o.data_);
   }
};
#endif // LOCKED_QUEUE_HPP_INCLUDED