#ifndef GAME_H_
#define GAME_H_

#include "SmartPlayer.h"

#include <conio.h>
#include <windows.h>

class Game{
public:
	bool isOpen;
	char pressedKey;
	GameMap map;
	SmartPlayer player;
public:
	Game();	//init
	void handleEvent();	//events
	void update();	//update
	void render();	//draw the screen
	void runLoop();

	void updateAI();

	void nextMap(unsigned walls);
	void coin();
};


#endif /* GAME_H_ */
