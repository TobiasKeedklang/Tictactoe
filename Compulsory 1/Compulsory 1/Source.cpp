#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

char num[3][3]{ {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char renum[] = { '1','2','3', '4','5','6', '7','8','9' };

void table();
void play();
void turn();
bool xo();
void victory();
void rematch();

int main() 
{
	//litterally only starts the play function, which contain the whole game
	play();
}

void table()// creates the tic tac toe table
{
	std::cout << "Welcome to Tic Tac Toe!!" << std::endl; 
	std::wcout << "-------------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|";
		for (int j = 0; j < 3; j++)
		{
			std::cout << " " << num[i][j] << " |";

		}
		std::cout << std::endl << "-------------" << std::endl;
	}
}

int cp = 1; //current player for 1 or 2
char mark = 'X'; //player mark
int p{}; //player input for mark
int pw{}; //player win value for confirmation
void play()
{
	for (int i = 0; i < 9; i++)
	{
		//Prints table
		system("cls");
		table();
		//Ask for and execute player input, unless its allready ocupied
		std::cout << "Player " << cp << ", enter a slot to insert '" << mark << "'" << std::endl;
		if (!xo())
		{
			i--; 
			std::cout << "The slot is occupied" << std::endl;
			Sleep(700);
			continue;
		}
		//Checks if anyone has won
		victory();
		if(pw==1)
		{
			break;
		}
		turn();
	}
	//prints tie after 9 rounds
	if (pw == 0)
	{
		system("cls");
		table();
		std::cout << "Uh oh, It's a tie!!" << std::endl << std::endl;
	}
	//Asks if the players want to start a new round
	rematch();
}
void turn()
{
	//changes mark and player
	if (mark == 'X')
	{
		mark = 'O';
	}
	else
	{
		mark = 'X';
	}
	if (cp == 1)
	{
		cp = 2;
	}
	else 
	{
		cp = 1;
	}
}
bool xo()
{
//takes player input
	char p = _getch();
	int i = (int)((char)p - '0');
//checks if the slot is occupied and if not, puts player mark in slot
	switch (i)
	{
	case 1:
		if (num[0][0] != 'X' && num[0][0] != 'O')
		{
			num[0][0] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 2:
		if (num[0][1] != 'X' && num[0][1] != 'O')
		{
			num[0][1] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 3:
		if (num[0][2] != 'X' && num[0][2] != 'O')
		{
			num[0][2] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 4:
		if (num[1][0] != 'X' && num[1][0] != 'O')
		{
			num[1][0] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 5:
		if (num[1][1] != 'X' && num[1][1] != 'O')
		{
			num[1][1] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 6:
		if (num[1][2] != 'X' && num[1][2] != 'O')
		{
			num[1][2] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 7:
		if (num[2][0] != 'X' && num[2][0] != 'O')
		{
			num[2][0] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 8:
		if (num[2][1] != 'X' && num[2][1] != 'O')
		{
			num[2][1] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 9:
		if (num[2][2] != 'X' && num[2][2] != 'O')
		{
			num[2][2] = mark;
			return true;
		}
		else
		{
			return false;
		}
		break;
	default:
		std::cout << "Please enter a number representing a slot" << std::endl;
		return false;
		break;

	}
}

void victory()
{
	//checks horisontal, vertical and diagonal lines for a row of similar marks
	for (int i = 0; i < 3; i++)
	{
		if (num[i][0] == num[i][1] && num[i][1] == num[i][2])
		{
			system("cls");
			table();
			std::cout << "Victory for player " << cp << "!!!" << std::endl << std::endl;
			pw = 1; 
			
		}
		if (num[0][i] == num[1][i] && num[1][i] == num[2][i])
		{
			system("cls");
			table();
			std::cout << "Victory for player " << cp << "!!!" << std::endl << std::endl;
			pw = 1; 
			
		}
		if (num[0][0] == num[1][1] && num[1][1] == num[2][2])
		{
			system("cls");
			table();
			std::cout << "Victory for player " << cp << "!!!" << std::endl << std::endl;
			pw = 1;
		
		}
		if (num[2][0] == num[1][1] && num[1][1] == num[0][2])
		{
			system("cls");
			table();
			std::cout << "Victory for player " << cp << "!!!" << std::endl << std::endl;
			pw = 1;
			
		}
	}
}

int counter = 0;
void rematch()
{
	std::cout << "Play again? Y or N" << std::endl;
	char answ = _getch();
	switch (answ)
	{
//resets values and start new round
	case 'Y': case 'y':
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				num[i][j] = renum[counter];
				counter++;
			}
		}
	play();
		break;
//stops the program
	case 'N': case 'n':
		std::cout << "Quitting...";
		Sleep(500);
		exit(0);
		break;
	}
}


