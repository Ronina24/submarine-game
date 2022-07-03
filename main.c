#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"
#include "game.h"

int main(void)
{
    int p = 1;
    int count1 = 0, count2 = 0;
    char player1[10][10], player2[10][10],game;
    FILE *f;
    f = fopen("Result.txt", "w");
    if (f == NULL)
        exit(0);
    printf ("--------------------------------------------------------------------------------------\n");
    printf ("  XXXXX    XXXX   XXXXXX  XXXXXX  XX      XXXXXX   XXXXX  XX  XX  XX  XXXXx    XXXXX  \n");
	printf ("  XX  XX  XX  XX    XX      XX    XX      XX      XX      XX  XX  XX  XX  XX  XX      \n");
	printf ("  XXXXX   XX  XX    XX      XX    XX      XXXX     XXXX   XXXXXX  XX  XXXXX    XXXX   \n"); 
	printf ("  XX  XX  XXXXXX    XX      XX    XX      XX          XX  XX  XX  XX  XX          XX  \n");
	printf ("  XXXXX   XX  XX    XX      XX    XXXXXX  XXXXXX  XXXXX   XX  XX  XX  XX      XXXXX   \n");
    printf ("--------------------------------------------------------------------------------------\n");

printf("RULES OF THE GAME:\n 1. The game is played turn after turn\n 2. Format of collumns: CAPITAL letters only\n 3. Format of player name: CAPITAL letters only, for example: PLAYER_1\n 4. You must initialize your board with exactly 10 submarines:\n\t4 submarines with 1 cell\n\t3 submarines with 2 cells\n\t2 submarines with 3 cells\n\t1 submarine with 4 cells\n 5. HAVE FUN!\n");
    initial(player1);
    initial(player2);
    printf("SELECT 1 FOR AUTOMATIC GAME OR 2 FOR 1 ON 1 GAME>  ");
    do{
        game= getc(stdin);
    if (game!='2' && game!='1')
    printf("WRONG SELECTION, TRY AGAIN>  ");
    }while (game!='2' && game!='1');
     


    printf("Please enter the file name of player_1 board> ");
    fromFile(player1, 1);
    printf("\nPlease enter the file name of player_2 board> ");
    fromFile(player2, 2);
    if (game=='2')
    {
    while (1)
    {
        count1 = count1 + getFromPlayer(player2, 2);
        printf("");
        if (count2 == 10 || count1 == 10)
            break;
        count2 = count2 + getFromPlayer(player1, 1);
        if (count2 == 10 || count1 == 10)
            break;
    }
    if (count1 < count2)
        p = 2;
    }
    
if (game=='1')
{
p=automatic(player1,player2);
if (p!=2 && p!=1)
{
    if (p==3)
    {
       printf("\nPlayer_1 board:\n");
    print(player1);
    printf("\nPlayer_2 board:\n");
    print(player2);
    }
else{printf("Not enough moves for winning");
return(2);
}
}
}
     
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("  XX       XXX       XX  XX  XXX     XX  \n");
        printf("   XX     XX XX     XX   XX  XX XX   XX  \n");
        printf("    XX   XX   XX   XX    XX  XX  XX  XX  \n");
        printf("     XX XX     XX XX     XX  XX   XX XX  \n");
        printf("      XXX       XXX      XX  XX     XXX  \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("\nWINNER: PLAYER_%d\n", p);
    printf("\nPlayer_1 board:\n");
    print(player1);
    printf("\nPlayer_2 board:\n");
    print(player2);


    




}
