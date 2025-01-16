#include "include/ckmacs.h"

int main()
{
  enable_raw_mode();

  while (1) {
    process_input();
  }

  return 0;
}
