#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <GL/glut.h>
#include "colors.h"

class Line {
    public:
        Line(float size, float width, Color color):
            size(size), width(width), color(color) {}
    
        void draw();
    private:
        float size;
        float width;
        Color color;
};

class Square {
    public:
        Square(float size, Color color):
            size(size), color(color) {}
    
        void draw();
    private:
        float size;
        Color color;
};

class Circle {
    public:
        Circle(float radius, Color color):
            radius(radius), color(color) {}
    
        void draw();
    private:
        float radius;
        Color color;
};

#endif