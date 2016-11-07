// old code that has been commended out is done so using C90-style comments (i.e. /**/)
// comments that are relevant to this modified Bad_list are done using C++-style comments (i.e. //)
/*#pragma once*/
#ifndef BAD_LIST_HPP_INCLUDED
#define BAD_LIST_HPP_INCLUDED
#include <algorithm>
#include <memory>
#include <utility>

/*using namespace std;*/

template <typename T>
   // requires ranges::Regular<T>() &&
   //         ranges::StrictTotallyOrdered<T>()
class Bad_list {
   struct Node;
   template <typename P>
      // requires ranges::Same<Node, std::remove_const_t<P>>()
   class Iterator;
public:
   using value_type             = T;
   using size_type              = std::size_t;
   using difference_type        = std::ptrdiff_t;
   using reference              = value_type&;
   using const_reference        = const value_type&;
   using pointer                = value_type*;
   using const_pointer          = const value_type*;
   /*typedef Iterator iterator;*/
   using iterator               = Iterator<Node>;
   /*typedef const Iterator const_iterator;*/
   using const_iterator         = Iterator<const Node>;
   using reverse_iterator       = std::reverse_iterator<iterator>;
   using const_reverse_iterator = std::reverse_iterator<const_iterator>;

   /*Bad_list()
   {
      head_.reset();
      size_.reset();
   }*/
   Bad_list() noexcept = default;

   /*Bad_list(unsigned int size)
   {
      int i = 0;
      head_ = shared_ptr<Node>(new Node(T{}, shared_ptr<Node>{}, shared_ptr<Node>{}));
      while (i < size) {
         head_ = shared_ptr<Node>(new Node{T(), shared_ptr<Node>{}, shared_ptr<Node>{}});
         i++;
      }

      size_ = shared_ptr<int>(new int);
      *size_ = size;
   }*/
   explicit Bad_list(const difference_type n, const T& t = T{})
   {
      while (size() < n)
         push_back_impl(*this, t);
   }

   /*Bad_list(const Bad_list& o)
   {
      head_ = o.head_;
      size_ = o.size_;
   }*/
   Bad_list(const Bad_list& o)
      : head_{!o.empty() ? std::make_unique<Node>(*o.head_) : nullptr},
        front_{head_ ? head_->next_.get() : nullptr},
        back_{head_.get()}
   {
      for (; size() < o.size(); ++size_)
         back_ = back_->next_.get();
      back_ = back_->prev_;
   }

   /*Bad_list(Bad_list&& o)
   {
      if (this != &o) {
         head_ = o.head_;
         size_ = o.size_;
      }
   }*/
   Bad_list(Bad_list&& o) noexcept
      : head_{std::move(o.head_)},
        front_{o.front_},
        back_{o.back_},
        size_{o.size_}
   {
      o.clear();
   }

   /*Bad_list& operator=(const Bad_list& o)
   {
      head_ = o.head_;
      size_ = o.size_;
      return *this;
   }*/
   Bad_list& operator=(const Bad_list& o)
   {
      Bad_list{o}.swap(*this);
      return *this;
   }

   /*Bad_list& operator=(const Bad_list&& o)
   {
      if (this != &o) {
         head_ = o.head_;
         size_ = o.size_;

         const_cast<Bad_list&&>(o).head_.reset();
         const_cast<Bad_list&&>(o).size_ = 0;
      }

      return *this;
   }*/
   Bad_list& operator=(Bad_list&& o) noexcept
   {
      clear();
      swap(o);
      return *this;
   }

   ~Bad_list() = default;

   /*void push_back(T t)
   {
      shared_ptr<Node> p = head_;
      while (p->next_)
         p = p->next_;
      p->next_ = shared_ptr<Node>(new Node(T(), shared_ptr<Node>(), shared_ptr<Node>()));
      p->next_->prev_ = p;
   }*/
   void push_back(const T& t)
   {
      push_back_impl(*this, t);
   }

   void push_back(T&& t)
   {
      push_back_impl(*this, std::move(t));
   }

