#include <stdio.h>
#include <windows.h>

char field[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

typedef unsigned char bool;
#define TRUE 1
#define FALSE 0

void showField();
void getInput();
bool isGameOver();
void showFinalMessage();

char winner;
bool game_over = FALSE;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (1) {
        showField();
        while (1)
        {
            if (game_over) {
                showFinalMessage();

                printf("\nPress Enter to exit...");
                getchar();          
                getchar();          

                return 0;
            }

            getInput();

            if (isGameOver()) {
                game_over = TRUE;
                showField();
            }
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
    if (game_over) return;

    static char lastMotion = 'X';
    int motion;
    int y;
    int x;

    switch (lastMotion)
    {
    case 'X':
        printf("X (Crosses) enter your move: ");
        scanf("%d", &motion);
        y = (motion % 10) - 1;
        x = (motion / 10) - 1;
        if (y > 2 || x > 2 || x < 0 || y < 0)
            getInput();
        else
        {
            if (field[x][y] == ' ')
            {
                field[x][y] = 'X';
                showField();
            }
            else
            {
                getInput();
            }
        }
        lastMotion = 'O';
        break;
    case 'O':
        printf("O (Noughts) enter your move: ");
        scanf("%d", &motion);
        y = (motion % 10) - 1;
        x = (motion / 10) - 1;
        if (y > 2 || x > 2 || x < 0 || y < 0)
            getInput();
        else
        {
            if (field[x][y] == ' ')
            {
                field[x][y] = 'O';
                showField();
            }
            else
            {
                getInput();
            }
        }
        lastMotion = 'X';
        break;
    }
}

bool isGameOver()
{
    if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][0] != ' ') || 
        (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[0][0] != ' ') || 
        (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][0] != ' ') || 
        (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][0] != ' ') || 
        (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[0][1] != ' ') || 
        (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[0][2] != ' ') || 
        (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != ' ') || 
        (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] != ' '))
    {
        winner = field[0][0];
        return TRUE;
    }

    if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][0] == 'X') || 
        (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[0][0] == 'X') || 
        (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][0] == 'X') || 
        (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][0] == 'X') || 
        (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[0][1] == 'X') || 
        (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[0][2] == 'X') || 
        (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'X') || 
        (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'X'))
    {
        winner = 'X';
        return TRUE;
    }

    if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][0] == 'O') || 
        (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[0][0] == 'O') || 
        (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][0] == 'O') || 
        (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][0] == 'O') || 
        (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[0][1] == 'O') || 
        (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[0][2] == 'O') || 
        (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'O') || 
        (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'O'))
    {
        winner = 'O';
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
    else
    {
        printf("Noughts win!\n");
    }
}