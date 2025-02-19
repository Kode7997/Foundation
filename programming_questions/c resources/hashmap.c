/*
key, value
To handle collision = linkedlist

insert()
*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<pthread.h>

#define SIZE 10

struct Entry {

    char *key;
    char *value;
    struct Entry *next;
};

//create lock where data is updated
// another lock to track multiple readers

struct HashMap{
    struct Entry *arr[SIZE];
    pthread_mutex_lock data_lock;
    pthread_mutex_lock reader_lock;
    int readers;

};

//get_hash_key

//create_hashtable

//insert_to_hashtable

int get_hash_key(char *key) {

    int hash=0;
    int i = 0;

    while(key[i] != '\0') {
        hash = hash + key[i];
        i++;
    }

    return hash % SIZE;
}

struct HashMap* create_hashtable() {
    
    struct HashMap *map = (struct HashMap*)malloc(sizeof(struct HashMap));
    for(int i =0;i<SIZE;i++){
        map->arr[i]->key = NULL;
        map->arr[i]->value = NULL;
        map->arr[i]->next = NULL;
    }

    pthread_mutex_init(&map->data_lock, NULL);
    pthread_mutex_init(&map->reader_lock, NULL);
    map->readers = 0;

    return map;
}

void insert(struct HashMap *map, char *key, char *value){



    pthread_mutex_lock(&map->data_lock);

    int hash = get_hash_key(key);

    if (map->arr[hash] ==  NULL){
        map->arr[hash] = (struct Entry *)malloc(sizeof(struct Entry));
        map->arr[hash]->key = (char *)malloc(sizeof(strlen(key)+1));
        map->arr[hash]->value = (char *)malloc(sizeof(strlen(value)+1));

        strcpy(map->arr[hash]->key, key);
        strcpy(map->arr[hash]->value, value);
        map->arr[hash]->next = NULL;

        return;
    }
    else {
        struct Entry *node = map->arr[hash];
        struct Entry *prev=node;

        while (node != NULL)
        {   
            prev = node;
            node = node->next;
        }
        printf("last node\n");
        prev->next = (struct Entry *)malloc(sizeof(struct Entry));
        prev->next->key = (char *)malloc(sizeof(strlen(key)+1));
        prev->next->value = (char *)malloc(sizeof(strlen(value)+1));
        strcpy(prev->next->key,  key);
        strcpy(prev->next->value, value);
        prev->next->next = NULL;
        
    }

    pthread_mutex_unlock(&map->data_lock);
}



void delete(struct HashMap *map, char *key){


    pthread_mutex_lock(&map->data_lock);

    printf("delete\n");
    int hash = get_hash_key(key);
    printf("hash\n");

    if(map->arr[hash] == NULL) return;
    printf("hash null crossed\n");

    struct Entry *node = map->arr[hash];
    printf("key mwtch %s\n",node->key);
    if(strcmp(node->key, key) == 0){
            printf("key mwtch\n");
            map->arr[hash] = node->next;
            free(node);
            return;
    }else{
        printf("else");
        struct Entry *prev = node;
        node = node->next;

        while (node != NULL)
        {
            if(strcmp(node->key, key) == 0) {
                printf("enter delete successful\n");
                prev->next = node->next;
                node->next = NULL;
                free(node);
                printf("delete successful\n");
                return;
            }
        }
    }  

    pthread_mutex_lock(&map->data_lock);
}

char* read(struct HashMap *map, char *key){         // this allows the multiple users to read while there is no write.
    pthread_mutex_lock(&map->reader_lock);          // lock the "map->reader++" and unlock
    map->readers++;

    if(map->readers ==  1){
        pthread_mutex_lock(&map->writer_lock);      // lock the writer if reader count is 1
    }

    pthread_mutex_unlock(&map->reader_lock);        // unlock the reader_lock once reader_count is updated

    //read 
    // check if has key is present.                 // check the key is present

    pthread_mutex_lock(&map->reader_lock);          // protect the reader count while decrement using reader_lock
    map->readers--;
    if(map->readers ==  0){
        pthread_mutex_unlock(&map->writer_lock);    // if no reader then, unlock the writer lock
    }
    pthread_mutex_unlock(&map->reader_lock);        // unlock the reader_lock 

}


int main(){

    struct HashMap *map = create_hashtable();
    insert(map, "11.1.1.1","mac address");
    insert(map, "1.1.1.11","mac address");
    insert(map, "1.1.11.1","mac address");
    delete(map, "1.1.1.11");
    delete(map, "11.1.1.1");

}




