#include <ncurses.h>
#include "colors.h"
#include "game.h"

int main() {
    initscr(); // Initialize the screen
    cbreak(); // Don't buffer characters
    noecho(); // Don't print typed characters
    keypad(stdscr, true); // Initialize the keypad
    timeout(10);
    curs_set(0); // Make the cursor invisible
    init_colors(); // Initialize the colors

    refresh();

    game_loop();

    endwin();

    return 0;
}
