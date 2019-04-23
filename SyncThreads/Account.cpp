#include <iostream>
#include <Account.h>

Account::Account( double balance )
    : m_balance( balance )
{}

//////////////////////////////////////////////

double Account::GetBalance()
{
    return m_balance;
}

//////////////////////////////////////////////

void Account::Withdraw( double amount )
{
    if ( m_balance < amount )
    {
        std::cout << "Insufficient funds" << std::endl;
        return;
    }

    m_balance -= amount;
}

//////////////////////////////////////////////

void Account::Deposit( double amount )
{
    m_balance += amount;
}

//////////////////////////////////////////////