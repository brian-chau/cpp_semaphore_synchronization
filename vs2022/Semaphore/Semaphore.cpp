#include <functional>
#include <iostream>
#include <semaphore>
#include <thread>

std::counting_semaphore<1> a(0);
std::counting_semaphore<1> b(0);

void first() {
    std::cout << "1 ";
    a.release();
}

void second() {
    a.acquire();
    std::cout << "2 ";
    b.release();
}

void third() {
    b.acquire();
    std::cout << "3 ";
}

int main() {
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < 100; i++) {
        std::thread t1(first);
        std::thread t2(second);
        std::thread t3(third);

        t2.join();
        t1.join();
        t3.join();
        std::cout << '\n';
    }
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "Duration: " << dur.count() << " seconds" << '\n';
}