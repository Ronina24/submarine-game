#ifndef FUNC_GAME
#define FUNC_GAME

/*asks from player to enter a cell and calls to "action" function to make sure the move fits the format 
after it calls "move" function*/
int getFromPlayer(char player[][10], int p);

/*checks if the action that the player entered is okay and returns row*/
int action (char act[]);

/*gets file that contains the moves of the game and, sends the moves to "move" function
and returns the number of the player that won*/
int automatic(char player1[][10], char player2[][10]);

#endif