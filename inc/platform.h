/**
 * @file platform.h
 * @brief
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */


#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifdef VERBOSE
#define PRINTF printf
#endif

#ifndef VERBOSE
#define PRINTF(...)
#endif


#endif
