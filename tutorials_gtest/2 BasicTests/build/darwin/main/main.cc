/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST(ASSERT_TRUE, TwoEqualTwo) {
	ASSERT_TRUE(2 == 2);
}

TEST(ASSERT_TRUE, OneEqualTwo) {
	ASSERT_TRUE(1 == 2);
}

TEST(EXPECT_FALSE, TwoEqualThree) {
	EXPECT_FALSE(2 == 3);
}

TEST(EXPECT_FALSE, OneEqualTwo) {
	EXPECT_FALSE(1 == 2);
}

TEST(ASSERT_EQ, OneOne) {
	ASSERT_EQ(1, 1);
}

TEST(EXPECT_EQ, OneTwo) {
	EXPECT_EQ(1, 2);
}

TEST(ASSERT_NE, OneTwo) {
	ASSERT_NE(1, 2);
}

TEST(EXPECT_NE, OneOne) {
	EXPECT_NE(1, 1);
}

TEST(ASSERT_LT, OneTwo) {
	ASSERT_LT(1, 2);
}

TEST(EXPECT_LT, OneOne) {
	EXPECT_LT(1, 1);
}

TEST(ASSERT_LE, OneOne) {
	ASSERT_LE(1, 1);
}

TEST(EXPECT_LE, OneOne) {
	EXPECT_LE(1, 1);
}

TEST(ASSERT_GT, TwoOne) {
	ASSERT_GT(2, 1);
}

TEST(EXPECT_GT, OneOne) {
	EXPECT_GT(1, 1);
}

TEST(ASSERT_GE, OneOne) {
	ASSERT_GE(1, 1);
}

TEST(EXPECT_GE, OneTwo) {
	EXPECT_GE(1, 2);
}

TEST(ASSERT_STREQ, SreeSREE) {
	ASSERT_STREQ("Sree", "SREE");
}

TEST(EXPECT_STREQ, SreeRam) {
	EXPECT_STREQ("Sree", "Ram");
}

TEST(ASSERT_STRNE, SreeRam) {
	ASSERT_STRNE("Sree", "Ram");
}

TEST(EXPECT_STRNE, SreeSree) {
	EXPECT_STRNE("Sree", "Sree");
}

TEST(ASSERT_STRCASEEQ, SreeSree) {
	ASSERT_STRCASEEQ("Sree", "Sree");
}

TEST(EXPECT_STRCASEEQ, SreeRam) {
	EXPECT_STRCASEEQ("Sree", "Ram");
}

TEST(ASSERT_STRCASENE, SreeRam) {
	ASSERT_STRCASENE("Sree", "Ram");
}

TEST(EXPECT_STRCASENE, SreeSree) {
	EXPECT_STRCASENE("Sree", "Sree");
}



int main(int argc, char *argv[])
{

	cout << "started...." << endl;

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}