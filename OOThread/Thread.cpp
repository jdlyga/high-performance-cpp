#include "Thread.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void Thread::run()
{
    while ( !m_stopped )
    {
        std::cout << "running: " << std::this_thread::get_id() << "\n";
        std::this_thread::sleep_for( 1s );
    }

    std::cout << "\nThread " << std::this_thread::get_id()
              << " stopped as requested." << "\n";
}

////////////////////////////////////////////////////////////

void Thread::start()
{
    m_pThread.reset( new std::thread( &Thread::run, this ) );
}

////////////////////////////////////////////////////////////

void Thread::stop()
{
    m_stopped = true; 
}
////////////////////////////////////////////////////////////

void Thread::join()
{
    m_pThread->join();
}

////////////////////////////////////////////////////////////

void Thread::detach()
{
    m_pThread->detach();
}

////////////////////////////////////////////////////////////
