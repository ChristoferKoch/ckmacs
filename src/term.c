#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <termios.h>

struct termios terminal_attr;

void die(const char *s)
{
  perror(s);
  exit(1);
}

void disable_raw_mode()
{
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal_attr) == -1)
    die("tcsetattr");
}

void enable_raw_mode()
{
  if (tcgetattr(STDIN_FILENO, &terminal_attr) == -1)
    die("tcgetattr");
  atexit(disable_raw_mode);

  struct termios raw = terminal_attr;
  raw.c_iflag &= ~(ICRNL | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
    die("tcsetattr");
}
