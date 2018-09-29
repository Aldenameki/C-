#include "Application.h"

Application::Application(){
	stateID = STATE_NULL;
	nextState = STATE_MENU;

	window.create(sf::VideoMode(600,400), "Car Game", sf::Style::Close);
	window.setFramerateLimit(30);

	runLoop();
}

void Application::runLoop(){
	while(window.isOpen())
	{
		changeState();
		currentState->handleEvents();
		currentState->update();
		currentState->render();
	}
}

void Application::changeState(){
	if(nextState != STATE_NULL){
		if(stateID != STATE_NULL)
			delete currentState;

		switch( nextState ){
			case STATE_MENU:
				currentState = new Menu(&window, &nextState);
				break;
			case STATE_GAME:
				currentState = new Game(&window, &nextState);
				break;
		}

		stateID = nextState;
		nextState = STATE_NULL;
	}
}
