#include <iostream>
#include <unordered_map>
#include <list>
#include <mutex>

class LRUCache {
private:
    size_t capacity;
    std::list<std::pair<int, int>> cache; // Doubly linked list for tracking usage
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map; // Key to list iterator
    std::mutex mtx; // Mutex for thread-safe access

public:
    LRUCache(size_t cap) : capacity(cap) {}

    // Read value from cache
    int get(int key) {
        std::lock_guard<std::mutex> lock(mtx); // Protect shared resources
        if (map.find(key) == map.end()) {
            return -1; // Key not found
        }
        // Move accessed item to the front of the cache
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }

    // Write value to cache
    void put(int key, int value) {
        std::lock_guard<std::mutex> lock(mtx); // Protect shared resources
        if (map.find(key) != map.end()) {
            // Key already exists, update value and move to front
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
            return;
        }

        // Insert new key-value pair
        cache.emplace_front(key, value);
        map[key] = cache.begin();

        // If capacity exceeded, remove the least recently used item
        if (cache.size() > capacity) {
            int lruKey = cache.back().first;
            cache.pop_back();
            map.erase(lruKey);
        }
    }

    void display() {
        std::lock_guard<std::mutex> lock(mtx); // Protect shared resources
        std::cout << "Cache contents: ";
        for (const auto& pair : cache) {
            std::cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        std::cout << "\n";
    }
};

int main() {
    LRUCache cache(3); // Capacity of 3

    // Test thread-safe read and write
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    cache.display();

    std::cout << "Get 1: " << cache.get(1) << "\n"; // Access key 1
    cache.display();

    cache.put(4, 400); // Add key 4, evict least recently used key (2)
    cache.display();

    std::cout << "Get 2: " << cache.get(2) << "\n"; // Key 2 has been evicted
    cache.display();

    return 0;
}
