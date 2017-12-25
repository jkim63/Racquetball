//Project: Racquetball
//Joo Yun (Rosa) Kim

//#include "gfxnew.h"
#include <iostream>
#include "pong.h"
#include <time.h>
#include <cmath>
#include <unistd.h>
#include <cstdlib>

using namespace std;

#define PI 3.14

pong::pong(int posX, int posY)
{
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
	direction = STOP;
}

void pong::Reset()
{
	x = originalX;
	y = originalY;
	direction = STOP;
}

void pong::changeDirection(dir d)
{
	direction = d;
}

void pong::randomDirection() 
{
	direction = (dir)((rand() % 6) +1);
}

int pong::getX() { return x; }

int pong::getY() { return y; }

dir pong::getDirection() { return direction; }

void pong::moveBall()
{
	switch (direction) 
	{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--; 
			y--;
			break;
		case DOWNLEFT:
			x--;
			y++;
			break;
		case UPRIGHT:
			x++;
			y--;
			break;
		case DOWNRIGHT: 
			x++;
			y++;
			break;
		default:
			break;
	}
}

paddle::paddle() { x=0; y=0; }

paddle::paddle(int posX, int posY)
{
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
}

void paddle::Reset()
{
	x = originalX;
	y = originalY;
}

int paddle::getX() { return x; }

int paddle::getY() { return y; }

void paddle::moveUp() { y--; }

void paddle::moveDown() { y++; }

game::game(int w, int h)
{
	srand(time(NULL));
	quit = false;
	up = 'w';
	down = 's';
	score = 0;
	width = w; height = h;
	ball = new pong(w/2, h/2);
	user = new paddle(1, h/2);
}

game::~game() { delete ball, user; }

void game::draw()
{
	system("clear");
	cout << "STARTING" << endl;
	for (int i=0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int ballX = ball->getX();
			int ballY = ball->getY();
			int userX = user->getX();
			int userY = user->getY();

			if (j == 0)
				cout << "#";

			if (ballX == j && ballY == i)
				cout << "O";
			else if (userX == j && userY == i)
				cout << "|";
			else if (userX == j && userY + 1 == i)
				cout << "|";
			else if (userX == j && userY + 2 == i)
				cout << "|";
			else if (userX == j && userY + 3 == i)
				cout << "|";
			else cout << " ";

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i=0; i < width + 2; i++)
		cout << "#";
	cout << endl;
}

void game::userInput()
{
	ball->moveBall();

	int ballX = ball->getX();
	int ballY = ball->getY();
	int userX = user->getX();
	int userY = user->getY();

	char move;
	cin >> move;
	if (move == up)
		if (userY > 0)
			user->moveUp();
	if (move == down){
		if (userY +4 < height)
			user->moveDown();

	if (ball->getDirection() == STOP)
		ball->randomDirection();

	if (move == 'q')
		quit = true;
}

void game::Logic()
{
	int ballX = ball->getX();
	int ballY = ball->getY();
	int userX = user->getX();
	int userY = user->getY();

	//Paddle
	for (int i=0; i<4; i++) {
		if (ballX == userX + 1){
			if (ballY == userY + i) {
				ball->changeDirection((dir)((rand() % 3) + 4));
			}
		}
	}

	//Right wall
	for (int i=0; i<4; i++) {
		if (ballX == width - 1){
			if (ballY == width + i) {
				ball->changeDirection((dir)((rand() % 3) + 4));
			}
		}
	}

	//Bottom
	if (ballY == height -1) 
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

	//Top
	if (ballY == 0) 
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
}

void game::run()
