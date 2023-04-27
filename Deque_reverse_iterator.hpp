#pragma once

namespace deque_fefu {
template <class Iter>
class Deque_reverse_iterator {
 public:
  using iterator_type = Iter;
  using iterator_category =
      typename std::iterator_traits<Iter>::iterator_category;
  using value_type = typename std::iterator_traits<Iter>::value_type;
  using difference_type = typename std::iterator_traits<Iter>::difference_type;
  using pointer = typename std::iterator_traits<Iter>::pointer;
  using reference = typename std::iterator_traits<Iter>::reference;

  constexpr Deque_reverse_iterator();

  constexpr explicit Deque_reverse_iterator(iterator_type x);

  template <class U>
  constexpr Deque_reverse_iterator(const Deque_reverse_iterator<U>& other);

  template <class U>
  Deque_reverse_iterator& operator=(const Deque_reverse_iterator<U>& other);

  iterator_type base() const;

  reference operator*() const;

  pointer operator->() const;

  reference operator[](difference_type n);

  Deque_reverse_iterator& operator++();
  Deque_reverse_iterator operator++(int);

  Deque_reverse_iterator& operator--();
  Deque_reverse_iterator operator--(int);

  Deque_reverse_iterator operator+(difference_type n) const;
  Deque_reverse_iterator& operator+=(difference_type n);

  Deque_reverse_iterator operator-(difference_type n) const;
  Deque_reverse_iterator& operator-=(difference_type n);

  constexpr auto operator<=>(const Deque_reverse_iterator&) const = default;

  template <class IterT>
  friend Deque_reverse_iterator<IterT> operator+(
      typename Deque_reverse_iterator<IterT>::difference_type n,
      const Deque_reverse_iterator<IterT>& it) {
    return it - n;
  }

  template <class Iterator>
  friend auto operator-(const Deque_reverse_iterator<Iterator>& lhs,
                        const Deque_reverse_iterator<Iterator>& rhs) {
    return lhs.iterator_ - rhs.iterator_;
  }

  // operator <=> will be handy

  // friend constexpr std::iter_rvalue_reference_t<Iter> iter_move( const
  // std::reverse_iterator& i ); // For extra points

  // template<std::indirectly_swappable<Iter> Iter2>
  // friend constexpr void iter_swap(const reverse_iterator& x, const
  // std::reverse_iterator<Iter2>& y); // For extra points

 private:
  iterator_type iterator_;
};

template <class Iter>
Deque_reverse_iterator<Iter> make_reverse_iterator(Iter i);

}  // namespace deque_fefu
