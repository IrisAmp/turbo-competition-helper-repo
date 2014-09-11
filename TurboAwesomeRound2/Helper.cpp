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

/*============================================================================
	FUNCTIONS
============================================================================*/
/*----------------------------------------------------------------------------
		FILE IO                                                             */
StringList_t parseFile(std::string fileName)
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
IntList_t parseIntFile(std::string fileName, std::string delimiter)
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
	IntList_t result;

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
	return result;
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
void appendStringListToOutput(StringList_t writeMe, std::string fileName = "Output.txt")
{
	// Open the file (in append mode)
	std::ofstream outFile;
	outFile.open(fileName, std::ios::out || std::ios::app);

	// Break operation if there is an FIO err.
	if(!outFile.is_open())
		throw new std::exception("Error in function \"appendToOutput(std::string)\" - File could not be oppened.");

	// Write the lines
	for (std::string line : writeMe)
	{
		line += '\n';
		outFile << line;
	}

	// Cleanup.
	outFile.close();
}

/*----------------------------------------------------------------------------
		STRING MANIPULATION                                                 */
std::string removeAllChar(std::string &inString, const char removeMe)
{
	inString.erase(
		std::remove(
			inString.begin(),
			inString.end(),
			removeMe),
		inString.end());
	return inString;
}
StringList_t splitString(const std::string inString, char delimiter)
{
	StringList_t elems;
	std::stringstream strs(inString);
	std::string item;

	while (std::getline(strs, item, delimiter))
	{
		elems.push_back(item);
	}

	return elems;
}
std::string toUpper(std::string &inString)
{
	for (std::string::iterator p = inString.begin(); inString.end() != p; ++p)
		*p = toupper(*p);
	return inString;
}
std::string removeString(std::string &inString, std::string removeMe)
{
	int pos = inString.find(removeMe);
	try{
		inString.replace(pos, removeMe.size(), "");}
	catch(...)
	{

	}
	return inString;
}

/*----------------------------------------------------------------------------
		MATH                                                                */
float normalizeAngle(float angle)
{
	while(angle < 0)
	{
		angle += 2*MATH_PI;
	}
	return fmod(angle, 2*MATH_PI);
}
float lerp(float from, float to, float amount)
{
	return ( from + amount * (to - from) );
}
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
float rtodeg(float radians)
{
	return radians * 180/MATH_PI;
}
float degtor(float degrees)
{
	return degrees * MATH_PI/180;
}
float convertScales(float x_min, float x_max, float y_min, float y_max, float target)
{
		return ((target - x_min) / (x_max - x_min)) * (y_max - y_min);
}