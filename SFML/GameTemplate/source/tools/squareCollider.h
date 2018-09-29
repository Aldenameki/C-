#ifndef SQUARECOLLIDER_H_
#define SQUARECOLLIDER_H_

#include <SFML/Graphics.hpp>

class squareCollider{
public:

public:
	squareCollider();
	bool pointCollision(sf::Vector2f point);
	bool squareCollision(sf::FloatRect square);
};


#endif /* SQUARECOLLIDER_H_ */
