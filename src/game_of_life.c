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

#include "game_of_life.h"
//compute live cells destiny:
//if it has 2-3 neighbours it survives...
//else it dies
static int live_cell(int s[][SIZE], int row, int col);

//compute empty cells destiny:
//if there is exactly 3 neighbours a new cell was born...
//else the cell remain empty
static int empty_cell(int s[][SIZE], int row, int col);

void init_game(struct game *g, const int scheme[][SIZE], unsigned gen)
{	
	g->tick_flag = 1;
	g->generation = gen;
	
	for(int row = 0; row < SIZE; row++) {
		for(int col = 0; col < SIZE; col++) {
			g->space1[row][col] = scheme[col][row];
			g->space2[row][col] = 0;
		}
	}
}

void print_space(int s[][SIZE])
{	
	//upper frame
	for (int i = 1; i < SIZE + 2; i++) {
		printf("%c", '-');
	}
	printf("\n");

	for (int i = 1; i < SIZE; i++) {
		printf("%c", '|');
		for (int j = 1; j < SIZE; j++) {
			printf("%c", s[i][j]? '#' : ' ');
		}
		printf("%c", '|');
		printf("\n");
	}

	//lower frame
	for (int i = 1; i < SIZE + 2; i++) {
		printf("%c", '-');
	}
	printf("\n");
}

void next_generation(struct game *g)
{
	//int (*s1)[SIZE][SIZE] = &g->space1;
	//int (*s2)[SIZE][SIZE] = &g->space2;
	
	if (g->tick_flag == 1) {
		for (int i = 1; i < SIZE; i++) {
			for (int j = 1; j < SIZE; j++) {
				if (g->space1[i][j] == 1) {
					g->space2[i][j] = live_cell(g->space1, i, j);
				}
				else {
					g->space2[i][j] = empty_cell(g->space1, i, j);
				}
			}
		}
	}
	else {
		for (int i = 1; i < SIZE; i++) {
			for (int j = 1; j < SIZE; j++) {
				if (g->space2[i][j] == 1) {
					g->space1[i][j] = live_cell(g->space2, i, j);
				}
				else {
					g->space1[i][j] = empty_cell(g->space2, i, j);
				}
			}
		}
	}
	
	/*
	if (g->tick_flag == 1) {
		for (int i = 1; i < SIZE; i++) {
			for (int j = 1; j < SIZE; j++) {
				if (*s1[i][j] == 1) {
					*s2[i][j] = live_cell(g->space1, i, j);
				}
				else {
					*s2[i][j] = empty_cell(g->space1, i, j);
				}
			}
		}
	}
	else {
		for (int i = 1; i < SIZE; i++) {
			for (int j = 1; j < SIZE; j++) {
				if (*s2[i][j] == 1) {
					*s1[i][j] = live_cell(g->space2, i, j);
				}
				else {
					*s1[i][j] = empty_cell(g->space2, i, j);
				}
			}
		}
	}
	*/
	g->tick_flag = 1 - g->tick_flag;	//toggle tick
}


static int live_cell(int s[][SIZE], int row, int col)
{
	int neighbours = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) 
				continue; //skip the cell position

			if (s[i + row - 1][j + col - 1] == 1)
				neighbours++;
		}
	}

	if (neighbours == 2 || neighbours == 3)	
		return 1; //if there are 2 or 3 neighbours, cell survives

	return 0; //cell dies
}


static int empty_cell(int s[][SIZE], int row, int col)
{
	int neighbours = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;

			if (s[i + row - 1][j + col - 1] == 1)
				neighbours++;
		}
	}

	if (neighbours == 3)
		return 1; //a new cell was born

	return 0; //the cell remain empty
}
