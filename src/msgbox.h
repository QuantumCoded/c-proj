#ifndef MSGBOX_H_INCLUDED
#define MSGBOX_H_INCLUDED

#include <ncurses.h>

#define MSGBOX_LINES 256

typedef struct {
    char* messages[MSGBOX_LINES];
    int count;
} MSGQUEUE;

typedef struct {
    MSGQUEUE* queue;
    int cols;
    int lines_wrote;
    int scroll;
    int max_scroll;
    WINDOW* pad;
} MSGBOX;

void init_msgbox(MSGBOX* msgbox);
void write_line(MSGBOX* msgbox, char* line);

#endif
