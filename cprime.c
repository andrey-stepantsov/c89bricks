#include <stdio.h>

#ifndef CBricksLib_VERSION_MAJOR
#include "CBricksLibConfig.h"
#endif

int main() {
  printf("hello world, v%d.%d\n", CBricksLib_VERSION_MAJOR, CBricksLib_VERSION_MINOR);
  return 0;
}
