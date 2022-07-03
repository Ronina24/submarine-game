#ifndef CHECK
#define CHECK
/*if collumn format (A-J) okay returns 1' else returns 0*/
int checkCol(char col);

/*if row format (1-10) okay returns row, else returns 0*/
int checkRow(char row);

/*checks if the moves in movements file are turn by turn*/
int checkauto (FILE *f);

#endif