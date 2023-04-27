#include "Deque_iterator.hpp"
#pragma once
namespace deque_fefu {
template <typename T>
class Deque_const_iterator {
 public:
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;

  Deque_const_iterator() noexcept;
  Deque_const_iterator(const Deque_const_iterator&) noexcept;
  Deque_const_iterator(const Deque_iterator<T>&) noexcept;

  Deque_const_iterator& operator=(const Deque_const_iterator&);
  Deque_const_iterator& operator=(const Deque_iterator<T>&);

  ~Deque_const_iterator() = default;

  friend void swap(Deque_const_iterator<T>& lhs, Deque_const_iterator<T>& rhs) {
    Deque_const_iterator<T> tmp = lhs;
    lhs = rhs;
    rhs = tmp;
  }

  T& operator*() const;
  T* operator->() const;

  Deque_const_iterator& operator++();
  Deque_const_iterator operator++(int);

  Deque_const_iterator& operator--();
  Deque_const_iterator operator--(int);

  Deque_const_iterator operator+(const difference_type&) const;
  Deque_const_iterator& operator+=(const difference_type&);

  Deque_const_iterator operator-(const difference_type&) const;
  Deque_const_iterator& operator-=(const difference_type&);

  difference_type operator-(const Deque_const_iterator&) const;

  T& operator[](const difference_type&);

  auto operator<=>(const Deque_const_iterator&) const = default;

 private:
  Deque_iterator<T> curr_;
};

}  // namespace deque_fefu