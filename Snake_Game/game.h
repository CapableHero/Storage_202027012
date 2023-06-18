#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#define WIDTH 20
#define HEIGHT 20

extern bool gameOver;
extern bool gamePaused;
extern int x, y, fruitX, fruitY, score;
extern int tailX[100], tailY[100];
extern int tailLength;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
extern enum eDirection dir;

void Setup();
bool isObstacle(int posX, int posY);

void Draw();
void Input();
void Logic();
void HideCursor();
void PauseGame();

#endif
