#include <GL/gl.h>
#include <GL/glut.h>

void Init() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20, 20, -20, 20, -1, 1);
}

void Square() {
  glBegin(GL_LINE_LOOP);
  glColor3f(0, 0, 0);
  glVertex3f(-1, -1, 0);
  glVertex3f(1, -1, 0);
  glVertex3f(1, 1, 0);
  glVertex3f(-1, 1, 0);
  glEnd();
}

void Triangle() {
  glBegin(GL_LINE_LOOP);
  glColor3f(0, 0, 0);
  glVertex3f(-1, 0, 0);
  glVertex3f(1, 0, 0);
  glVertex3f(0, 1, 0);
  glEnd();
}

void CastleBase() {
  glPushMatrix();
  glTranslatef(0, 4, 0);
  glScalef(6, 4, 1);
  Square();
  glPopMatrix();
}

void RightTowerBase() {
  glPushMatrix();
  glTranslatef(8, 6, 0);
  glScalef(2, 6, 1);
  Square();
  glPopMatrix();
}

void LeftTowerBase() {
  glPushMatrix();
  glTranslatef(-8, 6, 0);
  glScalef(2, 6, 1);
  Square();
  glPopMatrix();
}

void LeftTowerRoof() {
  glPushMatrix();
  glTranslatef(-8, 12, 0);
  glScalef(2, 4, 1);
  Triangle();
  glPopMatrix();
}

void RightTowerRoof() {
  glPushMatrix();
  glTranslatef(8, 12, 0);
  glScalef(2, 4, 1);
  Triangle();
  glPopMatrix();
}

void MiddleTowerBase() {
  glPushMatrix();
  glTranslatef(0, 11, 0);
  glScalef(2, 3, 1);
  Square();
  glPopMatrix();
}

void MiddleTowerRoof() {
  glPushMatrix();
  glTranslatef(0, 14, 0);
  glScalef(2, 4, 1);
  Triangle();
  glPopMatrix();
}

void LeftTowerWindow() {
  glPushMatrix();
  glTranslatef(-8, 0.8*12, 0);
  glScalef(0.5, 1, 1);
  Square();
  glPopMatrix();
}

void RightTowerWindow() {
  glPushMatrix();
  glTranslatef(8, 0.8*12, 0);
  glScalef(0.5, 1, 1);
  Square();
  glPopMatrix();
}

void MiddleTowerWindow() {
  glPushMatrix();
  glTranslatef(0, 12, 0);
  glScalef(0.5, 1, 1);
  Square();
  glPopMatrix();
}

void CastleDoor() {
  glPushMatrix();
  glTranslatef(0, 2, 0);
  glScalef(2, 2, 1);
  Square();
  glPopMatrix();
}

void RightTower() {
  RightTowerBase();
  RightTowerRoof();
  RightTowerWindow();
}

void LeftTower() {
  LeftTowerBase();
  LeftTowerRoof();
  LeftTowerWindow();
}

void MiddleTower() {
  MiddleTowerBase();
  MiddleTowerRoof();
  MiddleTowerWindow();
}

void Castle() {
  CastleBase();
  CastleDoor();
  RightTower();
  LeftTower();
  MiddleTower();
}

void Sun() {
  glPushMatrix();
  glTranslatef(13, 15, 0);
  Square();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(13, 15, 0);
  glRotatef(45, 0, 0, 1);
  Square();
  glPopMatrix();
}

void Display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(2);
  Castle();
  Sun();
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  GLint widht = 500;
  GLint height = 500;
  glutInitWindowSize(widht, height);
  glutInitWindowPosition(400, 100);
  glutCreateWindow("Castelo de Hogwarts");

  Init();
  glutDisplayFunc(Display);
  glutMainLoop();

  return 0;
}