#ifndef SHAPES_H
#define SHAPES_H

#define MAX_SHAPES 50

typedef enum {
    CIRCLE, RECTANGLE, LINE, TRIANGLE
} ShapeType;

typedef struct {
    ShapeType type;
    int params[8];
} Shape;

extern Shape shapes[MAX_SHAPES];
extern int shapeCount;

void drawCircle(int cx, int cy, int r);
void drawRectangle(int x, int y, int w, int h);
void drawLine(int x1, int y1, int x2, int y2);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void redrawAll();

#endif