#include <unistd.h>

void refresh_screen()
{
  write(STDOUT_FILENO, "\x1b[2J", 4);
}
