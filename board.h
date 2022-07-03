#ifndef FUNC_BOARD
#define FUNC_BOARD

typedef struct Submarine submarine;
/*function that initalize creates for each player a matrix and initilize it with dots*/
void initial(char matrix[][10]);
 
/*gets file name, opens file and calls to "checkfile" function*/
void fromFile(char player[][10],int p);

/*check if the subaine spread horizontal (0) or vertical (1) */
int direction (char colS, char colE, int rowS, int rowE);

/*checks file's format*/
int checkFile(char array_file[],char player[][10],int p);

/*prints wanted player board- matrix*/
void print(char player[][10]);

/*fill cells with '*' according to the initilize file*/
void fillBoard(char colS, char colE, int rowS, int rowE, char player[][10],int p);

/*creates submarine struct and allocate memory*/
submarine *createSub(int size);

/*gets cell from "getFromPlayer" function and 
fills in 'X' where submarine's cell is '*' and checks if a whole submarine was sunk*/ 
int move(char col, int row,char player[][10],int p, int gameType);

/*function blocks with '!' the cells around the submarines 
so the player could not place submarines there*/
void block(int colS, int colE, int rowS, int rowE, char player[][10], int dire);


#endif