/**
 * @file debug.c
 * @brief debug source implementing debug functions
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "memory.h"
#include "data.h"

void print_cstd_type_sizes()
{
  size_t tmp;
  tmp = sizeof(char);
  printf("sizeof(char) = %lu\n", tmp);
  tmp = sizeof(short);
  printf("sizeof(short) = %lu\n", tmp);
  tmp = sizeof(long);
  printf("sizeof(long) = %lu\n", tmp);
  tmp = sizeof(double);
  printf("sizeof(double) = %lu\n", tmp);
  tmp = sizeof(float);
  printf("sizeof(float) = %lu\n", tmp);
  tmp = sizeof(unsigned char);
  printf("sizeof(unsigned char) = %lu\n", tmp);
  tmp = sizeof(unsigned int);
  printf("sizeof(unsigned int) = %lu\n", tmp);
  tmp = sizeof(unsigned long);
  printf("sizeof(unsigned long) = %lu\n", tmp);
  tmp = sizeof(signed char);
  printf("sizeof(signed char) = %lu\n", tmp);
  tmp = sizeof(signed int);
  printf("sizeof(signed int) = %lu\n", tmp);
  tmp = sizeof(signed long);
  printf("sizeof(signed long) = %lu\n", tmp);
}

void print_stdint_type_sizes()
{
  size_t tmp;
  tmp = sizeof(int8_t);
  printf("sizeof(int8_t) = %lu\n", tmp);
  tmp = sizeof(uint8_t);
  printf("sizeof(uint8_t) = %lu\n", tmp);
  tmp = sizeof(int16_t);
  printf("sizeof(int16_t) = %lu\n", tmp);
  tmp = sizeof(uint16_t);
  printf("sizeof(uint16_t) = %lu\n", tmp);
  tmp = sizeof(int32_t);
  printf("sizeof(int32_t) = %lu\n", tmp);
  tmp = sizeof(uint_fast8_t);
  printf("sizeof(uint_fast8_t) = %lu\n", tmp);
  tmp = sizeof(uint_fast16_t);
  printf("sizeof(uint_fast16_t) = %lu\n", tmp);
  tmp = sizeof(uint_fast32_t);
  printf("sizeof(uint_fast32_t) = %lu\n", tmp);
  tmp = sizeof(uint_least8_t);
  printf("sizeof(uint_least8_t) = %lu\n", tmp);
  tmp = sizeof(uint_least16_t);
  printf("sizeof(uint_least16_t) = %lu\n", tmp);
  tmp = sizeof(uint_least32_t);
  printf("sizeof(uint_least32_t) = %lu\n", tmp);
  tmp = sizeof(size_t);
  printf("sizeof(size_t) = %lu\n", tmp);
  tmp = sizeof(ptrdiff_t);
  printf("sizeof(ptrdiff_t) = %lu\n", tmp);

}

void print_pointer_sizes()
{
  size_t tmp;
  tmp = sizeof(char *);
  printf("sizeof(char *) = %lu\n", tmp);
  tmp = sizeof(short *);
  printf("sizeof(short *) = %lu\n", tmp);
  tmp = sizeof(int *);
  printf("sizeof(int *) = %lu\n", tmp);
  tmp = sizeof(long *);
  printf("sizeof(long *) = %lu\n", tmp);
  tmp = sizeof(double *);
  printf("sizeof(double *) = %lu\n", tmp);
  tmp = sizeof(float *);
  printf("sizeof(float *) = %lu\n", tmp);
  tmp = sizeof(void *);
  printf("sizeof(void *) = %lu\n", tmp);
  tmp = sizeof(int8_t *);
  printf("sizeof(int8_t *) = %lu\n", tmp);
  tmp = sizeof(int16_t*);
  printf("sizeof(int16_t *) = %lu\n", tmp);
  tmp = sizeof(int32_t *);
  printf("sizeof(int32_t *) = %lu\n", tmp);
  tmp = sizeof(char **);
  printf("sizeof(char **) = %lu\n", tmp);
  tmp = sizeof(int **);
  printf("sizeof(int **) = %lu\n", tmp);
  tmp = sizeof(void **);
  printf("sizeof(void **) = %lu\n", tmp);

}

int32_t swap_data_endianness(uint8_t * data, size_t type_length)
{
  if(data==NULL || type_length <= 0)        //Protection against NULL pointer or malformed array length
  {
    return SWAP_ERROR;
  }

  uint32_t i;
  for(i=0;i<(type_length/2);i++)
  {
    uint8_t tmp = *(data+i);
    *(data+i) = *(data+type_length-1-i);
    *(data+type_length-1-i) = tmp;
  }
  return SWAP_NO_ERROR;
}

uint32_t determine_endianness()
{
  uint32_t data = 0x12345678;
  uint8_t * ptr = (uint8_t *)&data;
  if(*ptr == 0x78)
  {
    return LITTLE_ENDIAN;
  }
  else if(*ptr == 0x12)
  {
    return BIG_ENDIAN;
  }
  else
  {
    return -1;
  }
}
