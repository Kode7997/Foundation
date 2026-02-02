#include <iostream>
#include <queue>
#include <vector>

struct Person {
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}
};

// Comparator: Sort by increasing age, then alphabetically by name
struct ComparePerson {
    bool operator()(const Person& p1, const Person& p2) {
        if (p1.age == p2.age) {
            return p1.name > p2.name;  // Sort alphabetically if ages are equal
        }
        return p1.age > p2.age;  // Sort by age otherwise
    }
};

int main() {
    std::priority_queue<Person, std::vector<Person>, ComparePerson> pq;  // less<T>, greater<T>(for minHeap)

    pq.push(Person("Alice", 30));
    pq.push(Person("Bob", 25));
    pq.push(Person("Charlie", 30));
    pq.push(Person("David", 25));

    while (!pq.empty()) {
        std::cout << pq.top().name << " (" << pq.top().age << ")" << std::endl;
        pq.pop();
    }

    return 0;
}
