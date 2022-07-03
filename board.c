#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check.h"
#include "board.h"
#include "game.h"
struct Submarine
{
    int size;
    char **sub;
    int isDestroyed;
};
submarine arrP1[10] = {0};
submarine arrP2[10] = {0};
submarine *createSub(int size)
{
    submarine *SUB;
    SUB = (submarine *)malloc(sizeof(submarine));
    if (SUB == NULL)
    {
        printf("EROOR");
        return NULL;
    }
    SUB->size = size;
    SUB->sub = (char **)malloc(size * sizeof(char *));
    if (SUB->sub == NULL)
    {
        printf("EROOR");
        return NULL;
    }
    SUB->isDestroyed = 0;
    return SUB;
}

void block(int colS, int colE, int rowS, int rowE, char player[][10], int dire)
{
    int i, j;
    if (dire == 1)
    {
        if (rowS > 1)
        {
            i = rowS - 2;
            player[i][colS] = '!';
        }
        else
            i = rowS - 1;
        if (rowE < 10)
        {
            j = rowE;
            player[j][colS] = '!';
        }
        else
            j = rowE - 1;
        for (i; i <= j; i++)
        {
            if (colE < 9)
                player[i][colS + 1] = '!';
            if (colS > 0)
                player[i][colS - 1] = '!';
        }
    }
    else
    {
        if (colS > 0)
        {
            i = colS - 1;
            player[rowS - 1][i] = '!';
        }
        else
            i = colS;
        if (colE < 9)
        {
            j = colE + 1;
            player[rowS - 1][j] = '!';
        }
        else
            j = colE;
        for (i; i <= j; i++)
        {
            if (rowS > 1)
                player[rowS - 2][i] = '!';
            if (rowE < 10)
                player[rowS][i] = '!';
        }
    }
}

void fillBoard(char colS, char colE, int rowS, int rowE, char player[][10], int p)
{
    int size, dire,tmp;
    static int count = 0;
    char temp;
    submarine *SUB;
    dire = direction(colS, colE, rowS, rowE);
    if (dire == 1)
    {

        size = rowE - rowS + 1;
        fflush(stdin);
        SUB = createSub(size);
        if (SUB == NULL)
        {
            printf("ERROR while creating submarine");
            exit(1);
        }
        for (int i = rowS, j = 0; i <= rowE; i++, j++)
        {
            if (player[i - 1][colS - 'A'] == '*')
            {
                printf("\nERROR: There's already a submarine in %c%d cell\n \t*\tEXIT\t*", colS, i);
                exit(1);
            }
            if (player[i - 1][colS - 'A'] == '!')
            {
                printf("\nERROR: Cannot place submarine in %c%d cell\n \t*\tEXIT\t*", colS, i);
                exit(1);
            }
            player[i - 1][colS - 'A'] = '*';

            SUB->sub[j] = &player[i - 1][colS - 'A'];
        }
        block(colS - 'A', colE - 'A', rowS, rowE, player, dire);
    }
    else
    {
        
        size = colE - colS + 1;
        SUB = createSub(size);
        if (SUB == NULL)
        {
            printf("ERROR while craeting submarine");
            exit(1);
        }
        for (int i = colS - 'A', j = 0; i <= colE - 'A'; i++, j++)
        {
            if (player[rowS - 1][i] == '*')
            {
                printf("\nERROR: There's already a submarine in %c%d cell\n \t*\tEXIT\t*", colS + i, rowS);
                exit(1);
            }
            if (player[rowS - 1][i] == '!')
            {
                printf("\nERROR: Cannot place submarine in %c%d cell\n \t*\tEXIT\t*", colS, i);
                exit(1);
            }
            player[rowS - 1][i] = '*';
            SUB->sub[j] = &player[rowS - 1][i];
        }
        block(colS - 'A', colE - 'A', rowS, rowE, player, dire);
    }
    if (count == 10)
    {
        count = 0;
    }
    if (p == 1)
    {
        arrP1[count] = *SUB;
        count++;
    }
    else
    {
        arrP2[count] = *SUB;
        count++;
    }
}

