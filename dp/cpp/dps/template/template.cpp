#include <iostream>
using namespace std;

// Base class
// Template class
class Account {
    public:
        // Abstract Methods
        virtual void Start() = 0;

        virtual void Allow() = 0;

        virtual void End() = 0;

        virtual int MaxLimit() = 0;

        // Template Method
        void Withdraw(int amount) {

            Start();

            int limit = MaxLimit();
            if ( amount < limit ) {
            Allow();
            }
            else {
            cout << "Not allowed" << endl;
            }

            End();
        }
};

// Derived class
class AccountNormal : public Account {
    public:
        void Start() {
            cout << "Start ..." << endl;
        }

        void Allow() {
            cout << "Allow ..." << endl;
        }

        void End() {
            cout << "End ..." << endl;
        }

        int MaxLimit() {
            return 1000;
        }
};

// Derived class
class AccountPower : public Account {
    public:
        void Start() {
            cout << "Start ..." << endl;
        }

        void Allow() {
            cout << "Allow ..." << endl;
        }

        void End() {
            cout << "End ..." << endl;
        }

        int MaxLimit() {
            return 5000;
        }
};

int main() {
    AccountPower power;
    power.Withdraw(1500);

    AccountNormal normal;
    normal.Withdraw(1500);
}