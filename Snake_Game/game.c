#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

bool gameOver;
bool gamePaused;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tailLength;
enum eDirection dir;

// 장애물 좌표
int obstacleX[] = { 5, 10, 15 };
int obstacleY[] = { 7, 12, 17 };
int numObstacles = 3;

void Setup()
{
    gameOver = false;
    gamePaused = false;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    score = 0;
    tailLength = 0;

    // 먹이의 초기 위치 설정
    bool validPosition = false;
    while (!validPosition)
    {
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;

        // 장애물과 겹치지 않는지, 뱀과 겹치지 않는지 검사
        if (!isObstacle(fruitX, fruitY) && !(fruitX == x && fruitY == y))
            validPosition = true;
    }

    // 장애물의 초기 위치 설정
    for (int i = 0; i < numObstacles; i++)
    {
        validPosition = false;
        while (!validPosition)
        {
            obstacleX[i] = rand() % WIDTH;
            obstacleY[i] = rand() % HEIGHT;

            // 뱀과 겹치지 않는지 검사
            if (!(obstacleX[i] == x && obstacleY[i] == y))
                validPosition = true;
        }
    }
}





bool isObstacle(int posX, int posY)
{
    for (int i = 0; i < numObstacles; i++)
    {
        if (obstacleX[i] == posX && obstacleY[i] == posY)
            return true;
    }
    return false;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
                printf("O");
            else if (isObstacle(j, i))
                printf("#");
            else if (i == fruitY && j == fruitX && !isObstacle(j, i))
                printf("F");
            else
            {
                bool printTail = false;
                for (int k = 0; k < tailLength; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        printf("o");
                        printTail = true;
                    }
                }
                if (!printTail)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);

    if (gamePaused)
    {
        printf("\n--- 게임 일시 정지 ---\n");
        printf("나가시겠습니까?\n");
        printf("1. 예\n");
        printf("2. 아니오\n");
    }
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'p':
            if (gamePaused)
                gamePaused = false;
            else
                gamePaused = true;
            break;
        case '1':
            gameOver = true;
            break;
        case 27: // ESC 키
            gamePaused = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < tailLength; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    // 벽과의 충돌 검사
    if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
        gameOver = true;

    // 장애물과의 충돌 검사
    if (isObstacle(x, y))
        gameOver = true;

    for (int i = 0; i < tailLength; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY && !isObstacle(x, y))
    {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        tailLength++;
    }

    // 게임 종료 처리
    if (gameOver)
    {
        // 게임 종료 시 추가 동작을 수행할 수 있습니다.
        // 예를 들어, 최종 점수를 저장하거나 게임 종료 메시지를 출력할 수 있습니다.
    }
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void PauseGame()
{
    printf("\n--- 게임 일시 정지 ---\n");
    printf("나가시겠습니까?\n");
    printf("1. 예\n");
    printf("2. 아니오\n");

    char key;
    while (gamePaused)
    {
        if (_kbhit())
        {
            key = _getch();
            if (key == '1')
            {
                gameOver = true;
                gamePaused = false;
            }
            else if (key == '2')
            {
                gamePaused = false;
            }
        }
    }
}
