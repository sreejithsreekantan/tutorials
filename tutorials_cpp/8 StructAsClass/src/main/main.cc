/*
Copyright 2014 Sreejith Sreekantan

Usage: 
    1. Normal execution
        build/darwin/exe 
Read:

Tips:
*/

#include <iostream>

using namespace std;

typedef struct A {
    A() {cout << "A()" << endl;}
} A;

int main(int argc, char *argv[]) {
    try {
        
        A a;

    }catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
