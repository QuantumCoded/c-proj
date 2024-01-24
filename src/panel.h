#ifndef PANEL_H_INCLUDED
#define PANEL_H_INCLUDED

#include <ncurses.h>
#include "bar.h"
#include "game.h"

#define PANEL_WIDTH 30

typedef struct {
    BAR hp_bar;
    BAR mp_bar;
    WINDOW* window;
} PANEL;

void init_panel(PANEL* panel);
void update_panel(PANEL* panel, GAMESTATE* state);

#endif
