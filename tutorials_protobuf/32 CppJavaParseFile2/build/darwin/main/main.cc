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
#include <proto/EmployeeData.pb.h>
#include <fstream>

using namespace std;


int main(int argc, char const *argv[])
{
    const char* data_file = "employee_data.dat";
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

    Employee *empToSerialize = new Employee();

    empToSerialize->set_empid(183267);
    empToSerialize->set_empname("Sree Sreejith Sree");
    Employee::PhoneNumber *phoneNumber = empToSerialize->add_phonenumber();
    phoneNumber->set_type(Employee::MOBILE);
    phoneNumber->set_number("+91-926138172381");
    phoneNumber = empToSerialize->add_phonenumber();
    phoneNumber->set_type(Employee::HOME);
    phoneNumber->set_number("+91-493-172381");
    phoneNumber = empToSerialize->add_phonenumber();
    phoneNumber->set_type(Employee::OFFICE);
    phoneNumber->set_number("+91-417-3021381");

    fstream f(data_file, ios::out | ios::trunc | ios::binary); // file is created in the project-folder
    empToSerialize->SerializeToOstream(&f);
    f.close();

    f.open(data_file, ios::in | ios::binary ); 
    Employee* empAfterParsing = new Employee();
    empAfterParsing->ParseFromIstream(&f);
    cout << "Parsed data: " << endl;
    if (empAfterParsing->has_empid()) cout << "\t ID      : " << empAfterParsing->empid() << endl;
    if (empAfterParsing->has_empname()) cout << "\t Name    : " << empAfterParsing->empname() << endl;
    for (int i = 0; i < empAfterParsing->phonenumber_size(); ++i)
    {
        cout << "\t phone number : " << empAfterParsing->phonenumber(i).type() << "(type) " << empAfterParsing->phonenumber(i).number() << "(number) " << endl;
    }

    // // Comment below to see the result of 0 repeated fields
    // for (float i = 0.1; i < 10; i+=0.5)
    // {
    //     empToSerialize.add_f(i);
    // }
    
    
    // cout << "empToSerialize.f_size() : " << empToSerialize.f_size() << endl;

    // fstream f(data_file, ios::out | ios::trunc | ios::binary); // file is created in the project-folder
    // empToSerialize.SerializeToOstream(&f);
    // f.close();

    // f.open(data_file, ios::in | ios::binary ); 

    // Data empAfterParsing;
    // empAfterParsing.ParseFromIstream(&f);
    
    // int size = empAfterParsing.f_size();

    // cout << "empAfterParsing.f_size() : " << empAfterParsing.f_size() << endl;

    // if (size > 0)
    // {
    //     cout << "empToSerialize.f() : ";
    //     for (int i = 0; i < size; ++i)
    //     {
    //         cout << empToSerialize.f(i) << ", ";
    //     }
    //     cout << endl;
    // }
    

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    cout << "end.." << endl;



    return 0;
}