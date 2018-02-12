/**
 * @file arch_arm32.h
 * @brief Arm specific register manipulation functions and macros
 *
 * Definition of ARM register address values and endianness extraction
 * function used to determine ARM processor endianness setting
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */


#ifndef __ARCH_ARM32_H__
#define __ARCH_ARM32_H__

#include <stdint.h>

#define __SCB_ADDRESS (0xE000ED00)
#define __AIRCR_ADDRESS_OFFSET (0x0C)
#define __AIRCR (__SCB_ADDRESS+__AIRCR_ADDRESS_OFFSET)
#define __AIRCR_ENDIANNESS_OFFSET (0xF)
#define __AIRCR_ENDIANNESS_MASK (0x8000)



/**
 * @brief Reads the AIRCR register and returns endianness of this read
 *
 * Extracts the ARM AIRCR register bit which tells the user what endianness
 * that the processor is in. 
 *
 * @return is the bit value of the endianness mode of the AIRCR register
 */
uint32_t ARM32_AIRCR_get_endianness_setting();


#endif
