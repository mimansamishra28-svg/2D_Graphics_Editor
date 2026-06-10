#include <stdio.h>
#include "canvas.h"
#include "shapes.h"
#include "menu.h"

int main() {
    initCanvas();
    int choice;
    while (1) {
        showMainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: handleAdd();     displayCanvas(); break;
            case 2: handleDelete();  displayCanvas(); break;
            case 3: handleModify();  displayCanvas(); break;
            case 4: displayCanvas(); break;
            case 5: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}