#include <GL/glut.h>
#include "../colors/colors.h"

Color newColor(GLfloat r, GLfloat g, GLfloat b)
{
  return {r / 255, g / 255, b / 255, 1};
}

const Color WHITE = newColor(255, 255, 255);
const Color RED = newColor(255, 59, 48);
const Color GRAY1 = newColor(199, 199, 204);
const Color GRAY2 = newColor(174, 174, 178);
const Color GRAY3 = newColor(142, 142, 147);
const Color BLACK = newColor(0, 0, 0);
const Color GREEN = newColor(40, 205, 65);
const Color CYAN = newColor(85, 190, 240);
const Color YELLOW = newColor(255, 204, 0);
const Color PINK = newColor(255, 45, 85);
const Color BROWN = newColor(162, 132, 94);