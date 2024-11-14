#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "levenshtein.hpp"

TEST(LevenshteinDistanceTests, GivenExample_WhenCalculateDistance_ThenReturnsCorrectDistance)
{
  const auto distance = levenshtein::calculate_distance("Tier", "Tor");

  EXPECT_EQ(distance, 2u);
}


TEST(LevenshteinDistanceTests, GivenAIsZero_WhenCalculateDistance_ThenReturnsCorrectDistance)
{
  auto distance = levenshtein::calculate_distance("", "a");
  EXPECT_EQ(distance, 1u);

  distance = levenshtein::calculate_distance("", "aaa");
  EXPECT_EQ(distance, 3u);

  distance = levenshtein::calculate_distance("", "abcdefghijklmnopqrstuvwxyz");
  EXPECT_EQ(distance, 26u);
}

TEST(LevenshteinDistanceTests, GivenBIsZero_WhenCalculateDistance_ThenReturnsCorrectDistance)
{
  auto distance = levenshtein::calculate_distance( "a","");
  EXPECT_EQ(distance, 1u);

  distance = levenshtein::calculate_distance( "aaa","");
  EXPECT_EQ(distance, 3u);

  distance = levenshtein::calculate_distance( "abcdefghijklmnopqrstuvwxyz","");
  EXPECT_EQ(distance, 26u);
}

TEST(LevenshteinDistanceTests, GivenEqualWords_WhenCalculateDistance_ThenReturnsCorrectDistance)
{
  EXPECT_EQ(levenshtein::calculate_distance("a", "a"),0);
  EXPECT_EQ(levenshtein::calculate_distance("abc", "abc"),0);
  EXPECT_EQ(levenshtein::calculate_distance("hello", "hello"),0);
}
