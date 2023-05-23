#include <GL/gl.h>
#include <GL/glut.h>

void init() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20, 20, -20, 20, -1, 1);
}

void Corpo() {
  glBegin(GL_QUADS);
  glColor3f(0, 0, 1);
  glVertex3f(3, 1, 0);
  glVertex3f(5, 1, 0);
  glVertex3f(5, 6, 0);
  glVertex3f(3, 6, 0);
  glEnd();
}

void Bico() {
  glBegin(GL_TRIANGLES);
  glColor3f(0, 1, 0);
  glVertex3f(3, 6, 0);
  glVertex3f(4, 8, 0);
  glVertex3f(5, 6, 0);
  glEnd();
}

void AsaEsquerda() {
  glBegin(GL_TRIANGLES);
  glColor3f(1, 0, 0);
  glVertex3f(1.5, 1, 0);
  glVertex3f(3, 1, 0);
  glVertex3f(3, 3, 0);
  glEnd();
}

void AsaDireita() {
  glBegin(GL_TRIANGLES);
  glColor3f(1, 0, 0);
  glVertex3f(5, 1, 0);
  glVertex3f(6.5, 1, 0);
  glVertex3f(5, 3, 0);
  glEnd();
}

void foguete() {
  Bico();
  Corpo();
  AsaEsquerda();
  AsaDireita();
}

void DesenhaFoguete() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  // glScalef(0.5, 0.5, 1);
  // glRotatef(20, 0, 0, 1); // rotaciona 20 graus no sentido anti-horario com relacao ao eixo z (saindo da tela)
  // foguete();
  glTranslatef(4, 4.5, 0);
  glRotatef(20, 0, 0, 1);
  glTranslatef(-4, -4.5, 0);
  foguete();
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  GLint widht = 500;
  GLint height = 500;
  glutInitWindowSize(widht, height);
  glutInitWindowPosition(400, 100);
  glutCreateWindow("Desenhando um foguete");

  init();
  glutDisplayFunc(DesenhaFoguete);
  glutMainLoop();

  return 0;
}