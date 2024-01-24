#include <ncurses.h>
#include "msgbox.h"
#include "panel.h"


void game_loop() {
    MSGBOX msgbox;
    PANEL panel;
    GAMESTATE state;

    state.hp = 10;
    state.max_hp = 100;
    state.mp = 50;
    state.max_mp = 100;

    msgbox.cols = COLS - PANEL_WIDTH - 1;

    init_msgbox(&msgbox);
    init_panel(&panel);

    write_line(&msgbox, "Welcome to My Game!");

    char ch;
    while((ch = getch()) != 'q')
    {
        update_panel(&panel, &state);
    }

    delwin(msgbox.pad);
    delwin(panel.window);
}
