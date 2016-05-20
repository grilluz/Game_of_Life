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