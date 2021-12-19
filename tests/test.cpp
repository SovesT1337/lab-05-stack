// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>

#include <stack.hpp>
#include <stack2.hpp>
#include <stdexcept>

TEST(Stack, Push) {
  Stack<int> st;
  int i = 1;
  st.push(i);
  st.push(2);
  EXPECT_EQ(st.head(), 2);
}

TEST(Stack, Pop) {
  Stack<int> st;
  st.push(1);
  st.push(2);
  st.pop();
  EXPECT_EQ(st.head(), 1);
}

TEST(Stack, Move) {
  EXPECT_TRUE(std::is_move_assignable<Stack<int>>::value);
  EXPECT_TRUE(std::is_move_constructible<Stack<int>>::value);
}

TEST(Stack_2, Push) {
  Stack2<int> st;
  st.push(1);
  EXPECT_EQ(st.head(), 1);
  st.push(2);
  EXPECT_EQ(st.head(), 2);
}

TEST(Stack_2, Pop) {
  Stack2<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  EXPECT_EQ(st.pop(), 3);
}

TEST(Stack_2, Emplace) {
  Stack2<int> st;
  for (int i = 0; i < 4; ++i) 
    st.push_emplace(i);
  EXPECT_EQ(st.head(), 3);
}
