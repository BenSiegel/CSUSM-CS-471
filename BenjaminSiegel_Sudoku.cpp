#include <iostream>
#include "BenjaminSiegel_Sudoku.h"
using namespace std;

int board[9][9];
int row[9][9] = {{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9}};
int col[9][9] = {{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9}};
int box[9][9] = {{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9}};

bool checkSize = false;
bool checkPreset = true;
bool r = false;
bool c = false;
bool b = false;
int RowNum, ColNum; 
int BoxNum1, BoxNum2, BoxNum3, BoxNum4, BoxNum5, BoxNum6, BoxNum7, BoxNum8, BoxNum9;

//start menu- goes to start the game
void Sudoku::start()
{
	int choice = 0;
	cout << "Welcome to Sudoku!" << endl
		<< "To play:\n"
		<< ">Fill out the board completely.\n"
		<< ">Each row, column, and box may only contain 1-9." << endl;
	cout << "Select 1 to start a new game or 2 to quit" << endl;
	cin >> choice;
	
	switch(choice)
	{
		case 1: initboard();
			break;
		case 2: 
		default: cout << "Good bye." << endl;
	}
}

/*
Initalizes board to contain preset numbers
and sets up the domain
*/
void Sudoku::initboard()
{
	int temp = 0;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			board[i][j] = 0;
		}
	}
	//hard coding preset numbers on the board
	board[0][0] = 2;
	board[0][2] = 3;
	board[0][3] = 7;
	board[0][8] = 8;
	
	board[1][0] = 7;
	board[1][1] = 4;
	board[1][2] = 9;
	board[1][4] = 5;
	board[1][5] = 8;
	board[1][6] = 1;		

	board[2][0] = 8;
	board[2][5] = 2;
	board[2][6] = 7;
	board[2][7] = 9;
	board[2][8] = 4;
	
	board[3][2] = 4;
	board[3][4] = 8;
	board[3][5] = 7;
	board[3][8] = 9;
	
	board[4][1] = 2;
	board[4][2] = 8;
	board[4][3] = 3;
	board[4][5] = 1;
	board[4][6] = 6;
	board[4][7] = 4;
	
	board[5][0] = 1;
	board[5][2] = 7;
	board[5][6] = 8;
	board[5][7] = 5;
	board[5][8] = 3;
	
	board[6][0] = 3;
	board[6][1] = 8;
	board[6][5] = 4;
	board[6][8] = 6;
		
	board[7][0] = 4;
	board[7][3] = 9;
	board[7][4] = 7;
	board[7][5] = 5;
	board[7][6] = 3;
	board[7][8] = 1;
		
	board[8][0] = 9;
	board[8][1] = 7;
	board[8][5] = 3;
	board[8][6] = 4;
	board[8][8] = 5;
	
	for(int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(board[i][j] != 0)
			{
				temp = board[i][j];
				row[i][temp - 1] = 0;
				col[j][temp - 1] = 0;
				
				//box1
				if(i == 0 || i == 1 || i == 2)
				{
					if(j == 0 || j == 1 || j == 2)
					{
						if(board[i][j] != 0)
						{
							box[0][temp - 1] = 0;
						}
					}
				}
				//box2
				if(i == 0 || i == 1 || i == 2)
				{
					if(j == 3 || j == 4 || j == 5)
					{
						if(board[i][j] != 0)
						{
							box[1][temp - 1] = 0;
						}	
					}
				}
				//box3
				if(i == 0 || i == 1 || i == 2)
				{
					if(j == 6 || j == 7 || j == 8)
					{
						if(board[i][j] != 0)
						{
							box[2][temp - 1] = 0;
						}
						
					}
				}
				//box4
				if(i == 3 || i == 4 || i == 5)
				{
					if(j == 0 || j == 1 || j == 2)
					{
						if(board[i][j] != 0)
						{
							box[3][temp - 1] = 0;
						}
					}
				}
				//box5
				if(i == 3 || i == 4 || i == 5)
				{
					if(j == 3 || j == 4 || j == 5)
					{
						if(board[i][j] != 0)
						{
							box[4][temp - 1] = 0;
						}
					}
				}
				//box6
				if(i == 3 || i == 4 || i == 5)
				{
					if(j == 6 || j == 7 || j == 8)
					{
						if(board[i][j] != 0)
						{
							box[5][temp - 1] = 0;
						}
					}
				}
				//box7
				if(i == 6 || i == 7 || i == 8)
				{
					if(j == 0 || j == 1 || j == 2)
					{
						if(board[i][j] != 0)
						{
							box[6][temp - 1] = 0;
						}
					}
				}
				//box8
				if(i == 6 || i == 7 || i == 8)
				{
					if(j == 3 || j == 4 || j == 5)
					{		
						if(board[i][j] != 0)
						{
							box[7][temp -1] = 0;
						}
					}
				}
				//box9	
				if(i == 6 || i == 7 || i == 8)
				{
					if(j == 6 || j == 7 || j != 0)
					{
						if(board[i][j] != 0)
						{
							box[8][temp - 1] = 0;
						}
					}
				}
			}//end of if statement
		}
	}
	
	displayBoard();
	
	inputsNumbers();
}	

