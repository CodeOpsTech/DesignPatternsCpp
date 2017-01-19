#include <iostream> 
#include <array> 
using namespace std; 

template <typename Derived> 
class Counter { 
private: 
   static long count;  
 
protected: 
   Counter() { 
     ++Counter<Derived>::count; 
   } 
 
   Counter (Counter<Derived> const&) { 
     ++Counter<Derived>::count; 
   } 
 
   virtual ~Counter() { 
     --Counter<Derived>::count; 
   } 
 
public: 
   static long use_count() { 
     return Counter<Derived>::count; 
   } 
}; 
 
template <typename Derived> 
long Counter<Derived>::count = 0; 

template <typename T> 
class MyClass : public Counter<MyClass<T>> { };  

int main() {
	MyClass<int> intObj;
	MyClass<int> intObj2;
	MyClass<char> charObj; 
	cout << "number of MyClass<int> objects is " << MyClass<int>::use_count() << endl;
	cout << "number of MyClass<char> objects is " << MyClass<char>::use_count() << endl;
} 

