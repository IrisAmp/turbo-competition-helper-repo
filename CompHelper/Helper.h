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

#define MATH_PI  3.1415926535897932384626433832795028841971693993751058
#define MATH_E   2.7182818284590452353602874713526624977572470936999595
#define MATH_PHI 1.6180339887498948482045868343656381177203091798057628

typedef std::vector<std::string> StringList_t;
typedef std::vector<int> IntList_t;


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
IntList_t parseIntFile(const char *fileName, const char *delimiter)
{
	// Open the file
	std::ifstream inFile;
	inFile.open(filename, std::ios::in);
	
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
	
	// TODO: IMPLEMENT THE REST OF THE PARSER

	// Cleanup
	inFile.close();

	// Return the result.
	return new IntList_t;
}


void appendToOutput(std::string writeMe)
{
	// Open the file (in append mode)
	std::ofstream outFile;
	outFile.open("Output.txt", std::ios::out || std::ios::app);

	// Break operation if there is an FIO err.
	if(!outFile.is_open())
		throw new std::exception("Error in function \"appendToOutput(std::string)\" - File could not be oppened.");

	// Write the line
	outFile << writeMe;

	// Cleanup.
	outFile.close();
}



#endif//__COMP_HELPER_H_DEFINED__
