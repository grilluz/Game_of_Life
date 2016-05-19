#include "game_of_life.h"

void init_game(Game *game, const int scheme[][SIZE])
{
	int *s1 = game->space1;
	
	for(int row = 0; row < SIZE; row++) {
		for(int col = 0; col < SIZE; col++) {
			s1[row][col] = scheme[col][row];
		}
	}
}

void print_space(const int s[][SIZE])
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

void next_generation(Game *game)
{
	bool tick = game->tick_flag;
	int *s1 = game->space1;
	int *s2 = game->space2;
	
	if (tick == 1) {
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < SIZE; j++) {
				if (s1[i][j] == 1) {
					s2[i][j] = live_cell(s1, i, j);
				}
				else {
					s2[i][j] = empty_cell(s1, i, j);
				}
			}
		}
	}
	else {
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < SIZE; j++) {
				if (s2[i][j] == 1) {
					s1[i][j] = live_cell(s2, i, j);
				}
				else {
					s1[i][j] = empty_cell(s2, i, j);
				}
			}
		}
	}

	tick = 1 - tick;	//toggle tick
}

//compute live cells destiny:
//if it has 2-3 neighbours it survives...
//else it dies
static int live_cell(const int s[][SIZE], int row, int col)
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

//compute empty cells destiny:
//if there is exactly 3 neighbours a new cell was born...
//else the cell remain empty
static int empty_cell(const int s[][SIZE], int row, int col)
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
