cmake_minimum_required(VERSION 3.18)
project(MCTS)

include_directories(include src)

add_executable(main src/main.cpp)

add_executable(tictactoe_tests tests/tictactoe_test.cpp)
add_executable(mcts_tests tests/mcts_test.cpp)
