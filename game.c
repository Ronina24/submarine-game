#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check.h"
#include "game.h"
#include "board.h"

int getFromPlayer(char player[][10], int p)
{
    char act[3], col;
    FILE *f;
    if (f == NULL)
    {
        exit(0);
    }
    f = fopen("Result.txt", "a");
    int row, count = 0, play = 1;
    if (p == 1)
        play = 2;
    do
    {
        /*gets moves from player*/
        printf("\nPlayer_%d - make your move > ", play);
        fflush(stdin);
        scanf("%s", act);
        row = action(act);
    } while (row == 0);
    col = *act;
    count = move(col, row, player, p, 2);
    fclose(f);
    return count;
}

int action(char act[])
{
    char col, temp;
    int row, len = strlen(act);
    col = *act++;
    if (checkCol(col) == 0)
    {
        return 0;
    }
    temp = *act++;
    if ((row = checkRow(temp)) == 0)
    {
        return 0;
    }
    temp = *act++;
    if (len != 2)
    {
        if (row == 1)
        {
            if (temp == '0')
            {
                row = 10;
                temp = *act++;
            }
            else
                row = checkRow(0);
        }
        else{
        printf("Wrong format of cell, try again\n");
        return 0;
        }
    }
 
    return row;
}

int automatic(char player1[][10], char player2[][10])
{
    FILE *fMove = NULL;
    char movements[20];
    char col, movem[4], player[12], temp;
    int row, p, count1 = 0, count2 = 0;
    printf("\nplease enter movements file name> ");
    scanf("%s", movements);
    fMove = fopen(movements, "r");
    if (checkauto(fMove)==0)
    {
        exit(1);
        }
        rewind(fMove);
    while (fscanf(fMove, "%s %s", player, movem) == 2)
    {
        if (strcmp(player, "PLAYER_1") == 0)
            p = 2;
      else  if (strcmp(player, "PLAYER_2") == 0)
            p = 1;
        else if (strcmp(player,"PRINT_BOARD")==0)
         return 3;
        else {
            printf("Wrong format of player name");
        exit(1);
        }
        col = *movem;
       
        if (checkCol(col) == 0)
            exit(1);
        temp = movem[1];
        if ((row = checkRow(temp)) == 0)
            exit(1);
        temp = movem[2];
        if (row == 1 && temp == '0' && movem[3]==0)
            row = 10;
        else if(movem[2]!=0)
        {
        printf("\nWrong format of cells");
        exit(1);
        }

        if (p == 2)
        {
            count1 = count1 + move(col, row, player2, p, 1);
        }

        if (p == 1)
        {
            count2 = count2 + move(col, row, player1, p, 1);
        }
        if (count1 == 10)
            return 1; //returns num of player that won
        else if (count2 == 10)
            return 2;
    }
        fclose(fMove);
}
