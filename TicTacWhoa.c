#include <stdio.h>
#include <string.h>
int player =1;
void displayBoard(char TTT[3][3]) { //creates board and assigns array values to positions on the board
	printf("3 _%c_|_%c_|_%c_\n", TTT[0][0], TTT[0][1], TTT[0][2]);
	printf("2 _%c_|_%c_|_%c_\n", TTT[1][0], TTT[1][1], TTT[1][2]);
	printf("1  %c | %c | %c \n", TTT[2][0], TTT[2][1], TTT[2][2]);
	printf("   A   B   C\n");
}
int BoardFull(char TTT[3][3]) { // checks if board if full
	for (int i = 0; i < 3; i++) { //double for loop
		for (int j = 0; j < 3; j++) {
			if (TTT[i][j] == '_' || TTT[i][j] == ' ') { //checks if board still has spaces
				return 0;  // Board is not full
			}
		}
	}
	return 1;  // Board is full
}

void CheckWin(char TTT[3][3]) {
	for (int i = 0; i < 3; i++) {
		if ((TTT[i][0] == 'X' || TTT[i][0] == 'O') && TTT[i][0] == TTT[i][1] && TTT[i][1] == TTT[i][2]) { // checks rows
			displayBoard(TTT);
			printf("Congratulations!!! Player %d has won!!!", player);
			exit(0);
		}
	}
	for (int i = 0; i < 3; i++) {
		if ((TTT[0][i] == 'X' || TTT[0][i] == 'O') && TTT[0][i] == TTT[1][i] && TTT[1][i] == TTT[2][i]) { //checks columns
			displayBoard(TTT);
			printf("Congratulations!!! Player %d has won!!!", player);
			exit(0);
		}
	}
	if ((TTT[0][0] == 'X' || TTT[0][0] == 'O') && TTT[0][0] == TTT[1][1] && TTT[1][1] == TTT[2][2]) { //checks diagonal 1
		displayBoard(TTT);
		printf("Congratulations!!! Player %d has won!!!", player);
		exit(0);
	}


	if ((TTT[0][2] == 'X' || TTT[0][2] == 'O') && TTT[0][2] == TTT[1][1] && TTT[1][1] == TTT[2][0]) { //check diagonal 2
		displayBoard(TTT);
		printf("Congratulations!!! Player %d has won!!!", player);
		exit(0);
	}

}
int main()
{
	char start[20]; //stores user input
	int a=0;
	while(a==0) { //loop for start menu
		printf("Type 'New Game' to start a new game\n"); // start or quit program
		printf("Type 'Quit' to exit program\n");
		scanf("%s", start ); //user input
		if (strcmp(start, "Quit") == 0) {
			printf("Exiting Program\n"); // Matches "Quit"
			break;
		}
		if (strcmp(start,"New")==0) { //compares if string matches to "New Game"
			char game[20];
			scanf("%s", game); // Read next part of the input
			if (strcmp(game, "Game") == 0) {
				a=1;//exits loop
				char TTT[3][3]= {
					{'_', '_', '_'},
					{'_', '_', '_'},
					{' ', ' ', ' '}
				};  // Initialize the board
				printf("type 'quit' for program to quit\n") ;
				while(1) { // infinte loop for moves
					displayBoard(TTT);
					printf("Player %d's Move: ", player); //player input
					char move[5]; //
					scanf("%s", move); // gets input for move
					if (strcmp(move, "quit")==0) { // if move is quit, program exits
						printf("Game ending...");
						exit(0);
					}
					if (move[0] < 'A' || move[0] > 'C' || move[1] < '1' || move[1] > '3') { // checks if move is not enough characters,
						// or uses a letter or number that is not valid
						printf("Invalid move, please specify both column and row.\n");
						continue;
					}
					int col=move[0] - 'A'; // assigns columns to 0, 1, and 2
					int row= '3' - move[1]; // assigns rows to 2,1, and 0

					if ((row<2 && TTT[row][col] != '_') || (row == 2 && TTT[row][col] != ' ')) { // checks if spot is already taken
						printf("Invalid move, spot already taken.\n");
						continue;
					}
					if (player==1) { //code for player 1 turn
						TTT[row][col]='X'; //places X
						CheckWin(TTT); //goes to check Win function
						if (BoardFull(TTT)) { //checks if Board is Full
							displayBoard(TTT);
							printf("It is a Draw\n");
							exit(0);
						}
						player++; // increments to player 2
					}
					else if (player ==2) { // code for player 2 turn
						TTT[row][col]='O'; //places O
						CheckWin(TTT); //checkWin function
						if (BoardFull(TTT)) { // checks if board is full
							displayBoard(TTT);
							printf("It is a Draw\n");
							exit(0);
						}
						player--; //decrements to player 1
					}

				}
			}
		}
		else {
			printf("Invalid input\n"); // if not new game or quit, invalid input
		}
	}
}