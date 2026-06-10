#include <stdio.h>
#include "menu.h"
#include "shapes.h"
#include "canvas.h"

void handleAdd() {
    int choice;
    printf("\n1. Circle\n2. Rectangle\n3. Line\n4. Triangle\nChoose shape: ");
    scanf("%d", &choice);
    Shape s;
    s.type = choice - 1;
    switch (choice) {
        case 1:
            printf("Enter cx cy radius: ");
            scanf("%d %d %d", &s.params[0], &s.params[1], &s.params[2]);
            drawCircle(s.params[0], s.params[1], s.params[2]);
            break;
        case 2:
            printf("Enter x y width height: ");
            scanf("%d %d %d %d", &s.params[0], &s.params[1], &s.params[2], &s.params[3]);
            drawRectangle(s.params[0], s.params[1], s.params[2], s.params[3]);
            break;
        case 3:
            printf("Enter x1 y1 x2 y2: ");
            scanf("%d %d %d %d", &s.params[0], &s.params[1], &s.params[2], &s.params[3]);
            drawLine(s.params[0], s.params[1], s.params[2], s.params[3]);
            break;
        case 4:
            printf("Enter x1 y1 x2 y2 x3 y3: ");
            scanf("%d %d %d %d %d %d",
                &s.params[0], &s.params[1], &s.params[2],
                &s.params[3], &s.params[4], &s.params[5]);
            drawTriangle(s.params[0],s.params[1],s.params[2],
                         s.params[3],s.params[4],s.params[5]);
            break;
        default:
            printf("Invalid choice.\n"); return;
    }
    shapes[shapeCount++] = s;
}

void handleDelete() {
    if (shapeCount == 0) { printf("No shapes to delete.\n"); return; }
    printf("Enter shape index to delete (0 to %d): ", shapeCount - 1);
    int idx; scanf("%d", &idx);
    if (idx < 0 || idx >= shapeCount) { printf("Invalid index.\n"); return; }
    for (int i = idx; i < shapeCount - 1; i++)
        shapes[i] = shapes[i + 1];
    shapeCount--;
    redrawAll();
    printf("Shape deleted.\n");
}

void handleModify() {
    if (shapeCount == 0) { printf("No shapes to modify.\n"); return; }
    printf("Enter shape index to modify (0 to %d): ", shapeCount - 1);
    int idx; scanf("%d", &idx);
    if (idx < 0 || idx >= shapeCount) { printf("Invalid index.\n"); return; }
    shapeCount--;
    Shape s;
    s.type = shapes[idx].type;
    switch (s.type) {
        case CIRCLE:
            printf("Enter new cx cy radius: ");
            scanf("%d %d %d", &s.params[0], &s.params[1], &s.params[2]);
            break;
        case RECTANGLE:
            printf("Enter new x y width height: ");
            scanf("%d %d %d %d", &s.params[0], &s.params[1], &s.params[2], &s.params[3]);
            break;
        case LINE:
            printf("Enter new x1 y1 x2 y2: ");
            scanf("%d %d %d %d", &s.params[0], &s.params[1], &s.params[2], &s.params[3]);
            break;
        case TRIANGLE:
            printf("Enter new x1 y1 x2 y2 x3 y3: ");
            scanf("%d %d %d %d %d %d",
                &s.params[0], &s.params[1], &s.params[2],
                &s.params[3], &s.params[4], &s.params[5]);
            break;
    }
    shapes[idx] = s;
    shapeCount++;
    redrawAll();
    printf("Shape modified.\n");
}

void showMainMenu() {
    printf("\n===== 2D Graphics Editor =====\n");
    printf("1. Add Shape\n");
    printf("2. Delete Shape\n");
    printf("3. Modify Shape\n");
    printf("4. Display Canvas\n");
    printf("5. Exit\n");
    printf("Choose: ");
}