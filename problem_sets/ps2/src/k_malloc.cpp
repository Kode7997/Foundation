#include "../include/k_malloc.hh"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sys/mman.h>
#include <cstddef>

struct k_memory_buffer{

  unsigned long long int size= 8 << 20;
  char *buffer;
  unsigned long long int pos = 0;

  k_memory_buffer();
  ~k_memory_buffer();

};


static k_memory_buffer dbuffer;

k_memory_buffer::k_memory_buffer(){
  
  // mmap = block the memory to virtual space where process can access
  void *buff = mmap(nullptr, dbuffer.size, PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
  
  if(buff == MAP_FAILED){
    fprintf(stdout, "failed to init buffer\n");
    exit(0);    
  }
  
  dbuffer.buffer = (char *)buff;
}

k_memory_buffer::~k_memory_buffer(){

  munmap(dbuffer.buffer, dbuffer.size);
}

void* k_malloc(unsigned long long int sz, char* file, int line){

  (void) file, (void) line;

  if(dbuffer.pos+sz > dbuffer.size){
    fprintf(stdout, "no memory space");
    return nullptr;
  }

  // pointer points to the memory address
  void *ptr = &dbuffer.buffer[dbuffer.pos];
  dbuffer.pos = dbuffer.pos + sz;

  return ptr;
}

void k_free(void *ptr, const char* file, int line){

  (void)ptr, (void)file, (void)line;
}

void* k_calloc(unsigned long long int count, unsigned long long int sz, char* file, int line){

  void *ptr = k_malloc(count * sz, file, line);

  if (ptr == nullptr){
    exit(0);
  }

  memset(ptr, 0, count * sz);

  return ptr;
}


k_statistics k_statistics_get(){

  k_statistics k_mem_stats;

  memset(&k_mem_stats, 255, sizeof(k_statistics));
  return k_mem_stats;
}

/*
unsigned long long int nactive;
  unsigned long long int active_size;
  unsigned long long int nalloc;
  unsigned long long int total_size;
  unsigned long long int nfailed_alloc;
  unsigned long long int nfailed_size;
  uintptr_t heap_min;
  uintptr_t heap_max;
*/


void k_statistics_print(){
  k_statistics k_mem_stats = k_statistics_get();

  printf("alloc count: active %10llu   total %10llu   fail %10llu\n",
      k_mem_stats.nactive, k_mem_stats.nalloc, k_mem_stats.nfailed_alloc);
  
  printf("alloc size:  active %10llu   total %10llu   fail %10llu\n",
    k_mem_stats.active_size, k_mem_stats.total_size, k_mem_stats.nfailed_size);
  
  return;
}

