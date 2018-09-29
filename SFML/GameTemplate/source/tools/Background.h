#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.hpp>
#include <iostream>

class Background{
public:
	unsigned int sprites;	//numbers of vertical or horizontal consecutives sprites
	sf::Vector2f size;
	sf::Sprite background;
	sf::Texture texture;
public:
	Background();
	Background(sf::Vector2f Size);
	Background(sf::Vector2u Size);
	~Background();
	void setSize(sf::Vector2f Size);
	void Fullscreen();	//scale to cover the screen, but don't the aspect ratio
	void MaintainAspectRatio();	//scale the screen size, but keeping the aspect ratio
	sf::Vector2f getSize();
	unsigned int getSprites();
	void move(float x, float y);	//move all sprites at once, animating and repeating reaching the end
	void move(sf::Vector2f speed);
	void draw(sf::RenderWindow* window);
};


#endif /* BACKGROUND_H_ */

/* FUNTIONS
 * Static image
 * Animated Image (Gif)
 * Dinamic images (Moving with depth levels, a tree move faster than a montain, and the scenery repeats)
 */
