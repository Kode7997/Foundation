// Dynamic Median using two heaps
#include <iostream>
#include <queue>
using namespace std;

class DynamicMedian {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    void insert(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }
    double getMedian() {
        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;
        return maxHeap.top();
    }
};

int main() {
    DynamicMedian dm;
    dm.insert(1); dm.insert(2); dm.insert(3);
    cout << dm.getMedian() << endl;
    dm.insert(4);
    cout << dm.getMedian() << endl;
    return 0;
}
