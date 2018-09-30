#ifndef DRAWTOOLS_H_
#define DRAWTOOLS_H_

#include "Canvas.h"

void line(Vector2i a, Vector2i b, Canvas& canvas);
void line(char c, Vector2i a, Vector2i b, Canvas& canvas);
void rectangle(Vector2i a, Vector2i b, Canvas& canvas);
void rectangle(char c, Vector2i a, Vector2i b, Canvas& canvas);


#endif /* DRAWTOOLS_H_ */
