#include <iostream>

using namespace std;

// Singleton class
class MySingleton {

    public:
        static MySingleton* iInstance;

    public:
        static MySingleton* GetInstance();

    private:
        // private constructor
        MySingleton();

};

MySingleton* MySingleton::iInstance = NULL;

MySingleton::MySingleton()
{
    cout << "In construtor ..." << endl;
}

MySingleton* MySingleton::GetInstance()
{
    if ( iInstance == NULL ) {
    iInstance = new MySingleton();
    }

    return iInstance;
}

int main()
{
    MySingleton* obj;
    obj = MySingleton::GetInstance();
}
