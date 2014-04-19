#include <iostream>

#define STRIP_FLAG_HELP 1    // this must go before the #include! !!!!!!!!!!!!!!

#include <gflags/gflags.h>

using namespace std;

DEFINE_int32(a, 0, "Integer value between -101 and 101 ");


int main(int argc, char *argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, true);

	cout << "adfasfFLAGS_a => " << FLAGS_a << endl; 


	return 0;
}