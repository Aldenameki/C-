#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <vector>
#include <fstream>

class Map{
private:
	std::vector<std::string> map;
public:
	Map();
	Map(std::string file);
	bool loadMap(std::string File);
	void push(std::string data);
	void create(unsigned int rows, unsigned int cols);
	void clear();
	unsigned int getRow();
	unsigned int getCol(unsigned int Row);
	char getCell(unsigned int Row, unsigned int Col);
	void setCell(char character, unsigned int Row, unsigned int Col);
	void setMap(char character);
};


#endif /* MAP_H_ */
