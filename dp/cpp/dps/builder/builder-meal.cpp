#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Product
class Meal {
public:
    Meal() {}
    ~Meal() {}

    void setMealItem(string mealItem) { mMeal.push(mealItem);}
    void serveMeal() {
        int i = 1;
        while(!mMeal.empty()) {
            cout << " Serve item " << i++ << ":" << mMeal.front() << endl ;
            mMeal.pop();
          }
    }

private:
    queue <string> mMeal;
};

// Builder
class MealBuilder {
public:
    MealBuilder() {}
    ~MealBuilder() {}

    const Meal& getMeal() { return mMeal; }
    virtual void buildStarter() = 0;
    virtual void buildMainCourse() = 0;
    virtual void buildDessert() = 0;

protected:
    Meal mMeal;
};

// Director: Makes sure the right sequence of food is prepared and served.
class MultiCuisineCook {
public:
    MultiCuisineCook():mMealBuilder(NULL) {}
    ~MultiCuisineCook() { if (mMealBuilder) delete mMealBuilder;}

    void setMealBuilder(MealBuilder *mealBuilder) {
        if (mMealBuilder) delete mMealBuilder;
        mMealBuilder = mealBuilder;
    }

    const Meal& getMeal() { return mMealBuilder->getMeal(); }

    void  createMeal() {
        mMealBuilder->buildStarter();
        mMealBuilder->buildMainCourse();
        mMealBuilder->buildDessert();
    }

private:
    MealBuilder *mMealBuilder;

};

// Concrete Meal Builder 1
class IndianMealBuilder : public MealBuilder {
public:
    IndianMealBuilder() {}
    ~IndianMealBuilder() {}

    void buildStarter() { mMeal.setMealItem("FriedOnion");}
    void buildMainCourse() { mMeal.setMealItem("CheeseCurry");}
    void buildDessert() { mMeal.setMealItem("SweetBalls");}

};

// Concrete Meal Builder 2
class ChineeseMealBuilder : public MealBuilder {
public:
    ChineeseMealBuilder() {}
    ~ChineeseMealBuilder() {}

    void buildStarter() { mMeal.setMealItem("Manchurian");}
    void buildMainCourse() { mMeal.setMealItem("FriedNoodles");}
    void buildDessert() { mMeal.setMealItem("MangoPudding");}

};

// Concrete Meal Builder 3
class MexicanMealBuilder : public MealBuilder {
public:
    MexicanMealBuilder() {}
    ~MexicanMealBuilder() {}

    void buildStarter() { mMeal.setMealItem("ChipsNSalsa");}
    void buildMainCourse() { mMeal.setMealItem("RiceTacoBeans");}
    void buildDessert() { mMeal.setMealItem("FriedIcecream");}

};

int main()
{
    MultiCuisineCook cook;

    cout << "Build a Chineese Meal!" << endl;
    cook.setMealBuilder(new ChineeseMealBuilder());
    cook.createMeal();

    Meal chineeseMeal = cook.getMeal();
    chineeseMeal.serveMeal();

    cout << "Build a Mexican Meal!" << endl;
    cook.setMealBuilder(new MexicanMealBuilder());
    cook.createMeal();

    Meal mexicanMeal = cook.getMeal();
    mexicanMeal.serveMeal();

    return 0;
}