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
#include "Sudoku.h"
#include "Helper.h"
SudokuPuzzle::SudokuPuzzle(){}
SudokuPuzzle::~SudokuPuzzle(){}

void SudokuPuzzle::convertToInts(StringList_t lines, char token)
{
	std::string s = ""; s += token;
	unsigned i, j;

	i = 0;
	for(std::string line : lines)
	{
		StringList_t nums = splitString(line, ' ');

		j = 0;
		for(std::string num : nums)
		{
			if (num == s)
			{
				this -> Puzzle[i][j] = 0;
				this -> SafePuzzle[i][j] = 0;
			}
			else
			{
				this -> Puzzle[i][j] = atoi(num.c_str());
				this -> SafePuzzle[i][j] = atoi(num.c_str());
			}
			j++;
		}
		i++;
	}
}
bool SudokuPuzzle::solve()
{
	unsigned i = 0, j = 0;
	bool mod = false;

	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (Puzzle[i][j] == 0)
			{
				TurboDebugHelper::getInstance()
					.writeToBoth(
						formatString("Finding solutions for %i, %i", i, j)
							.c_str());

				IntList_t solns = findValidSolutions(i, j);

				#ifdef DEBUG
				printf("    Possible solutions are ");
				for (int x : solns)
				{
					printf("%i ", x);
				}
				printf("\n");
				#endif

				if (solns.size() < 1)
				{
					TurboDebugHelper::getInstance()
						.writeToBoth(
							"The puzzle is unsolvable!"
								);
					return false;
				}
				if (solns.size() < 2)
				{
					Puzzle[i][j] = solns[0];
					mod = true;
					TurboDebugHelper::getInstance()
						.writeToBoth(
							formatString("    Wrote solution: %i", solns[0])
								.c_str());
				}
			}
			j++;
		}
		i++;
	}

	if (mod) return solve();
	else     return guess(i, j);

	return false;
}
IntList_t SudokuPuzzle::findValidSolutions(unsigned x, unsigned y)
{
	unsigned i;
	uint16_t invalid = 0xfe00;

	// Rows
	for (i = 0; i < 9; i++)
	{
		if (i == y) continue;
		if (this -> Puzzle[x][i] == 0) continue;
		invalid = invalid | (0x1 << (Puzzle[x][i] - 1));
	}

	// Cols
	for (i = 0; i < 9; i++)
	{
		if (i == x) continue;
		if (this -> Puzzle[i][y] == 0) continue;
		invalid = invalid | (0x1 << (Puzzle[i][y] - 1));
	}

	// Square
	unsigned xi = (x / 3)*3, yi = (y / 3)*3;
	for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int foo = this -> Puzzle[xi + i][yi + j]; 
			if (foo == 0) continue;
			invalid = invalid | (0x1 << (Puzzle[xi + i][yi + j] - 1));
		}
	}

	invalid = ~invalid;

	i = 1;
	IntList_t result;
	while (invalid)
	{
		if (invalid & 0x1) result.push_back(i);
		i++; invalid = invalid >> 1;
	}
	return result;
}
bool SudokuPuzzle::guess(unsigned x, unsigned y)
{
	#ifdef DEBUG
	printf("\nMaking a guess in space (%i, %i)\n", x, y);
	#endif

	std::copy(&Puzzle[0][0], &Puzzle[0][0] + (9*9), &SafePuzzle[0][0]);
	for (int i: findValidSolutions(x, y))
	{	
		#ifdef DEBUG
		printf("    Trying value: %i\n", i);
		#endif
		// Write the guess into the space.
		Puzzle[x][y] = i;

		// Try to solve the guess.
		if (solve()) return true;

		// Roll back if incorrect.
		else std::copy(&SafePuzzle[0][0], &SafePuzzle[0][0] + (9*9), &Puzzle[0][0]);
	}
	return false;
}
void SudokuPuzzle::print()
{
	printf("\n\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%i ", Puzzle[i][j]);
		}
		printf("\n");
	}
}
