#include <ncurses.h>
#include <stdlib.h>
#include "msgbox.h"
#include "panel.h"


void game_loop() {
    MSGBOX msgbox;
    MSGQUEUE msgqueue;
    PANEL panel;
    GAMESTATE state;

    // TODO: this should be loaded from a save state
    state.hp = 10;
    state.max_hp = 100;
    state.mp = 50;
    state.max_mp = 100;

    msgbox.cols = COLS - PANEL_WIDTH - 1;
    msgbox.queue = &msgqueue;

    init_msgbox(&msgbox);
    init_panel(&panel);

    for (int i = 0; i < 43; i++) {
        char* buf = malloc(50);
        sprintf(buf, "Thing %d", i);
        write_line(&msgbox, buf);
    }

    char ch;
    while((ch = getch()) != 'q')
    {
        update_panel(&panel, &state);
    }

    delwin(msgbox.pad);
    delwin(panel.window);
}