/*
Recursively called function to take inputs from the user
Calls updateArray to update the domains,
spotCheck for valid locations,
and numberCheck to make sure the number is valid	
*/
void Sudoku::inputsNumbers()
{
	int a, b, c, ans;
	
	cout << "Please enter a location on the field: \n>Row: ";
	cin >> a;
	cout << ">Column: ";
	cin >> b;
	
	updateArray(a, b);
	
	if(!spotCheck(a, b))
	{
		do
		{
			cout << "Invalid location. Re-enter. \n>Row: ";
			cin >> a;
			cout << ">Column: ";
			cin >> b;
		}while(!spotCheck(a, b));
	}
		
	cout << "Please enter a value: \n>Value: ";
	cin >> c;
	
	if(!numberCheck(a, b, c))
	{
		do
		{
			cout << "Invalid number. 1 to Re-enter or 2 for new location? \n>";
			cin >> ans;
			if(ans == 1)
			{
				cout << ">Value: ";
				cin >> c;
			}
			else if(ans == 2)
			{
				inputsNumbers();
			}
			else
			{
				cout << "Invalid input." << endl;
				inputsNumbers();
			}
		}while(!numberCheck(a, b, c));
	}
	
	board[a][b] = c;
	
	displayBoard();	
	
	while(!gameOver())
	{
		inputsNumbers();
	}
}

