#include"game_func.h"



// global variables

char matrix[3][3] = { ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ' };

char current_player = 'X';


// functions

void draw_board()
{
	system("cls");

	std::cout << "Tic tac toe game\n";

	std::cout << "\n Player 1 = (X) - Player 2 = 'O'\n\n";

	for (int i = 0; i < 3; i++)
	{
		std::cout << " ------------\n";

		for (int j = 0; j < 3; j++)
		{
			std::cout << " | " << matrix[i][j];
		}

		std::cout << "\n";
	}

	std::cout << " ------------\n";
}


int Input_matrix()
{
	int num;

	std::cout << "\nPlayer : " << current_player << " your turn Press the cell number to put the mark in:";
	std::cin >> num;

	while (num > 0 && num < 10)
	{
		switch (num)
		{
		case 1:

			if (matrix[0][0] == 'X' || matrix[0][0] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				return 0;
			}
			else
			{
				matrix[0][0] = current_player;
				return 1;
			}

			break;

		case 2:

			if (matrix[0][1] == 'X' || matrix[0][1] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				return 0;
			}
			else
			{
				matrix[0][1] = current_player;
				return 1;
			}

			break;

		case 3:

			if (matrix[0][2] == 'X' || matrix[0][2] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				return 0;
			}
			else
			{
				matrix[0][2] = current_player;
				return 1;
			}

			break;

		case 4:

			if (matrix[1][0] == 'X' || matrix[1][0] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				return 0;
			}
			else
			{
				matrix[1][0] = current_player;
				return 1;
			}

			break;

		case 5:

			if (matrix[1][1] == 'X' || matrix[1][1] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				return 0;
			}
			else
			{
				matrix[1][1] = current_player;
				return 1;
			}

			break;

		case 6:

			if (matrix[1][2] == 'X' || matrix[1][2] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				return 0;
			}
			else
			{
				matrix[1][2] = current_player;
				return 1;
			}

			break;

		case 7:

			if (matrix[2][0] == 'X' || matrix[2][0] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				return 0;
			}
			else
			{
				matrix[2][0] = current_player;
				return 1;
			}

			break;

		case 8:

			if (matrix[2][1] == 'X' || matrix[2][1] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				return 0;
			}
			else
			{
				matrix[2][1] = current_player;
				return 1;
			}

			break;

		case 9:

			if (matrix[2][2] == 'X' || matrix[2][2] == 'O')
			{
				std::cout << "\nThis cell is not empty try again\n";
				
			}
			else
			{
				matrix[2][2] = current_player;
				return 1;
			}

			break;
		}
	}

	return 0;
}



void change_player()
{
	if (current_player == 'X')
	{
		current_player = 'O';
	}

	else
	{
		current_player = 'X';
	}
}


char check_mark()
{
	// check the winner
	for (int i = 0; i < 3; i++)
	{
		// check rows
		if (matrix[i][0] == current_player && matrix[i][1] == current_player && matrix[i][2] == current_player)
			return current_player;

		// check columns
		if (matrix[0][i] == current_player && matrix[1][i] == current_player && matrix[2][i] == current_player)
			return current_player;
	}

	// check diagonals
	if (matrix[0][0] == current_player && matrix[1][1] == current_player && matrix[2][2] == current_player)
		return current_player;

	if (matrix[0][2] == current_player && matrix[1][1] == current_player && matrix[2][0] == current_player)
		return current_player;

	// case nobody wins
	return '=';
}


void game()
{
	int valid_input, turn;

	for (turn = 0; turn < 9; turn++)
	{
		valid_input = Input_matrix();

		if (!valid_input)
		{
			turn--;
			continue;
		}

		draw_board();

		if (check_mark() == 'X')
		{
			std::cout << "Player (X) wins \n";
			break;
		}

		else if (check_mark() == 'O')
		{
			std::cout << "Player (O) wins\n";
			break;
		}

		change_player();
	}

	if (check_mark() == '=' && turn == 9)
	{
		std::cout << "It's a tie game\n";
	}
}