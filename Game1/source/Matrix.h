#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <stdlib.h> //rand()
#include <time.h> //time()
#include <typeinfo> //typeid

class Matrix{
public:
	float** matrix;
	unsigned int row;
	unsigned int col;

public:
	Matrix(unsigned int row_, unsigned int col_);
	void sum(float a);
	void sum(Matrix a);
	void sum(Matrix* a);
	void multiply(float a);
	void multiply(Matrix a);
	void multiply(Matrix* a);
	void map(float (*func)(float n));
	void transpose();
	void randomize(int min, int max);
	void randomizef(float min, float max);
	void push_back();
	void pop_back();
	void show();
};

Matrix* sum(Matrix* a, Matrix* b);
Matrix* multiply(Matrix* a, Matrix* b);
float** toArray(Matrix* matrix);
int randi(int min, int max);
int randli(int min, int max);
float randf(float min, float max);
float randlf(float min, float max);

#endif /* MATRIX_H_ */
