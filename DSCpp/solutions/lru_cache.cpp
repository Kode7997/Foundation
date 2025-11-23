// LRU Cache implementation using unordered_map and list
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
public:
    LRUCache(int cap) : capacity(cap) {}
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        keys.erase(cache[key].second);
        keys.push_front(key);
        cache[key].second = keys.begin();
        return cache[key].first;
    }
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            keys.erase(cache[key].second);
        } else if (keys.size() == capacity) {
            int old = keys.back();
            keys.pop_back();
            cache.erase(old);
        }
        keys.push_front(key);
        cache[key] = {value, keys.begin()};
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4, 4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    return 0;
}
