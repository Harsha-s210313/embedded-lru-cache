/*
 * cache.h
 *
 *  Created on: 07-Feb-2026
 *      Author: HARSHA
 */

#ifndef CACHE_CACHE_H_
#define CACHE_CACHE_H_


#include<stdint.h>
#include<stdbool.h>
#include<cache/cache_internal.h>


typedef enum{
	CACHE_OK 		= 0,
	CACHE_ERROR 	= -1,
	CACHE_HIT 		= 1,
	CACHE_MISS 		= 0,
}cache_status_t;

void cache_init(void);

int cache_lookup(uint32_t addr);

void cache_update_lru(uint32_t set, uint32_t accessed_way);

uint8_t cache_find_lru_way(uint32_t set);

cache_stats_t cache_get_status(void);

void cache_reset_stats(void);


#endif /* CACHE_CACHE_H_ */
