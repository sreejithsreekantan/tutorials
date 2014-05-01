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
using ::testing::Return;

class FakeDummy {
public:
	bool happy() { return true; }
};


class MockDummy{
public:
	MOCK_METHOD0(happy, bool());
	MOCK_METHOD0(sad, bool());
};

TEST(DummyTest, expectHappy) {
	MockDummy m;
	EXPECT_CALL(m,happy())
		.WillRepeatedly(Return(true));
	m.happy();
}

TEST(DummyTest, happy) {
	MockDummy m;
	ON_CALL(m,happy())
		.WillByDefault(Return(true));
	EXPECT_TRUE(m.happy());
}


TEST(DummyTest, sad) {
	MockDummy m;
	EXPECT_FALSE(m.sad());
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