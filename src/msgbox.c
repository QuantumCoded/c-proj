#include <ncurses.h>
#include "msgbox.h"
#include "panel.h"
#include "utils.h"

void add_message(MSGQUEUE* msgqueue, char* message) {
    if (msgqueue->count == MSGBOX_LINES) {
        for (int i = 1; i < MSGBOX_LINES; i++) {
            msgqueue->messages[i - 1] = msgqueue->messages[i];
        }
    }

    int line_index = min(msgqueue->count, MSGBOX_LINES - 1);
    msgqueue->messages[line_index] = message;

    if (msgqueue->count < MSGBOX_LINES) {
        msgqueue->count++;
    }
}

void init_msgbox(MSGBOX* msgbox) {
    msgbox->queue->count = 0;
    msgbox->pad = newpad(MSGBOX_LINES, msgbox->cols);
    msgbox->lines_wrote = 0;
    msgbox->scroll = 0;
    msgbox->max_scroll = 0;
}

void write_line(MSGBOX* msgbox, char* line) {
    add_message(msgbox->queue, line);

    for (int i = 0; i < msgbox->queue->count; i++) {
        mvwprintw(
            msgbox->pad,
            i,
            0,
            "%d %s",
            msgbox->queue->count,
            msgbox->queue->messages[i]
        );
    }

    // TODO: this nees some more logic for handling
    // user scrolling (don't move scroll if not at
    // max scroll)
    if (msgbox->queue->count > LINES) {
        msgbox->scroll++;
        msgbox->max_scroll++;
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
