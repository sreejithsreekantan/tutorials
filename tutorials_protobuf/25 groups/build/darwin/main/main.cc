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
    Data::MiniData *miniDataToSerialize = new Data::MiniData();
    miniDataToSerialize->set_i(1883712);
    miniDataToSerialize->set_b(true);
    dataToSerialize.set_allocated_minidata(miniDataToSerialize);
    cout << "dataToSerialize.minidata().i() : " << dataToSerialize.minidata().i() << endl;
    cout << "dataToSerialize.minidata().b() : " << dataToSerialize.minidata().b() << endl;

    // miniDataToSerialize->set_i(712188);
    // miniDataToSerialize->set_b(false);
    // cout << "dataToSerialize.minidata().i() : " << dataToSerialize.minidata().i() << endl;
    // cout << "dataToSerialize.minidata().b() : " << dataToSerialize.minidata().b() << endl;
    

    string s;
    dataToSerialize.SerializeToString(&s);
    cout << "s :" << s << endl;

    Data dataAfterParsing;
    dataAfterParsing.ParseFromString(s);
    cout << "dataAfterParsing.has_minidata() : " << (dataAfterParsing.has_minidata() ? "True" : "False") << endl;
    if (dataAfterParsing.has_minidata())
    {
        cout << "dataAfterParsing.minidata().has_i() : " << (dataAfterParsing.minidata().has_i() ? "True" : "False") << endl;
        if (dataAfterParsing.minidata().has_i()) {
            cout << "dataToSerialize.minidata().i() : " << dataToSerialize.minidata().i() << endl;
        }
        cout << "dataAfterParsing.minidata().has_b() : " << (dataAfterParsing.minidata().has_b() ? "True" : "False") << endl;
        if (dataAfterParsing.minidata().has_b()) {
            cout << "dataToSerialize.minidata().b() : " << dataToSerialize.minidata().b() << endl;
        }
    }

    // // Another serialize and parsing with the same variables
    // cout << endl << endl;

    // miniDataToSerialize = new MiniData();
    // miniDataToSerialize->set_i(143222);
    // miniDataToSerialize->set_b(false);
    // dataToSerialize.set_allocated_minidata(miniDataToSerialize);
    // cout << "dataToSerialize.minidata().i() : " << dataToSerialize.minidata().i() << endl;
    // cout << "dataToSerialize.minidata().b() : " << dataToSerialize.minidata().b() << endl;

    // dataToSerialize.SerializeToString(&s);

    // dataAfterParsing.ParseFromString(s);
    // cout << "dataAfterParsing.has_minidata() : " << (dataAfterParsing.has_minidata() ? "True" : "False") << endl;
    // if (dataAfterParsing.has_minidata())
    // {
    //     cout << "dataAfterParsing.minidata().has_i() : " << (dataAfterParsing.minidata().has_i() ? "True" : "False") << endl;
    //     if (dataAfterParsing.minidata().has_i()) {
    //         cout << "dataToSerialize.minidata().i() : " << dataToSerialize.minidata().i() << endl;
    //     }
    //     cout << "dataAfterParsing.minidata().has_b() : " << (dataAfterParsing.minidata().has_b() ? "True" : "False") << endl;
    //     if (dataAfterParsing.minidata().has_b()) {
    //         cout << "dataToSerialize.minidata().b() : " << dataToSerialize.minidata().b() << endl;
    //     }
    // }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    cout << "end.." << endl;



    return 0;
}