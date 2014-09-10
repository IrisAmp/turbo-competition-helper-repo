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
#include "Helper.h"

#define IFN "SampleInput.txt"
#define OFN "Output.txt"

/*============================================================================
	SHORTCUT NAMESPACE
============================================================================*/
#ifdef __TURBO_HELPER_H_DEFINED__
namespace help
{
	namespace c // Containers
	{
		typedef std::string					s;
		typedef StringList_t				sl;
		typedef IntList_t					il;
		typedef std::pair<int, int>			ii;
		typedef std::tuple<int, int, int>	iii;
		typedef std::pair<std::string,
			std::string>					ss;
		typedef std::tuple<std::string,
			std::string, std::string>		sss;
	}
	namespace f // File
	{
		auto r  = parseFile;
		auto ri = parseIntFile;
		auto w  = appendToOutput;
		auto wl = appendStringListToOutput;
	}
	namespace s // String
	{
		auto rm = removeAllChar;
		auto sp = splitString;
	}
	namespace m // Math
	{
		auto na = normalizeAngle;
		auto li = lerp;
		auto ib = IsBetween;
		auto rd = rtodeg;
		auto dr = degtor;
		auto cs = convertScales;
	}
}
#endif//__TURBO_HELPER_H_DEFINED__

int main(int argc, char* argv[])
{
	printf("Hello World!\n");

	using namespace help;

	c::sl x;

	try{x = f::r(IFN);}
	catch(...){
		printf("An error occured when oppening %s", IFN);
		return 1;
	}

	for(c::s y : x)
	{
		// Do something
	}

	return 0;
}
