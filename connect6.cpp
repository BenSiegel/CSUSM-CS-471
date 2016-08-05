/*
Created by Andrew Luu
			Shane Lopez
			Benjamin Siegel

For CS471 Introduction to Artificial Intelligence Project.

Object: Build a program using Mini-Max sorting to build a board game and compete against it.
*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include "connect6.h"
using namespace std;

int ply = 2;//////////////
			//size of array
int x = 9;
int y = 9;
int Board[9][9];
//input from user
int a = 0;
int b = 0;
int c = 0;
int d = 0;
//checks for victory in spotAdjCheck
int oValue = 10;
int xValue = 11;
int scoreCheck = 0;
//score needed for victory
int player1Victory = 60;
int player2Victory = 66;
bool victoryCondition = false;
int player1Score = 0;
int player2Score = 0;
int vertScore = 0;
int horzScore = 0;
int diagUpScore = 0;
int diagDownScore = 0;
int winner = 0;
//diagonal scores calculator
int upScore = 0;
int downScore = 0;
bool player1Turn = false;
bool player2Turn = false;
int turnNumber = 0;
bool victoryCheck = false;
bool checkSize = false;
bool checkLoc = false;
int player1ScoreLongest = 0;
int player2ScoreLongest = 0;
//visuals/ graphics
string oString = "O";
string xString = "X";
string outPut = " ";
int graphCount = 0;

void Connect6::mainScreen()
{
	int response = 0;

	//Introduction screen/ menu
	cout << "     0   1   2   3   4   5   6   7   8" << endl
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  0| C | O | N | N | E | C | T | ~ | 6 |" << endl //0
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  1|   | C | R | E | A | T | E | D |   |" << endl //1
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  2|   |   |   | B | Y | : |   |   |   |" << endl //2
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  3| S | H | A | N | E |   |   |   |   |" << endl //3
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  4|   |   |   |   | L | O | P | E | Z |" << endl //4
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  5| A | N | D | R | E | W |   |   |   |" << endl //5
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  6|   |   |   |   |   |   | L | U | U |" << endl //6
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  7| B | E | N | J | A | M | I | N |   |" << endl //7
		<< "   |---|---|---|---|---|---|---|---|---|" << endl
		<< "  8|   |   |   | S | I | E | G | E | L |" << endl //8 
		<< "   |---|---|---|---|---|---|---|---|---|" << endl;

	cout << "Enter 1 for Instructions" << endl
		<< "Enter 2 to start a new game" << endl
		<< "Enter 3 to quit \n >";
	cin >> response;

	if (response == 1)
	{
		Instructions();
	}
	else if (response == 2)
	{
		firstMove();
	}
	else
	{
		cout << "\n Goodbye! \n\n";
		return;
	}

	return;
}

void Connect6::Instructions()
{
	cout << "___       __ ___ _       _ ___ ___  _        __" << endl
		<< " |  |\\ | (_   | |_) | | /   |   |  / \\ |\\ | (_ " << endl
		<< "_|_ | \\| __)  | | \\ |_| \\_  |  _|_ \\_/ | \\| __)" << endl
		<< "_______________________________________________" << endl << endl;

	cout << "! Player 1 is O" << endl
		<< "! Player 2 is X" << endl
		<< "! Player 1 starts the game." << endl
		<< "! Player 1 placing 1 piece on the board to start the game." << endl
		<< "! Each player will take turns after the first move is played by placing" << endl
		<< "   ! 2 pieces per turn." << endl
		<< "! To win the game, one player must have 6 pieces in a row" << endl
		<< "   ! The row can be vertical, horizontal, or diagonal." << endl
		<< "! If the board fills up and no one won, the game will end in a draw." << endl
		<< "! To enter the location to place a piece" << endl
		<< "  ! enter like this: \"0 1\" to represent [0,1]"
		<< "! Have Fun!" << endl << endl;

	initalizeBoard();

	return;
}

void Connect6::initalizeBoard()
{
	//Initalizing board

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Board[i][j] = 0;
		}
	}

	firstMove();
}

void Connect6::firstMove()
{
	player1Turn = true;
	turnNumber++;
	cout << "Turn Number: " << turnNumber << endl
		<< "O's turn \n >";
	cin >> a >> b;
	cout << endl << endl;

	spotCheck(a, b);

	Board[a][b] = 10;
	player1Score += 10;

	player1Turn = false; //end of player 1's turn
	player2Turn = true;

	graphics(a, b);

	Game();
}

void Connect6::Game()
{
	while (victoryCondition == false)
	{
		if (player1Turn == true)
		{
			player1();
		}
		if (player2Turn == true)
		{
			player2();
		}

	}
}

bool Connect6::spotCheck(int t, int u)
{
	if (t > -1 && t < 9 && u > -1 && u < 9)
	{
		checkSize = true;
	}

	else if (t < 0 || t > 8 || u < 0 || u > 8)
	{
		checkSize = false;
	}

	if (Board[t][u] == 0)
	{
		checkLoc = true;
	}

	else if (Board[t][u] != 0)
	{
		checkLoc = false;
	}

	if (checkSize == false || checkLoc == false)
	{
		return false;
	}

	return true;
}

bool Connect6::player1()
{
	turnNumber++;

	cout << "Turn Number: " << turnNumber << endl
		<< "O's turn" << endl
		<< "Enter first piece \n>";
	cin >> a >> b;
	cout << endl << endl;

	if (!spotCheck(a, b))//spotCheck(a,b); //valid move in terms of logistics
	{
		while (!spotCheck(a, b))
		{
			cout << "Invalid location. Re-enter. \n>";
			cin >> a >> b;
		}
	}
	Board[a][b] = 10;
	graphics(a, b);

	spotAdjCheckP1(turnNumber, a, b); //valid move in terms of game win conditions
	draw();

	cout << "O's turn \n" << "Enter second piece \n > ";
	cin >> c >> d;
	cout << endl << endl;
	if (!spotCheck(c, d))//spotCheck(a,b); //valid move in terms of logistics
	{
		while (!spotCheck(c, d))
		{
			cout << "Invalid location. Re-enter. \n>";
			cin >> c >> d;
		}
	}

	Board[c][d] = 10;
	graphics(c, d);
	spotAdjCheckP1(turnNumber, c, d); //valid move in terms of game win conditions
	draw();

	player1Turn = false;
	player2Turn = true;

	return player2Turn;
}

//////////////////////////////////////////////////////////////////////////
void gametree::buildtree(node *root, int depth, int turnnum, bool max)
{
	int player1longest = 0;
	int player2longest = 0;
	node *cur = new node;
	bool pass = false;
	player1longest = 0;
	player2longest = 0;
	int dummy;
	int dummy2;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cur->board[i][j] = root->board[i][j];
		}
	}
	for (int posx = 0; posx < 9; posx++)
	{
		for (int posy = 0; posy < 9; posy++)
		{
			if (root->board[posx][posy] == 0 && depth < (ply * 2) + 1)
			{
				if (max == true)
				{
					cur->board[posx][posy] = 11;
				}
				else
				{
					cur->board[posx][posy] = 10;
				}
				for (int posx2 = 0; posx2 < 9; posx2++)
				{
					for (int posy2 = 0; posy2 < 9; posy2++)
					{
						if (cur->board[posx2][posy2] == 0 && depth < (ply * 2) + 1)
						{
							if (max == true)
							{
								cur->board[posx2][posy2] = 11;
								max = false;
								dummy = depth + 1;
								dummy2 = depth + 1;
								buildtree(cur, dummy, dummy2, max);
							}
							else
							{
								cur->board[posx2][posy2] = 10;
								max = true;
								dummy = depth + 1;
								dummy2 = turnnum + 1;
								buildtree(cur, dummy, dummy2, max);
							}
							if (max == false && cur->wieght >= root->wieght && cur->wieght != 0)
							{
								root->wieght = cur->wieght;
								root->nextmv[0] = posx;
								root->nextmv[1] = posy;
								root->nextmv[2] = posx2;
								root->nextmv[3] = posy2;
							}
							else if (max == true && turnnum != 0 && cur->wieght <= root->wieght)
							{
								root->wieght = cur->wieght;
							}
							else if (max == false && turnnum != 0 && cur->wieght < root->wieght)
							{
								delete cur;
								return;
							}

						}
					}
				}
			}
		}
	}
	if (depth == ((ply * 2) + 1))
	{
		int temp = 0;
		int check;
		int check2;
		int win = 0;
		int loss = 0;
		//dummy = spotAdjCheck(turnnum, posx, posy); //need to change to predicted adj check
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (cur->board[i][j] == 11)
				{
					temp++;
					check = j;
					check2 = i;
					while (cur->board[i][check] != 10 && cur->board[i][check] != 0 && check < j + 6 && check < 9)//vertical negitive check
					{
						temp++;
						check++;
					}
					if (temp == 6)
					{
						win++;
						temp = 0;
					}
					check = j;
					while (cur->board[i][check] != 10 && cur->board[i][check] != 0 && check > j - 6 && check > 0)//vertical positive check
					{
						temp++;
						check--;
					}
					if (temp == 6)
					{
						win++;
						temp = 0;
					}
					if (temp > player2longest)
					{
						player2longest = temp;
					}
					temp = 0;
					check = j;
					while (cur->board[check2][j] != 10 && cur->board[check2][j] != 0 && check2 < i + 6 && check2 < 9)//horizontal check
					{
						temp++;
						check2++;
					}
					if (temp == 6)
					{
						win++;
						temp = 0;
					}
					check2 = i;
					while (cur->board[check2][j] != 10 && cur->board[check2][j] != 0 && check2 > i - 6 && check2 > 0)//horizontal check
					{
						temp++;
						check2--;
					}
					if (temp == 6)
					{
						win++;
						temp = 0;
					}
					if (temp > player2longest)
					{
						player2longest = temp;
					}
					temp = 0;
					check2 = i;
					while (cur->board[check2][check] != 10 && cur->board[check2][check] != 0 && check2 < i + 6 && check < j + 6 && check < 9)//dig check
					{
						temp++;
						check++;
						check2++;
					}
					if (temp == 6)
					{
						win++;
						temp = 0;
					}
					check = j;
					check2 = i;
					while (check2 >= 0 && check >= 0 && cur->board[check2][check] != 10 && cur->board[check2][check] != 0 && check2 > i - 6 && check > j - 6)//dig check
					{
						temp++;
						check--;
						check2--;
					}
					if (temp == 6)
					{
						win++;
						temp = 0;
					}
					if (temp > player2longest)
					{
						player2longest = temp;
					}
					temp = 0;
				}
				else if (cur->board[i][j] == 10)
				{
					temp++;
					check = j;
					check2 = i;
					while (cur->board[i][check] != 11 && cur->board[i][check] != 0 && check < j + 6 && check < 9)//vertical negitive check
					{
						temp++;
						check++;
					}
					if (temp == 6)
					{
						loss++;
						temp = 0;
					}
					check = j;
					while (cur->board[i][check] != 11 && cur->board[i][check] != 0 && check > j - 6 && check > 0)//vertical positive check
					{
						temp++;
						check--;
					}
					if (temp == 6)
					{
						loss++;
						temp = 0;
					}
					if (temp > player1longest)
					{
						player1longest = temp;
					}
					check = j;
					temp = 0;
					while (cur->board[check2][j] != 11 && cur->board[check][j] != 0 && check2 < i + 6 && check2 < 9)//horizontal check
					{
						temp++;
						check2++;
					}
					if (temp == 6)
					{
						loss++;
						temp = 0;
					}
					check = i;
					while (cur->board[check2][j] != 11 && cur->board[check2][j] != 0 && check > i - 6 && check > 0)//horizontal check
					{
						temp++;
						check--;
					}
					if (temp == 6)
					{
						loss++;
						temp = 0;
					}
					if (temp > player1longest)
					{
						player1longest = temp;
					}
					check2 = i;
					temp = 0;
					while (cur->board[check2][check] != 11 && cur->board[check2][check] != 0 && check2 < i + 6 && check < j + 6 && check < 9)//dig check
					{
						temp++;
						check++;
						check2++;
					}
					if (temp == 6)
					{
						loss++;
						temp = 0;
					}
					check = j;
					check2 = i;
					while (check2 >= 0 && check >= 0 && cur->board[check2][check] != 11 && cur->board[check2][check] != 0 && check2 > i - 6 && check > j - 6)//dig check
					{
						temp++;
						check--;
						check2--;
					}
					if (temp == 6)
					{
						loss++;
						temp = 0;
					}
					if (temp > player1longest)
					{
						player1longest = temp;
					}
					temp = 0;
				}
			}
		}
		if (depth == ((ply * 2) + 1))
		{
			cur->wieght = ((win * 50) + (player2longest * 15)) - ((player1longest * 20) + (loss * 50));
			if (cur->wieght < root->wieght)
			{
				root->wieght = cur->wieght;
			}
		}
		player1longest = 0;
		player2longest = 0;
	}
	delete cur;
}
///////////////////////////////////////////////////////////////////////

bool Connect6::player2()
{
	turnNumber++;
	gametree tree;
	node *p = new node;
	p->wieght = 0;
	p->nextmv[0] = 0;
	p->nextmv[1] = 0;
	p->nextmv[2] = 0;
	p->nextmv[3] = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			p->board[i][j] = Board[i][j];
		}
	}

	cout << "Turn Number: " << turnNumber << endl
		<< "X's turn" << endl
		<< "Enter first piece >";
	tree.buildtree(p, 0, 0, true);
	cout << p->nextmv[0] << " " << p->nextmv[1];
	cout << endl << endl;

	Board[p->nextmv[0]][p->nextmv[1]] = 11;
	graphics(p->nextmv[0], p->nextmv[1]);
	spotAdjCheckP2(turnNumber, p->nextmv[0], p->nextmv[1]); //valid move in terms of game win conditions
	draw();

	cout << "X's turn\n" << "Enter second piece >";
	cout << p->nextmv[2] << " " << p->nextmv[3];
	cout << endl << endl;

	Board[p->nextmv[2]][p->nextmv[3]] = 11;
	graphics(p->nextmv[2], p->nextmv[3]);
	spotAdjCheckP2(turnNumber, p->nextmv[2], p->nextmv[3]); //valid move in terms of game win conditions
	draw();
	//player2Score+=11;

	player1Turn = true;
	player2Turn = false;

	return player1Turn;
}

bool Connect6::spotAdjCheckP1(int turnNumber, int t, int u)
{
	vertScore = 0;
	horzScore = 0;
	diagUpScore = 0;
	diagDownScore = 0;
	int h = t;
	int v = u;

	if (turnNumber % 2 != 0)
	{
		//cout << "First Value: " << t << " Second value: " << u << endl << endl;
		//check vertical
		for (int i = 0; i < x; i++)
		{
			if ((Board[t][i]) == 10)
			{
				vertScore += 10;
				//cout << "Verticle Score: " << vertScore << endl;
				player1ScoreLongest = vertScore;
			}
			else if ((Board[t][i] == 0) || (Board[t][i] == 11))
			{
				player1ScoreLongest = vertScore;
				vertScore = 0;
			}
			if (player1ScoreLongest >= player1Victory)
			{
				winner = 1;
				gameOver();
			}
		}
		//player1Score = 0;

		//check horizontal
		for (int i = 0; i < x; i++)
		{
			if (Board[i][u] == 10)
			{
				horzScore += 10;
				//cout << "Horizontal Score: " << horzScore << endl;
				player1ScoreLongest = horzScore;
			}
			else if ((Board[i][u] == 0) || (Board[i][u] == 11))
			{
				player1ScoreLongest = horzScore;
				horzScore = 0;
			}
			if (player1ScoreLongest >= player1Victory)
			{
				winner = 1;
				gameOver();
			}
		}
		player1Score = 0;


		//check negative diagonal
		player1Score = 10; //initial spot
		while (Board[h - 1][v - 1] == 10)
		{
			h--;
			v--;
			downScore += 10;
			diagDownScore = downScore;
			//cout << "Down Score: " << downScore << endl;

			if (Board[h - 1][v - 1] != 10 || h == 8) //what if it goes past 9
			{
				diagDownScore = downScore;
				downScore = 0;
				break;
			}
			if (diagDownScore >= player1Victory)
			{
				winner = 1;
				gameOver();
			}
		}

		h = t;
		v = u;

		while (Board[h + 1][v + 1] == 10)
		{
			h++;
			v++;
			upScore += 10;
			diagUpScore = upScore;
			//cout << "Up Score: " << upScore << endl;

			if ((Board[h + 1][v + 1] != 10) || h == 0)
			{
				diagUpScore = upScore;
				upScore = 0;
				break;
			}
			if (diagUpScore >= player1Victory)
			{
				winner = 1;
				gameOver();
			}
		}

		if ((diagUpScore + diagDownScore + player1Score) >= player1Victory)
		{
			winner = 1;
			gameOver();
		}

		//check positive diagonal
		player1Score = 10; //initial spot
		diagDownScore = 0;
		diagUpScore = 0;
		while (Board[h + 1][v - 1] == 10)
		{
			h++;
			v--;
			downScore += 10;
			diagDownScore = downScore;
			//cout << "Down Score: " << downScore << endl;

			if (Board[h + 1][v - 1] != 10 || h == 8) //what if it goes past 9
			{
				diagDownScore = downScore;
				downScore = 0;
				break;
			}
			if (diagDownScore >= player1Victory)
			{
				winner = 1;
				gameOver();
			}
		}

		h = t;
		v = u;

		while (Board[h - 1][v + 1] == 10)
		{
			h--;
			v++;
			upScore += 10;
			diagUpScore = upScore;
			//cout << "Up Score: " << upScore << endl;

			if ((Board[h - 1][v + 1] != 10) || h == 0)
			{
				diagUpScore = upScore;
				upScore = 0;
				break;
			}
			if (diagUpScore >= player1Victory)
			{
				winner = 1;
				gameOver();
			}
		}

		if ((diagUpScore + diagDownScore + player1Score) >= player1Victory)
		{
			winner = 1;
			gameOver();
		}
	}

	return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Connect6::spotAdjCheckP2(int turnNumber, int t, int u)
{
	vertScore = 0;
	horzScore = 0;
	diagUpScore = 0;
	diagDownScore = 0;
	int h = t;
	int v = u;

	if (turnNumber % 2 == 0)
	{
		//cout << "First Value: " << t << " Second value: " << u << endl << endl;
		//check vertical
		for (int i = 0; i < x; i++)
		{
			if ((Board[t][i]) == 11)
			{
				vertScore += 11;
				//cout << "Verticle Score: " << vertScore << endl;
				player2ScoreLongest = vertScore;
			}
			else if ((Board[t][i] == 0) || (Board[t][i] == 10))
			{
				player2ScoreLongest = vertScore;
				vertScore = 0;
			}
			if (player2ScoreLongest >= player2Victory)
			{
				winner = 2;
				gameOver();
			}
		}
		//player2Score = 0;

		//check horizontal
		for (int i = 0; i < x; i++)
		{
			if (Board[i][u] == 11)
			{
				horzScore += 11;
				//cout << "Horizontal Score: " << horzScore << endl;
				player2ScoreLongest = horzScore;
			}
			else if ((Board[i][u] == 0) || (Board[i][u] == 10))
			{
				player2ScoreLongest = horzScore;
				horzScore = 0;
			}
			if (player2ScoreLongest >= player2Victory)
			{
				winner = 2;
				gameOver();
			}
		}
		player2Score = 0;


		//check negative diagonal
		player2Score = 11; //initial spot
		while (Board[h - 1][v - 1] == 11)
		{
			h--;
			v--;
			downScore += 11;
			diagDownScore = downScore;
			//cout << "Down Score: " << downScore << endl;

			if (Board[h - 1][v - 1] != 11 || h == 8) //what if it goes past 9
			{
				diagDownScore = downScore;
				downScore = 0;
				break;
			}
			if (diagDownScore >= player2Victory)
			{
				winner = 2;
				gameOver();
			}
		}

		h = t;
		v = u;

		while (Board[h + 1][v + 1] == 11)
		{
			h++;
			v++;
			upScore += 11;
			diagUpScore = upScore;
			//cout << "Up Score: " << upScore << endl;

			if ((Board[h + 1][v + 1] != 11) || h == 0)
			{
				diagUpScore = upScore;
				upScore = 0;
				break;
			}
			if (diagUpScore >= player2Victory)
			{
				winner = 2;
				gameOver();
			}
		}

		if ((diagUpScore + diagDownScore + player2Score) >= player2Victory)
		{
			winner = 2;
			gameOver();
		}

		//check positive diagonal
		player2Score = 11; //initial spot
		diagDownScore = 0;
		diagUpScore = 0;
		while (Board[h + 1][v - 1] == 11)
		{
			h++;
			v--;
			downScore += 11;
			diagDownScore = downScore;
			//cout << "Down Score: " << downScore << endl;

			if (Board[h + 1][v - 1] != 11 || h == 8) //what if it goes past 9
			{
				diagDownScore = downScore;
				downScore = 0;
				break;
			}
			if (diagDownScore >= player2Victory)
			{
				winner = 2;
				gameOver();
			}
		}

		h = t;
		v = u;

		while (Board[h - 1][v + 1] == 11)
		{
			h--;
			v++;
			upScore += 11;
			diagUpScore = upScore;
			//cout << "Up Score: " << upScore << endl;

			if ((Board[h - 1][v + 1] != 11) || h == 0)
			{
				diagUpScore = upScore;
				upScore = 0;
				break;
			}
			if (diagUpScore >= player2Victory)
			{
				winner = 2;
				gameOver();
			}
		}

		if ((diagUpScore + diagDownScore + player2Score) >= player2Victory)
		{
			winner = 2;
			gameOver();
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return false;
}

void Connect6::gameOver()
{
	cout << "Game Over" << endl
		<< "Player " << winner << " wins!" << endl << endl;
	exit(0);
}

void Connect6::graphics(int t, int u)
{
	string graphic[9][9];
	graphCount = 0;

	system("clear");

	cout << "      0   1   2   3   4   5   6   7   8" << endl
		<< "    |---|---|---|---|---|---|---|---|---|" << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << "  " << graphCount;
		for (int j = 0; j < 9; j++)
		{
			if (Board[j][i] == 0)
			{
				graphic[j][i] = " ";
			}
			else if (Board[j][i] == 10)
			{
				graphic[j][i] = "O";
			}
			else if (Board[j][i] == 11)
			{
				graphic[j][i] = "X";
			}
			cout << " | " << graphic[j][i];
		}
		cout << " |";
		cout << endl << "    |---|---|---|---|---|---|---|---|---|" << endl;

		graphCount++;

	}
	return;
}

bool Connect6::draw()
{
	int spaces = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Board[j][i] == 0)
			{
				spaces++;
			}
		}
	}
	if (spaces == 0)
	{
		cout << "Draw!\n" << "Game Over." << endl << endl;
		exit(0);
	}

	return true;
}
