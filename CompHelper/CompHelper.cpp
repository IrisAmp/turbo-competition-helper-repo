// CompHelper.cpp : Defines the entry point for the console application.
//
#include "Helper.h"

#define INPUT_FILENAME "foo.txt"
#define OUTPUT_FILENAME "Output.txt"

int main(int argc, char* argv[])
{
	using namespace help;

	c::sl lines = f::r(INPUT_FILENAME),
	      result;

	for(c::s line : lines)
	{
		// Do something to each line
	}

	f::wl(result, OUTPUT_FILENAME);

	return 0;
}

