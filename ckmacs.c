#include "include/term.h"
#include "include/input.h"
#include "include/output.h"

int main()
{
  initialize_window();

  while (1) {
    process_input();
    refresh_screen();
  }

  return 0;
}
