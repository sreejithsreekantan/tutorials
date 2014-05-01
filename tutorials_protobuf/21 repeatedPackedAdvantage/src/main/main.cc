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

    UnpackedData unpackedDataToSerialize;
    PackedData packedDataToSerialize;

    // Comment below and run to see the result of 0 repeated fields
    for (float i = 0.1; i < 10; i+=0.5)
    {
        unpackedDataToSerialize.add_f(i);
        packedDataToSerialize.add_f(i);
    }
    
    
    cout << "unpackedDataToSerialize.f_size() : " << unpackedDataToSerialize.f_size() << endl;
    cout << "packedDataToSerialize.f_size() : " << packedDataToSerialize.f_size() << endl;

    string s;
    
    // Un-packed Data
    unpackedDataToSerialize.SerializeToString(&s);
    cout << "size of unpacked data when after serialization:" << s.size() << endl;

    // Packed Data
    packedDataToSerialize.SerializeToString(&s);
    cout << "size of packed data when after serialization:" << s.size() << endl;

    

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    cout << "end.." << endl;



    return 0;
}