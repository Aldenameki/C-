#ifndef CANVAS_H_
#define CANVAS_H_

#include <iostream>
#include "Vector.h"


class Canvas{
private:
	char** canvas;	//whole screen
	Vector2ui canvasSize;
	Recti cameraRect;
public:

public:
	Canvas();
	Canvas(Vector2ui canvasSize);
	virtual ~Canvas();
	void create(Vector2ui canvasSize);
	void setSize(Vector2ui canvasSize);
	void setCamera(Vector2i a, Vector2i b);	//rendered screen
	void setCamera(Recti rectangle);
	void camera(Vector2i position, Vector2i cameraSize);
	Vector2ui getCanvasSize();
	Recti getCamera();
	char getPixel(int x, int y);
	char getPixel(Vector2i pos);
	void pixel(char character, int x, int y);
	void pixel(char character, Vector2i position);
	void clear();
	virtual void render();
};


#endif /* CANVAS_H_ */
