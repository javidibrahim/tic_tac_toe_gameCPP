#include <iostream>
using namespace std;


#include "JavidIbrahimov_tictactoe.h"

TicTacToe::TicTacToe()
{

}

TicTacToe::~TicTacToe()
{

}

//getters

int TicTacToe::getpRow()
{
	return pRow;
}

int TicTacToe::getpCol()
{
	return pCol;
}

//setters

void TicTacToe::setpRow(int r)
{
	pRow = r;
}

void TicTacToe::setpCol(int c)
{
	pCol = c;
}


void TicTacToe::initArray()
{
	for (int i = 0; i < 3; i++)
	{
		for (int u = 0; u<3; u++)
		{
			board[i][u] = '*';
		}
	}
}

void TicTacToe::displayboard()
{
	for(int i=0; i<3; i++)
	{
		for(int u=0; u<3; u++)
		{
			cout << board[i][u] << " ";
		}
		cout << endl;
	}
}

void TicTacToe::play(int a)
{
	if(a == 0)
	{
		board[pRow][pCol] = 'X';
	}
	else if (a == 1)
	{
		board[pRow][pCol] = 'O';
	}

}

bool TicTacToe::validateInput(int row, int col)
{
	if(board[row][col] != '*')
	{
		return true;
	}
	else
	{
		return false;	
	}
}

char TicTacToe::win()
{
	char a = 'N';
	for (int i=0; i<3; i++)
	{

		if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			if(board[i][0] == '*')
			{
				
			}
			else
			{
				a = board[i][0];
			}
		}
		
		if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			if(board[0][i] == '*')
			{
				
			}
			else
			{
				a = board[0][i];
			}	
		}
		if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
		{
			if(board[0][0] == '*')
			{
				
			}
			else
			{
				a = board[0][0];
			}	
		}
		if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]))
		{
			if(board[0][2] == '*')
			{
				
			}
			else
			{
				a = board[0][2];
			}	
		}
	}
		return a;
	
}
