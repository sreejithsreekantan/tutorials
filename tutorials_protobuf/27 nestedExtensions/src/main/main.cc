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
    dataToSerialize.set_foo(1234321);
    dataToSerialize.SetExtension(Sree::bar, 1020201);
    cout << "dataToSerialize.foo() : " << dataToSerialize.foo() << endl;

    string s;
    dataToSerialize.SerializeToString(&s);

    Data dataAfterParsing;
    dataAfterParsing.ParseFromString(s);
    cout << "dataAfterParsing.has_foo() : " << (dataAfterParsing.has_foo() ? "True" : "False") << endl;
    cout << "dataAfterParsing.HasExtension(bar) : " << (dataAfterParsing.HasExtension(Sree::bar) ? "True" : "False") << endl;
    
    cout << "dataAfterParsing.foo() : " << dataAfterParsing.foo() << endl;
    cout << "dataAfterParsing.GetExtension(bar) : " << dataAfterParsing.GetExtension(Sree::bar) << endl;
    

    cout << "end.." << endl;



    return 0;
}