   /*template <typename... Args>          content necessary for emplace_back not covered in COMP6771
   void emplace_back(Args... a)
   {
      T t(a...);
      return push_back(t);
   }

   void push_front(T t)
   {
      head_->prev_ = shared_ptr<Node>(new Node(T(), shared_ptr<Node>(), shared_ptr<Node>()));
      head_->prev_->next_ = head_;
      head_ = head_->prev_;
   }*/
   void push_front(const T& t)
   {
      push_front_impl(*this, t);
   }

   void push_front(T&& t)
   {
      push_front_impl(*this, std::move(t));
   }

   /*template <typename... Args>         content necessary for emplace_front not covered in COMP6771
   void emplace_front(Args... a)
   {
      T t(a...);
      return push_front(t);
   }

   T pop_back()
   {
      if (empty())
         throw new runtime_error("couldn't do it...");
      shared_ptr<Node> p = head_;
      while (p->next_)
         p = p->next_;
      T t = p->element_;
      p->prev_->next_.reset();
      return std::move(t);
   }*/
   const T& back() const noexcept
   {
      return back_->element_;
   }

   T& back() noexcept
   {
      return back_->element_;
   }

   void pop_back() noexcept
   {
      back_ = back_->prev_;
      back_->next_ = std::move(back_->next_->next_);
      back_->next_->prev_ = back_;
      --size_;
   }

   /*T pop_front()
   {
      if (empty())
         throw runtime_error("couldn't do it...");
      shared_ptr<Node> p = head_;
      head_ = head_->next_;
      return std::forward<T>(p->element_);
   }*/
   const T& front() const noexcept
   {
      return front_->element_;
   }

   T& front() noexcept
   {
      return front_->element_;
   }

   void pop_front() noexcept
   {
      head_->next_ = std::move(head_->next_->next_);
      front_ = head_->next_.get();
      front_->prev_ = head_.get();
      --size_;
   }

   /*bool empty()
   {
      return size_ == 0;
   }*/
   bool empty() const noexcept
   {
      return !size();
   }

   /*unsigned int size()
   {
      return *size_;
   }*/
   difference_type size() const noexcept
   {
      return size_;
   }

   /*void clear() noexcept
   {
      try {
         pop_front();
         clear();
      }
      catch (...) {
         return;
      }
   }*/
   void clear() noexcept
   {
      head_ = nullptr;
      front_ = nullptr;
      back_ = nullptr;
      size_ = 0;
   }

   /*iterator& begin()
   {
      const_iterator i = cbegin();
      return const_cast<iterator&>(i);
   }*/
   iterator begin() noexcept
   {
      return begin_impl(*this);
   }

   const_iterator begin() const noexcept
   {
      return begin_impl(*this);
   }

   /*const_iterator cbegin()
   {
      return *(new const_iterator(head_));
   }*/
   auto cbegin() const noexcept
   {
      return begin();
   }

   /*iterator& end()
   {
      const_iterator i = cend();
      return const_cast<iterator&>(i);
   }*/
   iterator end() noexcept
   {
      return end_impl(*this);
   }

   const_iterator end() const noexcept
   {
      return end_impl(*this);
   }

   /*const_iterator cend()
   {
      return *(new const_iterator(shared_ptr<Node>()));
   }*/
   auto cend() const noexcept
   {
      return end();
   }

   reverse_iterator rbegin() noexcept
   {
      return rbegin_impl(*this);
   }

   const_reverse_iterator rbegin() const noexcept
   {
      return rbegin_impl(*this);
   }

   auto crbegin() const noexcept
   {
      return rbegin();
   }

   reverse_iterator rend() noexcept
   {
      return rend_impl(*this);
   }

   const_reverse_iterator rend() const noexcept
   {
      return rend_impl(*this);
   }

   auto crend() const noexcept
   {
      return rend();
   }

   /*void swap(Bad_list* other)
   {
      std::swap(this->head_, other->head_);
      std::swap(this->size_, other->size_);
   }*/
   void swap(Bad_list& other) noexcept
   {
      using std::swap;
      swap(head_, other.head_);
      swap(size_, other.size_);
   }
private:
   using Owner = std::unique_ptr<Node>;

   //shared_ptr<Node> head_;
   Owner head_{};
   Node* front_{};
   Node* back_{};
   //shared_ptr<int> size_;
   difference_type size_{};

