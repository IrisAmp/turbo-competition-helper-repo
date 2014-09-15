/*
    turbo-competition-helper
    Copyright (C) 2014  Brandon Yue & Andrew Coulthard

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "HelperNameHack.h"

#define IFN "SampleInput.txt"
#define OFN "Output.txt"

// Problem Solution Files:
#include "TextQueryProblem.h"

int main(int argc, char* argv[])
{
	using namespace help;

	c::sl x;

	try{x = f::r(IFN);}
	catch(...){
		printf("An error occured when oppening %s", IFN);
//		return 1;
	}

	for(c::s y : x)
	{
		// Do something
	}
	
	SolveQueryProblem("SampleInput.txt", "fileout.txt");

	return 0;
}
