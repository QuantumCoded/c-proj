#include <ncurses.h>

int main() {
    int panel_width = 15;

    // Initialize the screen
    initscr();
    // Don't buffer characters
    cbreak();
    // Don't print typed characters
    noecho();

    WINDOW* main_window = newwin(LINES, COLS - panel_width, 0, 0);
    WINDOW* side_window = newwin(LINES, panel_width, 0, 0);

    return 0;
}
