/*
Copyright 2014 Sreejith Sreekantan

Usage: 
    1. Normal execution
        build/darwin/exe 
Read:
	http://www.cplusplus.com/reference/memory/weak_ptr/

Tips:
*/

#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;

class A { 
public:
	A(){ cout << "A()\n";} 
	~A(){ cout << "~A()\n";}
};

int main(int argc, char *argv[]) {
    try {
        
		int i;

		cout << boolalpha;

		// %%%%%%%%%%%%%%%%%%%%%%%% pointer to a class %%%%%%%%%%%%%%%%%%%%%%%%
		
		cout << "std::unique_ptr<A>  a1;" << endl;
		std::unique_ptr<A>  a1;
		cout << "typeid(a1).name() : " << typeid(a1).name() << endl;
		cout << "a1.reset(new A());" << endl;
		a1.reset(new A());
		if (a1)	{ cout << "a1 is valid" << endl;} else { cout << "a1 is not valid" << endl;}
		cout << endl;
		
		cout << "auto a2 = a1.get();" << endl;
		auto a2 = a1.get();
		cout << "typeid(a2).name() : " << typeid(a2).name() << endl;
		if (a1)	{ cout << "a1 is valid" << endl;} else { cout << "a1 is not valid" << endl;}
		cout << endl;
		
		cout << "auto a3 = a1.release();" << endl;
		auto a3 = a1.release();
		cout << "typeid(a3).name() : " << typeid(a3).name() << endl;
		if (a1)	{ cout << "a1 is valid" << endl;} else { cout << "a1 is not valid" << endl;}
		cout << endl;

		cout << "a1.reset(a3);" << endl;
		a1.reset(a3);
		cout << endl;

		cout << "a1.reset();" << endl;
		a1.reset();
		cout << endl;

		cout << "a1.reset(new A());" << endl;
		a1.reset(new A());
		if (a1)	{ cout << "a1 is valid" << endl;} else { cout << "a1 is not valid" << endl;}
		cout << endl;
		
		cout << "auto a3 = a1.release();" << endl;
		a3 = a1.release(); // NOTE: need to explicitly delete the memory calling "delete a3;"
		cout << "typeid(a3).name() : " << typeid(a3).name() << endl;
		if (a1)	{ cout << "a1 is valid" << endl;} else { cout << "a1 is not valid" << endl;}
		cout << "NOTE: need to explicitly delete the memory" << endl;
		cout << endl;

		cout << "delete a3;" << endl;
		delete a3;


    }catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}


		// std::shared_ptr<int> foo = std::make_shared<int> (10);
		// same as:
		// std::shared_ptr<int> foo2 (new int(10));

		// auto bar = std::make_shared<int> (20);

		// auto baz = std::make_shared<std::pair<int,int>> (30,40);

		// std::cout << "*foo: " << *foo << '\n';
	 //  	std::cout << "*bar: " << *bar << '\n';
	 //  	std::cout << "*baz: " << baz->first << ' ' << baz->second << '\n';
