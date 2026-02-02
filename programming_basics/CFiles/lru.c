// struct Node{
//     int data;
//     struct Node *prev;
//     struct Node *next;
// };

// struct LRU{
//     struct Node **cache;
//     int capacity;
//     int size;
//     struct Node *head;
//     struct Node *tail;
// };
// add to cache
// get cache = move to head, remove node

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Doubly linked list node
struct dllNode {
    char *key;
    char *value;
    struct dllNode *prev;
    struct dllNode *next;
};

// LRU cache entry
struct LRU {
    char *key;
    struct dllNode *node;
};

// Cache structure
struct CACHE {
    struct LRU **lru_cache; // Array of pointers to LRU cache entries
    int capacity;
    int size;
    struct dllNode *head; // Pointer to the head of the doubly linked list
    struct dllNode *tail; // Pointer to the tail of the doubly linked list
};

// Function to create a new doubly linked list node
struct dllNode* createNode(char *key, char *value) {
    struct dllNode *newNode = (struct dllNode *)malloc(sizeof(struct dllNode));
    newNode->key = (char *)malloc(strlen(key) + 1);
    newNode->value = (char *)malloc(strlen(value) + 1);
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create an LRU cache
struct CACHE* createCache(int capacity) {
    struct CACHE *cache = (struct CACHE *)malloc(sizeof(struct CACHE));
    cache->lru_cache = (struct LRU **)malloc(capacity * sizeof(struct LRU *));
    for (int i = 0; i < capacity; i++) {
        cache->lru_cache[i] = NULL;
    }
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

// Function to add an entry to the LRU cache
void addEntryToCache(struct CACHE *cache, char *key, char *value) {
    if (cache->size >= cache->capacity) {
        // Remove least recently used entry
        struct dllNode *oldTail = cache->tail;
        cache->tail = oldTail->prev;
        if (cache->tail) {
            cache->tail->next = NULL;
        } else {
            cache->head = NULL;
        }
        free(oldTail->key);
        free(oldTail->value);
        free(oldTail);
        cache->size--;
    }

    // Create new node and add it to the front
    struct dllNode *newNode = createNode(key, value);
    newNode->next = cache->head;
    if (cache->head) {
        cache->head->prev = newNode;
    }
    cache->head = newNode;
    if (!cache->tail) {
        cache->tail = newNode;
    }
    cache->size++;
}

// Function to move a node to the front of the doubly linked list
void moveToHead(struct CACHE *cache, struct dllNode *node) {
    if (node == cache->head) return;

    // Remove the node from its current position
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    if (node == cache->tail) {
        cache->tail = node->prev;
    }

    // Move the node to the front
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head) {
        cache->head->prev = node;
    }

    cache->head = node;
    if (!cache->tail) {
        cache->tail = node;
    }
}

// Function to get an entry from the LRU cache
char* getCache(struct CACHE *cache, char *key) {
    struct dllNode *current = cache->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            moveToHead(cache, current);
            return current->value;
        }
        current = current->next;
    }
    return NULL; // Key not found
}

// Example main function
int main() {
    struct CACHE *cache = createCache(3);
    addEntryToCache(cache, "A", "ValueA");
    addEntryToCache(cache, "B", "ValueB");
    addEntryToCache(cache, "C", "ValueC");
    addEntryToCache(cache, "D", "ValueD");

    printf("Get B: %s\n", getCache(cache, "B")); // Should print ValueB
    printf("Get A: %s\n", getCache(cache, "A")); // Should print NULL (A was removed)

    struct dllNode *current = cache->head;
    while (current) {
        printf("Key: %s Value: %s\n", current->key, current->value);
        current = current->next;
    }

    // Clean up allocated memory
    // Note: You should implement a proper function to free the entire cache
    
    return 0;
}


