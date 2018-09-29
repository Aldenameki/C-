#ifndef BRAIN_H_
#define BRAIN_H_

#include "Matrix.h"
#include <vector>
#include <stdarg.h> //Variadic Function
#include <math.h>

class Brain{
public:
	unsigned int* layers;
	std::vector<Matrix*> layer;
	std::vector<Matrix*> weight;
	std::vector<Matrix*> bias;

public:
	Brain(unsigned int layers, ...);
	void setBias(float bias_);
	void randomizeBias(float min, float max);
	void randomizeBiasLayer(float min, float max);
	void randomizeWeight(float min, float max);
	void feedForward();
	void input(float input[]);
	void input(float input[][1]);
	void input(Matrix input);
	void input(Matrix* input);
	Matrix* output();
	void mutate(float rate, float step);
	void crossingover(Brain& a, Brain& b);
	void crossingover(Brain* a, Brain* b);
};

//Activation Functions-----------------------

float sigmoid(float n);

//Utility Functions--------------------------

float error(float goal, float score);

#endif /* BRAIN_H_ */
