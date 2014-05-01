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

    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    Data dataToSerialize;
    dataToSerialize.set_s(Data::EMPLOYED);
    cout << "dataToSerialize.s() : " << dataToSerialize.s() << endl;

    string s;
    dataToSerialize.SerializeToString(&s);
    // cout << "s :" << s << endl;

    Data dataAfterParsing;
    dataAfterParsing.ParseFromString(s);
    cout << "dataAfterParsing.has_s() : " << (dataAfterParsing.has_s() ? "True" : "False") << endl;
    if (dataAfterParsing.has_s())
    {
        cout << "dataToSerialize.s() : " << dataToSerialize.s() << endl;
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    cout << "end.." << endl;



    return 0;
}