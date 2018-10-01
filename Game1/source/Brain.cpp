#include "Brain.h"

Brain::Brain(unsigned int layers_, ...){
	if(layers_<3){	//error
		std::cout << "\nInvalid number of layers, minimun 3.\n";
	} else {
		layers = new unsigned int[layers_];

		//Cria as Layers
		va_list ap;
		va_start(ap, layers_);
		for(unsigned int i=0; i<layers_; i++){
			unsigned int num = va_arg(ap,int);
			layers[i] = num;
			//layer[i] = Matrix(num,1);
			layer.push_back(new Matrix(num,1));
		}

		//Cria os weight
		for(unsigned int i=0; i<layers_-1; i++){
			unsigned int current = layers[i];
			unsigned int next = layers[i+1];
			//weight[i] = Matrix(next,current);
			weight.push_back(new Matrix(next,current));
		}

		//Cria bias
		for(unsigned int i=1; i<layers_; i++){
			bias.push_back(new Matrix(layers[i],1));
		}

	}
}

void Brain::setBias(float bias_){
	for(unsigned int i=0; i<bias.size(); i++){
		bias[i]->sum(bias_);
	}
}

void Brain::randomizeBias(float min, float max){
	for(unsigned int i=0; i<bias.size(); i++){
		for(unsigned int j=0; j<bias[i]->row; j++){
			bias[i]->matrix[j][0] = randi(min,max);
		}
	}
}

void Brain::randomizeBiasLayer(float min, float max){
	for(unsigned int i=0; i<bias.size(); i++){
		bias[i]->sum(randi(min,max));
	}
}

void Brain::randomizeWeight(float min, float max){
	for(unsigned int i=0; i<weight.size(); i++){
		weight[i]->randomizef(min,max);
	}
}

void Brain::feedForward(){
	for(unsigned int i=0; i<layer.size()-1; i++){
		layer[i+1] = multiply(weight[i],layer[i]);
		layer[i+1]->sum(bias[i]);
		layer[i+1]->map(sigmoid); //activation function
	}
}

void Brain::input(float input[]){
	//copy matrix
	for(unsigned int i=0; i<layer[0]->row; i++){
		layer[0]->matrix[i][0] = input[i];
	}
	//process
	feedForward();
}

void Brain::input(float input[][1]){
	//if((sizeof(input)/sizeof(input[0]))==layer[0]->col){
		//copy matrix
		for(unsigned int i=0; i<layer[0]->row; i++){
			layer[0]->matrix[i][0] = input[i][0];
		}
		//process
		feedForward();

	/*} else {
		std::cout << "\nInvalid input matrix.\n";
	}*/
}

void Brain::input(Matrix input){
	if(input.row == layer[0]->row && input.col == layer[0]->col){
		//copy matrix
		for(unsigned int i=0; i<layer[0]->row; i++){
			for(unsigned int j=0; j<layer[0]->col; j++){
				layer[0]->matrix[i][j] = input.matrix[i][j];
			}
		}
		//process
		feedForward();

	} else {
		std::cout << "\nInvalid input matrix.\n";
	}
}

void Brain::input(Matrix* input){
	if(input->row == layer[0]->row && input->col == layer[0]->col){
		layer[0] = input;
		feedForward();
	} else {
		std::cout << "\nInvalid input matrix.\n";
	}
}

Matrix* Brain::output(){
	return layer[layer.size()-1];
}

void Brain::mutate(float rate, float step){
	for(unsigned int i=0; i<weight.size(); i++){
		for(unsigned int j=0; j<weight[i]->row; j++){
			for(unsigned int k=0; k<weight[i]->col; k++){
						if(rand()%(int)(100/rate)==0){
							if(rand()%2==1)
								step = -step;
							weight[i]->matrix[j][k] += step;
						}
			}
		}
	}
}

void Brain::crossingover(Brain& a, Brain& b){
	for(unsigned int i=0; i<weight.size(); i++){
		for(unsigned int j=0; j<weight[i]->row; j++){
			for(unsigned int k=0; k<weight[i]->col; k++){
						if(rand()%2==1){
							weight[i]->matrix[j][k] = a.weight[i]->matrix[j][k];
						} else {
							weight[i]->matrix[j][k] = b.weight[i]->matrix[j][k];
						}
			}
		}
	}
}

void Brain::crossingover(Brain* a, Brain* b){
	for(unsigned int i=0; i<weight.size(); i++){
		for(unsigned int j=0; j<weight[i]->row; j++){
			for(unsigned int k=0; k<weight[i]->col; k++){
						if(rand()%2==1){
							weight[i]->matrix[j][k] = a->weight[i]->matrix[j][k];
						} else {
							weight[i]->matrix[j][k] = b->weight[i]->matrix[j][k];
						}
			}
		}
	}
}

//Activation Functions-----------------------

float sigmoid(float n){
	return 1/(1+powf(2.71828182846,-n));
}

//Utility Functions--------------------------

float error(float goal, float score){
	if(1-(score/goal)<0.1) //mínimo
		return 0.1;
	return 1-(score/goal);
}
