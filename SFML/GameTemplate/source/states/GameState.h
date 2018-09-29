#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <SFML/Graphics.hpp>

enum GameStates{
	STATE_NULL,
	STATE_MENU,
	STATE_GAME
};

class GameState{
public:
	sf::RenderWindow* window;	//screen
	sf::Event event;	//events
	unsigned int* nextState;	//change the main state

	virtual ~GameState(){};
	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	void setNextState(unsigned int next_state){*nextState = next_state;}
};


#endif /* GAMESTATE_H_ */
