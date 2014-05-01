/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST(SampleTest, oneIsEqualToOne) {
	EXPECT_EQ(1+0, 2);
}

int main(int argc, char *argv[])
{

	cout << "started...." << endl;

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}