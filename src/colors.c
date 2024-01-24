#include <ncurses.h>
#include <stdlib.h>
#include "colors.h"

void init_colors() {
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");

	exit(1);
    }

    start_color();

    init_pair(HEALTH_COLOR, COLOR_WHITE, COLOR_RED);
    init_pair(MANA_COLOR, COLOR_WHITE, COLOR_BLUE);
}
