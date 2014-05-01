/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 
Reference:
	http://code.google.com/p/googletest/wiki/AdvancedGuide#More_Assertions
*/
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

bool f1(int i) {
	return i==1;
}

bool f2(int i, int j) {
	return i-j==0;
}

const int x = 1, y = 2, p = 9, q = 7;

TEST(ASSERT_TRUE, OneEqualsTrue) {
	ASSERT_TRUE(f1(y));
}

TEST(ASSERT_PRED1, OneEqualsTwo) {
	ASSERT_PRED1(f1, y);
}

// TEST(ASSERT_PRED1, OneEqualsOne) {
// 	ASSERT_PRED1(f1, x);
// }

// TEST(ASSERT_PRED2, NineMinusNineIsZero) {
// 	ASSERT_PRED2(f2, p, p);
// }

// TEST(ASSERT_PRED2, NineMinusSevenIsZero) {
// 	ASSERT_PRED2(f2, p, q);
// }



int main(int argc, char *argv[])
{

	cout << "started...." << endl;

	::testing::InitGoogleTest(&argc, argv);

	cout << "NOTE: y's value is not displayed in first failure.." << endl;	

	return RUN_ALL_TESTS();
}