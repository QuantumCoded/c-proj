#ifndef MSGBOX_H_INCLUDED
#define MSGBOX_H_INCLUDED

#include <ncurses.h>

#define MSGBOX_LINES 256

typedef struct {
    char* lines[MSGBOX_LINES];
    int cols;
    int lines_wrote;
    int scroll;
    WINDOW* pad;
} MSGBOX;

void init_msgbox(MSGBOX* msgbox);
void write_line(MSGBOX* msgbox, char* line);

#endif
