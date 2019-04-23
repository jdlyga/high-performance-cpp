#include <pthread.h>
#include <iostream>

using namespace std;

void* threadProc ( void * param )
{
    for ( int i = 0; i < 3; i++ )
    {
        std::cout << "Message: " << i << " from " << pthread_self() << "\n";
    }

    pthread_exit(0);
}

int main()
{
    pthread_t thread1, thread2, thread3;

    pthread_create( &thread1, nullptr, threadProc, nullptr );
    pthread_create( &thread2, nullptr, threadProc, nullptr );
    pthread_create( &thread3, nullptr, threadProc, nullptr );
    pthread_join( thread1, nullptr );
    pthread_join( thread2, nullptr );
    pthread_join( thread3, nullptr );
}
