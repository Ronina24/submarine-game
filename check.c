#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "check.h"
int checkCol(char col)
{

    if (col < 65 || col > 74)
    {
        printf("WRONG FORMAT OF COLLUMN");
        return 0;
    }
    return 1;
}
int checkRow(char row)
{
    if (row < '1' || row > '9')
    {
        printf("WRONG FORMAT OF ROW");
        return 0;
    }
    return row - 48;
}


int checkauto (FILE *f)
{
    char move1[4],move2[4], player1[9],player2[9],playerA[9], playerB[9];
    if (fscanf(f, "%s %s",player1,move1)==2)
    {
     if (strcmp(player1, "PLAYER_1") == 0)
     {
         strcpy(player1, "PLAYER_1");
         strcpy(player2, "PLAYER_2");
     }
     else  if (strcmp(player1, "PLAYER_2") == 0)
     {
         strcpy(player1, "PLAYER_2");
          strcpy(player2, "PLAYER_1");
     }
    }

     while (fscanf(f, "%s %s",playerA,move2)==2 &&(fscanf(f, "%s %s",playerB,move1)==2))
     {
if ((strcmp(playerA, "PRINT_BOARD")!=0) || (strcmp(playerB, "PRINT_BOARD")!=0))
{
    if ((strcmp(playerA, player2)!=0) || (strcmp(playerB, player1)!=0))
    {printf("MOVEMENTS NOT ACCORDING TO ORDER\n");
    return 0;
    }
}
else return 3;
     }
     return 1;

}
