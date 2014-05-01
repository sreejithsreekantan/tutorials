/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

http://code.google.com/p/googlemock/wiki/CookBook#Invoking_an_Argument_of_the_Mock_Function

*/
#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;

using ::testing::InvokeWithoutArgs;
using ::testing::_;
using ::testing::Gt;
using ::testing::Return;


class MockSignClass {
public:
	MOCK_METHOD2(sum, int(int,int));
};

int mysum() { return 2091; }

TEST(MockSignClass, sign) {
	MockSignClass m;
	EXPECT_CALL(m,sum(_,_))
		.WillOnce(InvokeWithoutArgs(mysum));
		
		// mysum will be invoked only on first call to sum(_,_)
		// EXPECT_CALL(m,sum(_,_)).WillOnce(Invoke(mysum)); 
		
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