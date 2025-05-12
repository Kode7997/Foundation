/*
- key, value
- collision
    - linked list
- hash_key 
- insert
- search
- delete 

- read/write problem
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

struct Node {
    char *key;
    char *value;
    struct Node *next;
};

struct HashMap{
    int capacity;
    struct Node **bucket;
};

struct HashMap* create_hashmap(int capacity) {

    if(capacity == 0) return NULL;

    struct HashMap* hmap = (struct HashMap *)malloc(sizeof(struct HashMap));
    
    if(hmap ==  NULL) return NULL;

    hmap->capacity = capacity;

    hmap->bucket = (struct Node**)malloc(capacity * sizeof(struct Node));

    for(int i=0;i<hmap->capacity;i++){
        hmap->bucket[i] = NULL;
    }

    return hmap;

}

int get_hash_key(char *key){
    int hash = 0;
    for (int i=0; key[i] != '\0';i++){
        hash = hash + key[i] + 0;
    }

    return (hash % SIZE);
}

struct Node* create_node(char *key, char *value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = (char *)malloc(strlen(key)+1);
    node->value = (char *)malloc(strlen(value)+1);
    strcpy(node->key, key);
    strcpy(node->value, value);
    node->next = NULL;

    return node;
}

int insert(struct HashMap *hmap, char *key, char *value){
    
    if ((key == NULL) || (hmap == NULL)) return -1;

    int hash = get_hash_key(key);
    printf("hash values %d\n", hash);
    
    struct Node* new_node = create_node(key, value);

    if(hmap->bucket[hash] == NULL){
        //create node and add to bucket at index of hash value
        hmap->bucket[hash] = new_node;
        return 1;
    }else{
        // if same key already exist then change the value
        struct Node* node = hmap->bucket[hash];
        struct Node *prev;
        while(node != NULL) {
            prev = node;
            if (strcmp(node->key, key)==0){
                free(node->value);
                node->value = (char *)malloc(strlen(value)+1);
                strcpy(node->value, value);
                return 1;
            }
            node = node->next;
        }
        // else add newnode to the index and next will be existing node at index of hash
        prev->next = new_node;
    }
    return -1;
}

int delete(struct HashMap *hmap, char *key){

    int hash = get_hash_key(key);

    if (hmap->bucket[hash] == NULL){
        return -1;
    }else{
        struct Node* node = hmap->bucket[hash];
        if(strcmp(node->key, key)==0){
            hmap->bucket[hash] = node->next;
            free(node->key);
            free(node->value);
            free(node);
            return 1;
        }else{
            struct Node* prev=NULL;
            while (node != NULL)
            {   
                prev = node;
                if(strcmp(node->key, key)==0){
                    prev->next = node->next;
                    free(node->key);
                    free(node->value);
                    free(node);
                    return 1;
                }
                node = node->next;
            }
            if (prev){
                printf("Key %s not present!\n", key);
                return -1;
            }
            
        }
    }
    return -1;
}

void display(struct HashMap *hmap){
    for(int i=0;i<hmap->capacity;i++){
       if(hmap->bucket[i] != NULL){
           struct Node* node = hmap->bucket[i];
           while (node != NULL)
           {
               printf("index i: %d Key: %s value: %s\n",i, node->key, node->value);
               node = node->next;
           }
           
       }else{
           printf("index i: %d is empty\n",i);
       }
    }
}

int main(){

    struct HashMap *hmap = create_hashmap(SIZE);
    
    if (hmap == NULL){
        printf("HashMap creation failed\n");
    }

    insert(hmap, "10","ten");
    insert(hmap, "20","twenty");
    insert(hmap, "01","one");
    insert(hmap, "02", "two");
    insert(hmap, "ten", "10");
    insert(hmap, "net", "10");
    insert(hmap, "net", "100");

    display(hmap);
    delete(hmap, "etn");
    display(hmap);

    //freehashmap();
    return 0;
}
