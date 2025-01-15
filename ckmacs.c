#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios terminal_attr;

void disable_raw_mode()
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal_attr);
}

void enable_raw_mode()
{
  tcgetattr(STDIN_FILENO, &terminal_attr);
  atexit(disable_raw_mode);

  struct termios raw = terminal_attr;
  raw.c_lflag &= ~(ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main()
{
  char c;
  enable_raw_mode();

  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'c');

  return 0;
}
