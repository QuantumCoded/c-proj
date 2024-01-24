#ifndef BAR_H_INCLUDED
#define BAR_H_INCLUDED

#include <ncurses.h>
#include "colors.h"

#define BAR_PADDING 2
#define BAR_WIDTH (PANEL_WIDTH - 2 * BAR_PADDING - 1)

typedef struct {
    enum Color color;
    int value;
    int max;
    int y_offset;
    char* name;
    WINDOW* panel;
} BAR;

void draw_bar(BAR* bar);

#endif
