#include <iostream>
#include <gflags/gflags.h>
#include "dummy.h"

using namespace std;

DEFINE_string(string_a, "sun rises in east..", "testing string");

int main(int argc, char *argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, true);
	
	print_flag_a();
	return 0;
}