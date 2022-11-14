#include "singleton.h"
#include <stdio.h>

int main()
{
  Log *ptrlog1 = Log::initLog();
  Log *ptrlog2 = Log::initLog();

  printf("ptrlog1 = %p\n", ptrlog1);
  printf("ptrlog2 = %p\n", ptrlog2);

  return 0;
}