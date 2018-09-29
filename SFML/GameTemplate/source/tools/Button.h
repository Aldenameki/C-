#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.hpp>
#include <iostream>

class Button{
public:
	sf::RectangleShape rect;
	sf::Text text;
	sf::Font font;
	sf::Texture texture;
public:
	Button();
	Button(std::string text, unsigned int size);
	Button(std::string Text, unsigned int size, sf::Vector2f position);
	void setText(std::string Text);
	void setSize(unsigned int size);
	void setFont(std::string path);
	void setTextOutline(sf::Color color, float thickness);
	void setButtonOutline(sf::Color color, float thickness);
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setOriginEdge();
	void setOriginMiddle();
	void setTexture(std::string path);
	void setButtomColor(sf::Color normal, sf::Color mouseOver);
	sf::Vector2f getPosition();
	bool isLeftButtonPressed(sf::RenderWindow* window);
	bool isRightButtonPressed(sf::RenderWindow* window);
	bool isMiddleButtonPressed(sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);
	void fixButton();	//fix the button size and position in relation to the text
};


#endif /* BUTTON_H_ */
