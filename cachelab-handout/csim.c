/* Implement the [-hv] option and the -s -E -b -t parameters*/
/* Error output: Usage() */
/* L:data load; M:data modify; S:data store; */
#define _GNU_SOURCE
#include "cachelab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
// function may be used
// atoi:convert a string to a interger
// getopt:get optional speciphy
typedef struct cache_line
{
    int valid;
    int dirty;
    unsigned long tag;
}cache_line;

int main(int argc,char* argv[]){
    /* Malloc memory for cache */
    int sets,lines,blocks;
    char* filename = NULL;
    int opt;
    while ((opt = getopt(argc,argv,"s:E:b:t:")) != -1)
    {
        switch (opt)
        {
        case 's':
            sets = atoi(optarg);
            break;
        case 'E':
            lines = atoi(optarg);
            break;
        case 'b':
            blocks = atoi(optarg);
            break;
        case 't':
            filename = optarg;
            break;
        default:
            break;
        }
    }
    cache_line* cache = (cache_line*)malloc((1 << sets) * lines * sizeof(cache_line));
    if (!cache)
    {
        fprintf(stderr,"can not malloc memory\n");
        exit(1);
    }
    for (int i = 0; i < sets; i++)
    {
        for (int j = 0; j < lines; j++)
        {
            (cache + i * lines + j)->valid = 0;
            (cache + i * lines + j)->dirty = 0;
        }
        
    }
    int hits = 0;
    int misses = 0;
    int evictions = 0;
    /* process */
    FILE *trace = fopen(filename,"r");
    if (!trace)
    {
        fprintf(stderr,"can not open file for reading\n");
        exit(1);
    }

    char access_type;
    unsigned long address;
    int size;

    unsigned long index;
    unsigned long tag;
    unsigned long offset;
    int block_size;
    cache_line* cur_cache_line = NULL;
    while (fscanf(trace," %c %lx,%d",&access_type,&address,&size) > 0)
    {   
        // decode address
        index = address << (64 - sets - blocks) >> (64 - sets);
        tag = address >> (sets + blocks);
        offset = address % (1 << blocks);
        block_size = 1 << blocks;
        cur_cache_line = cache + index * lines;
        printf("%lx %lx %lx ",index,tag,offset);
        
        // Load
        if (access_type == 'L')
        {
            if (cur_cache_line->valid == 0)
            {
                misses += 1;
                cur_cache_line->valid = 1;
                cur_cache_line->tag = tag;
                printf("%c %lx,%d %s\n",access_type,address,size,"miss");
            }else if ((cur_cache_line->tag != tag) || (offset > block_size))
            {
                misses += 1;
                evictions += 1;
                cur_cache_line->valid = 1;
                cur_cache_line->tag = tag;
                if (cur_cache_line->dirty == 1)
                {
                    cur_cache_line->dirty = 0;
                }
                printf("%c %lx,%d %s\n",access_type,address,size,"miss eviction");
            }else
            {
                hits += 1;
                printf("%c %lx,%d %s\n",access_type,address,size,"hit");
            }  
        }
        // Store
        if (access_type == 'S')
        {
            if (cur_cache_line->valid == 0)
            {
                misses += 1;
                cur_cache_line->valid = 1;
                cur_cache_line->tag = tag;
                printf("%c %lx,%d %s\n",access_type,address,size,"miss");
            }else if ((cur_cache_line->tag != tag) || (offset > block_size))
            {
                misses += 1;
                evictions += 1;
                cur_cache_line->valid = 1;
                cur_cache_line->tag = tag;
                if (cur_cache_line->dirty == 1)
                {
                    cur_cache_line->dirty = 0;
                }
                printf("%c %lx,%d %s\n",access_type,address,size,"miss eviction");
            }else
            {
                hits += 1;
                //here set dirty to 1 will cause segfault
                cur_cache_line->dirty = 1;
                printf("%c %lx,%d %s\n",access_type,address,size,"hit");
            }
        }
        //modify
        if (access_type == 'M')
        {
            if (cur_cache_line->valid == 0)
            {
                misses += 1;
                hits += 1;
                cur_cache_line->valid = 1;
                cur_cache_line->tag = tag;
                printf("%c %lx,%d %s\n",access_type,address,size,"miss hit");
            }else if ((cur_cache_line->tag != tag) || (offset > block_size))
            {
                misses += 1;
                evictions += 1;
                hits += 1;
                cur_cache_line->valid = 1;
                cur_cache_line->tag = tag;
                if (cur_cache_line->dirty == 1)
                {
                    cur_cache_line->dirty = 0;
                }
                printf("%c %lx,%d %s\n",access_type,address,size,"miss eviction hit");
            }else
            {
                hits += 2;
                cur_cache_line->dirty = 1;
                printf("%c %lx,%d %s\n",access_type,address,size,"hit hits");
            }
        }
    }
    printSummary(hits,misses,evictions);
    free(cache);
    fclose(trace);
    return 0;
}
