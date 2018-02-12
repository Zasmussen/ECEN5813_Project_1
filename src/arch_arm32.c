/**
 * @file arch_arm32.c
 * @brief Implementation of Arm specific register functions
 *
 * Register maniupulation functions specific to an ARM system.
 * Currently extracts the ARM register which represents the 
 * endianness of the processor.
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */
#include "arch_arm32.h"
#include <stdint.h>

__attribute__((always_inline)) inline uint32_t ARM32_AIRCR_get_endianness_setting()
{
    return ((__AIRCR & __AIRCR_ENDIANNESS_MASK) >> __AIRCR_ENDIANNESS_OFFSET);
}
