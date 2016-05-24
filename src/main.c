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

int main(void) 
{
	const int scheme[SIZE][SIZE] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
									 { 0, 0, 0, 0, 0, 0, 0, 0 }, 
									 { 0, 0, 0, 0, 0, 0, 0, 0 }, 
									 { 0, 0, 1, 1, 1, 0, 0, 0 }, 
									 { 0, 0, 0, 1, 1, 1, 0, 0 }, 
									 { 0, 0, 0, 0, 0, 0, 0, 0 }, 
									 { 0, 0, 0, 0, 0, 0, 0, 0 }, 
									 { 0, 0, 0, 0, 0, 0, 0, 0 } };
	
	struct game game1;
	
	init_game(&game1, scheme, 1000);
	print_space(game1.space1);
	
	for (int i = 0; i < game1.generation; i++) {
		printf("%s%d", "generation=", i); 
		printf("%s%d\n", "tick=", game1.tick_flag);
		
		next_generation(&game1);
		
		if(game1.tick_flag == 1) 
			print_space(game1.space2);
		else
			print_space(game1.space1);

		//Sleep(100);
		//system("cls");
	}
	
	return 0;
}