#include <ncurses.h>

int main() {
    int panel_width = 15;

    initscr(); // Initialize the screen
    cbreak(); // Don't buffer characters
    noecho(); // Don't print typed characters
    keypad(stdscr, true); // Initialize the keypad

    printw("Hello World");
    refresh();

    getch();

    WINDOW* main_window = newwin(LINES, COLS - panel_width, 0, 0);
    WINDOW* side_window = newwin(LINES, panel_width, 0, 0);

    endwin();

    return 0;
}
