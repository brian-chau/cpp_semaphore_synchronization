#include <semaphore.h>

#include <chrono>
#include <iostream>
#include <thread>

sem_t s1, s2;
void first() {
    std::cout << "1 ";
    sem_post(&s1);
}

void second() {
    sem_wait(&s1);
    std::cout << "2 ";
    sem_post(&s2);
}

void third() {
    sem_wait(&s2);
    std::cout << "3 ";
}

int main() {
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);

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
    std::chrono::duration<double> dur =
        std::chrono::system_clock::now() - start;
    std::cout << "Duration: " << dur.count() << " seconds" << '\n';

    return 0;
}