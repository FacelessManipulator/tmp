#include "hello.h"
#include "gtest/gtest.h"

TEST(HelloTest, Test1) {
	EXPECT_EQ(0, playground::hello());
}

