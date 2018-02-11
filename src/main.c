#include "MKL25Z4.h"
#include "project1.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "conversion.h"
#include "data.h"
#include "debug.h"
#include "memory.h"
#include "platform.h"

int main(void)
{
  #ifdef PROJECT1
    project1();
  #endif
  while(1)
  {
    i++;
  }
}
