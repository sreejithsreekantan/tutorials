/*
Author: Sreejith Sreekantan

Usage: 
	1. Normal execution
		build/darwin/exe 

*/
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

// class to test
class DummyClass {
private:
	int i_;
public:
	DummyClass(int i=191):i_(i) {}
	int i() {return this->i_;}
	bool add(int temp) { if(temp<0) { return false; } else { i_+=temp; return true; } }
};


// Fixture class for DummyClass
class DummyClassTest : public ::testing::Test {
public:
	DummyClassTest() { 
		cout << "DummyClassTest()" << endl;
	}

	~DummyClassTest() { 
		cout << "~DummyClassTest()" << endl;
	}

	virtual void SetUp() { 
		cout << "Setup()" << endl;
	}

	virtual void TearDown() { 
		cout << "TearDown()" << endl;
	}
protected:
	DummyClass d;
};

class DummyClassConstructorTest : public ::testing::Test {
public:
	DummyClassConstructorTest():d(DummyClass(2000)) { 
		cout << "DummyClassTest()" << endl;
	}

	~DummyClassConstructorTest() { 
		cout << "~DummyClassTest()" << endl;
	}

	virtual void SetUp() { 
		cout << "Setup()" << endl;
	}

	virtual void TearDown() { 
		cout << "TearDown()" << endl;
	}
protected:
	DummyClass d;
};

TEST_F(DummyClassTest, ConstructorTest) {
	EXPECT_EQ(191, d.i());
}

TEST_F(DummyClassConstructorTest, ConstructorTest) {
	EXPECT_EQ(2000, d.i());
}

TEST_F(DummyClassTest, AddTen ){
	EXPECT_TRUE(d.add(10));
}

TEST_F(DummyClassTest, ValueOfIAfterAddTen ){
	d.add(10);
	EXPECT_EQ(201, d.i());
}

TEST_F(DummyClassTest, AddMinusOne ){
	EXPECT_FALSE(d.add(-1));
}

TEST_F(DummyClassTest, ValueOfIAfterAddMinusOne ){
	d.add(-1);
	EXPECT_EQ(191, d.i());
}



int main(int argc, char *argv[])
{

	cout << "started...." << endl;

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}