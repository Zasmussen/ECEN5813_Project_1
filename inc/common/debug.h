/**
 * @file debug.h
 * @brief debug header defining debug function prototypes
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */
 #ifndef __DEBUG_H__
 #define __DEBUG_H__

#include <stdint.h>
#include <stdlib.h>
 /**
  * @brief print_array prints the hex values pointed in memory of size length
  *
  * @param start is a byte pointer to the start of print pointing to a memory location
  * @param length is the size of bytes to print
  * @return is the size of the string located at ptr
  */
void print_array(uint8_t * start, uint32_t length);


void print_string(uint8_t * start, uint32_t length);
#endif
