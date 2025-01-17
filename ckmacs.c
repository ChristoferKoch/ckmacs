#include "include/term.h"
#include "include/input.h"

int main()
{
  enable_raw_mode();

  while (1) {
    process_input();
  }

  return 0;
}
