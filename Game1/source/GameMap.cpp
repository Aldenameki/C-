#include "GameMap.h"

void GameMap::newCoin(){
	unsigned int row, col;
	for(unsigned int i=getRow()*getCol(0); i>0; i--){
		row = randui(0, getRow()-1);
		col = randui(0, getCol(0)-1);
		if(getCell(row, col)=='0'){
			setCell('2', row, col);
			coin.x=col;
			coin.y=row;
			break;
		}
	}
}

void GameMap::randomWall(unsigned int walls){
	setMap('0');

	for(unsigned int i=0; i<walls; i++){
		unsigned int row, col;
		for(unsigned int j=getRow()*getCol(0); j>0; j--){
			row = randui(0, getRow()-1);
			col = randui(0, getCol(0)-1);
			if(getCell(row, col)=='0'){
				setCell('1', row, col);
				break;
			}
		}
	}
}

Vector2ui GameMap::getCoin(){
	return coin;
}
