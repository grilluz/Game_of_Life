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
	bool tick_flag = 1;		//flag that toggles every generation
	int space1[SIZE][SIZE];
	int space1[SIZE][SIZE] = {0};
};
typedef struct game Game;

//init space with a predefined scheme of cells
void init_game(int s1[][SIZE], const int scheme[][SIZE]);

//print on the console the matrix s
void print_space(const int s[][SIZE]);

//compute next generation 
void next_generation(int s[][SIZE], int next_s[][SIZE], int row);

#endif //GAME_OF_LIFE_H