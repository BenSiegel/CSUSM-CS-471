//Benjamin Siegel
//CS 436
//Individual Project 2 12/02/15

class Sudoku
{
	public:
		void start();
		void mainGame();
		void initboard();
		void inputsNumbers();
		int changeMove(int, int, int);
		bool spotCheck(int, int);
		bool numberCheck(int, int, int);
		bool updateArray(int, int);
		void displayBoard();
		bool gameOver();
	};
	
	