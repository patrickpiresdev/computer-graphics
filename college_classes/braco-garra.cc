#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int shoulder = 0, elbow = 0, thumb = 0, index = 0;

void init(void) {
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void) {
  glClear (GL_COLOR_BUFFER_BIT);

  glPushMatrix();

  glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
  glTranslatef(1, 0, 0);

  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube(1.0);
  glPopMatrix();
  
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);

  glPushMatrix();
  glTranslatef(1.0, 0, 0.0);
  glScalef(2.0, 0.4, 1.0);
  glutWireCube(1.0);
  glPopMatrix();

  glTranslatef(2, -0.2, 0);

  glPushMatrix();
  glRotatef((GLfloat) thumb, 0, 0, 1);
  glTranslatef(0.25, 0, 0);
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();
  
  glTranslatef(0, 0.2, 0);
  
  glPushMatrix();
  glRotatef((GLfloat) index, 0, 0, 1);
  glTranslatef(0.25, 0, 0);
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();

  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(85, (GLfloat) w/(GLfloat) h, 0.1, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0,0,5,0,0,0,0,1,0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 'p':
    thumb = (thumb + 5) % 360;
    glutPostRedisplay();
    break;
  case 'P':
    thumb = (thumb - 5) % 360;
    glutPostRedisplay();
    break;
  case 'i':
    index = (index + 5) % 360;
    glutPostRedisplay();
    break;
  case 'I':
    index = (index - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}


