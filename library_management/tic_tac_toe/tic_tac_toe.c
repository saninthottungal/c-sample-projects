#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef enum
{
    PX,
    P0,
} Player;

void drawBoard(char board[3][3]);
void takeTurn(Player turn, int *x, int *y);
void validateTake(char board[3][3], int x, int y);

int main()
{
    Player turn = PX;
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    while (1)
    {
        int x = 0, y = 0;
        drawBoard(board);

        takeTurn(turn, &x, &y);
        validateTake(board, x, y);
        system("clear");
    }

    return 0;
}

void drawBoard(char board[3][3])
{

    printf("\nTic-Tac-Toe\n\n");

    for (int i = 0; i < 3; i++)
    {
        if (i != 0)
        {
            printf("\n-----------\n");
        }

        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
            {
                printf("|");
            }
        }
    }

    printf("\n\n");
}

void takeTurn(Player turn, int *x, int *y)
{
    char player = turn == PX ? 'X' : '0';
    int n1, n2;

    printf("turn of %c, play! (1-3)(1-3): ", player);
    scanf("%d %d", &n1, &n2);
    *x = n1 - 1;
    *y = n2 - 1;
}

void validateTake(char board[3][3], int x, int y)
{
    int isValid = board[x][y] == ' ' && x < 3 && y < 3;
    if (!isValid)
    {
        printf("!!! Not a valid Move !!!\n");
        sleep(2);
    }
}