void initial(char matrix[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = '.';
        }
    }
}
void fromFile(char player[][10], int p)
{
    int numberOfSub[4] = {4, 3, 2, 1}, i, bad_file = 0;
    char array_file[8], colS, colE, file[20];
    FILE *f = NULL;
    do
    {
        scanf("%s", file);
        f = fopen(file, "r");
        if (f == NULL)
        {
            printf("File is empty, try another file> ");
        }
    } while (f == NULL);
    while (fscanf(f, "%s", array_file) >0)
    {
        if (*array_file=='#')
        {
        while (fgetc(f)!='\n');
        continue;
        }
        i = checkFile(array_file, player, p);
        numberOfSub[i - 1]--;
        if (numberOfSub[i - 1] < 0)
        {
            printf("Too many submarines with %d cells", i);
            exit(1);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (numberOfSub[i] > 0)
        {
            printf("Not enough submarines with %d cells\n", 4 - i);
            bad_file++;
        }
    }
    if (bad_file > 0)
        exit(1);

    fclose(f);
    }

int direction(char colS, char colE, int rowS, int rowE)
{
    int horizontal = 0, vertical = 1;
    if (colS == colE)
    {
        return vertical;
    }
    if (rowS = rowE)
    {

        return horizontal;
    }
}

int checkFile(char array_file[], char player[][10], int p)
{
    char colS, colE, sign = '-', temp, coltemp;
    int rowS, rowE, size, rowtemp;
    colS = *array_file++;

    if (checkCol(colS) == 0)
    {
        exit(1);
    }
    temp = *array_file++;
    if ((rowS = checkRow(temp)) == 0)
        exit(1);
    temp = *array_file++;
    if (rowS == 1 && temp == '0')
    {
        rowS = 10;
        temp = *array_file++;
    }

    if (temp != sign)
    {
        printf("\nWrong format of cells");
        exit(1);
    }
    colE = *array_file++;

    if (checkCol(colE) == 0)
    {
        exit(1);
    }
    temp = *array_file++;
    if ((rowE = checkRow(temp)) == 0)
        exit(1);

    temp = *array_file++;
    if (rowE == 1 && temp == '0' && *array_file==0)
    {
        rowE = 10;
    }
    
    else if( temp!=0)
    {
            printf("\nWrong format of cells");
        exit(1);
    }
    

    if (colS == colE)
    {
        if(rowE<rowS)
        {
            rowtemp=rowE;
            rowE=rowS;
            rowS=rowtemp;
        }
        size = rowE - rowS + 1;
    }
    if (rowS == rowE)
    {
        if (colE<colS)
        {
            coltemp= colE;
            colE=colS;
            colS=coltemp;
        }
        size = colE - colS + 1;
    }
    if (size > 4)
    {
        printf("ERROR: There's a submarine with too many cells");
        exit(1);
    }
    fillBoard(colS, colE, rowS, rowE, player, p);

    return size;
}
void print(char player[][10])

{
    printf("\n    A  B  C  D  E  F  G  H  I  J");
    for (int i = 0; i < 10; i++)
    {
        printf("\n");
        printf("%-2d ", i + 1);
        for (int j = 0; j < 10; j++)
        {
           if (player[i][j] == '!')
           player[i][j] = '.';
        
                printf(" %c ", player[i][j]);
        }
    }
}




int move(char col, int row, char player[][10], int p, int gameType)
{
    int destroyed = 0, size;
    FILE *f = NULL;
    char act[3], temp;
    f = fopen("Result.txt", "a");
    if (f == NULL)
    {
        exit(0);
    }
    submarine *array;

    if (p == 1)
    {
        array = arrP1;
    }
    if (p == 2)
    {
        array = arrP2;
    }
    if (player[row - 1][col - 'A'] == 'X')
    {
        do
        {
            p==2 ?  fprintf(f, "player_%d %c%d  ALREADY BEEN HIT\n", 1, col, row) : fprintf(f, "player_%d %c%d  ALREADY BEEN HIT\n", 2, col, row);
            printf("This cell has already been hit > ");
            if (gameType==1)
            return 0;
            do
            {
                char act[8];
                printf("  > try again > ");
                scanf("%s", act);
                col = *act;
                row = action(act);
            } while (row == 0);
        } while (player[row - 1][col - 'A'] == 'X');
    
    }
    if (player[row - 1][col - 'A'] == '*')
    {
        p==2 ? (fprintf(f, "player_%d %c%d  HIT\n", 1, col, row)) : (fprintf(f, "player_%d %c%d  HIT\n", 2, col, row));
        printf(" HIT!\n");
        player[row - 1][col - 'A'] = 'X';
        for (int i = 0; i < 10; i++)
        {
            size = array[i].size;
            if (array[i].isDestroyed == 0)
            {
                int count = 0;
                for (int j = 0; j < size; j++)
                {
                    if (*(array[i].sub[j]) != 'X')
                        continue;
                    else
                        count++;
                    if (count == size)
                    {
                        array[i].isDestroyed = 1;
                        fflush(stdin);
                        printf("*****The submarine was sunk!*****\n");
                        fclose(f);
                        return 1;
                    }
                }
            }
        }
    }
   
    else
    {
       p==2 ?  (fprintf(f, "player_%d %c%d  MISS\n", 1, col, row)) : (fprintf(f, "player_%d %c%d  MISS\n", 2, col, row));
        printf("MISS\n");
    }
    fclose(f);
    return 0;
}
