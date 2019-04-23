#include <stdio.h>
#include <thread>
#include <chrono>
#include <iostream>


int main(int argc, char *argv[])
{
    using namespace std::chrono_literals;
    this_thread::sleep_for(10s);
    cout << "Hello World!" << endl;
    return 0;
}

