#include <stdio.h>

void drawBoard(char board[3][3]);

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    drawBoard(board);

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
