// Thread-safe Hash Map using mutex
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <thread>
using namespace std;

class ThreadSafeHashMap {
    unordered_map<int, int> map;
    mutable mutex mtx;
public:
    void insert(int key, int value) {
        lock_guard<mutex> lock(mtx);
        map[key] = value;
    }
    bool get(int key, int& value) const {
        lock_guard<mutex> lock(mtx);
        auto it = map.find(key);
        if (it == map.end()) return false;
        value = it->second;
        return true;
    }
};

void writer(ThreadSafeHashMap& m) {
    for (int i = 0; i < 100; ++i) m.insert(i, i*i);
}
void reader(const ThreadSafeHashMap& m) {
    int v;
    for (int i = 0; i < 100; ++i) if (m.get(i, v)) cout << v << " ";
    cout << endl;
}

int main() {
    ThreadSafeHashMap m;
    thread t1(writer, ref(m)), t2(reader, cref(m));
    t1.join(); t2.join();
    return 0;
}
