#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

//Initialization
char Stone[5][5];
int P1_Wins = 0, P2_Wins = 0;
int Row, Col, Missing = 0;
bool P1 = true, Game = true, Win = false, Restart = true;
int c = 0;
bool Exit=false;
string Player1, Player2;

int main() {
	//Creating Profile of the Players
	cout << "Player 1 Enter your name: "; cin >> Player1;
	cout << "Player 2 Enter your name: "; cin >> Player2;

	//Restart Loop
	while (Game) {
		//Creating Stones
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				Stone[i][j] = '*';
		
		
		//GameLoop
		while (Game&&!Exit) {
			system("cls");
			//Printing Leader Board
			cout << "~~~~~~~~~~~LeaderBoard~~~~~~~~~~~" << endl << Player1<<" Victories" << "  |||  " << Player2<<" Victories" << endl << "      " << P1_Wins << "                          " << P2_Wins << endl<<"---------------------------------" << endl<<endl;
			
			//Printing Stones
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					cout << " " << Stone[i][j] << " ";
				}	cout << endl;
			}

			//Player's 'Turn
			if (P1)cout << Player1;
			else cout << Player2;
			cout << " Enter Row Number: "; cin >> Row; 

			//Checking Stones Left in the row
			Missing = 5;
			for (int i = 0; Stone[Row - 1][i] == '*' && i < 5; i++)--Missing;

			cout << "Enter Col Number: "; cin >> Col; Col += Missing;
			if (Row > 5 || Row < 1 || Col>5 || Col < 1) {
				cout << "~~~~~~ Invalid Input Detected ~~~~~~" << endl; P1 = !P1; cout << "Press ESC to Exit or Enter to Continue" << endl;
				if(_getch()==27)
					Exit=true;
			}
			else {
				for (int i = 4, j = 0; j < Col && i >= 0; i--, j++)
					Stone[Row - 1][i] = ' ';
			}
			P1 = !P1;

			//Win Check
			Win = true;
			c = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (Stone[i][j] == ' ')
						c++;
					if (c >= 24) {
						Win = true; Game = false; P1 = !P1;
					}
					else Win = false;
				}
			}
			
		}
		Restart = false;
		if (!Game) {
			if (P1) {
				cout << endl << Player1 << " Won!!!";
				P1_Wins++;
			}
			else {
				cout << endl << Player2 << " Won!!!";
				P2_Wins++;
			}
		}
		else if (Exit) {
			cout << endl << "You chose to end the game in between!!!"<<endl;
		}
		//Game Restart Menu
		cout << "Press SPACEBAR to restart the game"<<endl;
		if (_getch() == 32) {
			Game = true; Exit = false; 
			//This decides Player's turn based on the number of game
			if ((P1_Wins + P2_Wins) % 2 == 0)
				P1 = true;
			else
				P1 = false;
		}
	}



	return 0;
}