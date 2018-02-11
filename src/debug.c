/**
 * @file debug.c
 * @brief debug source implementing debug functions
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */
#include "debug.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void print_array(uint8_t * start, uint32_t length)
{
#ifdef VERBOSE
  uint32_t i;
  for(i=0;i<length-1;i++)
  {
    printf("%d,", *(start+i));
  }
  printf("%d\n", *(start+i));
#endif
  return;
}

void print_string(uint8_t * start, uint32_t length)
{
  uint32_t i;
  for(i=0;i<length-1;i++)
  {
    printf("%c", *(start+i));
  }
  printf("%c\n", *(start+i));
}
