#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../Res.cpp"
using namespace deque_fefu;

TEST(Deque_const_iterator_test, test1) {
  int g = 8;
  int& a = g;
  Deque_const_iterator<int> it(a);

  EXPECT_EQ(*it, g);
}

TEST(Deque_const_iterator_test, test2) {
  int* arr = new int[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = i;
  }

  Deque_const_iterator<int> it1(arr[0]);
  Deque_const_iterator<int> it2(arr[2]);
  Deque_const_iterator<int> it3(it1);
  it1 = it2;
  EXPECT_EQ(*it3, arr[0]);

  EXPECT_EQ(*it1, arr[2]);

  delete[] arr;
}

TEST(Deque_const_iterator_test, test3) {
  int* arr = new int[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = i;
  }

  Deque_const_iterator<int> it1(arr[0]);
  Deque_const_iterator<int> it2(arr[2]);
  Deque_const_iterator<int> it3(arr[8]);

  bool cmp = it1 > it2;
  EXPECT_EQ(cmp, 0);
  cmp = it1 >= it2;
  EXPECT_EQ(cmp, 0);
  cmp = it1 == it2;
  EXPECT_EQ(cmp, 0);
  cmp = it1 < it2;
  EXPECT_EQ(cmp, 1);
  cmp = it1 <= it2;
  EXPECT_EQ(cmp, 1);
  cmp = it1 != it2;
  EXPECT_EQ(cmp, 1);

  delete[] arr;
}

TEST(Deque_const_iterator_test, test4) {
  std::string a = "abc";
  Deque_const_iterator<std::string> it(a);

  EXPECT_EQ(it->size(), 3);

  it->append("a");

  EXPECT_EQ(it->size(), 4);
  EXPECT_EQ(*it, "abca");
}

TEST(Deque_const_iterator_test, test5) {
  int* arr = new int[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = i;
  }

  Deque_const_iterator<int> it(arr[0]);

  EXPECT_EQ(*(it++), arr[0]);
  EXPECT_EQ(*it, arr[1]);
  EXPECT_EQ(*(++it), arr[2]);

  EXPECT_EQ(*(it--), arr[2]);
  EXPECT_EQ(*it, arr[1]);
  EXPECT_EQ(*(--it), arr[0]);

  it = it + 4;
  EXPECT_EQ(*it, arr[4]);
  it += 3;
  EXPECT_EQ(*it, arr[7]);
  it = it - 2;
  EXPECT_EQ(*it, arr[5]);
  it -= 4;
  EXPECT_EQ(*it, arr[1]);

  Deque_const_iterator<int> it1(arr[0]), it2(arr[9]);

  std::ptrdiff_t diff = it1 - it2;
  EXPECT_EQ(diff, 9);
  diff = it2 - it1;
  EXPECT_EQ(diff, 9);

  diff = 4;
  arr[4] = 67;
  Deque_const_iterator<int> it3(arr[0]);
  EXPECT_EQ(it3[4], arr[4]);

  delete[] arr;
}

TEST(Deque_const_iterator_test, test6) {
  int* arr = new int[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = i;
  }

  Deque_const_iterator<int> it(arr[0]), it1(arr[3]);

  swap(it1, it);

  EXPECT_EQ(*it, arr[3]);
  EXPECT_EQ(*it1, arr[0]);
  delete[] arr;
}
int main() {
  testing::InitGoogleTest();
  std::cout << "Testing: \n";
  std::cout << "Deque iterator\n|||||\n|||||\n|||||\nvvvvv\n";

  return RUN_ALL_TESTS();
}