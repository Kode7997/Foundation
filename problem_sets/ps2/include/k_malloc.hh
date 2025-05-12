#include<cinttypes>

#ifndef K_MALLOC_HH
#define K_MALLOC_HH 1


struct k_statistics {

  unsigned long long int nactive;
  unsigned long long int active_size;
  unsigned long long int nalloc;
  unsigned long long int total_size;
  unsigned long long int nfailed_alloc;
  unsigned long long int nfailed_size;
  uintptr_t heap_min;
  uintptr_t heap_max;
};

void *k_malloc(unsigned long long int sz, const char* file, int line);
void *k_calloc( unsigned long long int count, unsigned long long int sz, const char* file, int line);
void k_free(void *ptr, const char* file, int line);
//void *k_realloc();


k_statistics k_statistics_get();

void k_statistics_print();

void k_statistics_leak_report();


#endif

