#include <iostream>
#include <thread>
#include <chrono>
#include "Thread.h"

int main()
{
    using namespace std::chrono_literals;

    Thread thread1, thread2, thread3;
    thread1.start();
    thread2.start();
    thread3.start();

    thread1.detach();
    thread2.detach();
    thread3.detach();

    std::cout << "starting sleep\n";
    std::this_thread::sleep_for( 10s );
    std::cout << "sleep over\n";

    thread1.stop();
    thread2.stop();
    thread3.stop();

    std::cout << "sleeping to let threads stop\n";
    std::this_thread::sleep_for( 5s );
    std::cout << "sleep over\n";
}
