#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
hashmap = table with key, value pair
*/

#define SIZE 10

struct Entry{
    char *key;
    char *val;
    struct Entry *next;
};
typedef struct Entry *entry;

struct HashTable {
    struct Entry *bucket[SIZE];
};

typedef struct HashTable *hashtable;

hashtable create_table(){

    hashtable table = (hashtable)malloc(sizeof(struct HashTable));
    for(int i=0;i<SIZE; i++){
        table->bucket[i] = NULL;
    }
    return table;
}

int k_hash(char *key){
    int hash = 0;
    
    for(int i=0; i<strlen(key); i++) {
        hash = hash + (int)(key[i]);
    }

    return (hash % SIZE);
    }

void insert(hashtable hmap, char *key, char *val){

    int hash_key = k_hash(key);

    if (hmap->bucket[hash_key] ==  NULL) {
        hmap->bucket[hash_key] = (entry)malloc(sizeof(struct Entry));
        hmap->bucket[hash_key]->key = (char *)malloc(sizeof(strlen(key)+1));
        hmap->bucket[hash_key]->val = (char *)malloc(sizeof(strlen(val)+1));
        strcpy(hmap->bucket[hash_key]->key, key);
        strcpy(hmap->bucket[hash_key]->val, val);
        
        printf("new member added\n");
        hmap->bucket[hash_key]->next = NULL;
    } else {
        entry prev = NULL;
        entry node = hmap->bucket[hash_key];
        while (node != NULL){
            if (strcmp(node->key, key) == 0){
                printf("updated with new value\n");
                free(node->val);                                    //free memory before update
                node->val = (char *)malloc(sizeof(strlen(val)+1));
                strcpy(node->val, val);
                return;
            }
            prev = node;
            node = node->next;
        }

        if (node == NULL) {
            printf("insert at end of linked list\n");
            entry new_entry = (entry)malloc(sizeof(struct Entry));
            
            new_entry->key = (char *)malloc(sizeof(strlen(key)+1));
            new_entry->val = (char *)malloc(sizeof(strlen(val)+1));
            
            strcpy(new_entry->key, key);
            strcpy(new_entry->val, val);
            new_entry->next = NULL;
            prev->next = new_entry;
        }

    }
  
    }


int main(){

    hashtable hmap = create_table();
    int hash = k_hash("name");

    insert(hmap ,"name","keshav");
    insert(hmap, "enam","cisco");
    insert(hmap, "enam","cisco pvt limited");

    /*
    memory handling
    - free val, key
    - free node 
    - table 
    */
    return 0;
}