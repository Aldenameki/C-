#ifndef VECTOR_H_
#define VECTOR_H_


class Vector2i{
public:
	int x, y;
public:
	Vector2i(){
		x = y = 0;
	}
	Vector2i(int X, int Y){
		x = X;
		y = Y;
	}
	Vector2i(const Vector2i& vector){
		x = vector.x;
		y = vector.y;
	}
};

class Vector2ui{
public:
	unsigned int x, y;
public:
	Vector2ui(){
		x = y = 0;
	}
	Vector2ui(unsigned int X, unsigned int Y){
		x = X;
		y = Y;
	}
	Vector2ui(const Vector2i& vector){
		x = vector.x;
		y = vector.y;
	}
};

class Recti{
public:
	Vector2i a, b;
public:
	Recti(){}
	Recti(int Ax, int Ay, int Bx, int By){
		a.x = Ax;
		a.y = Ay;
		b.x = Bx;
		b.y = By;
	}
	Recti(Vector2i A, Vector2i B){
		a = A;
		b = B;
	}
	Recti(const Recti& rectangle){
		a = rectangle.a;
		b = rectangle.b;
	}
};

#endif /* VECTOR_H_ */
