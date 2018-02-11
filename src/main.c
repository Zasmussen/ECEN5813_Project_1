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
  uint32_t i = 0;
  // uint8_t *ptr = (uint8_t*)reserve_words(10);
  // uint8_t digits = my_itoa(-0x1234, ptr, 16);
  // int32_t value = my_atoi(ptr, digits, 16);
  // printf("%d\n", value);
  //print_string(ptr, digits);

  //project1();
  int8_t ret;
  //uint32_t data = 0x1234567;
  //printf("%#09x\n", data);
  //ret = swap_data_endianness((uint8_t *)&data, sizeof(data));
  //printf("%#09x\n", data);
  ret = determine_endianness();
  printf("%d\n", ret);
  // uint8_t * ptr = (uint8_t *)reserve_words(2);
  // for(i=0;i<8;i++)
  // {
  //   *(ptr+i) = i;
  // }
  //uint8_t arr[11] = {0x34, 0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xAD, 0xFE};
  //my_memset(arr, 11, 5);
  //my_memzero(arr, 11);
  //my_reverse(arr, 11);
//  printf("\nNext\n");
  // for(i=0;i<12;i++)
  // {
  //   printf("%#02x\n", *(ptr+i));
  // }
  //test_memmove1();
  //printf("%#02x %#02x %#02x %#02x \n", *out, *(out+1), *(out+2), *(out+3));
  while(1)
  {
    i++;
  }
}
