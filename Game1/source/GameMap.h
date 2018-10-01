#ifndef GAMEMAP_H_
#define GAMEMAP_H_

#include "Map.h"
#include "utils.h"
#include "Vector.h"

class GameMap: public Map{
private:
	Vector2ui coin;
public:
	void newCoin();
	void randomWall(unsigned int walls);
	Vector2ui getCoin();
};


#endif /* GAMEMAP_H_ */
