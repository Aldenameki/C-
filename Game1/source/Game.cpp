#include "Game.h"

Game::Game(){
	isOpen=1;
	pressedKey='n';

	randSeed();
	map.create(10,10);
	/*if(!map.loadMap("../maps/map2.txt"))
		isOpen=0;*/

	map.randomWall(8);
	map.newCoin();

	render();
	runLoop();
}

void Game::handleEvent(){	//user input
	pressedKey = getch();

	if(pressedKey=='w'){
		player.moveUp(map);
	}
	else if(pressedKey=='s'){
		player.moveDown(map);
	}
	else if(pressedKey=='a'){
		player.moveLeft(map);
	}
	else if(pressedKey=='d'){
		player.moveRight(map);
	}
	else if(pressedKey==27){
		isOpen=0;
	}
}

void Game::update(){	//game processing
	coin();
}

void Game::render(){	//graphics
	std::string data;

		data += "score " + cString(player.score) + '\n';
		data += "coin " + cString(map.getCoin().y) + ' ' + cString(map.getCoin().x) + '\n';

		for(unsigned int i=0; i<map.getRow(); i++){
			for(unsigned int j=0; j<map.getCol(i); j++){
				//data += map.getMap(i,j);
				if(player.row == i && player.col == j){	//player
					data += (char)2;
				}
				else if(map.getCell(i,j) == '0'){	//air
					data += (char)255;
				}
				else if(map.getCell(i,j) == '1'){	//wall
					data += (char)219;
				}
				else if(map.getCell(i,j) == '2'){	//coin
					data += (char)206;
				}
			}
			data += '\n';
		}

	system("cls");
	std::cout << data;
}

void Game::runLoop(){
	while(isOpen){
		handleEvent();
		update();
		render();
	}
}


void updateAI(){

}


void Game::nextMap(unsigned int walls){
	map.setMap('0');
	map.randomWall(walls);
	map.newCoin();
}

void Game::coin(){
	if(map.getCell(player.row, player.col) == '2'){
		map.setCell('0', player.row, player.col);
		nextMap(5);
	}
}
