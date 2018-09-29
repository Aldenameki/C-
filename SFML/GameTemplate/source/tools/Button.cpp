#include "Button.h"

Button::Button(){

}

Button::Button(std::string Text, unsigned int size){
	setFont("font/Arial/arial.ttf");
	setText(Text);
	setSize(size);
}

Button::Button(std::string Text, unsigned int size, sf::Vector2f position){
	setFont("font/Arial/arial.ttf");

	setText(Text);
	setSize(size);
	setOriginMiddle();
	setOriginEdge();
	setPosition(position);

	/*sf::FloatRect box(text.getLocalBounds());
	std::cout << "text x: " << text.getPosition().x << '\n';
	std::cout << "text y: " << text.getPosition().y << '\n';
	std::cout << "box left:" << box.left << '\n';
	std::cout << "box top:" << box.top << '\n';
	std::cout << "box width:" << box.width << '\n';
	std::cout << "box height:" << box.height << '\n';*/
}

void Button::setText(std::string Text){
	text.setString(Text);
	fixButton();
}

void Button::setSize(unsigned int size){
	text.setCharacterSize(size);
	fixButton();
}

void Button::setFont(std::string path){
	font.loadFromFile(path);
	text.setFont(font);
}

void Button::setTextOutline(sf::Color color, float thickness){
	text.setOutlineColor(color);
	text.setOutlineThickness(thickness);
}

void Button::setButtonOutline(sf::Color color, float thickness){
	rect.setOutlineColor(color);
	rect.setOutlineThickness(thickness);
}

void Button::setPosition(sf::Vector2f position){
	text.setPosition(position);
	rect.setPosition(position);
}

void Button::setPosition(float x, float y){
	text.setPosition(x,y);
	rect.setPosition(x,y);
}

void Button::setOriginEdge(){
	sf::FloatRect box(text.getLocalBounds());
	text.setOrigin(box.left, box.top);
	rect.setOrigin(0,0);
}

void Button::setOriginMiddle(){
	sf::FloatRect box(text.getLocalBounds());
	text.setOrigin(box.left+box.width/2, box.top+box.height/2);
	rect.setOrigin(rect.getSize().x/2,rect.getSize().y/2);
}

void Button::setTexture(std::string path){
	texture.loadFromFile(path);
	rect.setTexture(&texture);
}

void Button::setButtomColor(sf::Color normal, sf::Color mouseOver){
	rect.setFillColor(normal);
}

sf::Vector2f Button::getPosition(){
	return rect.getPosition();
}

bool Button::isLeftButtonPressed(sf::RenderWindow* window){	//change text.getGlobalBounds() change rect.getGlobalBounds()
	return (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::FloatRect(text.getGlobalBounds()).contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y));
}

bool Button::isRightButtonPressed(sf::RenderWindow* window){	//change text.getGlobalBounds() change rect.getGlobalBounds()
	return (sf::Mouse::isButtonPressed(sf::Mouse::Right) && sf::FloatRect(text.getGlobalBounds()).contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y));
}

bool Button::isMiddleButtonPressed(sf::RenderWindow* window){	//change text.getGlobalBounds() change rect.getGlobalBounds()
	return (sf::Mouse::isButtonPressed(sf::Mouse::Middle) && sf::FloatRect(text.getGlobalBounds()).contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y));
}

void Button::draw(sf::RenderWindow* window){
	window->draw(rect);
	window->draw(text);
}

void Button::fixButton(){
	rect.setSize(sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height));
}
