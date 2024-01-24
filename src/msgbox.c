#include <ncurses.h>
#include "msgbox.h"
#include "panel.h"

void init_msgbox(MSGBOX* msgbox) {
    msgbox->pad = newpad(MSGBOX_LINES, msgbox->cols);
    msgbox->lines_wrote = 0;
    msgbox->scroll = 0;
}

void write_line(MSGBOX* msgbox, char* line) {
    mvwprintw(
        msgbox->pad,
        msgbox->lines_wrote,
        0,
        "%s",
        line
    );

    prefresh(
        msgbox->pad,
        msgbox->scroll,
        0,
        0,
        0,
        LINES-1,
        msgbox->cols
    );

    msgbox->lines_wrote++;

    if (msgbox->lines_wrote >= LINES) {
        msgbox->scroll++;
    }
}
