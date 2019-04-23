#include <thread>
#include <mutex>
#include "Account.h"

enum class ThreadType
{
    DEPOSIT,
    WITHDRAW
};

Account account( 5'000.0 );
std::mutex locker;

void threadProc( ThreadType type )
{
    using namespace std::chrono_literals;

    for (; ;)
    {
        switch( type )
        {
            case ThreadType::DEPOSIT:
                locker.lock();
                std::cout << "Deposit Thread: Current balance is " << account.GetBalance() << std::endl;
                account.Deposit( 2'000.0 );
                std::cout << "Deposit Thread: Balance after deposit is " << account.GetBalance() << std::endl;
                locker.unlock();
                std::this_thread::sleep_for( 1s );
                break;
                
            case ThreadType::WITHDRAW:
                locker.lock();
                std::cout << "Withdraw Thread: Current balance is " << account.GetBalance() << std::endl;
                account.Withdraw( 1'000.0 );
                std::cout << "Withdraw Thread: Balance after withdrawl is " << account.GetBalance() << std::endl;
                locker.unlock();
                std::this_thread::sleep_for( 1s );
                break;
        }
    }
}

int main()
{
    std::thread deposit( threadProc, ThreadType::DEPOSIT );
    std::thread withdraw( threadProc, ThreadType::WITHDRAW );

    deposit.join();
    withdraw.join();

    return 0;
}