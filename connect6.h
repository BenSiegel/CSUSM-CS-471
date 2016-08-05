struct node
{
	int nextmv[3];
	int board[9][9];
	int wieght;
};

class gametree
{
private:
	node *top;
public:
	gametree() { top = NULL; }
	void buildtree(node*, int, int, bool);
};


class Connect6
{
public:
	void mainScreen();
	void Instructions();
	void initalizeBoard();
	void firstMove();
	void Game();
	bool spotCheck(int, int);
  	bool spotAdjCheckP1(int, int, int);
  	bool spotAdjCheckP2(int, int, int);
	bool draw();
	bool player1();
	bool player2();
	void graphics(int, int);
	void gameOver();
};
