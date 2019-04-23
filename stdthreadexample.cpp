#include <thread>
#include <iostream>

void threadProc()
{
    for ( int i = 0; i < 3; i++ )
    {
        std::cout << "Message count " 
                  << i 
                  << " from thread "
                  << std::this_thread::get_id() 
                  << "\n";
    }
}


int main()
{


    std::thread thread1( threadProc );    
    std::thread thread2( threadProc );    
    std::thread thread3( threadProc );   

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
} 