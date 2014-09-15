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
#include "Sudoku.h"

int main(int argc, char* argv[])
{
	using namespace help;

	SudokuPuzzle puz(IFN, 'x');

	puz.print();
	puz.solve();
	puz.print();

	return 0;
}
