/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;

using ::testing::Invoke;
using ::testing::_;
using ::testing::Gt;
using ::testing::WithArgs;
using ::testing::Return;

MOCK_METHOD3(run, bool(int, int, int) );

bool f(int i) {return i==0;}

TEST(MockSignClass, runWithZero) {
	EXPECT_CALL( run(_,_,_) )
		.WillOnce( WithArgs<1>( Invoke(f) ) );

	EXPECT_TRUE( run(1092, 0, -7) );
}


// TEST(SampleTest, oneIsEqualToOne) {
// 	EXPECT_EQ(1+0, 2);
// }

int main(int argc, char *argv[])
{

	cout << "started...." << endl;

	::testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}