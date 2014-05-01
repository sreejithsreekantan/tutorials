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
    dataToSerialize.set_i(-4567891972835647);
    cout << "dataToSerialize.i() : " << dataToSerialize.i() << endl;

    string s;
    dataToSerialize.SerializeToString(&s);

    Data dataAfterParsing;
    dataAfterParsing.ParseFromString(s);
    cout << "dataAfterParsing.has_i() : " << (dataAfterParsing.has_i() ? "True" : "False") << endl;
    if (dataAfterParsing.has_i())
    {
        cout << "dataAfterParsing.i() : " << dataAfterParsing.i() << endl;
    }

    cout << "end.." << endl;



    return 0;
}