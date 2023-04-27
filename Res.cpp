#include "Allocator.hpp"
#include "Deque.hpp"
#include "Deque_const_iterator.hpp"
#include "Deque_iterator.hpp"
#include "Deque_reverse_iterator.hpp"

namespace deque_fefu {

// Allocator
template <typename T>
typename Allocator<T>::pointer Allocator<T>::allocate(size_type size) {
  return new T[size];
}

template <typename T>
void Allocator<T>::deallocate(pointer p, size_type n) noexcept {
  delete[] p;
}
// end Allocator

// Deque iterator
template <typename T>
Deque_iterator<T>::Deque_iterator() noexcept {}

template <typename T>
Deque_iterator<T>::Deque_iterator(T& smth) {
  curr_ = &smth;
}

template <typename T>
Deque_iterator<T>::Deque_iterator(const Deque_iterator<T>& other) noexcept {
  curr_ = other.curr_;
}

template <typename T>
Deque_iterator<T>& Deque_iterator<T>::operator=(
    const Deque_iterator<T>& other) {
  curr_ = other.curr_;
  return *this;
}

template <typename T>
T& Deque_iterator<T>::operator*() const {
  return *curr_;
}

template <typename T>
T* Deque_iterator<T>::operator->() const {
  return curr_;
}

template <typename T>
Deque_iterator<T> Deque_iterator<T>::operator+(
    const difference_type& shift) const {
  Deque_iterator<T> tmp = *this;
  tmp.curr_ += shift;
  return tmp;
}

template <typename T>
Deque_iterator<T>& Deque_iterator<T>::operator+=(const difference_type& shift) {
  *this = *this + shift;
  return *this;
}

template <typename T>
Deque_iterator<T>& Deque_iterator<T>::operator++() {
  *this = *this + 1;
  return *this;
}

template <typename T>
Deque_iterator<T> Deque_iterator<T>::operator++(int) {
  Deque_iterator<T> tmp = *this;
  *this = *this + 1;
  return tmp;
}

template <typename T>
Deque_iterator<T> Deque_iterator<T>::operator-(
    const difference_type& shift) const {
  Deque_iterator<T> tmp = *this;
  tmp.curr_ -= shift;
  return tmp;
}

template <typename T>
Deque_iterator<T>& Deque_iterator<T>::operator-=(const difference_type& shift) {
  *this = *this - shift;
  return *this;
}

template <typename T>
Deque_iterator<T>& Deque_iterator<T>::operator--() {
  *this = *this - 1;
  return *this;
}

template <typename T>
Deque_iterator<T> Deque_iterator<T>::operator--(int) {
  Deque_iterator<T> tmp = *this;
  *this = *this - 1;
  return tmp;
}

template <typename T>
typename Deque_iterator<T>::difference_type Deque_iterator<T>::operator-(
    const Deque_iterator& other) const {
  difference_type result;
  if (curr_ > other.curr_)
    result = curr_ - other.curr_;
  else
    result = other.curr_ - curr_;

  return result;
}

template <typename T>
T& Deque_iterator<T>::operator[](const difference_type& shift) {
  return *(*this + shift);
}

// end Deque iterator

// Deque const iterator
template <typename T>
Deque_const_iterator<T>::Deque_const_iterator() noexcept {}

template <typename T>
Deque_const_iterator<T>::Deque_const_iterator(
    const Deque_const_iterator<T>& other) noexcept {
  curr_ = other.curr_;
}

template <typename T>
Deque_const_iterator<T>::Deque_const_iterator(
    const Deque_iterator<T>& other) noexcept {
  curr_ = other;
}

template <typename T>
Deque_const_iterator<T>& Deque_const_iterator<T>::operator=(
    const Deque_const_iterator<T>& other) {
  curr_ = other.curr_;
  return *this;
}

template <typename T>
Deque_const_iterator<T>& Deque_const_iterator<T>::operator=(
    const Deque_iterator<T>& other) {
  curr_ = other;
  return *this;
}

template <typename T>
T& Deque_const_iterator<T>::operator*() const {
  return *curr_;
}

template <typename T>
T* Deque_const_iterator<T>::operator->() const {
  return &(*curr_);
}

template <typename T>
Deque_const_iterator<T> Deque_const_iterator<T>::operator+(
    const difference_type& shift) const {
  Deque_const_iterator<T> tmp = *this;
  tmp.curr_ = tmp.curr_ + shift;
  return tmp;
}

template <typename T>
Deque_const_iterator<T>& Deque_const_iterator<T>::operator+=(
    const difference_type& shift) {
  curr_ = curr_ + shift;
  return *this;
}

template <typename T>
Deque_const_iterator<T> Deque_const_iterator<T>::operator-(
    const difference_type& shift) const {
  Deque_const_iterator<T> tmp = *this;
  tmp.curr_ = tmp.curr_ - shift;
  return tmp;
}

template <typename T>
Deque_const_iterator<T>& Deque_const_iterator<T>::operator-=(
    const difference_type& shift) {
  curr_ = curr_ - shift;
  return *this;
}

template <typename T>
Deque_const_iterator<T>& Deque_const_iterator<T>::operator++() {
  curr_ = curr_ + 1;
  return *this;
}

template <typename T>
Deque_const_iterator<T> Deque_const_iterator<T>::operator++(int) {
  Deque_const_iterator<T> tmp = *this;
  ++(*this);
  return tmp;
}

template <typename T>
Deque_const_iterator<T>& Deque_const_iterator<T>::operator--() {
  curr_ = curr_ - 1;
  return *this;
}

template <typename T>
Deque_const_iterator<T> Deque_const_iterator<T>::operator--(int) {
  Deque_const_iterator<T> tmp = *this;
  --(*this);
  return tmp;
}

template <typename T>
typename Deque_const_iterator<T>::difference_type
Deque_const_iterator<T>::operator-(const Deque_const_iterator<T>& other) const {
  return curr_ - other.curr_;
}

template <typename T>
T& Deque_const_iterator<T>::operator[](const difference_type& shift) {
  return *(curr_ + shift);
}
// end Deque const iterator

// Deque reverse iterator
template <class Iter>
constexpr Deque_reverse_iterator<Iter>::Deque_reverse_iterator() {}

template <class Iter>
constexpr Deque_reverse_iterator<Iter>::Deque_reverse_iterator(
    Deque_reverse_iterator::iterator_type x) {
  iterator_ = x;
}

template <class Iter>
template <class U>
constexpr Deque_reverse_iterator<Iter>::Deque_reverse_iterator(
    const Deque_reverse_iterator<U>& other) {
  iterator_ = other.iterator_;
}

template <class Iter>
template <class U>
Deque_reverse_iterator<Iter>& Deque_reverse_iterator<Iter>::operator=(
    const Deque_reverse_iterator<U>& other) {
  iterator_ = other.iterator_;
  return *this;
}

template <class Iter>
typename Deque_reverse_iterator<Iter>::iterator_type
Deque_reverse_iterator<Iter>::base() const {
  return iterator_;
}

template <class Iter>
typename Deque_reverse_iterator<Iter>::reference
Deque_reverse_iterator<Iter>::operator*() const {
  return *(iterator_ - 1);
}

template <class Iter>
typename Deque_reverse_iterator<Iter>::pointer
Deque_reverse_iterator<Iter>::operator->() const {
  return *(iterator_ - 1);
}

template <class Iter>
typename Deque_reverse_iterator<Iter>::reference
Deque_reverse_iterator<Iter>::operator[](
    Deque_reverse_iterator<Iter>::difference_type n) {
  return *(iterator_ - 1 + n);
}

template <class Iter>
Deque_reverse_iterator<Iter>& Deque_reverse_iterator<Iter>::operator++() {
  --iterator_;
  return *this;
}

template <class Iter>
Deque_reverse_iterator<Iter> Deque_reverse_iterator<Iter>::operator++(int) {
  Deque_reverse_iterator<Iter> tmp = *this;
  --iterator_;
  return tmp;
}

template <class Iter>
Deque_reverse_iterator<Iter>& Deque_reverse_iterator<Iter>::operator--() {
  ++iterator_;
  return *this;
}

template <class Iter>
Deque_reverse_iterator<Iter> Deque_reverse_iterator<Iter>::operator--(int) {
  Deque_reverse_iterator<Iter> tmp = *this;
  ++iterator_;
  return tmp;
}

template <class Iter>
Deque_reverse_iterator<Iter> Deque_reverse_iterator<Iter>::operator+(
    difference_type n) const {
  return Deque_reverse_iterator(iterator_ - n);
}

template <class Iter>
Deque_reverse_iterator<Iter>& Deque_reverse_iterator<Iter>::operator+=(
    difference_type n) {
  iterator_ -= n;
  return *this;
}

template <class Iter>
Deque_reverse_iterator<Iter> Deque_reverse_iterator<Iter>::operator-(
    difference_type n) const {
  return Deque_reverse_iterator(iterator_ + n);
}

template <class Iter>
Deque_reverse_iterator<Iter>& Deque_reverse_iterator<Iter>::operator-=(
    difference_type n) {
  iterator_ += n;
  return *this;
}

template <class Iter>
Deque_reverse_iterator<Iter> make_reverse_iterator(Iter i) {
  return Deque_reverse_iterator(i);
}
// end Deque reverse iterator

// Deque
template <typename T, typename Allocator>
Deque<T, Allocator>::Deque() {
  // data_ = alloc_.allocate(0);
  data_size_ = 0;
  first_ = 0;
  last_ = 0;

  // this->expand(10, 10);
}

template <typename T, typename Allocator>
Deque<T, Allocator>::Deque(const Allocator& alloc) {
  // data_ = alloc_.allocate(0);
  alloc_ = alloc;
  data_size_ = 0;
  first_ = 0;
  last_ = 0;

  // this->expand(10, 10);
}

template <typename T, typename Allocator>
Deque<T, Allocator>::Deque(size_type count, const T& value,
                           const Allocator& alloc)
    : Deque(alloc) {
  for (size_type i = 0; i < count; ++i) {
    this->push_back(value);
  }
}

template <typename T, typename Allocator>
Deque<T, Allocator>::Deque(size_type count, const Allocator& alloc)
    : Deque(alloc) {
  this->resize(count);
}

template <typename T, typename Allocator>
template <class InputIt>
Deque<T, Allocator>::Deque(InputIt first, InputIt last, const Allocator& alloc)
    : Deque(alloc) {
  for (auto it = first; it != last; ++it) {
    this->push_back(*it);
  }
}

template <typename T, typename Allocator>
Deque<T, Allocator>::Deque(const Deque& other) : Deque() {
  this->assign(other.begin(), other.end());
}

template <typename T, typename Allocator>
Deque<T, Allocator>::Deque(const Deque& other, const Allocator& alloc)
    : Deque(alloc) {
  this->assign(other.begin(), other.end());
}

template <typename T, typename Allocator>
Deque<T, Allocator>::Deque(Deque&& other) : Deque() {
  this->swap(other);
}

template <typename T, typename Allocator>
Deque<T, Allocator>::Deque(Deque&& other, const Allocator& alloc)
    : Deque(alloc) {
  this->swap(other);
}

template <typename T, typename Allocator>
Deque<T, Allocator>::Deque(std::initializer_list<T> init,
                           const Allocator& alloc)
    : Deque(alloc) {
  this->assign(init);
}

template <typename T, typename Allocator>
Deque<T, Allocator>::~Deque() {
  if (this->size() != 0) alloc_.deallocate(data_, data_size_);
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::clear() noexcept {
  if (data_size_ == 0) return;
  alloc_.deallocate(data_, data_size_);
  data_ = nullptr;
  data_size_ = 0;
  first_ = 0;
  last_ = 0;
}

/// ITERATORS
template <typename T, typename Allocator>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::begin() noexcept {
  return iterator(data_[first_]);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_iterator Deque<T, Allocator>::begin()
    const noexcept {
  return const_iterator(iterator(data_[first_]));
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_iterator Deque<T, Allocator>::cbegin()
    const noexcept {
  return this->begin();
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::end() noexcept {
  return iterator(data_[last_]);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_iterator Deque<T, Allocator>::end()
    const noexcept {
  return const_iterator(iterator(data_[last_]));
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_iterator Deque<T, Allocator>::cend()
    const noexcept {
  return this->end();
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::reverse_iterator
Deque<T, Allocator>::rbegin() noexcept {
  return reverse_iterator(this->end());
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_reverse_iterator
Deque<T, Allocator>::rbegin() const noexcept {
  return const_reverse_iterator(this->cend());
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_reverse_iterator
Deque<T, Allocator>::crbegin() const noexcept {
  return this->rbegin();
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::reverse_iterator
Deque<T, Allocator>::rend() noexcept {
  return reverse_iterator(this->begin());
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_reverse_iterator Deque<T, Allocator>::rend()
    const noexcept {
  return const_reverse_iterator(this->cbegin());
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_reverse_iterator
Deque<T, Allocator>::crend() const noexcept {
  return this->rend();
}
///

/// CAPACITY
template <typename T, typename Allocator>
bool Deque<T, Allocator>::empty() const noexcept {
  return this->size() == 0;
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::size_type Deque<T, Allocator>::size()
    const noexcept {
  return this->data_size_;
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::size_type Deque<T, Allocator>::elementsCount()
    const noexcept {
  return this->data_size_ - first_;
}
///

template <typename T, typename Allocator>
void Deque<T, Allocator>::expand(size_type right, size_type left) {
  size_type new_data_size = data_size_ + right + left;

  T* tmp = alloc_.allocate(new_data_size);

  if (left == 0)
    for (size_type i = 0; i < data_size_; ++i) {
      tmp[i + left] = data_[i];
    }
  else
    for (size_type i = 0; i < data_size_; ++i) {
      tmp[i + first_ + left] = data_[i];
    }

  size_type new_first = first_ + left;
  size_type new_last = last_ + left;

  if (data_size_ != 0) this->clear();
  data_ = alloc_.allocate(new_data_size);

  for (int i = 0; i < new_data_size; ++i) data_[i] = tmp[i];

  data_size_ = new_data_size;
  first_ = new_first;
  last_ = new_last;

  alloc_.deallocate(tmp, new_data_size);
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::shrink(size_type new_size) {
  T* tmp = alloc_.allocate(new_size);

  for (size_type i = 0; i < new_size; ++i) {
    tmp[i] = *(this->begin() + i);
  }

  size_type new_first = 0;
  size_type new_last = new_size - 1;

  if (data_size_ != 0) this->clear();
  data_ = alloc_.allocate(new_size);

  for (int i = 0; i < new_size; ++i) data_[i] = tmp[i];

  data_size_ = new_size;
  first_ = new_first;
  last_ = new_last;

  alloc_.deallocate(tmp, new_size);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::reference Deque<T, Allocator>::front() {
  return *this->begin();
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_reference Deque<T, Allocator>::front()
    const {
  return *this->begin();
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::reference Deque<T, Allocator>::back() {
  return *(this->end() - 1);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_reference Deque<T, Allocator>::back()
    const {
  return *(this->end() - 1);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::reference Deque<T, Allocator>::at(size_type pos) {
  if (pos >= data_size_) {
    throw std::out_of_range("Trying to access data outside of container");
  }
  return *(this->begin() + pos);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_reference Deque<T, Allocator>::at(
    size_type pos) const {
  if (pos >= data_size_) {
    throw std::out_of_range("Trying to access data outside of container");
  }
  return *(this->begin() + pos);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::reference Deque<T, Allocator>::operator[](
    size_type pos) {
  if (pos >= data_size_) {
    throw std::out_of_range("Trying to access data outside of container");
  }
  return *(this->begin() + pos);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::const_reference Deque<T, Allocator>::operator[](
    size_type pos) const {
  if (pos >= data_size_) {
    throw std::out_of_range("Trying to access data outside of container");
  }
  return *(this->begin() + pos);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::allocator_type
Deque<T, Allocator>::get_allocator() const noexcept {
  return alloc_;
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::push_back(const T& value) {
  if (data_size_ == 0) this->expand(1);
  if (last_ == this->size()) {
    this->expand(1);
  }
  *(this->end()) = value;
  last_++;
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::push_back(T&& value) {
  if (data_size_ == 0) this->expand(1);
  if (last_ == this->size()) {
    this->expand(1);
  }
  *(this->end()) = std::move(value);
  last_++;
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::push_front(const T& value) {
  if (data_size_ == 0) this->expand(1);
  if (first_ == 0) this->expand(0, 2);
  *(this->begin() - 1) = value;
  first_--;
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::push_front(T&& value) {
  if (data_size_ == 0) this->expand(1);
  if (first_ == 0) this->expand(0, 2);
  *(this->begin() - 1) = std::move(value);
  first_--;
}

template <typename T, typename Allocator>
template <class... Args>
typename Deque<T, Allocator>::reference Deque<T, Allocator>::emplace_back(
    Args&&... args) {
  (this->push_back(args), ...);
  return this->back();
}

template <typename T, typename Allocator>
template <class... Args>
typename Deque<T, Allocator>::reference Deque<T, Allocator>::emplace_front(
    Args&&... args) {
  (this->push_front(args), ...);
  return this->front();
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::pop_back() {
  *(this->end() - 1) = T();
  last_--;
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::pop_front() {
  *(this->begin()) = T();
  first_++;
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::erase(
    const_iterator pos) {
  value_type temp = *(this->end() - 1);
  for (auto it = this->end() - 1; it >= pos; --it) {
    std::swap(*it, temp);
  }
  this->pop_back();
  return this->begin() + (pos - this->begin());
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::erase(
    const_iterator first, const_iterator last) {
  difference_type range = last - first;
  for (difference_type i = 0; i < range; ++i) {
    this->erase(first);
  }
  return this->begin() + (first - this->begin());
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::assign(size_type count, const T& value) {
  this->clear();
  for (auto i = 0; i < count; ++i) {
    this->push_back(value);
  }
}

template <typename T, typename Allocator>
template <class InputIt>
void Deque<T, Allocator>::assign(InputIt first, InputIt last) {
  this->clear();
  for (auto it = first; it != last; ++it) {
    this->push_back(*it);
  }
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::assign(std::initializer_list<T> ilist) {
  this->assign(ilist.begin(), ilist.end());
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::swap(Deque& other) {
  std::swap(data_, other.data_);
  std::swap(first_, other.first_);
  std::swap(last_, other.last_);
  std::swap(data_size_, other.data_size_);
  std::swap(alloc_, other.alloc_);
}

template <class T, class Allocator>
void swap(Deque<T, Allocator>& lhs, Deque<T, Allocator>& rhs) {
  lhs.swap(rhs);
}

template <class T, class Allocator, class U>
typename Deque<T, Allocator>::size_type erase(Deque<T, Allocator>& c,
                                              const U& value) {
  typename Deque<T, Allocator>::size_type count = 0;
  for (auto it = c.begin(); it != c.end(); ++it) {
    if (*it == value) {
      it = c.erase(it) - 1;
      ++count;
    }
  }
  return count;
}

template <class T, class Allocator, class Pred>
typename Deque<T, Allocator>::size_type erase_if(Deque<T, Allocator>& c,
                                                 Pred pred) {
  typename Deque<T, Allocator>::size_type number = 0;
  for (auto it = c.begin(); it != c.end(); ++it) {
    if (pred(*it)) {
      it = c.erase(it) - 1;
      ++number;
    }
  }
  return number;
}

template <typename T, typename Allocator>
Deque<T, Allocator>& Deque<T, Allocator>::operator=(const Deque& other) {
  this->clear();
  this->assign(other.begin(), other.end());
  return *this;
}

template <typename T, typename Allocator>
Deque<T, Allocator>& Deque<T, Allocator>::operator=(Deque&& other) {
  this->clear();
  data_ = std::move(other.data_);
  first_ = std::move(other.first_);
  last_ = std::move(other.last_);
  data_size_ = std::move(other.data_size_);
  alloc_ = std::move(other.alloc_);

  return *this;
}

template <typename T, typename Allocator>
Deque<T, Allocator>& Deque<T, Allocator>::operator=(
    std::initializer_list<T> ilist) {
  this->clear();
  this->assign(ilist);
  return *this;
}

template <class T, class Allocator>
auto Deque<T, Allocator>::operator<=>(const Deque& other) const {
  if (auto res = this->size() <=> other.size(); res != 0) {
    return res;
  }
  auto itl = this->begin();
  auto itr = other.begin();
  for (; itl != this->end(); ++itl, ++itr) {
    if (auto res = *itl <=> *itr; res != 0) {
      return res;
    }
  }
  return this->size() <=> other.size();
}

template <class T, class Allocator>
bool Deque<T, Allocator>::operator==(const Deque& other) const {
  return !((*this < other) || (*this > other));
}

template <class T, class Allocator>
bool Deque<T, Allocator>::operator!=(const Deque& other) const {
  return !(*this == other);
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::insert(
    const_iterator pos, const T& value) {
  difference_type shift = pos - this->begin();
  iterator it = this->begin() + shift;

  if (it == this->begin()) {
    this->push_front(value);
    return this->begin();
  }

  if (it == this->end()) {
    this->push_back(value);
    return this->end() - 1;
  }

  value_type tmp = value;
  while (it != this->end()) {
    std::swap(*it, tmp);
    ++it;
  }
  this->push_back(tmp);
  return this->begin() + shift;
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::insert(
    const_iterator pos, T&& value) {
  difference_type shift = pos - this->begin();
  iterator it = this->begin() + shift;

  if (it == this->begin()) {
    this->push_front(std::move(value));
    return this->begin();
  }

  if (it == this->end()) {
    this->push_back(std::move(value));
    return this->end() - 1;
  }

  value_type tmp = value;
  while (it != this->end()) {
    std::swap(*it, tmp);
    ++it;
  }
  this->push_back(tmp);
  return this->begin() + shift;
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::insert(
    const_iterator pos, size_type count, const T& value) {
  difference_type shift = pos - this->begin();
  iterator it = this->begin() + shift;
  for (size_type i = 0; i < count; ++i) {
    this->insert(pos, value);
  }
  return it + count - 1;
}

template <typename T, typename Allocator>
template <class InputIt>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::insert(
    const_iterator pos, InputIt first, InputIt last) {
  difference_type shift = pos - this->begin();
  iterator it = this->begin() + shift;
  size_type i = 0;
  for (auto it = first; it != last; ++it) {
    this->insert(pos, *it);
  }
  return it + i - 1;
}

template <typename T, typename Allocator>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::insert(
    const_iterator pos, std::initializer_list<T> ilist) {
  return this->insert(pos, ilist.begin(), ilist.end());
}

template <typename T, typename Allocator>
template <class... Args>
typename Deque<T, Allocator>::iterator Deque<T, Allocator>::emplace(
    const_iterator pos, Args&&... args) {
  (this->insert(pos, args), ...);
  iterator it(*pos);
  return it - 1;
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::resize(size_type count, const value_type& value) {
  size_type curr_size = this->size();
  if (this->size() < count) {
    this->expand(count - curr_size);
    for (int i = 0; i < count - curr_size + 1; ++i) {
      this->push_back(value);
    }
  } else {
    this->shrink(count);
  }
}

template <typename T, typename Allocator>
void Deque<T, Allocator>::resize(size_type count) {
  this->resize(count, T());
}
// end Deque

}  // namespace deque_fefu
