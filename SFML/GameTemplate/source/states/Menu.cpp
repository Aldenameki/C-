#include "Menu.h"

Menu::Menu(sf::RenderWindow* Window, unsigned int* NextState):
	b1("Hello World", 40, sf::Vector2f(200/2,28/2)),
	scene(sf::Vector2f(600,400))
{
	window = &*Window;
	nextState = &*NextState;

	sf::Vector2u teste = window->getSize();
	std::cout << teste.x << " - " << teste.y << '\n';

	b1.setTexture("texture/images.jpg");


}

void Menu::handleEvents(){
	while(window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			setNextState(STATE_GAME);

		if(b1.isLeftButtonPressed(window))
			setNextState(STATE_GAME);

	}
}

void Menu::update(){

}

void Menu::render(){
	window->clear(sf::Color(0,100,255));
		scene.draw(window);
		b1.draw(window);
	window->display();
}
