#include <set>
#include "Observer.h"

void Observable::notifyObservers(void* arg) {
    for(auto observer:m_observers)
        observer->update(this, arg);
}

void Observable::addObserver(Observer *observer) {
    m_observers.insert(observer);
}
