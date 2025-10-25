#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    PX,
    P0,
} Player;

void drawBoard(char board[3][3]);
void takeTurn(Player turn, int *x, int *y);
int validateTake(char board[3][3], int x, int y);

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
        int x = 0, y = 0, isValidMove = 1;
        drawBoard(board);
        if (!isValidMove)
        {
            printf("!!! Not a valid Move !!!\n");
        }

        takeTurn(turn, &x, &y);
        isValidMove = validateTake(board, x, y);
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

    printf("turn of %c, play! (1-3)(1-3): ", player);
    scanf("%d %d", x, y);
}

int validateTake(char board[3][3], int x, int y)
{
    return board[x][y] != ' ';
}