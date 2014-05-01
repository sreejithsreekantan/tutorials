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
#include <fstream>

using namespace std;


int main(int argc, char const *argv[])
{
    const char* data_file = "data.dat";
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << "<data file>" << endl;
        cout << "<data file> parameter missing.. " << endl;
        cout << "Continuing the program with data file as \'data.dat\'" << endl;
    }

    cout << "started...." << endl;

    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    Data dataToSerialize;

    dataToSerialize.set_f(1023.414);
    fstream f(data_file, ios::out | ios::trunc | ios::binary); // file is created in the project-folder
    dataToSerialize.SerializeToOstream(&f);
    f.close();

    f.open(data_file, ios::in | ios::binary ); 
    Data dataAfterParsing;
    dataAfterParsing.ParseFromIstream(&f);
    cout << "dataAfterParsing.f() : " << dataAfterParsing.f() << endl;


    // // Comment below to see the result of 0 repeated fields
    // for (float i = 0.1; i < 10; i+=0.5)
    // {
    //     dataToSerialize.add_f(i);
    // }
    
    
    // cout << "dataToSerialize.f_size() : " << dataToSerialize.f_size() << endl;

    // fstream f(data_file, ios::out | ios::trunc | ios::binary); // file is created in the project-folder
    // dataToSerialize.SerializeToOstream(&f);
    // f.close();

    // f.open(data_file, ios::in | ios::binary ); 

    // Data dataAfterParsing;
    // dataAfterParsing.ParseFromIstream(&f);
    
    // int size = dataAfterParsing.f_size();

    // cout << "dataAfterParsing.f_size() : " << dataAfterParsing.f_size() << endl;

    // if (size > 0)
    // {
    //     cout << "dataToSerialize.f() : ";
    //     for (int i = 0; i < size; ++i)
    //     {
    //         cout << dataToSerialize.f(i) << ", ";
    //     }
    //     cout << endl;
    // }
    

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    cout << "end.." << endl;



    return 0;
}