   template <typename N>
      // requires ranges::Same<T, std::remove_const_t<std::remove_reference_t<N>>>()
   static void push_back_impl(Bad_list& l, N&& n)
   {
      if (l.empty()) {
         push_first(l, std::forward<N>(n));
      }
      else {
         l.back_->next_ = std::make_unique<Node>(std::forward<N>(n), std::move(l.back_->next_), l.back_);
         l.back_ = l.back_->next_.get();
      }

      l.back_->next_->prev_ = l.back_;
      ++l.size_;
   }

   template <typename N>
      // requires ranges::Same<T, std::remove_const_t<std::remove_reference_t<N>>>()
   void push_front_impl(Bad_list& l, N&& n)
   {
      if (l.empty()) {
         push_first(l, std::forward<N>(n));
      }
      else {
         l.head_->element_ = std::forward<N>(n);
         l.head_ = std::make_unique<Node>(T{}, std::move(l.head_), nullptr);
         l.front_ = l.head_->next_.get();
      }

      l.head_->next_->prev_ = l.head_.get();
      ++size_;
   }

   template <typename N>
      // requires ranges::Same<T, std::remove_const_t<std::remove_reference_t<N>>>()
   static void push_first(Bad_list& l, N&& n)
   {
      l.head_ = std::make_unique<Node>(T{},
                                       std::make_unique<Node>(std::forward<N>(n),
                                                              std::make_unique<Node>(T{}, nullptr, nullptr),
                                                              nullptr),
                                       nullptr);
      l.back_ = l.head_->next_.get();
      l.back_->prev_ = l.head_.get();
      l.back_->next_->prev_ = l.back_;
      l.head_->next_->prev_ = l.head_.get();
      l.front_ = l.back_;
   }

   template <typename L>
      // requires ranges::Same<Node, std::remove_const_t<Node>>()
   static auto begin_impl(L& l) noexcept -> decltype(l.begin())
   {
      return decltype(l.begin()){l.front_};
   }

   template <typename L>
      // requires ranges::Same<Node, std::remove_const_t<Node>>()
   static auto end_impl(L& l) noexcept -> decltype(l.end())
   {
      return l.empty() ? begin_impl(l) : decltype(l.end()){l.back_->next_.get()};
   }

   template <typename L>
      // requires ranges::Same<Node, std::remove_const_t<Node>>()
   static auto rbegin_impl(L& l) noexcept -> decltype(l.rbegin())
   {
      return decltype(l.rbegin()){end_impl(l)};
   }

   template <typename L>
      // requires ranges::Same<Node, std::remove_const_t<Node>>()
   static auto rend_impl(L& l) noexcept -> decltype(l.rend())
   {
      return l.empty() ? rbegin_impl(l) : decltype(l.rend()){l.head_->next_.get()};
   }

   struct Node {
      T element_;
      /*shared_ptr<Node> next_;
        shared_ptr<Node> prev_;*/
      Owner next_;
      Node* prev_;

      /*Node(T e, shared_ptr<Node> n, shared_ptr<Node> p)
      {
         element_ = e;
         next_ = n;
         prev_ = p;
      }*/
      Node(T e, Owner n, Node* p) noexcept
         : element_{std::move(e)},
           next_{std::move(n)},
           prev_{p}
      {}

      /*Node(const Node& o)
      {
         element_ = o.element_;
         next_ = o.next_;
         prev_ = o.prev_;
      }*/
      Node(const Node& o)
         : element_{o.element_},
           next_{o.next_ ? std::make_unique<Node>(*o.next_) : nullptr}
      {
         if (next_)
            next_->prev_ = this;
      }

      Node(Node&&) noexcept = default;
      Node& operator=(const Node&) = delete;
      Node& operator=(Node&&) noexcept = default;

      /*~Node()
      {
         next_.reset();
         prev_.reset();
      }*/
      ~Node() = default;
   };

   template <typename P>
      // requires ranges::Same<Node, std::remove_const_t<P>>()
   /*struct Iterator {*/
   class Iterator {
   public:
      using difference_type = Bad_list::difference_type;
      using value_type = std::conditional_t<std::is_const<P>::value, const T, T>;
      using pointer = P*;
      using const_pointer = const P*;
      using reference = value_type&;
      using const_reference = const value_type&;
      using iterator_category = std::bidirectional_iterator_tag;

