/*
 * cache.c
 *
 *  Created on: 07-Feb-2026
 *      Author: HARSHA
 */


#include<cache/cache.h>
#include<cache/cache_internal.h>
#include<string.h>

cache_stats_t g_cache_stats = {0};

void cache_init(void){
	for (uint32_t set = 0; set< CACHE_NUM_SETS; set++){
		for (uint32_t way = 0; way< CACHE_NUM_WAYS; way++){
			CACHE_DATA_PTR[set].ways[way].valid = 0;
			CACHE_DATA_PTR[set].ways[way].tag = 0;
			CACHE_DATA_PTR[set].lru_counters[way] = way;
		}
	}
	memset(&g_cache_stats, 0, sizeof(cache_stats_t));
}

int cache_lookup(uint32_t addr){

	//call index of the address
	uint32_t set_index = cache_get_set_index(addr);

	//call tag of the address
	uint32_t tag = cache_get_tag(addr);

	//check if the required address is in the cache
	for(uint32_t way = 0; way < CACHE_NUM_WAYS; way++){

		if(CACHE_DATA_PTR[set_index].ways[way].valid){
			if(CACHE_DATA_PTR[set_index].ways[way].tag == tag){
				return way;
			}
		}
	}
	return -1;
}

void cache_update_lru(uint32_t set, uint32_t accessed_way){
	uint8_t old_counter = CACHE_DATA_PTR[set].lru_counters[accessed_way];

	for (uint32_t way=0; way < CACHE_NUM_WAYS; way++){
		if(CACHE_DATA_PTR[set].lru_counters[way] > old_counter){
			CACHE_DATA_PTR[set].lru_counters[way]-=1;
		}
	}
	CACHE_DATA_PTR[set].lru_counters[accessed_way] = 3;
}

uint8_t cache_find_lru_way(uint32_t set){
	for (uint32_t way=0; way< CACHE_NUM_WAYS; way++){
		if(CACHE_DATA_PTR[set].lru_counters[way]==0){
			return way;
		}
	}
	CACHE_ASSERT(0);
	return 0;
}

void flash_read_line(uint32_t flash__addr, uint8_t* buffer){
	uint32_t aligned_addr = cache_align_addr(flash_addr);
}
