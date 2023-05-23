#include <GL/glut.h>
#include <cmath>

void display() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 1.0, 1.0); // Define a cor para branco
  glMatrixMode(GL_PROJECTION);
  glOrtho(-100, 100, -100, 100, -100, 100);
  glLoadIdentity();

  const float radius = 0.5f;
  const int numSegments = 100;
  const float angleStep = 2.0f * M_PI / numSegments;

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < numSegments; ++i) {
    const float angle = i * angleStep;
    const float x = radius * cos(angle);
    const float y = radius * sin(angle);
    glVertex2f(x, y);
  }
  glEnd();
  
  const float lineLength = radius + 0.1;
  const int numLines = 16;
  const float linesAngleStep = 2.0f * M_PI / numLines;

  glBegin(GL_LINES);
  for (int i = 0; i < numLines; ++i) {
    const float angle = i * linesAngleStep;
    const float x = lineLength * cos(angle);
    const float y = lineLength * sin(angle);
    glVertex2f(0, 0);
    glVertex2f(x, y);
  }
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("desenhar roda");
  glutDisplayFunc(display);

  glutMainLoop();
  return 0;
}