      /*Iterator(shared_ptr<Node> p)
         : ptr_(p)
      {}*/
      Iterator() noexcept = default;
      Iterator(pointer p) noexcept
         : ptr_{p}
      {}

      template <typename U>
         // requires ranges::Same<U, std::remove_const_t<U>>() &&
         //          !ranges::Same<U, P>()                        // ew... shouldn't be negating a concept
      Iterator(Iterator<U> i) noexcept
         : ptr_{i.ptr_}
      {}

      /*Iterator operator++()
      {
         ptr_ = ptr_.lock()->next_;
      }*/
      Iterator& operator++() noexcept
      {
         ptr_ = ptr_->next_.get();
         return *this;
      }

      Iterator operator++(int) noexcept
      {
         auto i = *this;
         operator++();
         return i;
      }

      /*Iterator operator--()
      {
         ptr_ = ptr_.lock()->prev_;
      }*/
      Iterator& operator--() noexcept
      {
         ptr_ = ptr_->prev_;
         return *this;
      }

      Iterator operator--(int) noexcept
      {
         auto i = *this;
         operator--();
         return i;
      }

      /*T operator*() const
      {
         return new T(*ptr_.lock());
      }*/

      const_reference operator*() const noexcept
      {
         return ptr_->element_;
      }

      /*T& operator*()
      {
         return const_cast<T&>(operator*());
      }*/
      reference operator*() noexcept
      {
         return ptr_->element_;
      }

      /*shared_ptr<Node> operator->()
      {
         return ptr_.lock();
      }*/
      pointer operator->() noexcept
      {
         return std::addressof(**this);
      }

      const_pointer operator->() const noexcept
      {
         return std::addressof(**this);
      }

      /*bool operator==(const Iterator i)
      {
         return ptr_.lock() == i.ptr_.lock();
      }*/
      bool operator==(const Iterator& i) const noexcept
      {
         return ptr_ == i.ptr_;
      }

      /*bool operator!=(const Iterator i)
      {
         return ptr_.lock() != i.ptr_.lock();
      }*/

      bool operator!=(const Iterator& i) const noexcept
      {
         return !(*this == i);
      }
   private:
      /*weak_ptr<Node> ptr_;*/
      pointer ptr_;
      friend Iterator<const P>;
   };
};

template <typename T>
   // requires ranges::Regular<T>() &&
   //          ranges::StrictTotallyOrdered<T>()
inline bool operator==(const Bad_list<T>& a, const Bad_list<T>& b) noexcept
{
   if (a.size() != b.size())
      return false;
   for (auto i = a.begin(), j = b.begin(); i != a.end(); ++i, (void)++j) // yes, `(void)`; it's the only time you're allowed to do an unnamed cast :)
      if (*i != *j)
         return false;
   return true;
}

template <typename T>
   // requires ranges::Regular<T>() &&
   //          ranges::StrictTotallyOrdered<T>()
inline bool operator!=(const Bad_list<T>& a, const Bad_list<T>& b) noexcept
{
   return !(a == b);
}

template <typename T>
   // requires ranges::Regular<T>() &&
   //          ranges::StrictTotallyOrdered<T>()
inline bool operator<(const Bad_list<T>& a, const Bad_list<T>& b) noexcept
{
   return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

template <typename T>
   // requires ranges::Regular<T>() &&
   //          ranges::StrictTotallyOrdered<T>()
inline bool operator>(const Bad_list<T>& a, const Bad_list<T>& b) noexcept
{
   return b < a;
}

template <typename T>
   // requires ranges::Regular<T>() &&
   //          ranges::StrictTotallyOrdered<T>()
inline bool operator<=(const Bad_list<T>& a, const Bad_list<T>& b) noexcept
{
   return !(a > b);
}

template <typename T>
   // requires ranges::Regular<T>() &&
   //          ranges::StrictTotallyOrdered<T>()
inline bool operator>=(const Bad_list<T>& a, const Bad_list<T>& b) noexcept
{
   return !(a < b);
}

template <typename T>
   // requires ranges::Regular<T>() &&
   //          ranges::StrictTotallyOrdered<T>()
inline void swap(Bad_list<T>& a, Bad_list<T>& b) noexcept
{
   a.swap(b);
}
#endif // BAD_LIST_HPP_INCLUDED
