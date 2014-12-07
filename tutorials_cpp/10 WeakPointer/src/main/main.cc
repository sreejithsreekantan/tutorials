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


int main(int argc, char *argv[]) {
    try {
        
		int i;

		cout << boolalpha;

		// %%%%%%%%%%%%%%%%%%%%%%%% pointer to a class %%%%%%%%%%%%%%%%%%%%%%%%
		
		std::shared_ptr<int>  a1;
		cout << "std::shared_ptr<A>  a1;" << endl;
		a1.reset(new int);
		cout << "typeid(a3).name() : " << typeid(a3).name() << endl;
		cout << "a1.reset(new int());" << endl;
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << endl;
		
		cout << "auto a2 = a1;" << endl;
		weak_ptr<int> a2 = a1;
		cout << "typeid(a2).name() : " << typeid(a2).name() << endl; 
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << "a2.unique() : " << a2.unique() << endl;
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a2.use_count() : " << a2.use_count() << endl;
		cout << "a2.use_count() : " << a2.use_count() << " // didnt increase the count! "<< endl;
		cout << "a2.expired() : " << a2.expired() << endl;
		cout << endl;

		cout << "auto a3 = a2.lock();" << endl;
		auto a3 = a2.lock();
		cout << "typeid(a3).name() : " << typeid(a3).name() << endl;
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << "a2.unique() : " << a2.unique() << endl;
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a2.use_count() : " << a2.use_count() << endl;
		cout << "a3.use_count() : " << a3.use_count() << endl;
		cout << "a3.expired() : " << a3.expired() << endl;
		cout << endl;

		cout << "a3 = 0;" << endl;
		a2 = 0;
		cout << "typeid(a2).name() : " << typeid(a2).name() << endl; 
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << "a3.unique() : " << a3.unique() << endl;
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a2.expired() : " << a2.expired() << endl;
		cout << "a3.use_count() : " << a3.use_count() << endl;
		cout << endl;

		cout << "a1.reset();" << endl;
		a1.reset();
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << "a2.expired() : " << a3.expired() << endl;
		cout << endl;
		
		// make_shared<>()
		auto p1 = std::make_shared<int>(191);


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
