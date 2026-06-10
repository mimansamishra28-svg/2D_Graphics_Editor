# 2D Graphics Editor

A menu-driven 2D Graphics Editor implemented in C using a 2D character array as the drawing canvas.

## Features

- Canvas: 25 rows × 80 columns, initialized with `_` (underscore)
- Shapes drawn using `*` (asterisk)
- Draw: Circle, Rectangle, Line, Triangle
- Add, Delete, and Modify shapes
- Fully redraws canvas on every change

## Project Structure
ACP_Project/
├── src/
│   ├── main.c       # Entry point and main loop
│   ├── canvas.c     # Canvas init and display
│   ├── shapes.c     # Shape drawing algorithms
│   └── menu.c       # Menu and user interaction
├── include/
│   ├── canvas.h
│   ├── shapes.h
│   └── menu.h
├── build/           # Compiled output
├── Makefile
└── README.md
## How to Compile

Make sure you have gcc installed (TDM-GCC recommended for Windows).

```bash
gcc -Iinclude src/main.c src/canvas.c src/shapes.c src/menu.c -o build/editor
```

## How to Run

```bash
./build/editor
```

## Sample Coordinates

| Shape     | Input Example         |
|-----------|-----------------------|
| Circle    | cx=40 cy=12 r=8       |
| Rectangle | x=5 y=2 w=30 h=10    |
| Line      | x1=0 y1=0 x2=79 y2=24|
| Triangle  | 40 2 10 22 70 22      |

## Menu Options
Add Shape
Delete Shape
Modify Shape
Display Canvas
Exit

## Algorithms Used

- **Line**: Bresenham's line algorithm
- **Circle**: Midpoint circle algorithm
- **Rectangle**: Four lines using Bresenham
- **Triangle**: Three lines between vertices

## Author

Mimansa Mishra  
ACP Mini Project — June 2026