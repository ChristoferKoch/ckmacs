#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <curses.h>

WINDOW *win;

void die(const char *s)
{
  perror(s);
  exit(1);
}

void free_window()
{
  noraw();
  echo();
  endwin();
}

void initialize_window()
{
  initscr();
  if (raw() == -1) die("raw");
  if (noecho() == -1) die("noecho");

  win = newwin(0,0,0,0);
  
  atexit(free_window);
}

void refresh_screen()
{
  wrefresh(win);
}

char read_key()
{
  int nread;
  char c;

  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    if (nread == -1 && errno != EAGAIN)
      die("read");
  }

  return c;
}
