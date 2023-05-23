#include <GL/glut.h>
#include <cmath>
#include <unistd.h>
#include "colors.h"

void Init(void)
{
  glClearColor(WHITE.r, WHITE.g, WHITE.b, WHITE.alpha);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -100, 100, -100, 100);
}

void Circle(float radius, Color color)
{
  int numSegments = 100;
  float angleStep = 2.0f * M_PI / numSegments;
  float angle;
  float x;
  float y;

  glColor3f(color.r, color.g, color.b);
  glBegin(GL_POLYGON);
  for (int i = 0; i < numSegments; ++i)
  {
    float angle = i * angleStep;
    float x = radius * cos(angle);
    float y = radius * sin(angle);
    glVertex2f(x, y);
  }
  glEnd();
}

void Display()
{
  for (int i = 0; i < 20; i++)
  {
    glClear(GL_COLOR_BUFFER_BIT);
    if (i % 2 == 0)
    {
      Circle(30, RED);
    }
    glFlush();
    usleep(100000);
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(400, 100);
  glutCreateWindow("Blinking Light");
  Init();
  glutDisplayFunc(Display);
  glutMainLoop();
  return 0;
}