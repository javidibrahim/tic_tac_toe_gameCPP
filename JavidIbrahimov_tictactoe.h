#ifndef tictactoe
#define tictactoe

class TicTacToe
{
	private:
		int pRow;
		int pCol;
		char board[3][3];

	public:
		//constructor
		TicTacToe();
		//destructor
		~TicTacToe();
		
		//populates the array
		void initArray();
		//displays the board
		void displayboard();
		//assigns move for the position
		void play(int a);
		
		//validates positions
		bool validateInput(int row, int col);
		
		//checks the winner
		char win();


		//getters
		int getpRow();
		int getpCol();

		//setters
		void setpRow(int);
		void setpCol(int);

	
};
#endif
