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

class FakeDummy {
public:
	bool happy() { return true; }
};


class MockSignClass {
public:
	MOCK_METHOD1(sign, int(int));
};


TEST(MockSignClass, sign) {
	MockSignClass m;
	ON_CALL(m,sign(_))
		.WillByDefault(Return(-1));
	ON_CALL(m,sign(0))
		.WillByDefault(Return(0));
	ON_CALL(m,sign(Gt(0)))
		.WillByDefault(Return(1));
	
	EXPECT_EQ(m.sign(5), 1);
	EXPECT_EQ(m.sign(0), 0);
	EXPECT_EQ(m.sign(-5), -1);
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