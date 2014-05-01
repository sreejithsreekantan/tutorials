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
using ::testing::Return;


class MockSignClass {
public:
	MOCK_METHOD2(sum, int(int,int));
};

int mysum(int i, int j) { return i+j; }

TEST(MockSignClass, sign) {
	MockSignClass m;
	ON_CALL(m,sum(_,_))
		.WillByDefault(Invoke(mysum));
		// .WillOnce(Invoke(mysum)); // mysum will be invoked only on first call to sum(_,_)
	
	EXPECT_EQ(m.sum(5, 1), 6);
	EXPECT_EQ(m.sum(-1, 4), 3);
	EXPECT_EQ(m.sum(1092, 999), 2091);
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