/*
Updates the domains under this condition:
If a user places a number in x,y then later changes the number
in x,y the original number that was placed there has
to go back to the domain. This in done here. 
*/
bool Sudoku::updateArray(int t, int u)
{
	RowNum = board[t][u];
	if(board[t][u] != 0)
	{
		row[t][RowNum - 1] = RowNum;
		r = true;
	}

	ColNum = board[t][u];
	if(board[t][u] != 0)
	{
		col[u][ColNum - 1] = ColNum;
		c = true;
	}
	
	BoxNum1 = board[t][u];
	if(t == 0 || t == 1 || t == 2)
	{
		if(u == 0 || u == 1 || u == 2)
		{
			if(board[t][u] != 0)
			{
				box[0][BoxNum1 - 1] = BoxNum2;
				b = true;
			}
		}
	}
	//box2
	BoxNum2 = board[t][u];
	if(t == 0 || t == 1 || t == 2)
	{
		if(u == 3 || u == 4 || u == 5)
		{
			if(board[t][u] != 0)
			{
				box[1][BoxNum2 - 1] = BoxNum2;
				b = true;
			}
		}
	}
	//box3
	BoxNum3 = board[t][u];
	if(t == 0 || t == 1 || t == 2)
	{
		if(u == 6 || u == 7 || u == 8)
		{
			if(board[t][u] != 0)
			{
				box[2][BoxNum3 - 1] = BoxNum3;
				b = true;
			}
		}
	}
	//box4
	BoxNum4 = board[t][u];
	if(t == 3 || t == 4 || t == 5)
	{
		if(u == 0 || u == 1 || u == 2)
		{
			if(board[t][u] != 0)
			{
				box[3][BoxNum4 - 1] = BoxNum4;
				b = true;
			}
		}
	}
	//box5
	BoxNum5 = board[t][u];
	if(t == 3 || t == 4 || t == 5)
	{
		if(u == 3 || u == 4 || u == 5)
		{
			if(board[t][u] != 0)
			{
				box[4][BoxNum5 - 1] = BoxNum5;
				b = true;
			}
		}
	}
	//box6
	BoxNum6 = board[t][u];
	if(t == 3 || t == 4 || t == 5)
	{
		if(u == 6 || u == 7 || u == 8)
		{
			if(board[t][u] != 0)
			{
				box[5][BoxNum6 - 1] = BoxNum6;
				b = true;
			}
		}
	}
	//box7
	BoxNum7 = board[t][u];
	if(t == 6 || t == 7 || t == 8)
	{
		if(u == 0 || u == 1 || u == 2)
		{
			if(board[t][u] != 0)
			{
				box[6][BoxNum7 - 1] = BoxNum7;
				b = true;
			}
		}
	}
	//box8
	BoxNum8 = board[t][u];
	if(t == 6 || t == 7 || t == 8)
	{
		if(u == 3 || u == 4 || u == 5)
		{
			if(board[t][u] != 0)
			{
				box[7][BoxNum8 - 1] = BoxNum8;
				b = true;
			}
		}
	}
	//box9	
	BoxNum9 = board[t][u];
	if(t == 6 || t == 7 || t == 8)
	{
		if(u == 6 || u == 7 || u == 8)
		{
			if(board[t][u] != 0)
			{
				box[8][BoxNum9 - 1] = BoxNum9;
				b = true;
			}
		}
	}
	if(c == true && r == true && b == true)
	{
		return true;
	}
	return false;
}

/*
Checks to see if the location on the board is a valid
location for the user to place a piece.
*/
bool Sudoku::spotCheck(int t, int u)
{
	if (t < 0 || t > 8 || u < 0 || u > 8)
	{
		return false;
	}

	//Location of all of the preset numbers
	if (t == 0 && u == 0 || t == 0 && u == 2 || t == 0 && u == 3 || t == 0 && u == 8 ||
		t == 1 && u == 0 || t == 1 && u == 1 || t == 1 && u == 2 || t == 1 && u == 4 || t == 1 && u == 5 || t == 1 && u == 6 ||
		t == 2 && u == 0 || t == 2 && u == 5 || t == 2 && u == 6 || t == 2 && u == 7 || t == 2 && u == 8 ||
		t == 3 && u == 2 || t == 3 && u == 4 || t == 3 && u == 5 || t == 3 && u == 8 ||
		t == 4 && u == 1 || t == 4 && u == 2 || t == 4 && u == 3 || t == 4 && u == 5 || t == 4 && u == 6 || t == 4 && u == 7 ||
		t == 5 && u == 0 || t == 5 && u == 2 || t == 5 && u == 6 || t == 5 && u == 7 || t == 5 && u == 8 ||
		t == 6 && u == 0 || t == 6 && u == 1 || t == 6 && u == 5 || t == 6 && u == 8 ||
		t == 7 && u == 0 || t == 7 && u == 3 || t == 7 && u == 4 || t == 7 && u == 5 || t == 7 && u == 6 || t == 7 && u == 8 ||
		t == 8 && u == 0 || t == 8 && u == 1 || t == 8 && u == 5 || t == 8 && u == 6 || t == 8 && u == 8)
	{
		return false;
	}
	
	return true;
}

