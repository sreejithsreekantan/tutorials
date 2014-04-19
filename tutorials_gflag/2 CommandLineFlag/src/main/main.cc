#include <iostream>
#include <gflags/gflags.h>

using namespace std;

DEFINE_bool(bool_a, true, "a boolean variable");
DEFINE_int32(int32_a, -32,"a 32 bit integer");
DEFINE_int64(int64_a, -64,"a 64 bit integer");
DEFINE_uint64(uint64_a, 64,"a 64 bit unsigned integer");
DEFINE_double(double_a, 3.414,"a double value");
DEFINE_string(string_a, "sun rises in east..", "testing string");



int main(int argc, char *argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, true);

	cout << endl << "Example FLAGS: \n" << argv[0] << " " << "--nobool_a --int32_a=47 -int64_a=10239 --uint64_a 123021310 --double_a=12312.13129 --string_a=\"Sreejith is running this program\"" << endl << endl ;

	cout << "FLAGS_bool_a => " << FLAGS_bool_a << endl;
	cout << "FLAGS_int32_a => " << FLAGS_int32_a << endl;
	cout << "FLAGS_int64_a => " << FLAGS_int64_a << endl;
	cout << "FLAGS_uint64_a => " << FLAGS_uint64_a << endl;
	cout << "FLAGS_double_a => " << FLAGS_double_a << endl;
	cout << "FLAGS_string_a => " << FLAGS_string_a << endl;
	return 0;
}