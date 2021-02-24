//
// Created by nicola on 04/02/2021.
//
#include "gtest/gtest.h"
#include "../source/Validation.h"

TEST(ValidationTest, one)
{
    EXPECT_TRUE(Validate(reformatInput("-A/\\(B\\/C)")));
}

TEST(ValidationTest, two)
{
    EXPECT_TRUE(Validate(reformatInput("(A\\/B)/\\(-B\\/C\\/-D)/\\(D\\/-E)")));
}

TEST(ValidationTest, three)
{
    EXPECT_TRUE(Validate(reformatInput("A  /\\B")));
}

TEST(ValidationTest, four)
{
    EXPECT_TRUE(Validate(reformatInput("(A/\\B)\\/C")));
}

TEST(ValidationTest, five)
{
    EXPECT_TRUE(Validate(reformatInput("(((A\\/B)))")));
}

TEST(ValidationTest, six)
{
    EXPECT_TRUE(Validate("A"));
}

TEST(ValidationTest, unappropriate)
{
    EXPECT_FALSE(Validate(reformatInput("89ef489fq9h")));
}

TEST(NegativeValidation, one)
{
    EXPECT_FALSE(Validate(reformatInput("((A)")));
}

TEST(NegativeValidation, two)
{
    EXPECT_FALSE(Validate(reformatInput("A\\//\\B")));
}

TEST(NegativeValidation, three)
{
    EXPECT_FALSE(Validate(reformatInput("(\\/B/\\)")));
}

TEST(NegativeValidation, four)
{
    EXPECT_FALSE(Validate(reformatInput("(A-\\/B)")));
}

TEST(ValidationTest, empty)
{
    EXPECT_FALSE(Validate(""));
}

TEST(ValidationTest, bracket)
{
    EXPECT_FALSE(Validate(")"));
}
