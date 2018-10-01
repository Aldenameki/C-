#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

std::string cString(int num);
std::string cString(unsigned int num);
void randSeed();
//int randi(int min, int max);
unsigned int randui(unsigned int min, unsigned int max);

#endif /* UTILS_H_ */
