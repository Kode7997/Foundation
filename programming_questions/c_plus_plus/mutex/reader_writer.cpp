#include <iostream>
#include <thread>
#include <shared_mutex> // For std::shared_mutex and std::unique_lock

std::shared_mutex sharedMtx;
int counter = 0;

void writer() {
    std::unique_lock<std::shared_mutex> lock(sharedMtx); // Exclusive lock
    counter++; // Critical section
    std::cout << "Writer incremented counter to " << counter << "\n";
}

void reader() {
    std::shared_lock<std::shared_mutex> lock(sharedMtx); // Shared lock
    std::cout << "Reader accessed counter: " << counter << "\n";
}

int main() {
    std::thread t1(writer);
    std::thread t2(reader);
    std::thread t3(reader);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

