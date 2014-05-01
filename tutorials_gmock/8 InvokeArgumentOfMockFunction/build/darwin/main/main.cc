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

using ::testing::InvokeArgument;
using ::testing::_;
using ::testing::Gt;
using ::testing::Return;


class MockSignClass {
public:
	MOCK_METHOD2(run, bool(int, bool (*fp)(int)) );
};

bool f(int i) {return i==0;}

TEST(MockSignClass, runWithZero) {
	MockSignClass m;
	EXPECT_CALL( m,run(_,_) )
		.WillOnce( InvokeArgument<1>(0) );

	EXPECT_TRUE( m.run(1092, f) );
}

TEST(MockSignClass, runWithOne) {
	MockSignClass m;
	EXPECT_CALL( m,run(_,_) )
		.WillOnce( InvokeArgument<1>(1) );

	EXPECT_TRUE( m.run(1092, f) );
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