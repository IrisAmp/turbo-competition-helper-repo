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

#endif//__COMP_HELPER_H_DEFINED__