#include "Matrix.h"

//Matrix fuctions
Matrix::Matrix(unsigned int row_, unsigned int col_){
	srand(time(NULL));

	row = row_;
	col = col_;
	matrix = new float*[row]; for(unsigned int i=0; i<row; i++) matrix[i] = new float[col];
	//Reset the matrix;
	for(unsigned int i=0; i<row; i++){
		for(unsigned int j=0; j<col; j++){
			matrix[i][j] = 0;
		}
	}
}

void Matrix::sum(float a){
	for(unsigned int i=0; i<row; i++){
		for(unsigned int j=0; j<col; j++){
			matrix[i][j] += a;
		}
	}
}

void Matrix::sum(Matrix a){
	if(row != a.row || col != a.col){
		std::cout << "\nInvalid sum o matrix, the number of rows and columns of the two matrix need to be the same.\n";
	} else {
		for(unsigned int i=0; i<row; i++){
			for(unsigned int j=0; j<col; j++){
				matrix[i][j] += a.matrix[i][j];
			}
		}
	}
}

void Matrix::sum(Matrix* a){
	if(row != a->row || col != a->col){
		std::cout << "\nInvalid sum o matrix, the number of rows and columns of the two matrix need to be the same.\n";
	} else {
		for(unsigned int i=0; i<row; i++){
			for(unsigned int j=0; j<col; j++){
				matrix[i][j] += a->matrix[i][j];
			}
		}
	}
}

void Matrix::multiply(float a){
	for(unsigned int i=0; i<row; i++){
		for(unsigned int j=0; j<col; j++){
			matrix[i][j] *= a;
		}
	}
}

void Matrix::multiply(Matrix a){
	if(col != a.row ){
		std::cout << "\nInvalid matrix multiply, colums of matrix one needs to match raws of matrix two.\n";
	} else {
		unsigned int row_ = row;
		unsigned int col_ = a.col;
		unsigned int num = col;

		Matrix result(row_,col_);

		for(unsigned int i=0; i<row_; i++){
			for(unsigned int j=0; j<col_; j++){

				for(unsigned int k=0; k<num; k++){
					result.matrix[i][j] += matrix[i][k] * a.matrix[k][j];
				}

			}
		}

		//copy like: this = result;
		this->matrix = result.matrix;
		this->row = result.row;
		this->col = result.col;
	}
}

void Matrix::multiply(Matrix* a){
	if(col != a->row ){
		std::cout << "\nInvalid matrix multiply, colums of matrix one needs to match raws of matrix two.\n";
	} else {
		unsigned int row_ = row;
		unsigned int col_ = a->col;
		unsigned int num = col;

		Matrix result(row_,col_);

		for(unsigned int i=0; i<row_; i++){
			for(unsigned int j=0; j<col_; j++){

				for(unsigned int k=0; k<num; k++){
					result.matrix[i][j] += matrix[i][k] * a->matrix[k][j];
				}

			}
		}

		//copy like: this = result;
		this->matrix = result.matrix;
		this->row = result.row;
		this->col = result.col;
	}
}

void Matrix::map(float (*func)(float n)){
	for(unsigned int i=0; i<row; i++){
		for(unsigned int j=0; j<col; j++){
			matrix[i][j] = (*func)(matrix[i][j]);
		}
	}
}

void Matrix::transpose(){
	Matrix result(col,row);

	for(unsigned int i=0; i<row; i++){
		for(unsigned int j=0; j<col; j++){
			result.matrix[j][i] = matrix[i][j];
		}
	}

	//copy like: this = result;
	this->matrix = result.matrix;
	this->row = result.row;
	this->col = result.col;
}

void Matrix::randomize(int min, int max){
	if(max<min){
		std::cout << "\nInvalid values to randomize(min, max) function.\n";
	} else {
		for(unsigned int i=0; i<row; i++){
			for(unsigned int j=0; j<col; j++){
				matrix[i][j] = rand()%(max-min+1) + min;
			}
		}
	}
}

void Matrix::randomizef(float min, float max){
	if(max<min){
		std::cout << "\nInvalid values to randomize(min, max) function.\n";
	} else {
		unsigned int decimal = 3;
		unsigned int num = 1;
		for(unsigned int i=0; i<decimal; i++)
			num *= 10;
		min *= num;
		max *= num;
		for(unsigned int i=0; i<row; i++){
			for(unsigned int j=0; j<col; j++){
				matrix[i][j] = (rand()%(int)(max-min+1) + min)/num;
			}
		}
	}
}

void Matrix::push_back(){
	float** container = matrix;
	row++;

	matrix = new float*[row]; for(unsigned int i=0; i<row; i++) matrix[i] = new float[col];
	//Copy the matrix;
	for(unsigned int i=0; i<row-1; i++){
		for(unsigned int j=0; j<col; j++){
			matrix[i][j] = container[i][j];
		}
	}
	//clean last row
	for(unsigned int i=0; i<col; i++)
		matrix[row-1][i] = 0;
}

void Matrix::pop_back(){
	float** container = matrix;
	row--;

	matrix = new float*[row]; for(unsigned int i=0; i<row; i++) matrix[i] = new float[col];
	//Copy the matrix;
	for(unsigned int i=0; i<row; i++){
		for(unsigned int j=0; j<col; j++){
			matrix[i][j] = container[i][j];
		}
	}
}

void Matrix::show(){
	for(unsigned int i=0; i<row; i++){
		for(unsigned int j=0; j<col; j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

//utility funtions-----------------------------

Matrix* sum(Matrix* a, Matrix* b){
	Matrix* result = new Matrix(a->row,a->col);
	if(a->row != b->row || a->col != b->col){
		std::cout << "\nInvalid sum o matrix, the number of rows and columns of the two matrix need to be the same.\n";
	} else {
		for(unsigned int i=0; i<a->row; i++){
			for(unsigned int j=0; j<a->col; j++){
				result->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
			}
		}
	}
	return result;
}

Matrix* multiply(Matrix* a, Matrix* b){
	unsigned int row_ = a->row;
	unsigned int col_ = b->col;
	unsigned int num = a->col;
	Matrix* result = new Matrix(row_,col_);

	if(a->col != b->row ){
		std::cout << "\nInvalid matrix multiply, colums of matrix one needs to match raws of matrix two.\n";
	}

	for(unsigned int i=0; i<row_; i++){
		for(unsigned int j=0; j<col_; j++){

			for(unsigned int k=0; k<num; k++){
				result->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
			}

		}
	}

	return result;
}

float** toArray(Matrix* matrix){
	return matrix->matrix;
}

int randi(int min, int max){
	return rand()%(max-min+1)+min;
}

int randli(int min, int max){
	return (rand()*rand())%(max-min+1)+min;
}

float randf(float min, float max){
	float decimal = 100;
	return ((rand()%(int)((max-min)*decimal))/decimal)+min;
}

float randlf(float min, float max){
	float decimal = 100;
	return (((rand()*rand())%(int)((max-min)*decimal))/decimal)+min;
}
