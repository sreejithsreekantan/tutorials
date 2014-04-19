#include <iostream>

using namespace std;

DECLARE_string(string_a); // ******compulsory**********

void print_flag_a() {
	cout << "FLAGS_string_a => " << FLAGS_string_a << endl;
}