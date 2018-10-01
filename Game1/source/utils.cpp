#include "utils.h"

std::string cString(int num){
	std::stringstream ss;
	ss << num;
	return ss.str();
}

std::string cString(unsigned int num){
	std::stringstream ss;
	ss << num;
	return ss.str();
}

void randSeed(){
	srand(time(NULL));
}

/*int randi(int min, int max){	//já existe na Matrix.h
	return min+(rand()%(max+1-min));
}*/

unsigned int randui(unsigned int min, unsigned int max){
	return min+(rand()%(max+1-min));
}
