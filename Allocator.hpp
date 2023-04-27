#pragma once
#include <iterator>
#include <memory>

namespace deque_fefu {

template <typename T>
class Allocator {
 public:
  using value_type = T;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;

  Allocator() noexcept = default;

  Allocator(const Allocator&) noexcept = default;

  template <class U>
  Allocator(const Allocator<U>& other) noexcept;

  ~Allocator() = default;

  pointer allocate(size_type);

  void deallocate(pointer p, size_type n) noexcept;

  //[[nodiscard]] std::allocation_result<T*> allocate_at_least(
  // std::size_t n ); // TODO For extra points
};

}  // namespace deque_fefu