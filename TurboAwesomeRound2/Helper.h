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
#ifndef __TURBO_HELPER_H_DEFINED__
#define __TURBO_HELPER_H_DEFINED__

/*============================================================================
	INCLUDES
============================================================================*/
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include <sstream>
#include <math.h>
#include <climits>
#include <map>
#include <algorithm>

/*============================================================================
	DEFINE, TYPEDEF, MACROS, AUTOS
============================================================================*/
#define MATH_PI  3.1415926535897932384626433832795028841971693993751058f
#define MATH_E   2.7182818284590452353602874713526624977572470936999595f
#define MATH_PHI 1.6180339887498948482045868343656381177203091798057628f

typedef std::vector<std::string> StringList_t;
typedef std::vector<int> IntList_t;

// every element in a collection
#define for_e(elem,collection) for(auto &elem : collection)
// debug output that lists the variable name
#define debug(vari) std::cerr<<#vari<<"="<<(vari)<<std::endl;
// for map, pair
#define ii std::pair<int,int>
#define iii std::tuple<int,int,int>
#define ss std::pair<std::string,std::string>
#define sss std::tuple<std::string,std::string,std::string>
#define mp std::make_pair
#define mt std::make_tuple
#define fi first
#define se second
// for vectors :)
#define vec std::vector
#define pb push_back
// this asshole thing for reasons
#define cs c_str()

// test a bit of a number, return true if set
#define test_bit(num, bit) ((num & 1 << bit) != 0)

/*============================================================================
	FUNCTIONS
============================================================================*/
/*----------------------------------------------------------------------------
		FILE IO                                                             */
StringList_t parseFile(std::string fileName);
IntList_t parseIntFile(std::string fileName, std::string delimiter);

void appendToOutput(std::string writeMe, std::string fileName);
void appendStringListToOutput(StringList_t writeMe, std::string fileName);

/*----------------------------------------------------------------------------
		STRING MANIPULATION                                                 */
void removeAllChar(std::string inString, char removeMe);
StringList_t splitString(const std::string inString, char delimiter);

/*----------------------------------------------------------------------------
		MATH                                                                */
float normalizeAngle(float angle);
float lerp(float, float, float);
bool IsBetween(float num, float a, float b);
float rtodeg(float radians);
float deftor(float degrees);
float convertScales(float, float, float, float, float);

/*============================================================================
	SHORTCUT NAMESPACE
============================================================================*/
namespace help
{
	namespace c // Containers
	{

	}
	namespace s // String
	{

	}
	namespace f // File
	{

	}
	namespace m // Math
	{

	}
}

#endif//__TURBO_HELPER_H_DEFINED__