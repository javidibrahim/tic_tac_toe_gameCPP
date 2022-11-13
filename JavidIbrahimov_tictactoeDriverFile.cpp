				//Part I - Identification / Algorithm
/*

Javid Ibrahimov
10/11/2022
CS204-Computer Programming II

Program:  It is a Tic Tac Toe game, 
let's the user play the game after it shows the board(2 Dimentional array)
It let's the player 1 start by entering positions for X, replacing * and displaying board again.
Same for the player 2. Play until board is full, and display the board after every move.


***Design (Pseudo/Algorithm)***


Step 1: Decalare variable for position selection, variables for some flag values
Step 2: After creating an object populate an array with *
Step 3: Display the board before the loop starts
Step 4: Loop iterates 9 times or until game is won
Step 5: After loop starts program selects the user to be able to assign positions for them
Step 6: After the selection for rows and columns, validate input to check boundaries 0-3
Step 7: Pass positions to a function to check if array is taken, if taken loop until get the right answer
Step 8: After validation, pass positions to an array by calling a function
Step 9: Display the board after every move has been assigned to the board
Step 10: Check if entire row or column, or diagonally match, if it does exit the loop.
Step 11: It's a draw if the board is full and step 10 is not fullfilled

*******************************

*/
				//Part II - Preprocessor files / Libraries
				
//Define my header files
#include <iostream>
using namespace std;


#include "JavidIbrahimov_tictactoe.h"

/* 
***function prototypes*** 
*/
int positionValidation(int);

int main()
{
				//Part III - Declare / Initialize Variables
	//declare variables
	int pCol = 0;
	int pRow = 0;
	bool taken = false;
	int player;
	char winner = 'N';

				//Part IV - Algorithmic Process
	//declare my object
	TicTacToe test;
	//initialize the array with *
	test.initArray();
	
	
	//display the initial position
	test.displayboard();
	
	//loop to fill all gaps
	for(int i = 0; i < 9; i++)
	{	
		//determines which player plays 
		player = i%2;

		if (player == 0)
		{
			cout << "Player 1 MOVE" << endl << endl;
		}

		if (player == 1)
		{
			cout << "Player 2 MOVE" << endl << endl;
		}
	
		//get positions
		//rows
		cout << "Enter row position --> ";
		cin >> pRow;
		pRow = positionValidation(pRow);

		//columns
		cout << "Enter column position --> ";
		cin >> pCol;
		pCol = positionValidation(pCol);

		//flag value if position is taken
		taken  = test.validateInput(pRow, pCol);

		//if position is taken ask again 
		while (taken)
		{	
			//if taken show board again 
			test.displayboard();
			cout << "Position taken, enter a new row position --> ";
			cin >> pRow;
			positionValidation(pRow);

			cout << "Position taken, enter a new column position --> ";
			cin >> pCol;
			positionValidation(pCol);

			taken  = test.validateInput(pRow, pCol);
		}

		//after validations we set positions
		test.setpRow(pRow);
		test.setpCol(pCol);

		//play the move
		test.play(player);

		//display board after setting a position
		test.displayboard();

		//check if there is a winner
		winner = test.win();
		if (winner == 'X')
		{
			cout << "Player 1 WON";
			i = 10;
		}
		else if (winner == 'O')
		{
			cout << "Player 2 WON";
			i = 10;
		}
		if(i == 8 && winner == 'N')
		{
			cout << "Draw!";
		}

	}
	

				//Part V - Terminate the algorithmic process	
	return 0;
}

int positionValidation(int a)
{
	while(a < 0 || a >= 3)
	{
		cout << "Out of bounds, choose between 0 and 2 " << endl;
		cin >> a;
	}
	
	return a;
}



/*

				//Part 6 - Verification / Validation
				
Test Cases:



* * *
* * *
* * *
Player 1 MOVE

Enter row position --> 0
Enter column position --> 0
X * *
* * *
* * *
Player 2 MOVE

Enter row position --> 1
Enter column position --> 2
X * *
* * O
* * *
Player 1 MOVE

Enter row position --> 0
Enter column position --> 2
X * X
* * O
* * *
Player 2 MOVE

Enter row position --> 2
Enter column position --> 0
X * X
* * O
O * *
Player 1 MOVE

Enter row position --> 0
Enter column position --> 1
X X X
* * O
O * *
Player 1 WON
--------------------------------

Test Case 2:

* * *
* * *
* * *
Player 1 MOVE

Enter row position --> 0
Enter column position --> 1
* X *
* * *
* * *
Player 2 MOVE

Enter row position --> -2
Out of bounds, choose between 0 and 2
1
Enter column position --> 1
* X *
* O *
* * *
Player 1 MOVE

Enter row position --> 3
Out of bounds, choose between 0 and 2
1
Enter column position --> 0
* X *
X O *
* * *
Player 2 MOVE

Enter row position --> 2
Enter column position --> 2
* X *
X O *
* * O
Player 1 MOVE

Enter row position --> 0
Enter column position --> 2
* X X
X O *
* * O
Player 2 MOVE

Enter row position --> 0
Enter column position --> 0
O X X
X O *
* * O
Player 2 WON
--------------------------------
Case 3:

* * *
* * *
* * *
Player 1 MOVE

Enter row position --> 1
Enter column position --> 1
* * *
* X *
* * *
Player 2 MOVE

Enter row position --> 0
Enter column position --> 0
O * *
* X *
* * *
Player 1 MOVE

Enter row position --> 0
Enter column position --> 1
O X *
* X *
* * *
Player 2 MOVE

Enter row position --> 2
Enter column position --> 1
O X *
* X *
* O *
Player 1 MOVE

Enter row position --> 0
Enter column position --> 2
O X X
* X *
* O *
Player 2 MOVE

Enter row position --> 2
Enter column position --> 2
O X X
* X *
* O O
Player 1 MOVE

Enter row position --> 2
Enter column position --> 0
O X X
* X *
X O O
Player 1 WON
--------------------------------

*/
