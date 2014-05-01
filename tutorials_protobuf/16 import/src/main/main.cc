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
    MiniData *miniDataToSerialize = new MiniData();
    miniDataToSerialize->set_i(188712);
    miniDataToSerialize->set_b(true);
    dataToSerialize.set_allocated_m(miniDataToSerialize);
    cout << "dataToSerialize.m().i() : " << dataToSerialize.m().i() << endl;
    cout << "dataToSerialize.m().b() : " << dataToSerialize.m().b() << endl;

    // miniDataToSerialize->set_i(712188);
    // miniDataToSerialize->set_b(false);
    // cout << "dataToSerialize.m().i() : " << dataToSerialize.m().i() << endl;
    // cout << "dataToSerialize.m().b() : " << dataToSerialize.m().b() << endl;
    

    string s;
    dataToSerialize.SerializeToString(&s);
    cout << "s :" << s << endl;

    Data dataAfterParsing;
    dataAfterParsing.ParseFromString(s);
    cout << "dataAfterParsing.has_m() : " << (dataAfterParsing.has_m() ? "True" : "False") << endl;
    if (dataAfterParsing.has_m())
    {
        cout << "dataAfterParsing.m().has_i() : " << (dataAfterParsing.m().has_i() ? "True" : "False") << endl;
        if (dataAfterParsing.m().has_i()) {
            cout << "dataToSerialize.m().i() : " << dataToSerialize.m().i() << endl;
        }
        cout << "dataAfterParsing.m().has_b() : " << (dataAfterParsing.m().has_b() ? "True" : "False") << endl;
        if (dataAfterParsing.m().has_b()) {
            cout << "dataToSerialize.m().b() : " << dataToSerialize.m().b() << endl;
        }
    }

    // // Another serialize and parsing with the same variables
    // cout << endl << endl;

    // miniDataToSerialize = new MiniData();
    // miniDataToSerialize->set_i(143222);
    // miniDataToSerialize->set_b(false);
    // dataToSerialize.set_allocated_m(miniDataToSerialize);
    // cout << "dataToSerialize.m().i() : " << dataToSerialize.m().i() << endl;
    // cout << "dataToSerialize.m().b() : " << dataToSerialize.m().b() << endl;

    // dataToSerialize.SerializeToString(&s);

    // dataAfterParsing.ParseFromString(s);
    // cout << "dataAfterParsing.has_m() : " << (dataAfterParsing.has_m() ? "True" : "False") << endl;
    // if (dataAfterParsing.has_m())
    // {
    //     cout << "dataAfterParsing.m().has_i() : " << (dataAfterParsing.m().has_i() ? "True" : "False") << endl;
    //     if (dataAfterParsing.m().has_i()) {
    //         cout << "dataToSerialize.m().i() : " << dataToSerialize.m().i() << endl;
    //     }
    //     cout << "dataAfterParsing.m().has_b() : " << (dataAfterParsing.m().has_b() ? "True" : "False") << endl;
    //     if (dataAfterParsing.m().has_b()) {
    //         cout << "dataToSerialize.m().b() : " << dataToSerialize.m().b() << endl;
    //     }
    // }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    cout << "end.." << endl;



    return 0;
}