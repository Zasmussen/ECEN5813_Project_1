/**
 * @file conversion.h
 * @brief conversion header defining conversion function prototypes
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */
 #ifndef __CONVERSION_H__
 #define __CONVERSION_H__

#include <stdint.h>
#include <stdlib.h>
 /**
  * @brief Integer-to-ascii turns the 32-bit data into an ASCII string
  *
  * @param data represents the integer value to be converted
  * @param ptr is a byte pointer to the ASCII string
  * @param base is a base from 2 to 16 for conversion
  * @return is the size of the string located at ptr
  */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);



/**
 * @brief Ascii-to-integer turns ascii strings into integer values
 *
 * @param ptr is the ascii string to be converted
 * @param digits is the converted integer number
 * @param base is the converted number's base
 * @return is the digits converted number
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif
