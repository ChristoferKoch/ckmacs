#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
  raw.c_iflag &= ~(ICRNL | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main()
{
  char c;
  enable_raw_mode();

  while (1) {
    read(STDIN_FILENO, &c, 1);
    
    if (iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%c\r\n", c);
    }

    if (c == 3) break;
  }

  return 0;
}
