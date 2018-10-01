#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameMap.h"

class Player{
public:
	int row, col;
	unsigned int score;
public:
	Player();
	bool moveTest(char nextGround);
	void moveUp(Map map);
	void moveDown(Map map);
	void moveLeft(Map map);
	void moveRight(Map map);
};


#endif /* PLAYER_H_ */
