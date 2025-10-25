#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef enum
{
    PX,
    P0,
} Player;

typedef enum
{
    PXW,
    P0W,
    DRAW,
    NONE,
} Winner;

void drawBoard(char board[3][3]);
void takeTurn(Player turn, int *x, int *y);
void updateTakeAndTurn(char board[3][3], Player *turn, int x, int y);
int calculateWinner(char board[3][3]);

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
        updateTakeAndTurn(board, &turn, x, y);
        int gameRunning = calculateWinner(board);
        if (!gameRunning)
        {
            turn = PX;
            board[0][0] = ' ';
            board[0][1] = ' ';
            board[0][2] = ' ';
            board[1][0] = ' ';
            board[1][1] = ' ';
            board[1][2] = ' ';
            board[2][0] = ' ';
            board[2][1] = ' ';
            board[2][2] = ' ';
        }

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

void updateTakeAndTurn(char board[3][3], Player *turn, int x, int y)
{
    char player = *turn == PX ? 'X' : '0';
    int isValid = board[x][y] == ' ' && x < 3 && y < 3;
    if (!isValid)
    {
        printf("!!! Invalid Move !!!\n");
        sleep(2);
    }
    else
    {
        board[x][y] = player;
        *turn = *turn == PX ? P0 : PX;
    }
}

int calculateWinner(char board[3][3])
{
    int gameRunning = 1;
    Winner winner = NONE;

    for (int i = 0; i < 3; i++)
    {

        if (((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) && board[i][0] != ' ')
        {

            gameRunning = 0;
            winner = board[i][0] == 'X' ? PXW : P0W;
        }

        if (((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) && board[0][i] != ' ')
        {
            gameRunning = 0;
            winner = board[0][i] == 'X' ? PXW : P0W;
        }
    }

    if (winner != NONE)
    {
        if (winner == DRAW)
        {
            printf("\n\n!!! It's a Draw !!!\n\n");
        }
        else
        {
            printf("\n\n!!! The Winner is: %s !!!\n\n", winner == PXW ? "X" : "0");
        }

        sleep(3);
    }
    return gameRunning;
}