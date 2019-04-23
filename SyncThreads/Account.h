#pragma once

#include <iostream>

class Account
{
    public:

        Account( double balance );
        ~Account() = default;

        double GetBalance();
        void Deposit( double amount );
        void Withdraw( double amount );

    private:

        double m_balance{};        
};