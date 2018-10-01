#ifndef SMARTPLAYER_H_
#define SMARTPLAYER_H_

#include "Player.h"
#include "Brain.h"

class SmartPlayer: public Player{
private:
	Brain brain;
public:
	SmartPlayer();
	void think();
};


#endif /* SMARTPLAYER_H_ */
