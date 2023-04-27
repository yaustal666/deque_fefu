#include <iostream>

#include "Res.cpp"

using namespace deque_fefu;

int main() {
  Allocator<int> all;
  Deque<int> dq1((size_t)6, all);

  Deque<int> dq2(dq1);

  for (int i = 0; i < dq2.size(); ++i) {
    std::cout << dq2.data_[i] << std::endl;
  }
}