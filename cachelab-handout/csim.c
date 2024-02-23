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
typedef struct cache_line
{
    int valid;
    int dirty;
    unsigned long tag;
    int date;
}cache_line;

/* Results */
int hits = 0;
int misses = 0;
int evictions = 0;
/* Arguments */
char* filename = NULL;
int sets = 0;
int lines = 0;
int blocks = 0;
int verbose_flag = 0;
/* Process variables */
unsigned long id = 0;
unsigned long tag = 0;
unsigned long offset = 0;
int date = 0; // record the date


char access_type;
unsigned long address = 0;
int size = 0;
int block_size = 0;
cache_line* cur_cache_line = NULL;
/* Process functions */
void Cold_Loading(cache_line* bad_line);
void Conflict(cache_line* bad_line);
void Option_Token(int argc,char* argv[]);
void Help();
void Address_Decode(cache_line* cache);
void Load_Process();
void Store_Process();
void Modify_Process();
/*************************************************/
/****************** Main *************************/
/*************************************************/
int main(int argc,char* argv[]){
    Option_Token(argc,argv);
    /* Malloc memory for cache */
    cache_line* cache = (cache_line*)malloc((1 << sets) * lines * sizeof(cache_line));
    if (cache == NULL)
    {
        fprintf(stderr,"can not malloc memory\n");
        exit(1);
    }
    /* Initialize */
    for (int i = 0; i < sets; i++)
    {
        for (int j = 0; j < lines; j++)
        {
            (cache + i * lines + j)->valid = 0;
            (cache + i * lines + j)->dirty = 0;
            (cache + i * lines + j)->date  = 0;
        }
        
    }
    /* process */
    FILE *trace = fopen(filename,"r");
    if (trace == NULL)
    {
        fprintf(stderr,"can not open file for reading\n");
        exit(1);
    }
    while (fscanf(trace," %c %lx,%d",&access_type,&address,&size) > 0)
    {   
        date += 1;
        Address_Decode(cache);
        if (access_type == 'L') Load_Process();
        if (access_type == 'S') Store_Process();
        if (access_type == 'M') Modify_Process();
        //printf("%d\n",cur_cache_line->date);
    }
    printSummary(hits,misses,evictions);
    free(cache);
    fclose(trace);
    return 0;
}

void Option_Token(int argc,char* argv[]){
    int opt;
    while ((opt = getopt(argc,argv,"hvs:E:b:t:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            Help();
            break;
        case 'v':
            verbose_flag = 1;
            break;
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
            Help();
            break;
        }
    }
}
void Cold_Loading(cache_line* bad_line){
    misses += 1;
    bad_line->valid = 1;
    bad_line->tag = tag;
    bad_line->date = date;
}
void Conflict(cache_line* bad_line){
    misses += 1;
    evictions += 1;
    bad_line->valid = 1;
    bad_line->tag = tag;
    bad_line->date = date;
    if (bad_line->dirty == 1)
    {
        bad_line->dirty = 0;
    }
}
void Address_Decode(cache_line* cache){
    // decode address
    id = address << (64 - sets - blocks) >> (64 - sets);
    tag = address >> (sets + blocks);
    offset = address % (1 << blocks);
    block_size = 1 << blocks;
    cur_cache_line = cache + id * lines;
}
void Load_Process(){
    /* Check if there is a hit and record the LRU */
    int longest_period = cur_cache_line->date;
    int cur_line;
    cache_line* Lru_Line = cur_cache_line;
    for (cur_line = 0; cur_line < lines; cur_line++)
    {
        if (cur_cache_line->date < longest_period)
        {
            longest_period = cur_cache_line->date;
            Lru_Line = cur_cache_line;
        }
        
        if (cur_cache_line->valid == 1 && ((cur_cache_line->tag == tag) && (offset <= block_size)))
        {
            hits += 1;
            cur_cache_line->date = date;
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"hit ");
            break;
        }
        else cur_cache_line++;
    }
    if (cur_line == lines)
    {
        /* if not, LRU policy */
        if (Lru_Line->valid == 1)
        {
            Conflict(Lru_Line);
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"miss eviction ");
        } else
        {
            Cold_Loading(Lru_Line);
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"miss ");
        }
    }
}
void Store_Process(){
    int longest_period = cur_cache_line->date;
    cache_line* Lru_Line = cur_cache_line;
    int cur_line;
    for (cur_line = 0; cur_line < lines; cur_line++)
    {
        if (cur_cache_line->date < longest_period)
        {
            longest_period = cur_cache_line->date;
            Lru_Line = cur_cache_line;
        }
        /* Check if there is a hit and record the LRU */ 
        if (cur_cache_line->valid == 1 && ((cur_cache_line->tag == tag) && (offset <= block_size)))
        {
            hits += 1;
            cur_cache_line->date = date;
            cur_cache_line->dirty = 1;
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"hit ");
            break;
        }
        else cur_cache_line++;
    }
    if (cur_line == lines)
    {
        /* if not, LRU policy */
        if (Lru_Line->valid == 1)
        {
            Conflict(Lru_Line);
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"miss eviction ");
        } else
        {
            Cold_Loading(Lru_Line);
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"miss ");
        }
    }
}
void Modify_Process(){
    int longest_period = cur_cache_line->date;
    cache_line* Lru_Line = cur_cache_line;
    int cur_line;
    for (cur_line = 0; cur_line < lines; cur_line++)
    {
        if (cur_cache_line->date < longest_period)
        {
            longest_period = cur_cache_line->date;
            Lru_Line = cur_cache_line;
        }
        /* Check if there is a hit and record the LRU */ 
        if (cur_cache_line->valid == 1 && ((cur_cache_line->tag == tag) && (offset <= block_size)))
        {
            hits += 2;
            cur_cache_line->date = date;
            cur_cache_line->dirty = 1;
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"hit hit ");
            break;
        }
        else cur_cache_line++;
    }
    if (cur_line == lines)
    {
        /* if not, LRU policy */
        if (Lru_Line->valid == 1)
        {
            Conflict(Lru_Line);
            hits += 1;
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"miss eviction hit ");
        } else
        {
            Cold_Loading(Lru_Line);
            hits += 1;
            if (verbose_flag == 1) printf("%c %lx,%d %s\n",access_type,address,size,"miss hit ");
        }   
    }
}
void Help(){
    printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("Examples:\n");
    printf("  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
    exit(1);
}
