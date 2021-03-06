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

// Function to parse a file as a series of std::strings.
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

	// Cleanup
	inFile.close();

	// Return the result.
	return result;
}
StringList_t parseFile(std::string fileName)
{
	return parseFile(fileName.c_str());
}


// Function to parse a file that is a series of integer values.
IntList_t * parseIntFile(const char *fileName, const char *delimiter)
{
	// Open the file
	std::ifstream inFile;
	inFile.open(fileName, std::ios::in);
	
	// Break operation if there is a FIO err.
	if (!inFile.is_open())
		throw new std::exception("Error in function \"parseIntFile(const char *fileName, const char *delimiter)\" - File could not be oppened.");

	// Allocate memory
	std::string line;
	StringList_t lines;

	// Read the entire file.
	while(std::getline(inFile, line))
	{
		lines.push_back(line);
	}
	
	// For each line in the file.
	for (std::string line : lines)
	{
		// Split it into a list of strings.
	}

	// Cleanup
	inFile.close();

	// Return the result.
	return new IntList_t;
}

void appendToOutput(std::string writeMe, std::string fileName = "Output.txt")
{
	// Open the file (in append mode)
	std::ofstream outFile;
	outFile.open(fileName, std::ios::out || std::ios::app);

	// Break operation if there is an FIO err.
	if(!outFile.is_open())
		throw new std::exception("Error in function \"appendToOutput(std::string)\" - File could not be oppened.");

	// Write the line
	writeMe += '\n';
	outFile << writeMe;

	// Cleanup.
	outFile.close();
}

void appendStringListToOutput(StringList_t lines, std::string fileName = "Output.txt")
{
	// Open the file (in append mode)
	std::ofstream outFile;
	outFile.open(fileName, std::ios::out || std::ios::app);

	// Break operation if there is an FIO err.
	if(!outFile.is_open())
		throw new std::exception("Error in function \"appendToOutput(std::string)\" - File could not be oppened.");

	// Write the lines
	for (std::string line : lines)
	{
		line += '\n';
		outFile << line;
	}

	// Cleanup.
	outFile.close();
}


/**
*	Find a string in a string and replace it with another string
*/
void ReplaceString(std::string& str, const std::string& oldStr, const std::string& newStr)
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

void RemoveString(std::string& source, const std::string& chars) {
   std::string result="";
   for (unsigned int i=0; i<source.length(); i++) {
      bool foundany=false;
      for (unsigned int j=0; j<chars.length() && !foundany; j++) {
         foundany=(source[i]==chars[j]);
      }
      if (!foundany) {
         result+=source[i];
      }
   }

   source = result;
}

/**
*	Splits a string up into tokens with respect to the delimiter 
**/
std::vector<std::string> SplitString(const std::string &s, char delim) 
{
	StringList_t elems;
	std::stringstream strs(s);
	std::string item;

	while (std::getline(strs, item, delim)) {
		elems.push_back(item);
	}

	return elems;
}

/* 
*	Normalize angle between 0 and 2PI
*/
float NormalizeAngle(float angle)
{
	while(angle < 0)
	{
		angle += 2*MATH_PI;
	}
	return fmod(angle, 2*MATH_PI);
}

/*
*	Classic linear interpolation
*/
float Lerp(float from, float to, float amount)
{
	return ( from + amount * (to - from) );
}

/*
*	Determine if a number lies within a range
*/
bool IsBetween(float num, float a, float b)
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
bool CompareString(std::string& str1, std::string& str2)
{
	return str1.size() == str2.size() && str1 == str2;
}


// custom comparator
struct sort_pred 
{
	bool operator() (const std::pair<int,int> &left, const std::pair<int,int> &right)
	{
		return left.second < right.second;
	}
};

// Angle conversion
float rtodeg(float x)
{
	return x * 180/MATH_PI;
}
float degtor(float x)
{
	return x * MATH_PI/180;
}

// Remove all of one character from a string
void removeAllChar(std::string s, char c)
{
	// std::remove deletes all c
	// s.erase shortens the string to its new proper value
//	s.erase(std::remove(s.begin(), s.end(), c), s.end());
}
void removeAllString(std::string s, std::string c)
{
	// std::remove deletes all c
	// s.erase shortens the string to its new proper value
//	s.erase(std::remove(s.begin(), s.end(), c), s.end());
}

// Generic Conversion
float ConvertScales(float x_min, float x_max, float y_min, float y_max, float target)
{
		return ((target - x_min) / (x_max - x_min)) * (y_max - y_min);
}
