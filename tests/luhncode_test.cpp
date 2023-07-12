#include <span>
#include <string>
#include <luhncode.hpp>
#include <gtest/gtest.h>

TEST(luhncode, pointer) {
  ASSERT_EQ(luhncode("4561261212345464"), 57);
  ASSERT_EQ(luhncode("4561261212345467"), 60);
}

TEST(luhncode, span) {
  char str1[] = "4561261212345464";
  std::span<char, 16> s1(str1, 16);
  ASSERT_EQ(luhncode(s1), 57);

  char str2[] = "4561261212345467";
  std::span<char, 16> s2(str2, 16);
  ASSERT_EQ(luhncode(s2), 60);
}

TEST(luhncode, string) {
  ASSERT_EQ(luhncode(std::string("4561261212345464")), 57);
  ASSERT_EQ(luhncode(std::string("4561261212345467")), 60);
}

#ifndef LUHNCODE_NO_SIMD

TEST(luhncode_avx, pointer) {
  ASSERT_EQ(luhncode_avx("4561261212345464"), 57);
  ASSERT_EQ(luhncode_avx("4561261212345467"), 60);
}

TEST(luhncode_avx, span) {
  char str1[] = "4561261212345464";
  std::span<char, 16> s1(str1, 16);
  ASSERT_EQ(luhncode_avx(s1), 57);

  char str2[] = "4561261212345467";
  std::span<char, 16> s2(str2, 16);
  ASSERT_EQ(luhncode_avx(s2), 60);
}

TEST(luhncode_avx, string) {
  ASSERT_EQ(luhncode_avx(std::string("4561261212345464")), 57);
  ASSERT_EQ(luhncode_avx(std::string("4561261212345467")), 60);
}

#endif
