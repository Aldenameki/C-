#include "Canvas.h"

Canvas::Canvas(){
	canvas = NULL;
}

Canvas::Canvas(Vector2ui CanvasSize){
	create(CanvasSize);
}

Canvas::~Canvas(){
	delete canvas;
}

void Canvas::create(Vector2ui CanvasSize){
	canvasSize = CanvasSize;
	canvas = new char*[canvasSize.y];
	for(unsigned int i=0; i<canvasSize.y; i++)
		canvas[i] = new char[canvasSize.x];

	clear();
}

void Canvas::setCamera(Vector2i a, Vector2i b){
	cameraRect.a = a;
	cameraRect.b = b;
}

void Canvas::setCamera(Recti rectangle){
	cameraRect = rectangle;
}

void Canvas::camera(Vector2i position, Vector2i cameraSize){
	if(cameraSize.x%2){	//x impar
		if(cameraSize.y%2){	//y impar

		} else {	//y par

		}
	} else {	//x par
		if(cameraSize.x%2){	//y impar

		} else {	//y par

		}
	}
	setCamera(Vector2i(0,0), Vector2i(0,0));
}

Vector2ui Canvas::getCanvasSize(){
	return canvasSize;
}

Recti Canvas::getCamera(){
	return cameraRect;
}

char Canvas::getPixel(int x, int y){
	return canvas[(canvasSize.y-1)-y][x];
}

char Canvas::getPixel(Vector2i pixel){
	return canvas[(canvasSize.y-1)-pixel.y][pixel.x];
}

void Canvas::pixel(char character, int x, int y){
	if(0<=x && x<(int)canvasSize.x && 0<=y && y<(int)canvasSize.y)
		canvas[(canvasSize.y-1)-y][x] = character;
}

void Canvas::pixel(char character, Vector2i position){
	if(0<=position.x && position.x<(int)canvasSize.x && 0<=position.y && position.y<(int)canvasSize.y)
		canvas[(canvasSize.y-1)-position.y][position.x] = character;
}

void Canvas::clear(){
	for(unsigned int i=0; i<canvasSize.y; i++){
		for(unsigned int j=0; j<canvasSize.x; j++){
			canvas[i][j] = '0';
		}
	}
}

void Canvas::render(){
	std::string rendered;
		for(unsigned int i=0; i<canvasSize.y; i++){
			for(unsigned int j=0; j<canvasSize.x; j++){
				//rendered += canvas[i][j];
				if(canvas[i][j]=='0'){
					rendered += '.';
				} else {
					rendered += canvas[i][j];
				}
			}
			rendered += '\n';
		}
	//clear screen
	std::cout << rendered;
}
