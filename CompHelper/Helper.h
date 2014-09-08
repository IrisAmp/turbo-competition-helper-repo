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

#define PI 3.141592653589793238462643383279

typedef std::vector<std::string> StringList_t;

StringList_t parseFile(const char *fileName)
{
	// Open the file.
	std::ifstream inFile;
	inFile.open(fileName, std::ios::in);

	// Break operation if there is a FIO err.
	if(!inFile.is_open())
		throw new std::exception("Error in function \"parseFile(const char *fileName)\" - File could not be oppened.");

	// Create a new string.
	std::string line;
	StringList_t result;

	// Read the entire file into a string vector
	while(std::getline(inFile, line))
	{
		result.push_back(line);
	}

	// Return the result.
	return result;
}

/**
*	Find a string in a string and replace it with another string
*/
static void StrReplace(std::string& str, const std::string& oldStr, const std::string& newStr)
{
	if (str.size() == 0 || oldStr.size() == 0)
	{
		return;
	}
	size_t pos = 0;
	while((pos = str.find(oldStr, pos)) != std::string::npos)
	{
		str.replace(pos, oldStr.length(), newStr);
		pos += newStr.length();
	}
}

/**
*	Splits a string up into tokens with respect to the delimiter 
**/
static std::vector<std::string> SplitString(const std::string &s, char delim) 
{
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;

	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}

	return elems;
}

/* 
*	Normalize angle between 0 and 2PI
*/
static float NormalizeAngle(float angle)
{
	angle = fmod(angle, 2*PI);
}

/*
*	Classic linear interpolation
*/
static float Lerp(float from, float to, float amount)
{
	return ( from + amount * (to - from) );
}

/*
*	Determine if a number lies within a range
*/
static bool IsBetween(float num, float a, float b)
{
	if( a < num && num < b )
	{
		return true;
	} else if ( b < num && num < a )
	{
		return true;
	} else
	{
		return false;
	}
}

/*
*	String comparison function that checks both size + characters
*	does == do this anyway? we may never know
*/
static bool StrCompare(std::string& str1, std::string& str2)
{
	return str1.size() == str2.size() && str1 == str2;
}

#endif//__COMP_HELPER_H_DEFINED__