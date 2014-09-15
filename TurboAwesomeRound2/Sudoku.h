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
#ifndef __TURBO_SUDOKU_SOLVER_H_DEFINED__
#define __TURBO_SUDOKU_SOLVER_H_DEFINED__


#include "Helper.h"


class SudokuPuzzle
{
public:
	SudokuPuzzle(std::string fileName, char unknownToken = 'x')
	{
		StringList_t raw;

		try{raw = parseFile(fileName);}
			catch(...){printf("Couldn't open and parse %s\n", fileName);
				throw;}
		
		try{this -> convertToInts(raw, unknownToken);}
			catch(...){printf("Couldn't convert string values to ints (bad token for unknown).\n");
				throw;}
	}
	SudokuPuzzle(StringList_t raw, char unknownToken)
	{
		try{this -> convertToInts(raw, unknownToken);}
			catch(...){printf("Couldn't convert string values to ints (bad token for unknown).\n");
				throw;}
	}

	bool solve();
	void print();
	
	~SudokuPuzzle();

private:
	static const int ht = 9;
	static const int wd = 9;

	SudokuPuzzle();
	int Puzzle[ht][wd];
	int SafePuzzle[ht][wd];

	void convertToInts(StringList_t, char);

	IntList_t findValidSolutions(unsigned x, unsigned y);

	bool guess(unsigned x, unsigned y);
};


#endif//__TURBO_SUDOKU_SOLVER_H_DEFINED__