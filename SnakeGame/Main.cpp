#include "SnakeGame.h"
#include <Windows.h>


int main() 
{
	SnakeGame* snake = new SnakeGame(30, 30, 100);
	snake->Start();
	delete snake;
}