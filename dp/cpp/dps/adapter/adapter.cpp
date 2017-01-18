#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

// Legacy account
class LegacyAccount
{
    int no;

public:
    LegacyAccount(int no)
    {
        this->no = no;
    }

    void legacyAccountPrint()
    {
        cout << "Display legacy account details " << no << endl;
    }
};

// Renewed interface
class RenewedAccountIntf
{
public:
    virtual void display() = 0;
};

// Renewed account object
class Account : public RenewedAccountIntf
{
    string no;

public:
    Account(string no) {
        this->no = no;
    }

    void display()
    {
        cout << "Display renewed account details " << no << endl;
    }
};

// Legacy account adapter to renewed interface
class LegacyAccountAdapter : public LegacyAccount,
        public RenewedAccountIntf
{
public:
    LegacyAccountAdapter(string no) :
        LegacyAccount(atoi(no.c_str()))
    {
    }

    void display()
    {
        this->legacyAccountPrint();
    }
};


// Test program
int main()
{
    list<RenewedAccountIntf*> accountList;
    accountList.push_back(new Account("accountholder 1"));
    accountList.push_back(new Account("accountholder 2"));
    accountList.push_back(new LegacyAccountAdapter("12345"));

    while ( ! accountList.empty() )
    {
        RenewedAccountIntf* obj = accountList.front();
        obj->display();
        accountList.pop_front();
    }
}