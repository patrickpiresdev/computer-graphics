#ifndef COLORS_H
#define COLORS_H

#include <GL/glut.h>

typedef struct
{
  GLfloat r;
  GLfloat g;
  GLfloat b;
  GLfloat alpha;
} Color;

Color newColor(GLfloat r, GLfloat g, GLfloat b);

extern const Color WHITE;
extern const Color RED;
extern const Color GRAY1;
extern const Color GRAY2;
extern const Color GRAY3;
extern const Color BLACK;
extern const Color GREEN;
extern const Color CYAN;
extern const Color YELLOW;
extern const Color PINK;
extern const Color BROWN;

#endif