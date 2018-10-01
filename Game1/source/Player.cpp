#include "Player.h"

Player::Player(){
	row=1;
	col=1;
	score=0;
}

bool Player::moveTest(char nextGround){
	if(nextGround=='0'){
		return 1;
	}
	else if(nextGround=='1'){
		return 0;
	}
	else if(nextGround=='2'){
		score++;
		return 1;
	}

	return 0;
}

void Player::moveUp(Map map){
	if(moveTest(map.getCell(row-1, col)))
		row--;
}

void Player::moveDown(Map map){
	if(moveTest(map.getCell(row+1, col)))
		row++;
}

void Player::moveLeft(Map map){
	if(moveTest(map.getCell(row, col-1)))
		col--;
}

void Player::moveRight(Map map){
	if(moveTest(map.getCell(row, col+1)))
		col++;
}
