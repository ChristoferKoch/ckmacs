#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include "include/ckmacs.h"

int main()
{
  char c;
  enable_raw_mode();

  while (1) {
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
      die("read");
    
    if (iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%c\r\n", c);
    }

    if (c == 3) break;
  }

  return 0;
}
