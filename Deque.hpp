#pragma once

#include "Allocator.hpp"
#include "Deque_const_iterator.hpp"
#include "Deque_iterator.hpp"
#include "Deque_reverse_iterator.hpp"

namespace deque_fefu {

template <typename T, typename Allocator = Allocator<T>>
class Deque {
 public:
  using value_type = T;
  using allocator_type = Allocator;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = typename std::allocator_traits<Allocator>::pointer;
  using const_pointer =
      typename std::allocator_traits<Allocator>::const_pointer;
  using iterator = Deque_iterator<value_type>;
  using const_iterator = Deque_const_iterator<value_type>;
  using reverse_iterator = Deque_reverse_iterator<iterator>;
  using const_reverse_iterator = Deque_reverse_iterator<const_iterator>;

  Deque();  // t

  explicit Deque(const Allocator& alloc);  // t

  Deque(size_type count, const T& value, const Allocator& alloc = Allocator());

  explicit Deque(size_type count, const Allocator& alloc = Allocator());

  template <class InputIt>
  Deque(InputIt first, InputIt last, const Allocator& alloc = Allocator());

  Deque(const Deque& other);

  Deque(const Deque& other, const Allocator& alloc);

  Deque(Deque&& other);

  Deque(Deque&& other, const Allocator& alloc);

  Deque(std::initializer_list<T> init, const Allocator& alloc = Allocator());

  ~Deque();

  Deque& operator=(const Deque& other);

  Deque& operator=(Deque&& other);

  Deque& operator=(std::initializer_list<T> ilist);

  void assign(size_type count, const T& value);

  template <class InputIt>
  void assign(InputIt first, InputIt last);

  void assign(std::initializer_list<T> ilist);

  allocator_type get_allocator() const noexcept;

  /// ELEMENT ACCESS
  reference at(size_type pos);

  const_reference at(size_type pos) const;

  reference operator[](size_type pos);

  const_reference operator[](size_type pos) const;

  reference front();

  const_reference front() const;

  reference back();

  const_reference back() const;

  /// ITERATORS

  iterator begin() noexcept;

  const_iterator begin() const noexcept;

  const_iterator cbegin() const noexcept;

  iterator end() noexcept;

  const_iterator end() const noexcept;

  const_iterator cend() const noexcept;

  reverse_iterator rbegin() noexcept;

  const_reverse_iterator rbegin() const noexcept;

  const_reverse_iterator crbegin() const noexcept;

  reverse_iterator rend() noexcept;

  const_reverse_iterator rend() const noexcept;

  const_reverse_iterator crend() const noexcept;

  /// CAPACITY

  bool empty() const noexcept;

  size_type size() const noexcept;
  size_type elementsCount() const noexcept;

  // todo
  size_type max_size() const noexcept;
  void shrink_to_fit();

  /// MODIFIERS

  void clear() noexcept;

  iterator insert(const_iterator pos, const T& value);

  iterator insert(const_iterator pos, T&& value);

  iterator insert(const_iterator pos, size_type count, const T& value);

  template <class InputIt>
  iterator insert(const_iterator pos, InputIt first, InputIt last);

  iterator insert(const_iterator pos, std::initializer_list<T> ilist);

  template <class... Args>
  iterator emplace(const_iterator pos, Args&&... args);

  iterator erase(const_iterator pos);

  iterator erase(const_iterator first, const_iterator last);

  void push_back(const T& value);

  void push_back(T&& value);

  template <class... Args>
  reference emplace_back(Args&&... args);

  void pop_back();

  void push_front(const T& value);

  void push_front(T&& value);

  template <class... Args>
  reference emplace_front(Args&&... args);

  void pop_front();

  void resize(size_type count);

  void resize(size_type count, const value_type& value);

  void swap(Deque& other);

  /// COMPARISIONS

  auto operator<=>(const Deque& other) const;

  bool operator==(const Deque& other) const;

  bool operator!=(const Deque& other) const;

 public:
  value_type* data_;
  size_type data_size_;
  allocator_type alloc_;
  size_type first_, last_;

  void expand(size_type right, size_type left = 0);
  void shrink(size_type new_size);
};

/// NON-MEMBER FUNCTIONS

template <class T, class Alloc>
void swap(Deque<T, Alloc>& lhs, Deque<T, Alloc>& rhs);

template <class T, class Alloc, class U>
typename Deque<T, Alloc>::size_type erase(Deque<T, Alloc>& c, const U& value);

template <class T, class Alloc, class Pred>
typename Deque<T, Alloc>::size_type erase_if(Deque<T, Alloc>& c, Pred pred);

}  // namespace deque_fefu
