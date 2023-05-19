#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

GLint backgroundOffset = 0;
GLint backgroundMoveStep = 10;

void Init() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -100, 100, -1, 1);
}

void Display() {
  glClear(GL_COLOR_BUFFER_BIT);

  // draw here
  // glScalef(4, 4, 1);
  glTranslatef(backgroundOffset, 0, 0);

  glPushMatrix();
  // glTranslatef(900, 0, 0);
  // glScalef(40, 4, 1);
  glScalef(4, 1, 1);
  glBegin(GL_QUADS);
  glColor4f(1, 0, 0, 0.3);
  glVertex3f(-25, 25, 0);
  glVertex3f(-25, -25, 0);
  // glColor4f(1, 0, 0, 1);
  glVertex3f(25, -25, 0);
  glVertex3f(25, 25, 0);
  
  glEnd();
  glPopMatrix();

  glFlush();
}

void Keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 'd':
    backgroundOffset = -backgroundMoveStep;
    break;

  case 'a':
    backgroundOffset = backgroundMoveStep;
    break;
  }

  Display();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

  GLint widht = 500;
  GLint height = 500;
  glutInitWindowSize(widht, height);
  glutInitWindowPosition(400, 100);
  glutCreateWindow("Side Scrolling Game");

  Init();
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutMainLoop();

  return 0;
}