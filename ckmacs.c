#include "include/term.h"
#include "include/input.h"

int main()
{
  initialize_window();

  while (1) {
    refresh_screen();
    process_input();
  }

  return 0;
}
