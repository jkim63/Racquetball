//Project: Racquetball
//Joo Yun (Rosa) Kim

#include <iostream>
#include <time.h>
#include <cmath>
#include <unistd.h>
#include <cstdlib>

using namespace std;

enum dir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class Racquetball {
	public:
		Racquetball(int posX, int posY);
		void Reset();
		void changeDirection(dir d);
		void randomDirection();
		int getX();
		int getY();
		dir getDirection();
		void moveBall();
	private:
		int x, y;
		int originalX, originalY;
		dir direction;
};

class racquet {
	public:
		racquet();
		racquet(int posX, int posY);
		void Reset();
		int getX();
		int getY();
		void moveUp();
		void moveDown();
	private:
		int x, y;
		int originalX, originalY;
};

class game {
	public:
		game(int w, int h);
		~game();
		void draw();
		void userInput();
		void rules();
		void run();
	private:
		int width, height;
		int score;
		char up, down, stay;
		bool quit;
		Racquetball *ball;
		racquet *user;
};
