#include "DrawTools.h"

void line(Vector2i a, Vector2i b, Canvas& canvas){	//passar para float afim de melhorar precisão
	float m = (float)(a.y-b.y)/(a.x-b.x);

	if((a.x-b.x) != 0 && -1 <= m && m <= 1){
		if(a.x<=b.x){
			for(int i=a.x; i<=b.x; i++){
				float y = m*i+a.x;

				if((y-(int)y)<0.5f){
					canvas.pixel('1', i, (int)(y));
				} else {
					canvas.pixel('1', i, (int)(y+1));
				}
			}
		} else {
			for(int i=a.x; i<=b.x; i++){
				float y = m*i+b.x;

				if((y-(int)y)<0.5f){
					canvas.pixel('1', i, (int)(y));
				} else {
					canvas.pixel('1', i, (int)(y+1));
				}
			}
		}
	} else {
		m = (float)(a.x-b.x)/(a.y-b.y);
		if(a.x<=b.x){
			for(int i=a.y; i<=b.y; i++){
				float x = m*i+a.y;

				if((x-(int)x)<0.5f){
					canvas.pixel('1', (int)(x), i);
				} else {
					canvas.pixel('1', (int)(x+1), i);
				}
			}
		} else {
			for(int i=a.y; i<=b.y; i++){
				float x = m*i+b.y;

				if((x-(int)x)<0.5f){
					canvas.pixel('1', (int)(x), i);
				} else {
					canvas.pixel('1', (int)(x+1), i);
				}
			}
		}
	}
}

void rectangle(Vector2i a, Vector2i b, Canvas& canvas){

}
