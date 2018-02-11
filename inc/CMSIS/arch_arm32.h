/**
 * @file arch_arm32.h
 * @brief Arm specific register manipulation functions and macros
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */


#ifndef __ARCH_ARM32_H__
#define __ARCH_ARM32_H__

#include <stdint.h>

#define __SCB_ADDRESS ()
#define __AIRCR_ADDRESS_OFFSET ()
#define __AIRCR ()
#define __AIRCR_ENDIANNESS_OFFSET ()
#define __AIRCR_ENDIANNESS_MASK ()



/**
 * @brief Reads the AIRCR register and returns endianness of this read
 *
 * @return is the bit value of the endianness mode of the AIRCR register
 */
uint32_t ARM32_AIRCR_get_endianness_setting();


#endif
