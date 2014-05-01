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

class Dummy {
public:
	virtual bool happy() {
		return true;
	}
	virtual bool sad() {
		return false;
	}
};

class MockDummy : public Dummy {
public:
	MOCK_METHOD0(happy, bool());
	MOCK_METHOD0(sad, bool());
};

TEST(DummyTest, happy) {
	MockDummy m;
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