#include <GL/glut.h>
#include <cmath>
#include <random>
#include "colors.h"
#include "primitives.h"

float y_car = -63.75;
float x_scenario = 0;
float ROAD_UPPER_LIMIT = -48;
float ROAD_LOWER_LIMIT = -72;

void Init(void)
{
    glClearColor(CYAN.r, CYAN.g, CYAN.b, CYAN.alpha);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -100, 100);
}

void Grass()
{
    glColor3f(GREEN.r, GREEN.g, GREEN.b);
    glBegin(GL_QUADS);
    glVertex3f(-100, -100, 0);
    glVertex3f(-100, -15, 0);
    glVertex3f(100, -15, 0);
    glVertex3f(100, -100, 0);
    glEnd();
}

void Mountain(Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    glVertex3f(-50, 0, 0);
    glVertex3f(20, 60, 0);
    glVertex3f(50, 0, 0);
    glEnd();
}

void Sun()
{
    Circle(20, YELLOW).draw();
    for (int i = 0; i < 4; i++)
    {
        glRotatef(360 / 8, 0, 0, 1);
        Line(48, 3, YELLOW).draw();
    }
}

void Road()
{
    glPushMatrix();
    glScalef(8, 1, 1);
    Square(25, GRAY3).draw();
    glPopMatrix();
    Line(200, 4, WHITE).draw();
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
        WindmillHelix(35, GRAY1);
        glPopMatrix();
    }
}

void Windmill()
{
    glPushMatrix();
    glScalef(1, 30, 1);
    Square(2, GRAY2).draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 30, 0);
    glRotatef(-20, 0, 0, 1);
    WindmillHelixes();
    glPopMatrix();
}

void CarWheel(float radius)
{
    Circle(radius, BLACK).draw();
    Circle(0.8 * radius, GRAY1).draw();
    Circle(0.3 * radius, BLACK).draw();
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
    Square(10, RED).draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8.75, 11.5, 0);
    glScalef(2.5, 1, 1);
    Square(5, RED).draw();
    glPopMatrix();
}

void Mud() {
    Circle(5, BROWN).draw();

    glPushMatrix();
    glTranslatef(6, 0, 0);
    Circle(5, BROWN).draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, -3, 0);
    Circle(4, BROWN).draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 2, 0);
    Circle(6, BROWN).draw();
    glPopMatrix();
}

void Scenario()
{
    Grass();

    glPushMatrix();
    glTranslatef(-50, -15, 0);
    Mountain(GREEN);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50, -15, 0);
    Mountain(GRAY3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50, -5, 0);
    Windmill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -60, 0);
    Road();
    glPopMatrix();

    // y: -7, 8
    // posso deslocar de -5 ate 10
    std::random_device rd;
    std::mt19937 gen(rd());
    // Create a distribution that maps to the desired range
    std::uniform_int_distribution<int> distribution(-5, 10);

    // Generate a random number
    int randomNum = distribution(gen);
    glPushMatrix();
    glTranslatef(0, -60 + randomNum, 0);
    Mud();
    glPopMatrix();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(70, 70, 0);
    Sun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x_scenario, 0, 0);
    Scenario();
    glTranslatef(200, 0, 0);
    Scenario();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50, y_car, 0);
    Car();
    glPopMatrix();

    glutSwapBuffers();
}

void AnimateCar(int v)
{
    y_car += y_car == -63.75 ? 0.5 : -0.5;
    glutPostRedisplay();
    glutTimerFunc(100, AnimateCar, 0);
}

void AnimateScenario(int v)
{
    x_scenario -= x_scenario == -199 ? -199 : 1;
    glutPostRedisplay();
    glutTimerFunc(20, AnimateScenario, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Car Travel");
    Init();
    glutDisplayFunc(Display);
    glutTimerFunc(20, AnimateScenario, 0);
    glutTimerFunc(100, AnimateCar, 0);
    glutMainLoop();
    return 0;
}