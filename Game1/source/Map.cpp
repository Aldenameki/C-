#include "Map.h"

Map::Map(){

}

Map::Map(std::string file){
	loadMap(file);
}

bool Map::loadMap(std::string File){
	std::fstream file;
	file.open(File.c_str(), std::fstream::in);
	if(!file.is_open()){
		std::cout << "Error loading map.\n";
		return 0;
	} else {
		while(!file.eof()){
			std::string line;
			getline(file, line);
			push(line);
		}
	}
	return 1;
}

void Map::push(std::string data){
	map.push_back(data);
}

void Map::create(unsigned int rows, unsigned int cols){
	std::string container;

	clear();

	for(unsigned int i=0; i<cols; i++){
		container += '0';
	}
	for(unsigned int i=0; i<rows; i++){
		push(container);
	}
}

void Map::clear(){
	map.clear();
}

unsigned int Map::getRow(){
	return map.size();
}

unsigned int Map::getCol(unsigned int Row){
	if(Row<map.size())
		return map[Row].size();

	return 0;
}

char Map::getCell(unsigned int Row, unsigned int Col){
	if(0<=Row && Row<getRow() && 0<=Col && Col<getCol(Row)){
		return map[Row][Col];	//está dando erro
	}

	return ' ';
}

void Map::setCell(char character, unsigned int Row, unsigned int Col){
	if(Row>=0 && Row<getRow() && Col>=0 && Col<=getCol(Row))
		map[Row][Col] = character;
}

void Map::setMap(char character){
	for(unsigned int i=0; i<getRow(); i++)
		for(unsigned int j=0; j<getCol(i); j++){
			setCell(character, i, j);
		}
}
