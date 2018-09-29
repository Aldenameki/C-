#ifndef MENU_H_
#define MENU_H_

#include "../tools/Button.h"
#include "../tools/Background.h"
#include "GameState.h"

class Menu: public GameState {
public:
	//sf::RectangleShape rect;
	Button b1;
	Background scene;
public:
	Menu(sf::RenderWindow* Window, unsigned int* NextState);
	void handleEvents();
	void update();
	void render();
};


#endif /* MENU_H_ */
