#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* screen size - adapt to console size */
#define NUM_COLUMNS 80
#define NUM_ROWS 25

/* screen buffer */
char screen[NUM_COLUMNS][NUM_ROWS];

/* initialize buffer by setting all pixels to spaces */
void initialize_buffer() {
    for (int i = 0; i < NUM_ROWS; i++)
        for (int j = 0; j < NUM_COLUMNS; j++)
            screen[j][i] = ' ';
}


/* update screen by copying buffer to console window */
void update_screen() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++)
            putchar(screen[j][i]);
        putchar('\n');
    }
    fflush(stdout);
}

/* checks whether a given point (x,y) is within the screen */
unsigned in_screen(int x, int y) {
    int maxX = NUM_COLUMNS - 1;
    int maxY = NUM_ROWS - 1;

    if (x < 0 || y < 0) {
        return 0;
    }

    if (y > maxY || x > maxX) {
        return 0;
    }

    return 1;
}

/* draw a single point at given position (x,y) and with given character */
void draw_pixel(int x, int y, char c) {
    if (!in_screen(x,y)) {
        return;
    }

    screen[x][y] = c;
}

/* clear a single pixel at position (x,y) */
void clear_pixel(int x, int y) {
    if (!in_screen(x,y)) {
        return;
    }

    screen[x][y] = ' ';
}

/* draw a horizontal line (x1,y)-(x2,y) with dashes (-) */
void draw_horizontal_line(int x1, int x2, int y) {
    for (int i = x1; i < x2; i++) {
        draw_pixel(i, y, '-');
    }
}

/* draw a vertical line (x,y1)-(x,y2) with vertical bars (|) */
void draw_vertical_line(int x, int y1, int y2) {
    for (int i = y1; i < y2; i++) {
        draw_pixel(x, i, '|');
    }
}

/* draw a horizontal arrow (x1,y)-(x2,y) */
void draw_horizontal_arrow(int x1, int x2, int y) {
    draw_horizontal_line(x1, x2, y);
    if (x1 < x2)
        draw_pixel(x2, y, '>');
    else
        draw_pixel(x2, y, '<');
}

/* draw a vertical arrow (x,y1)-(x,y2) */
void draw_vertical_arrow(int x, int y1, int y2) {
    draw_vertical_line(x, y1, y2);
    if (y1 < y2)
        draw_pixel(x, y2, 'v');
    else
        draw_pixel(x, y2, '^');
}

void draw_rectangle(int x1, int y1, int x2, int y2) {
    // Draw first line with + at start & end
    for (int i = x1; i < x2; i++) {
        if (i == x1 || i == x2 - 1) {
            draw_pixel(i, y1, '+');
            continue;
        }

        draw_pixel(i, y1, '-');
    }

    // Draw first vertical line
    for (int i = y1 + 1; i < y2; i++) {
        draw_pixel(x1, i, '|');
    }

    // Draw end vertical line
    for (int i = y1 + 1; i < y2; i++) {
        draw_pixel(x2 - 1, i, '|');
    }

    // Draw end line
    for (int i = x1; i < x2; i++) {
        if (i == x1 || i == x2 - 1) {
            draw_pixel(i, y2, '+');
            continue;
        }

        draw_pixel(i, y2, '-');
    }
}


void draw_filled_rectangle(int x1, int y1, int x2, int y2, char c) {
    for (int i = x1; i < x2; i++) {
        for (int x = y1; x < y2; x++) {
            draw_pixel(i, x, c);
        }
    }
}

/* draw a general line (x1,y1)-(x2,y2) with character c */
void draw_line(int x1, int y1, int x2, int y2, char c) {
    int signX = 1;
    int signY = 1;

    int deltaX = abs(x2 - x1);
    int deltaY = abs(y2 - y1);

    if (x1 > x2)
        signX = -1;
    if (y1 > y2)
        signY = -1;

    float m = (float)deltaY / (float)deltaX;

    if (m <= 1) {
        for (int i = 0; i <= deltaX; i++) {
            draw_pixel(ceil(x1 + i * signX),
                       ceil(y1 + i * m * signY),
                       c);
        }
    } else {
        for (int i = 0; i <= deltaY; i++) {
            draw_pixel(ceil(x1 + i / m * signX),
                       ceil(y1 + i * signY),
                       c);
        }
    }
}

/* flood fill an area starting at given position with character c */
void flood_fill(int x, int y, char c) {
    if (!in_screen(x,y)) {
        return;
    }

    if (screen[x][y] != ' ') {
        return;
    }

    draw_pixel(x, y, c);

    flood_fill(x + 1, y, c);
    flood_fill(x - 1, y, c);
    flood_fill(x, y + 1, c);
    flood_fill(x, y - 1, c);
}

/* main program: entry point */
int main(int argc, const char *argv[]) {

    initialize_buffer();

    draw_rectangle(25, 2, 68, 8);
    draw_line(0, NUM_ROWS - 1, NUM_COLUMNS - 1, 0, '*');
    flood_fill(2, 2, '.');
    draw_pixel(30, 10, '1');
    draw_pixel(20, 15, '2');
    draw_pixel(75, 20, '3');
    draw_line(8, 8, 45, 15, '+');
    draw_horizontal_arrow(0, NUM_COLUMNS - 1, 0);
    draw_horizontal_arrow(NUM_COLUMNS - 1, NUM_COLUMNS / 2, NUM_ROWS - 2);
    draw_vertical_arrow(0, 1, NUM_ROWS - 1);
    draw_filled_rectangle(3, 3, 8, 5, '#');

    update_screen();
    return 0;
}