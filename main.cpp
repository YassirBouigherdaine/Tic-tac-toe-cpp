// tic tac toe game

#include"game_func.h"





int main()
{
	bool game_over = false;

	draw_board();

	while (!game_over)
	{
		game();

		game_over = true;
	}

	return 0;
}

