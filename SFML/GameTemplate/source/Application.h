#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "states/Menu.h"
#include "states/Game.h"

class Application{
public:
	unsigned int stateID;	//current state id
	unsigned int nextState;	//next state id
	GameState* currentState;	//load the current screen

	sf::RenderWindow window;
public:
	Application();
	void runLoop();
	void changeState();
};


#endif /* APPLICATION_H_ */
