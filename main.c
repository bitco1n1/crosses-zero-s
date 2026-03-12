#include <stdio.h>
#include <windows.h>

char field[3][3] =
{
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' }
};

typedef unsigned char bool;
#define TRUE 1
#define FALSE 0

void showField();
void getInput();
bool isGameOver();
void showFinalMessage();

char winner = ' ';

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (1)
    {
        while (1)
        {
            showField();

            if (isGameOver())
            {
                showFinalMessage();

                printf("\nPress Enter to exit...");
                getchar();
                getchar();

                return 0;
            }

            getInput();
        }
    }
    return 0;
}

void showField()
{
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("| ");
        for (int b = 0; b < 3; b++)
        {
            printf("%c | ", field[i][b]);
        }
        printf("\n-------------\n");
    }
}

void getInput()
{
    static char lastMotion = 'X';
    int motion;
    int y, x;

    switch (lastMotion)
    {
        case 'X':
        {
            printf("X (Crosses) enter your move: ");
            break;
        }
        case 'O':
        {
            printf("O (Noughts) enter your move: ");
            break;
        }
    }

    if (scanf("%d", &motion) != 1)
    {
        while (getchar() != '\n')
        {
        }
        getInput();
        return;
    }

    y = (motion % 10) - 1;
    x = (motion / 10) - 1;

    if (y > 2 || x > 2 || x < 0 || y < 0 || field[x][y] != ' ')
    {
        getInput();
    }
    else
    {
        field[x][y] = lastMotion;
        switch (lastMotion)
        {
            case 'X':
            {
                lastMotion = 'O';
                break;
            }
            case 'O':
            {
                lastMotion = 'X';
                break;
            }
        }
    }
}

bool isGameOver()
{
    for (int i = 0; i < 3; i++)
    {
        if (field[i][0] != ' ' && field[i][0] == field[i][1] && field[i][0] == field[i][2])
        {
            winner = field[i][0];
            return TRUE;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (field[0][i] != ' ' && field[0][i] == field[1][i] && field[0][i] == field[2][i])
        {
            winner = field[0][i];
            return TRUE;
        }
    }

    if (field[0][0] != ' ' && field[0][0] == field[1][1] && field[1][1] == field[2][2])
    {
        winner = field[0][0];
        return TRUE;
    }

    if (field[0][2] != ' ' && field[0][2] == field[1][1] && field[1][1] == field[2][0])
    {
        winner = field[0][2];
        return TRUE;
    }

    bool full = TRUE;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] == ' ')
            {
                full = FALSE;
            }
        }
    }

    if (full)
    {
        winner = 'D';
        return TRUE;
    }

    return FALSE;
}

void showFinalMessage()
{
    if (winner == 'X')
    {
        printf("Crosses win!\n");
    }
    else if (winner == 'O')
    {
        printf("Noughts win!\n");
    }
    else if (winner == 'D')
    {
        printf("It's a draw!\n");
    }
}