#pragma once

namespace deque_fefu {
template <typename T>
class Deque_iterator {
 public:
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;

  Deque_iterator() noexcept;

  Deque_iterator(T&);  // t

  Deque_iterator(const Deque_iterator& other) noexcept;  // t

  Deque_iterator& operator=(const Deque_iterator& other);  // t

  ~Deque_iterator() = default;

  auto operator<=>(const Deque_iterator&) const = default;  // t

  T& operator*() const;   // t
  T* operator->() const;  // t

  // t
  Deque_iterator& operator++();
  Deque_iterator operator++(int);

  Deque_iterator& operator--();
  Deque_iterator operator--(int);

  Deque_iterator operator+(const difference_type&) const;
  Deque_iterator& operator+=(const difference_type&);

  Deque_iterator operator-(const difference_type&) const;
  Deque_iterator& operator-=(const difference_type&);
  //

  difference_type operator-(const Deque_iterator&) const;  // t

  T& operator[](const difference_type&);  // t

  friend void swap(Deque_iterator<T>& lhs, Deque_iterator<T>& rhs) {  // t
    Deque_iterator<T> tmp = lhs;
    lhs = rhs;
    rhs = tmp;
  }

 private:
  T* curr_;
};

}  // namespace deque_fefu
