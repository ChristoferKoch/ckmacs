#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

WINDOW *win;

void free_window()
{
  endwin();
}

void initialize_window()
{
  initscr();
  win = newwin(0, 0, 0, 0);
  atexit(free_window);
}

void refresh_screen()
{
  wrefresh(win);
}
