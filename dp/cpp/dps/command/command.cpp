#include <iostream>
#include <vector>
using namespace std;

// Command interface
class Command
{
public:
    virtual void execute() = 0;
};

// Receiver
class StockTrade
{
public:
    StockTrade() {}
    void buy() { cout << "Buy stock" << endl; }
    void sell() { cout << "Sell stock" << endl; }
};

// Concrete command 1
class BuyOrder : public Command
{
    StockTrade* stock;
public:
    BuyOrder(StockTrade* stock)
    {
        this->stock = stock;
    }

    void execute()
    {
        stock->buy();
    }
};

// Concrete command 2
class SellOrder : public Command
{
    StockTrade* stock;
public:
    SellOrder(StockTrade* stock)
    {
        this->stock = stock;
    }

    void execute()
    {
        stock->sell();
    }
};

// Invoker
class StockAgent
{
public:
    StockAgent() {}
    void order( Command* command )
    {
        commandList.push_back(command);
        command->execute();
    }
private:
    // Looking at this command list gives
    // this order history
    vector<Command*> commandList;
};

// Test program
int main()
{
    StockTrade* stock = new StockTrade();
    BuyOrder* buy1 = new BuyOrder(stock);
    BuyOrder* buy2 = new BuyOrder(stock);
    SellOrder* sell1 = new SellOrder(stock);

    StockAgent* agent = new StockAgent();
    agent->order(buy1);
    agent->order(buy2);
    agent->order(sell1);

    delete agent;
    delete sell1;
    delete buy2;
    delete buy1;
    delete stock;
}