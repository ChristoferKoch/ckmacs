#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include "../include/term.h"

void refresh_screen()
{
  wrefresh(win);
}
