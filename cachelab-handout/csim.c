/* Implement the [-hv] option and the -s -E -b -t parameters*/
/* Error output: Usage() */
/* L:data load; M:data modify; S:data store; */
#include "cachelab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// function may be used
// atoi:convert a string to a interger
// strcat:cat hit/miss to the original string
// getopt:get optional speciphy
// bit level operation
typedef struct cache_line
{
    int valid;
    unsigned long tag;
    int dirty;
}cache_line;

int main(int argc,char** argv){
    /* Malloc memory for cache */
    int s = 4;
    int E = 1;
    int S = 1 << s;
    cache_line cache[S][E]; //dynamicly allocate afterwards
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < E; j++)
        {
            cache[i][j].valid = 0;
            cache[i][j].dirty = 0;
        }
        
    }
    int hits = 0;
    int misses = 0;
    int evictions = 0;
    /* process */
    FILE *trace = fopen(argv[1],"r");
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

    while (fscanf(trace," %c %lx,%d",&access_type,&address,&size) > 0)
    {   
        // decode address
        index = address << 56 >> 60;
        tag = address >> 8;
        printf("%lx %lx ",index,tag);
        // Load
        if (access_type == 'L')
        {
            if (cache[index][0].valid == 0)
            {
                misses += 1;
                cache[index][0].valid = 1;
                cache[index][0].tag = tag;
                printf("%c %lx,%d %s\n",access_type,address,size,"miss");
            }else if (cache[index][0].tag != tag)
            {
                misses += 1;
                evictions += 1;
                cache[index][0].valid = 1;
                cache[index][0].tag = tag;
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
            if (cache[index][0].valid == 0)
            {
                misses += 1;
                cache[index][0].valid = 1;
                printf("%c %lx,%d %s\n",access_type,address,size,"miss");
            }else if (cache[index][0].tag != tag)
            {
                misses += 1;
                evictions += 1;
                cache[index][0].valid = 1;
                cache[index][0].tag = tag;
                if (cache[index][0].dirty == 1)
                {
                    cache[index][0].dirty = 0;
                }
                printf("%c %lx,%d %s\n",access_type,address,size,"miss eviction");
            }else
            {
                hits += 1;
                cache[index][0].dirty = 1;
                printf("%c %lx,%d %s\n",access_type,address,size,"hit");
            }
        }
        //modify
        if (access_type == 'M')
        {
            if (cache[index][0].valid == 0)
            {
                misses += 1;
                cache[index][0].valid = 1;
                cache[index][0].tag = tag;
                printf("%c %lx,%d %s\n",access_type,address,size,"miss hit");
                hits += 1;
            }else if (cache[index][0].tag != tag)
            {
                misses += 1;
                evictions += 1;
                cache[index][0].valid = 1;
                cache[index][0].tag = tag;
                printf("%c %lx,%d %s\n",access_type,address,size,"miss eviction hit");
                cache[index][0].dirty = 1;
                hits += 1;
            }else
            {
                hits += 1;
                printf("%c %lx,%d %s\n",access_type,address,size,"hit");
                cache[index][0].dirty = 1;
            }
        }
    }
    printSummary(hits,misses,evictions);

    fclose(trace);

    /* Final Result */
}
