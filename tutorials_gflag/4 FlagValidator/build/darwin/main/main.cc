#include <iostream>
#include <gflags/gflags.h>

using namespace std;

DEFINE_int32(a, 0, "Integer value between -101 and 101 ");

static bool validate_string_a(const char* flagname, int val) {
	if (-5001<val && val<5001)		
	{
		return true;
	}
	return false;
}

static const bool port_dummy = google::RegisterFlagValidator(&FLAGS_a, &validate_string_a);

int main(int argc, char *argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, true);

	// cout << argv[0] << " --a=-1000" << endl \
	// 		<< argv[0] << " --a=-101" << endl \
	// 		<< argv[0] << " --a=-100" << endl \
	// 		<< argv[0] << " --a=-0" << endl \
	// 		<< argv[0] << " --a=100" << endl \
	// 		<< argv[0] << " --a=101" << endl \
	// 		<< argv[0] << " --a=1000" << endl ;

	cout << "FLAGS_a => " << FLAGS_a << endl; 
	
	return 0;
}