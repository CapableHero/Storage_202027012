#include "game.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    HideCursor();

    Setup();

    while (!gameOver)
    {
        if (!gamePaused)
        {
            Draw();
            Input();
            Logic();
            Sleep(40); // 0.1초 대기 (게임 속도 조절)
        }
        else
        {
            Draw();
            if (_kbhit())
            {
                char key = _getch();
                if (key == '1')
                    gameOver = true;
                else if (key == '2')
                    gamePaused = false;
            }
        }
    }

    printf("Game Over!\n");
    printf("Final Score: %d\n", score);

    return 0;
}
