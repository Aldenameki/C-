#include "Game.h"

Game::Game(sf::RenderWindow* Window, unsigned int* NextState){
	window = &*Window;
	nextState = &*NextState;
}

void Game::handleEvents(){
	while(window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			setNextState(STATE_MENU);
	}
}

void Game::update(){

}

void Game::render(){
	window->clear(sf::Color(255,100,0));
		//window draw
	window->display();
}