/*
Checks to see if the number is valid.
Uses arc consistency as the algorithm here.
*/
bool Sudoku::numberCheck(int t, int u, int v)
{
	bool vert = false;
	bool horz = false; 
	bool square = false;
	//row	
	for(int i = 0; i < 9; i++)
	{
 		if(row[t][i] == v)
		{
			//temp[t][i] = row[t][i];
			row[t][i] = 0;
			horz = true;
		}
	}//end of row for loop
		
	//col
	for(int i = 0; i < 9; i++)
	{
		if(col[u][i] == v)
		{
			//temp[u][i] = col[u][i];
			col[u][i] = 0;
			vert = true;
		}
	}//end of col for loop
	
	//box1
	
	if(t == 0 || t == 1 || t == 2)
	{
		if(u == 0 || u == 1 || u == 2)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[0][i] == v)
				{
					box[0][i] = 0;
					square = true;
				}
			}
		}
	}
	//box2
	if(t == 0 || t == 1 || t == 2)
	{
		if(u == 3 || u == 4 || u == 5)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[1][i] == v)
				{
					box[1][i] = 0;
					square = true;
				}
			}
		}
	}
	//box3
	if(t == 0 || t == 1 || t == 2)
	{
		if(u == 6 || u == 7 || u == 8)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[2][i] == v)
				{
					box[2][i] = 0;
					square = true;
				}
			}
		}
	}
	//box4
	if(t == 3 || t == 4 || t == 5)
	{
		if(u == 0 || u == 1 || u == 2)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[3][i] == v)
				{
					box[3][i] = 0;
					square = true;
				}
			}
		}
	}
	//box5
	if(t == 3 || t == 4 || t == 5)
	{
		if(u == 3 || u == 4 || u == 5)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[4][i] == v)
				{
					box[4][i] = 0;
					square = true;
				}
			}
		}
	}
	//box6
	if(t == 3 || t == 4 || t == 5)
	{
		if(u == 6 || u == 7 || u == 8)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[5][i] == v)
				{
					box[5][i] = 0;
					square = true;
				}
			}
		}
	}
	//box7
	if(t == 6 || t == 7 || t == 8)
	{
		if(u == 0 || u == 1 || u == 2)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[6][i] == v)
				{
					box[6][i] = 0;
					square = true;
				}
			}
		}
	}
	//box8
	if(t == 6 || t == 7 || t == 8)
	{
		if(u == 3 || u == 4 || u == 5)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[7][i] == v)
				{
					box[7][i] = 0;
					square = true;
				}
			}
		}
	}
	//box9	
	if(t == 6 || t == 7 || t == 8)
	{
		if(u == 6 || u == 7 || u == 8)
		{
			for(int i = 0; i < 9; i++)
			{
				if(box[8][i] == v)
				{
					box[8][i] = 0;
					square = true;
				}
			}
		}
	}

	if(vert == true && horz == true) //&& square == true)
	{
		return true;
	}
	return false;
}

//Draw function
void Sudoku::displayBoard()
{
	int e = 1, f = 1;
	int graphic[9][9];
	int graphCount = 0;
	system("clear");
	cout << "     0 1 2   3 4 5    6 7 8" << endl
		<< "    ------------------------" << endl;
	
	for (int i = 0; i < 9; i++)
	{
		cout << graphCount << " | ";

		for(int j = 0; j < 9; j++)
		{
			if(board[i][j] == 0)
			{
				graphic[i][j] = 0;
			}
			else
			{
				graphic[i][j] = board[i][j];
			}
		
			cout << " " << graphic[i][j];
			if(e % 3 == 0)
			{
				cout << "  |";
			}
			e++;
		}
	
	cout << endl;
	if(f % 3 == 0)
		{
			cout << "   --------------------------" << endl;
		}

	graphCount++;
	f++;
	}
	
	/*
	//Not needed, checks to see if the domains are working correctly
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cout << row[i][j] << " ";
		}	
		cout << endl;
	}
	*/
	return;
}

//End game function check
bool Sudoku::gameOver()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(board[i][j] == 0)
			{
				return false;
			}
		}
	}
	cout << "You win! Game over!" << endl;
	return true;
}
