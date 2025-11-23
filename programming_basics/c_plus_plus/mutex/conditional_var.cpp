#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

const int SIZE = 5;
std::vector<int> buffer(SIZE);
int count = 0;

std::mutex mtx;
std::condition_variable cond_producer, cond_consumer;

void producer() {
    for (int i = 0; i < SIZE * 2; i++) {
        std::unique_lock<std::mutex> lock(mtx);

        while (count == SIZE) {
            cond_producer.wait(lock);  // Wait if buffer is full
        }

        buffer[count] = i * 10;
        std::cout << "Producer: Added " << buffer[count] << " to buffer[" << count << "]" << std::endl;
        count++;

        cond_consumer.notify_one();  // Notify consumer
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate production delay
    }
}

void consumer() {
    for (int i = 0; i < SIZE * 2; i++) {
        std::unique_lock<std::mutex> lock(mtx);

        while (count == 0) {
            cond_consumer.wait(lock);  // Wait if buffer is empty
        }

        int value = buffer[count - 1];
        std::cout << "Consumer: Read buffer[" << count - 1 << "] = " << value << std::endl;
        count--;

        cond_producer.notify_one();  // Notify producer
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate consumption delay
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
