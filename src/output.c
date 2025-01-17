#include <unistd.h>
#include <curses.h>

WINDOW *win;

void initialize_window()
{
  initscr();
  win = newwin(0, 0, 0, 0);
}

void refresh_screen()
{
  wrefresh(win);
}
