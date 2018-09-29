#ifndef GAME_H_
#define GAME_H_

#include "GameState.h"

class Game: public GameState {
public:

public:
	Game(sf::RenderWindow* Window, unsigned int* NextState);
	void handleEvents();
	void update();
	void render();
};


#endif /* GAME_H_ */
