/*
strucutre
insert
lookup
delete
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct Entry{
    char *key;
    char *val;
    struct Entry *next;
}Entry;


typedef struct HashTable {
    Entry *bucket[SIZE];
}hashtable;

//create hashtable
hashtable *create_hashtable(){
    hashtable *table = malloc(sizeof(hashtable));
    for(int i=0;i<SIZE;i++) {
        table->bucket[i] = NULL;
    }

    return table;
}

long int hash(char *key){

    unsigned long int value = 0;
    for(int i=0;i<strlen(key); i++){
        value = value + (int)key[i];
    }

    return value % SIZE; // most import part of hashing
}

void insert(hashtable *table, char *key, char *value){
    long int hash_key = hash(key);
    Entry *entry = table->bucket[hash_key];
    if (entry == NULL){
        table->bucket[hash_key] = (Entry *)malloc(sizeof(Entry));
        table->bucket[hash_key]->key = key;
        table->bucket[hash_key]->val = value;
        table->bucket[hash_key]->next = NULL;
    }else{
       Entry *prev = NULL;
       while( entry != NULL){
        if (strcmp(entry->key, key)== 0){
            free(entry->val);
            entry->val = value;
            return;
        }
        prev = entry;
        entry = entry->next;
       }
       prev->next = malloc(sizeof(Entry));
       prev->next->key = key;
       prev->next->val = value;
       prev->next->next = NULL;
    }
}


int main(){
    
    hashtable *table = create_hashtable();
    insert(table, "key", "value");
    insert(table, "yek", "eulav");
    // unsigned long int hash_key = hash("keshav");
    // printf("%lu",hash_key);
    return 0;
}
