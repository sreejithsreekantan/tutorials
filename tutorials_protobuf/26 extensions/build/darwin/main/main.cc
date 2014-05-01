/*
Author: Sreejith Sreekantan

Usage:
    1. Normal execution
        build/darwin/exe

Tips:
    Execute following commands in terminal to view the difference:
    > make


*/
#include <iostream>
#include <string>
#include <bitset>
#include <proto/data.pb.h>

using namespace std;


int main(int argc, char const *argv[])
{

    cout << "started...." << endl;

    Data dataToSerialize;
    dataToSerialize.set_foo(1972835647);
    dataToSerialize.SetExtension(bar, 10001);
    cout << "dataToSerialize.foo() : " << dataToSerialize.foo() << endl;

    string s;
    dataToSerialize.SerializeToString(&s);

    Data dataAfterParsing;
    dataAfterParsing.ParseFromString(s);
    cout << "dataAfterParsing.has_foo() : " << (dataAfterParsing.has_foo() ? "True" : "False") << endl;
    cout << "dataAfterParsing.HasExtension(bar) : " << (dataAfterParsing.HasExtension(bar) ? "True" : "False") << endl;
    
    cout << "dataAfterParsing.foo() : " << dataAfterParsing.foo() << endl;
    cout << "dataAfterParsing.GetExtension(bar) : " << dataAfterParsing.GetExtension(bar) << endl;
    

    cout << "end.." << endl;



    return 0;
}