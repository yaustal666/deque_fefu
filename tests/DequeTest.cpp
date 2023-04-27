#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../Res.cpp"
using namespace deque_fefu;

TEST(Deque_test, test1) {
  Deque<int> dq;

  EXPECT_EQ(dq.size(), 0);

  dq.push_back(12);
  EXPECT_EQ(dq.front(), 12);
  EXPECT_EQ(dq.back(), 12);
  dq.push_back(34);
  EXPECT_EQ(dq.front(), 12);
  EXPECT_EQ(dq.back(), 34);
}

TEST(Deque_test, test2) {
  Allocator<int> all;
  Deque<int> dq(all);

  dq.push_front(12);
  EXPECT_EQ(dq.front(), 12);
  EXPECT_EQ(dq.back(), 12);
  dq.push_front(34);
  EXPECT_EQ(dq.front(), 34);
  EXPECT_EQ(dq.back(), 12);
}

TEST(Deque_test, test3) {
  Allocator<int> all;
  Deque<int> dq(all);

  dq.resize(5, 5);
  dq.push_front(23);

  std::stringstream ss;

  for (auto i = dq.begin(); i != dq.end(); ++i) {
    ss << *i << " ";
  }

  EXPECT_EQ(ss.str(), "23 5 5 5 5 5 5 ");
}

int main() {
  testing::InitGoogleTest();
  std::cout << "Testing: \n";
  std::cout << "Deque iterator\n|||||\n|||||\n|||||\nvvvvv\n";

  return RUN_ALL_TESTS();
}