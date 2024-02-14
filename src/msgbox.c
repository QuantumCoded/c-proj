#include <ncurses.h>
#include "msgbox.h"
#include "msgqueue.h"
#include "panel.h"

void init_msgbox(MSGBOX* msgbox) {
    msgbox->pad = newpad(MSGBOX_LINES, msgbox->cols);
    msgbox->lines_wrote = 0;
    msgbox->scroll = 0;
}

void write_line(MSGBOX* msgbox, char* line) {
    if (msgbox->lines_wrote == MSGBOX_LINES) {
        for (int i = 1; i < msgbox->lines_wrote; i++) {
            msgbox->lines[i-1] = msgbox->lines[i];
        }
    }

    msgbox->lines[msgbox->lines_wrote] = line;

    if (msgbox->lines_wrote < MSGBOX_LINES) {
        msgbox->lines_wrote++;
    }

    for (int i = 0; i < msgbox->lines_wrote; i++) {
        mvwprintw(
            msgbox->pad,
            i,
            0,
            "%d %d %s",
            i,
            msgbox->lines_wrote,
            msgbox->lines[i]
        );
    }

    prefresh(
        msgbox->pad,
        msgbox->scroll,
        0,
        0,
        0,
        LINES-1,
        msgbox->cols
    );
}

// void write_line(MSGBOX* msgbox, char* line) {
//     mvwprintw(
//         msgbox->pad,
//         msgbox->lines_wrote,
//         0,
//         "%s",
//         line
//     );
//
//     prefresh(
//         msgbox->pad,
//         msgbox->scroll,
//         0,
//         0,
//         0,
//         LINES-1,
//         msgbox->cols
//     );
//
//     msgbox->lines_wrote++;
//
//     if (msgbox->lines_wrote >= LINES) {
//         msgbox->scroll++;
//     }
// }
