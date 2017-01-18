#include <iostream>
#include <string>
#include <list>

using namespace std;

class DiagnosticInterface {
public:
    virtual void runDiagnostics() = 0;
    virtual string getDianosticsResult() = 0;
};

class DiagnosticCompositeInterface : public DiagnosticInterface  {
public:
    void runDiagnostics() {
        for (list<DiagnosticInterface*>::iterator it = mCompositeObjs.begin(); it != mCompositeObjs.end(); ++it )
            (*it)->runDiagnostics();
    }
    string getDianosticsResult() {
        string ret = "";
        for (list<DiagnosticInterface*>::iterator it = mCompositeObjs.begin(); it != mCompositeObjs.end(); ++it )
            ret += (*it)->getDianosticsResult() + "\n";
        return ret;
    }
    void addChild(DiagnosticInterface *child) {
        mCompositeObjs.push_back(child);
    }
    void removeChild(DiagnosticInterface *child) {
        // find and remove the child. not implemented yet.
    }
    DiagnosticInterface* getChild(int i) {
        // get the child at i. Not implemented yet.
    }
protected:
    list<DiagnosticInterface*> mCompositeObjs;
};

class PhoneDiagnostics : public DiagnosticCompositeInterface {
public:
    void runDiagnostics() {
        cout << "running PhoneDiagnostics..." << endl;
        DiagnosticCompositeInterface::runDiagnostics();
    }
    string getDianosticsResult() {
        string ret = "PhoneDiagnostics all tested Okay!\n";
        ret += DiagnosticCompositeInterface::getDianosticsResult();
        return ret;
    }
};

class ScreenSaverDiagnostics : public DiagnosticInterface {
public:
    void runDiagnostics() {
        cout << "running ScreenSaverDiagnostics..." << endl;
    }
    string getDianosticsResult() {
        return "ScreenSaverDiagnostics all tested Okay!";
    }
};

class HardwareDiagnostics : public DiagnosticCompositeInterface {
public:
    void runDiagnostics() {
        cout << "running HardwareDiagnostics..." << endl;
        DiagnosticCompositeInterface::runDiagnostics();
    }
    string getDianosticsResult() {
        string ret = "HardwareDiagnostics all tested Okay!\n";
        ret += DiagnosticCompositeInterface::getDianosticsResult();
        return ret;
    }
};

class NetworkDiagnostics : public DiagnosticCompositeInterface {
public:
    void runDiagnostics() {
        cout << "running NetworkDiagnostics..." << endl;
        DiagnosticCompositeInterface::runDiagnostics();
    }

    string getDianosticsResult() {
        string ret = "NetworkDiagnostics all tested Okay!\n";
        ret += DiagnosticCompositeInterface::getDianosticsResult();
        return ret;
    }
};

class TouchScreenDiagnostics : public DiagnosticInterface {
public:
    void runDiagnostics() {
        cout << "running TouchScreenDiagnostics..." << endl;
    }
    string getDianosticsResult() {
        return "TouchScreenDiagnostics all tested Okay!";
    }
};

class OnOffKeyDiagnostics : public DiagnosticInterface {
public:
    void runDiagnostics() {
        cout << "running OnOffKeyDiagnostics..." << endl;
    }
    string getDianosticsResult() {
        return "OnOffKeyDiagnostics all tested Okay!";
    }
};

class WifiDiagnostics : public DiagnosticInterface {
public:
    void runDiagnostics() {
        cout << "running WifiDiagnostics..." << endl;
    }
    string getDianosticsResult() {
        return "WifiDiagnostics all tested Okay!";
    }
};

class ThreeGDiagnostics : public DiagnosticInterface {
public:
    void runDiagnostics() {
        cout << "running ThreeGDiagnostics..." << endl;
    }
    string getDianosticsResult() {
        return "ThreeGDiagnostics all tested Okay!";
    }
};

int main()
{
    DiagnosticCompositeInterface *phoneDiagnostics = new PhoneDiagnostics();

    DiagnosticInterface *screenSaverDiagnostics = new ScreenSaverDiagnostics();
    DiagnosticCompositeInterface *hardwareDiagnostics = new HardwareDiagnostics();
    DiagnosticCompositeInterface *networkDiagnostics = new NetworkDiagnostics();

    DiagnosticInterface *touchScreenDiagnostics = new TouchScreenDiagnostics();
    DiagnosticInterface *onOffKeyDiagnostics = new OnOffKeyDiagnostics();

    DiagnosticInterface *wifiDiagnostics = new WifiDiagnostics();
    DiagnosticInterface *threeGDiagnostics = new ThreeGDiagnostics();

    hardwareDiagnostics->addChild(touchScreenDiagnostics);
    hardwareDiagnostics->addChild(onOffKeyDiagnostics);

    networkDiagnostics->addChild(wifiDiagnostics);
    networkDiagnostics->addChild(threeGDiagnostics);

    phoneDiagnostics->addChild(screenSaverDiagnostics);
    phoneDiagnostics->addChild(hardwareDiagnostics);
    phoneDiagnostics->addChild(networkDiagnostics);

    cout << "Run diagnostics on the phone!" << endl;
    phoneDiagnostics->runDiagnostics();
    cout << "****\nGet the diagnostics result\n" << phoneDiagnostics->getDianosticsResult() << endl;
    return 0;
}
