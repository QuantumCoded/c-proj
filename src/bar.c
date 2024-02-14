#include <ncurses.h>
#include <math.h>

#include "bar.h"
#include "panel.h"
#include "utils.h"

void draw_bar(BAR* bar) {
    char bar_text[BAR_WIDTH + 1];

    double fill_percent = (double)min(bar->value, bar->max) / (double)bar->max;

    int offset;
    int value_len = num_digits(bar->value);
    int substr_len = floor(fill_percent * BAR_WIDTH);

    offset = sprintf(bar_text, "%*s", (BAR_WIDTH >> 1) - value_len, "");
    offset = offset + sprintf(bar_text + offset, "%d", bar->value);
    offset = offset + sprintf(bar_text + offset, "/");
    offset = offset + sprintf(bar_text + offset, "%d", bar->max);
    sprintf(bar_text + offset, "%*s", BAR_WIDTH - offset, "");

    bar_text[BAR_WIDTH] = 0;

    mvwprintw(
        bar->panel,
        bar->y_offset,
        BAR_PADDING + 1,
        "%s",
        bar->name
    );

    wattron(bar->panel, COLOR_PAIR(bar->color));

    mvwprintw(
        bar->panel,
        bar->y_offset + 1,
        BAR_PADDING + 1,
        "%.*s",
        substr_len,
        bar_text
    );

    wattroff(bar->panel, COLOR_PAIR(bar->color));

    wprintw(
        bar->panel,
        "%s",
        bar_text + substr_len
    );
}
