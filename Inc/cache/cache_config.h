#ifndef CACHE_CACHE_CONFIG_H_
#define CACHE_CACHE_CONFIG_H_


#include <stdint.h>


/*
 * ====================================================================================================================================
 * CACHE CONFIGURATION
 * ====================================================================================================================================
 * Purpose: Configuring parameters for 4-way set associative LRU cache
 * Target:  STM32F4111RE (128KB RAM, 512KB FLASH)
 * Author:  ME
 * Date: 	05-02-2026
 */

#define CACHE_LINE_SIZE				64											//Line size defined for Cache
#define CACHE_NUM_WAYS				04											//4 way set associative

#define CACHE_SIZE					8*1024										//total cache size : 8KB


#define CACHE_NUM_LINES				(CACHE_SIZE / CACHE_LINE_SIZE)
#define CACHE_NUM_SET				(CACHE_NUM_LINES / CACHE_NUM_WAYS)

#define CACHE_OFFSET_BITS			06
#define CACHE_OFFSET_MASK			((1<<CACHE_OFFSET_BITS)-1)

#define CACHE_SET_INDEX_BITS		05
#define CACHE_SET_INDEX_MASK		((1<<CACHE_SET_INDEX_MASK)-1)

#define CACHE_TAG_BITS				21

#define CACHE_BASE_ADDR				0x20000000

#define CACHE_FLASH_START			0x08000000
#define CACHE_FLASH_END				0x0807FFFF

#define CACHE_ENABLE_STATS			1
#define CACHE_ENABLE_ASSERT			1

#if CACHE_ENABLE_ASSERT
#define CACHE_ASSERT(expr)	if(!(expr)) while(1)
#else
#define CACHE_ASSERT(expr)  ((void)0)

#endif /* CACHE_CACHE_CONFIG_H_ */
