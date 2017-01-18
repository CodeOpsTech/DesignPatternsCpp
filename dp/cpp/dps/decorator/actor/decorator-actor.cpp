#include <iostream>
#include <string>

using namespace std;

class actor {
public:
    actor() {}
    virtual void act() {}
    virtual string name() {}
};

class actorConcretePerson: public actor {
public:
    actorConcretePerson(string name) { mName = name; }
    void act() { cout << mName << " is acting" << endl;}
    string name() { return mName; }
private:
    string mName;

};

class actorCharacter: public actor {
public:
    actorCharacter(string charName) { mCharName = charName; }
    void setActorPerson( actor *anActor) {mActor = anActor;}
    void act() { mActor->act(); }
    actor* getActor() { return mActor; }
    void actCharacter() { act(); cout << mCharName << " is the role" << endl;}
    string getCharName() { return mCharName; }
private:
    actor *mActor;
    string mCharName;
};

class actorCharacterTheif: public actorCharacter {
public:
    actorCharacterTheif(string charName):actorCharacter(charName) { }
    void setTarget(string target) { mTarget = target ; }
    void steal() { cout << getActor()->name() << ", the " << getCharName() << ": Stole " << mTarget << endl; }

private:
    string mTarget;

};

class actorCharacterPolice: public actorCharacter {
public:
    actorCharacterPolice(string charName):actorCharacter(charName) { }
    void setTrack(string track) { mTrack = track ; }
    void catchThief() { cout << getActor()->name() << ", the " << getCharName() << ": Cought " << mTrack << endl; }
private:
    string mTrack;
};


int main()
{
    actor *cage = new actorConcretePerson("NicolasCage");
    actor *travolta = new actorConcretePerson("JohnTravolta");

    actorCharacterPolice *police = new actorCharacterPolice("Commissioner");
    actorCharacterTheif *smuggler = new actorCharacterTheif("Smuggler");
    actorCharacterTheif *robber = new actorCharacterTheif("Robber");

    cout << "Basic concrete objects and methods..." << endl;
    cage->act();
    travolta->act();

    cout << endl << "Decorator objects and methods..." << endl;
    police->setActorPerson(travolta);
    smuggler->setActorPerson(cage);

    police->actCharacter();
    police->setTrack(smuggler->getCharName());
    police->catchThief();

    smuggler->act();
    smuggler->actCharacter();
    smuggler->setTarget("Gold");
    smuggler->steal();

    robber->setActorPerson(travolta);
    robber->act();
    robber->actCharacter();
    robber->setTarget("Dollars");
    robber->steal();

    return 0;
} 
