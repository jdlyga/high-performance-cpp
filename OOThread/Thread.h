#pragma once

#include <iostream>
#include <thread>
#include <memory>

class Thread
{
    public:

        Thread() = default;
        ~Thread() = default;

        void start();
        void stop();
        void join();
        void detach();

    private:
        std::unique_ptr<std::thread> m_pThread;
        bool m_stopped = false;
        void run();
};

