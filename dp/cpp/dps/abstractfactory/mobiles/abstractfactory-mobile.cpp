#include <iostream>
#include <string>

using namespace std;

// Abstract base class
class Mobile {
    public:
       virtual string Camera() = 0;
       virtual string KeyBoard() = 0;

       void PrintSpecs() {
          cout << Camera() << endl;
          cout << KeyBoard() << endl;
       }
};

// Concrete classes
class LowEndMobile : public Mobile {
    public:
       string Camera() {
          return "2 MegaPixel";
       }

       string KeyBoard() {
          return "ITU-T";
       }
};

// Concrete classes
class HighEndMobile : public Mobile {
    public:
       string Camera() {
          return "5 MegaPixel";
       }

       string KeyBoard() {
          return "Qwerty";
       }
};


// Abstract Factory returning a mobile
class MobileFactory {
    public:
       Mobile* GetMobile(string type);
};

Mobile* MobileFactory::GetMobile(string type) {
    if ( type == "Low-End" ) return new LowEndMobile();
    if ( type == "High-End" ) return new HighEndMobile();
    return NULL;
}


int main()
{
   MobileFactory* myFactory = new MobileFactory();

   Mobile* myMobile1 = myFactory->GetMobile("Low-End");
   myMobile1->PrintSpecs();

   Mobile* myMobile2 = myFactory->GetMobile("High-End");
   myMobile2->PrintSpecs();
}
