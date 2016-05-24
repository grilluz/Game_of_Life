/*
Simple implementation of "Game of Life" in C!
Copyright (C) 2016  Grilluz

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

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPACE 8
#define BORDER 2			//prevents from out of bounds errors
#define SIZE SPACE+BORDER

struct game {
	unsigned generation;	
	int tick_flag;		//flag that toggles every generation
	int space1[SIZE][SIZE];
	int space2[SIZE][SIZE];
};

//init space with a predefined scheme of cells
void init_game(struct game *game, const int scheme[][SIZE], unsigned gen);

//print on the console the matrix s
void print_space(int s[][SIZE]);

//compute next generation 
void next_generation(struct game *game);


//prototypes of static functions
/*
//compute live cells destiny:
//if it has 2-3 neighbours it survives...
//else it dies
static int live_cell(int s[][SIZE], int row, int col);

//compute empty cells destiny:
//if there is exactly 3 neighbours a new cell was born...
//else the cell remain empty
static int empty_cell(int s[][SIZE], int row, int col);
*/
#endif //GAME_OF_LIFE_H