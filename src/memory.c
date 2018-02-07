/**
 * @file memory.c
 * @brief Memory source implementing header functions
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */
#include "memory.h"
#include <stdint.h>
#include <stdlib.h>

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{

  uint32_t i;
  for(i=0;i<length;i++)
  {
    *(dst+i) = *(src+i);
  }
}

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{

}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{

  uint32_t i;
  for(i=0;i<length;i++)
  {
    *(src+i) = value;
  }
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{

  uint32_t i;
  for(i=0;i<length;i++)
  {
    *(src+i) = 0;
  }
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
  uint8_t * ret = src;
  uint32_t i;
  for(i=0;i<length/2;i++)
  {
    *(src+i) = *(src+length-1-i);
  }
  return ret;
}

void * reserve_words(size_t length)
{

}

uint8_t free_words(void * src)
{

}
