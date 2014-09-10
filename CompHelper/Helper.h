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
#ifndef __COMP_HELPER_H_DEFINED__
#define __COMP_HELPER_H_DEFINED__

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
	TYPEDEFS, MACROS, AUTOS
============================================================================*/
#define MATH_PI  3.1415926535897932384626433832795028841971693993751058
#define MATH_E   2.7182818284590452353602874713526624977572470936999595
#define MATH_PHI 1.6180339887498948482045868343656381177203091798057628

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
	FILE IO
============================================================================*/
// Function to parse a file as a series of std::strings.
StringList_t parseFile(const char *fileName);
StringList_t parseFile(std::string fileName);

// Function to parse a file that is a series of integer values.
IntList_t * parseIntFile(const char *fileName, const char *delimiter);

// Functions to write to output file
void appendToOutput(std::string writeMe, std::string fileName);
void appendStringListToOutput(StringList_t lines, std::string fileName);

/*============================================================================
	STRING MANIPULATION
============================================================================*/
//	Find a string in a string and replace it with another string
void ReplaceString(std::string& str, const std::string& oldStr, const std::string& newStr);
auto StrReplace = ReplaceString; // Legacy. Remove when no longer used.
void RemoveString(std::string& source, const std::string& chars);

//	Splits a string up into tokens with respect to the delimiter 
std::vector<std::string> SplitString(const std::string &s, char delim);

//	String comparison function that checks both size + characters
bool CompareString(std::string& str1, std::string& str2);
auto StrCompare = CompareString;

// Remove all of one character from a string
void removeAllChar(std::string s, char c);
void removeAllString(std::string s, std::string c);

/*============================================================================
	MATH
============================================================================*/
//	Normalize angle between 0 and 2PI
float NormalizeAngle(float angle);

//	Classic linear interpolation
float Lerp(float from, float to, float amount);

//	Determine if a number lies within a range
bool IsBetween(float num, float a, float b);

// Angle conversion
float rtodeg(float x);
float degtor(float x);

// Generic Conversion
float ConvertScales(float, float, float, float, float);

/*============================================================================
	OTHER
============================================================================*/
// custom comparator
struct sort_pred 
{
	bool operator() (const std::pair<int,int> &left, const std::pair<int,int> &right)
	{
		return left.second < right.second;
	}
};


/*============================================================================
	SHORTCUT NAMESPACE
============================================================================*/
// KEEP THIS AT THE END OF THE FILE
namespace help
{
	namespace c // Containers
	{
		// String Vector
		typedef StringList_t sl;
		// Int Vector
		typedef IntList_t il;
		// String
		typedef std::string s;
	}
	namespace s // String
	{
		// Remove Substring from String
		auto rm = RemoveString;
		// Replace Substring with String
		auto rp = ReplaceString;
		// Split String by Delimiter
		auto sp = SplitString;
		// Compare two strings
		auto cm = StrCompare;
	}
	namespace f // File
	{
		// Read in file
		auto r  = static_cast<StringList_t(*)
			(const char*)>(parseFile);
		// Read in file
		auto r2 = static_cast<StringList_t(*)
			(std::string)>(parseFile);
		// Read in file of ints
		auto ri = parseIntFile;
		// Write to file
		auto w  = appendToOutput;
		// Write to file
		auto wl = appendStringListToOutput;
	}
	namespace m // Math
	{
		auto na = NormalizeAngle;
		auto li = Lerp;
		auto ib = IsBetween;
		auto rd = rtodeg;
		auto dr = degtor;
		auto cv = ConvertScales;
	}	
}
// DON'T PUT NEW CODE HERE.
#endif//__COMP_HELPER_H_DEFINED__