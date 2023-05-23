#include <GL/glut.h>

void init(GLint widht, GLint height) {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  GLint halfWidth = widht / 2;
  GLint halfHeight = height / 2;
  glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);
}

void drawHouseRoof() {
  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex3f(-65, 50, 0);
  glVertex3f(65, 50, 0);
  glVertex3f(0, 100, 0);
  glEnd();
}

void drawHouseBase() {
  glColor3f(0.5, 0, 0.8);
  glBegin(GL_POLYGON);
  glVertex3f(-65, -50, 0);
  glVertex3f(65, -50, 0);
  glVertex3f(65, 50, 0);
  glVertex3f(-65, 50, 0);
  glEnd();
}

void drawHouseDoor() {
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  glVertex3f(-20, -50, 0);
  glVertex3f(20, -50, 0);
  glVertex3f(20, 10, 0);
  glVertex3f(-20, 10, 0);
  glEnd();
}

void drawHouseWindow() {
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  glVertex3f(30, -10, 0);
  glVertex3f(50, -10, 0);
  glVertex3f(50, 10, 0);
  glVertex3f(30, 10, 0);
  glEnd();

  glColor3f(0.5, 0, 0.8);
  glLineWidth(2);
  glBegin(GL_LINES);
  glVertex3f(40, 10, 0);
  glVertex3f(40, -10, 0);
  glVertex3f(30, 0, 0);
  glVertex3f(50, 0, 0);
  glEnd();
}

void drawHouse() {
  drawHouseRoof();
  drawHouseBase();
  drawHouseDoor();
  drawHouseWindow();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawHouse();
  glFlush();
}

void keyboard(unsigned char key, GLint x, GLint y) {
  switch (key) {
  case 32:
    glClearColor(0.0, 0.0, 0.0, 1.0);
    break;
  default:
    glClearColor(1.0, 1.0, 1.0, 1.0);
    break;
  }

  display();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  GLint width = 500;
  GLint height = 500;
  glutInitWindowSize(width, height);
  glutInitWindowPosition(400, 100);
  glutCreateWindow("Tarefa 1 - Exercicio 1");

  init(width, height);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 0;
}