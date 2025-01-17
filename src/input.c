#include <stdlib.h>
#include "../include/ckmacs.h"
#include "../include/term.h"

void process_input()
{
  char c = read_key();

  // Will need to create another function here for ctrl-x
  // and meta-x. Perhaps case CTRL('x'): read_extension(),
  // which leads to an addtional switch with input from
  // read_key()
  switch (c) {
  case CTRL('c'):
    exit(0);
    break;
  }
}
