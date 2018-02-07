#include "MKL25Z4.h"
#include "project1.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "conversion.h"
#include "data.h"
#include "debug.h"
#include "memory.h"

int main(void)
{
  uint32_t i;
  //project1();
  uint32_t src = 0xABCD;
  uint8_t * out = my_reverse(&src, 4);
  // for(i=0;i<4;i++)
  // {
  //   uint8_t tmp = *(out+i);
  //   printf("%#06x\n", tmp);
  // }
  printf("%d\n", out);
  while(1)
  {
    i++;
  }
}
