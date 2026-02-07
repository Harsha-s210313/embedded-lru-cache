/*
 * cache_internal.h
 *
 *  Created on: 06-02-2026
 *      Author: HARSHA
 */

#ifndef CACHE_CACHE_INTERNAL_H_
#define CACHE_CACHE_INTERNAL_H_

#include<stdint.h>
#include<stdbool.h>
#include<cache/cache_config.h>


typedef struct{
	uint8_t 		valid;
	uint32_t 		tag;
	uint8_t 		data[CACHE_LINE_SIZE];
}cache_line_t;


/*=====CACHE LINE STRUCTURE======*/
typedef struct{
	cache_line_t ways[CACHE_NUM_WAYS];
	uint8_t lru_counters[CACHE_NUM_WAYS];

}cache_set_t;


/*====STATISTICS STRUCTURE====*/
typedef struct{
	uint32_t		total_accesses;
	uint32_t		hits;
	uint32_t		misses;
	uint32_t		evictions;
}cache_stats_t;


#define CACHE_DATA_PTR				((cache_set_t*) CACHE_BASE_ADDR)
extern cache_stats_t g_cache_stats;


static inline uint32_t cache_get_offset(uint32_t addr){
	return addr & CACHE_OFFSET_MASK;
}


static inline uint32_t cache_get_set_index(uint32_t addr){
	return (addr >> CACHE_OFFSET_BITS) & CACHE_SET_INDEX_MASK;
}

static inline uint32_t cache_get_tag(uint32_t addr){
	return (addr>>(CACHE_OFFSET_BITS + CACHE_SET_INDEX_BITS));
}

static inline uint32_t cache_align_addr(uint32_t addr){
	return addr & ~CACHE_OFFSET_MASK;
}

static inline bool cache_is_cacheable(uint32_t addr){
	return (addr >= CACHE_FLASH_START) && (addr < CACHE_FLASH_END);
}
#endif /* CACHE_CACHE_INTERNAL_H_ */
