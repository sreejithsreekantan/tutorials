/*
Copyright 2014 Sreejith Sreekantan

Usage: 
    1. Normal execution
        build/darwin/exe 
Read:
	http://www.cplusplus.com/reference/memory/shared_ptr/

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

/*
	Destructor of class A created and assigned to variable a1 in fn() is never
	called. It's programmer's responsibility to delete any memory allocated in 
	heap. Using smart pointers, the release of memory is automated at the time 
	of destruction of smart pointer.
*/
void fn() {
	cout << "inside fn()" << endl;
	
	cout << "std::shared_ptr<A> a(new A());" << endl;
	std::shared_ptr<A> a(new A());

	cout << "A* a1 = new A(); [NOTE: memory leak!!!!]" << endl;
	A* a1 = new A();

	cout << "exiting fn()" << endl;
}

int main(int argc, char *argv[]) {
    try {
        
		int i;

		cout << boolalpha;

		// %%%%%%%%%%%%%%%%%%%%%%%% pointer to a class %%%%%%%%%%%%%%%%%%%%%%%%
		fn();
		
		std::shared_ptr<A>  a1;
		cout << "std::shared_ptr<A>  a1;" << endl;
		a1.reset(new A());
		cout << "a1.reset(new A());" << endl;
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << endl;
		
		cout << "auto a2 = a1;" << endl;
		auto a2 = a1;
		cout << "typeid(a2).name() : " << typeid(a2).name() << endl; 
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << "a2.unique() : " << a2.unique() << endl;
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a2.use_count() : " << a2.use_count() << endl;
		cout << endl;

		cout << "auto a3 = a2.get();" << endl;
		auto a3 = a2.get();
		cout << "typeid(a3).name() : " << typeid(a3).name() << endl;
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << "a2.unique() : " << a2.unique() << endl;
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a2.use_count() : " << a2.use_count() << endl;
		cout << endl;

		cout << "a2 = 0;" << endl;
		a2 = 0;
		cout << "typeid(a2).name() : " << typeid(a2).name() << endl; 
		cout << "a1.unique() : " << a1.unique() << endl;
		cout << "a2.unique() : " << a2.unique() << endl;
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a2.use_count() : " << a2.use_count() << endl;
		cout << endl;

		cout << "a1.reset();" << endl;
		a1.reset();
		cout << "a1.use_count() : " << a1.use_count() << endl;
		cout << "a1.unique() : " << a1.unique() << endl;
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
