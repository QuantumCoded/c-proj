#include <ncurses.h>
#include "bar.h"
#include "panel.h"
#include "colors.h"

void init_panel(PANEL* panel) {
    panel->window = newwin(
        LINES,
        PANEL_WIDTH,
        0,
        COLS - PANEL_WIDTH
    );

    wvline(panel->window, 0, LINES);

    panel->hp_bar.color = HEALTH_COLOR;
    panel->hp_bar.name = "Health";
    panel->hp_bar.y_offset = 1;
    panel->hp_bar.panel = panel->window;

    panel->mp_bar.color = MANA_COLOR;
    panel->mp_bar.name = "Mana";
    panel->mp_bar.y_offset = 4;
    panel->mp_bar.panel = panel->window;
}

void update_panel(PANEL* panel, GAMESTATE* state) { 
    panel->hp_bar.value = state->hp;
    panel->hp_bar.max = state->max_hp;

    panel->mp_bar.value = state->mp;
    panel->mp_bar.max = state->max_mp;

    draw_bar(&panel->hp_bar);
    draw_bar(&panel->mp_bar);

    wrefresh(panel->window);
}
