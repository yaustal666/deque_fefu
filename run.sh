#! /usr/bin/bash

# clang++ -fsanitize=address -fsanitize=undefined -std=c++20 -Wall -Werror main.cpp
# ./a.out

# clang++ -pthread -fsanitize=address -fsanitize=undefined -std=c++20 -g -Wall -Werror -gdwarf-4 tests/Deque_iteratorTest.cpp -lgtest -lgtest_main -o TestsOutput/dq_it.out
# ./TestsOutput/dq_it.out

# clang++ -pthread -fsanitize=address -fsanitize=undefined -std=c++20 -g -Wall -Werror -gdwarf-4 tests/Deque_const_iteratorTest.cpp -lgtest -lgtest_main -o TestsOutput/dq_const_it.out
# ./TestsOutput/dq_const_it.out

clang++ -pthread -fsanitize=address -fsanitize=undefined -std=c++20 -g -Wall -Werror -gdwarf-4 tests/DequeTest.cpp -lgtest -lgtest_main -o TestsOutput/dq.out
./TestsOutput/dq.out