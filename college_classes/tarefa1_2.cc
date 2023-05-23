#include <GL/glut.h>
#include <vector>
#include <cstdio>

typedef struct Point {
  GLint x;
  GLint y;
} Point;

std::vector<Point> points;

void init(GLint width, GLint height) {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, width, 0, height, -1, 1);
}

void square(GLint side, GLint offsetX, GLint offsetY) {
  GLint halfSide = side / 2;
  glBegin(GL_POLYGON);
  glColor3f(0, 0, 0);
  glVertex3f(-halfSide + offsetX, 500 - (-halfSide + offsetY), 0);
  glVertex3f(halfSide + offsetX, 500 - (-halfSide + offsetY), 0);
  glVertex3f(halfSide + offsetX, 500 - (halfSide + offsetY), 0);
  glVertex3f(-halfSide + offsetX, 500 - (halfSide + offsetY), 0);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  for (Point point : points)
    square(50, point.x, point.y);
  glFlush();
}

void mouse(GLint button, GLint action, GLint x, GLint y) {
  switch (button) {
  case GLUT_LEFT_BUTTON: {
    points.push_back({x, y});
    break;
  }
  case GLUT_RIGHT_BUTTON: {
    points.clear();
    break;
  }
  default: break;
  }

  display();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  GLint widht = 500;
  GLint height = 500;
  glutInitWindowSize(widht, height);
  glutInitWindowPosition(400, 100);
  glutCreateWindow("Tarefa 1 - Exercicio 2");

  init(widht, height);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMainLoop();

  return 0;
}