#ifndef OBSERVER
#define OBSERVER

#include <set>
using namespace std;

class Observable;

class Observer {
public:
    virtual void update(Observable *arg0, void *arg1)  = 0;
};

class Observable {
public:
    void notifyObservers(void* arg);
    void addObserver(Observer *observer);

private:
    set<Observer *> m_observers;
};

#endif OBSERVER
