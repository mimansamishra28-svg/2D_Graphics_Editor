#include <stdlib.h>
#include "shapes.h"
#include "canvas.h"

Shape shapes[MAX_SHAPES];
int shapeCount = 0;

static void setPixel(int x, int y) {
    if (x >= 0 && x < COLS && y >= 0 && y < ROWS)
        canvas[y][x] = '*';
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    while (1) {
        setPixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 <  dx) { err += dx; y1 += sy; }
    }
}

void drawRectangle(int x, int y, int w, int h) {
    drawLine(x,     y,     x+w, y    );
    drawLine(x+w,   y,     x+w, y+h  );
    drawLine(x+w,   y+h,   x,   y+h  );
    drawLine(x,     y+h,   x,   y    );
}

void drawCircle(int cx, int cy, int r) {
    int x = 0, y = r, d = 1 - r;
    while (x <= y) {
        setPixel(cx+x, cy+y); setPixel(cx-x, cy+y);
        setPixel(cx+x, cy-y); setPixel(cx-x, cy-y);
        setPixel(cx+y, cy+x); setPixel(cx-y, cy+x);
        setPixel(cx+y, cy-x); setPixel(cx-y, cy-x);
        if (d < 0) d += 2*x + 3;
        else { d += 2*(x-y) + 5; y--; }
        x++;
    }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void redrawAll() {
    initCanvas();
    for (int i = 0; i < shapeCount; i++) {
        int *p = shapes[i].params;
        switch (shapes[i].type) {
            case CIRCLE:    drawCircle(p[0],p[1],p[2]); break;
            case RECTANGLE: drawRectangle(p[0],p[1],p[2],p[3]); break;
            case LINE:      drawLine(p[0],p[1],p[2],p[3]); break;
            case TRIANGLE:  drawTriangle(p[0],p[1],p[2],p[3],p[4],p[5]); break;
        }
    }
}