#include <GL/glut.h>
#include <cmath>
#include "../colors/colors.h"
#include "primitives.h"

void Line::draw()
{
    glColor3f(color.r, color.g, color.b);
    glLineWidth(width);
    glBegin(GL_LINES);
    float half_size = size / 2;
    glVertex3f(-half_size, 0, 0);
    glVertex3f(half_size, 0, 0);
    glEnd();
}

void Square::draw()
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

void Circle::draw()
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