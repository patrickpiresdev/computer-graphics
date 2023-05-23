#include <GL/glut.h>
#include <cmath>

typedef struct
{
  GLfloat r;
  GLfloat g;
  GLfloat b;
  GLfloat alpha;
} Color;

Color newColor(GLfloat r, GLfloat g, GLfloat b)
{
  return {r / 255, g / 255, b / 255, 1};
}

Color white = newColor(255, 255, 255);
Color gray1 = newColor(199, 199, 204);
Color gray2 = newColor(174, 174, 178);
Color gray3 = newColor(142, 142, 147);
Color black = newColor(0, 0, 0);
Color red = newColor(255, 59, 48);
Color green = newColor(40, 205, 65);
Color cyan = newColor(85, 190, 240);
Color yellow = newColor(255, 204, 0);
Color pink = newColor(255, 45, 85);

void init(void)
{
  glClearColor(cyan.r, cyan.g, cyan.b, cyan.alpha);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -100, 100, -100, 100);
}

void GrassAndMountains()
{
  glColor3f(green.r, green.g, green.b);
  glBegin(GL_POLYGON);
  glVertex3f(-100, -100, 0);
  glVertex3f(-100, -10, 0);
  glVertex3f(-60, 30, 0);
  glVertex3f(-50, 10, 0);
  glVertex3f(-10, 50, 0);
  glVertex3f(30, -15, 0);
  glVertex3f(70, 5, 0);
  glVertex3f(100, -10, 0);
  glVertex3f(100, -100, 0);
  glEnd();
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

void Line(float size, float width, Color color)
{
  glColor3f(color.r, color.g, color.b);
  glLineWidth(width);
  glBegin(GL_LINES);
  float half_size = size / 2;
  glVertex3f(-half_size, 0, 0);
  glVertex3f(half_size, 0, 0);
  glEnd();
}

void Sun()
{
  Circle(20, yellow);
  for (int i = 0; i < 4; i++)
  {
    glRotatef(360 / 8, 0, 0, 1);
    Line(48, 3, yellow);
  }
}

void Square(float size, Color color)
{
  glColor3f(color.r, color.g, color.b);
  glBegin(GL_QUADS);
  float half_size = size / 2;
  glVertex3f(-half_size, -half_size, 0);
  glVertex3f(half_size, -half_size, 0);
  glVertex3f(half_size, half_size, 0);
  glVertex3f(-half_size, half_size, 0);
  glEnd();
}

void Road()
{
  glPushMatrix();
  glScalef(8, 1, 1);
  Square(25, gray3);
  glPopMatrix();
  Line(200, 4, white);
}

void WindmillHelix(float size, Color color)
{
  float x_size = size / 7;
  float half_x_size = x_size / 2;
  float up = (5.0 / 7.0) * size;
  float down = size - up;

  glColor3f(color.r, color.g, color.b);
  glPushMatrix();
  glBegin(GL_POLYGON);
  glVertex3f(-half_x_size, 0, 0);
  glVertex3f(0, -down, 0);
  glVertex3f(half_x_size, 0, 0);
  glVertex3f(0, up, 0);
  glEnd();
  glPopMatrix();
}

void WindmillHelixes()
{
  for (int i = 0; i < 3; i++)
  {
    glRotatef(360 / 3, 0, 0, 1);
    glPushMatrix();
    glTranslatef(0, 10, 0);
    WindmillHelix(35, gray1);
    glPopMatrix();
  }
}

void Windmill()
{
  glPushMatrix();
  glScalef(1, 30, 1);
  Square(2, gray2);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 30, 0);
  glRotatef(-20, 0, 0, 1);
  WindmillHelixes();
  glPopMatrix();
}

void CarWheel(float radius)
{
  Circle(radius, black);
  Circle(0.8 * radius, gray1);
  Circle(0.3 * radius, black);
}

void Car()
{
  glPushMatrix();
  glTranslatef(-10, 0, 0);
  CarWheel(5);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(10, 0, 0);
  CarWheel(5);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 6.5, 0);
  glScalef(3.5, 1, 1);
  Square(10, red);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-8.75, 11.5, 0);
  glScalef(2.5, 1, 1);
  Square(5, red);
  glPopMatrix();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  GrassAndMountains();

  glPushMatrix();
  glTranslatef(70, 70, 0);
  Sun();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, -60, 0);
  Road();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(10, 5, 0);
  Windmill();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-85, 10, 0);
  glScalef(0.8, 0.8, 1);
  Windmill();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-40, 30, 0);
  glScalef(0.6, 0.6, 1);
  Windmill();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-50, -63.75, 0);
  Car();
  glPopMatrix();

  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(400, 100);
  glutCreateWindow("Car Travel");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}