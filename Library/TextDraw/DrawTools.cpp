#include "DrawTools.h"

void line(Vector2i a, Vector2i b, Canvas& canvas){
	line('1', a, b, canvas);
}

void line(char c, Vector2i a, Vector2i b, Canvas& canvas){
	float m = (float)(a.y-b.y)/(a.x-b.x);

	if(a.x!=b.x && (-1<=m && m<=1)){
		if(a.x<b.x){
			for(int i=a.x; i<=b.x; i++){
				float y = m*(i-a.x)+a.y;
				if(-0.5 < (y-(int)y) && (y-(int)y) < 0.5){
					canvas.pixel(c, i, (int)y);
				} else {
					canvas.pixel(c, i, (int)y+1);
				}
			}
		} else {
			for(int i=b.x; i<=a.x; i++){
				float y = m*(i-b.x)+b.y;
				if(-0.5 <= (y-(int)y) && (y-(int)y) <= 0.5){
					canvas.pixel(c, i, (int)y);
				} else {
					canvas.pixel(c, i, (int)y+1);
				}
			}
		}
	} else {
		m = (float)(a.x-b.x)/(a.y-b.y);

		if(a.y<b.y){
			for(int i=a.y; i<=b.y; i++){
				float x = m*(i-a.y)+a.x;
				if(-0.5 < (x-(int)x) && (x-(int)x) < 0.5){
					canvas.pixel(c, (int)x, i);
				} else {
					canvas.pixel(c, (int)x+1, i);
				}
			}
		} else {
			for(int i=b.y; i<=a.y; i++){
				float x = m*(i-b.y)+b.x;
				if(-0.5 <= (x-(int)x) && (x-(int)x) <= 0.5){
					canvas.pixel(c, (int)x, i);
				} else {
					canvas.pixel(c, (int)x+1, i);
				}
			}
		}
	}
}

void rectangle(Vector2i a, Vector2i b, Canvas& canvas){
	rectangle('1', a, b, canvas);
}

void rectangle(char c, Vector2i a, Vector2i b, Canvas& canvas){
	if(a.x<=b.x){
		if(a.y<=b.y){
			for(int i=a.x; i<=b.x; i++){
				for(int j=a.y; j<=b.y; j++){
					canvas.pixel(c, i, j);
				}
			}
		} else {
			for(int i=a.x; i<=b.x; i++){
				for(int j=b.y; j<=a.y; j++){
					canvas.pixel(c, i, j);
				}
			}
		}
	} else {
		if(a.y<=b.y){
			for(int i=b.x; i<=a.x; i++){
				for(int j=a.y; j<=b.y; j++){
					canvas.pixel(c, i, j);
				}
			}
		} else {
			for(int i=b.x; i<=a.x; i++){
				for(int j=b.y; j<=a.y; j++){
					canvas.pixel(c, i, j);
				}
			}
		}
	}
}
