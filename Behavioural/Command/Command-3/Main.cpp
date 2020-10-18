/*
 * Adopted from http://login2win.blogspot.com/2011/06/command-pattern.html
 */
#include <iostream>
#include <vector>
using namespace std;

// Command interface
class Command {
    public:
        virtual void execute() = 0;
};

// Receiver
class StockTrade {
    public:
        void buy() { cout << "Buy Stock" << endl; }
        void sell() { cout << "Sell Stock" << endl; }
};

// Concrete command 1
class BuyOrder : public Command {
    private:
        StockTrade* m_stock;
    public:
        BuyOrder(StockTrade* stock)
            :m_stock( stock ) {
            }

        void execute() {
            m_stock->buy();
        }
};

// Concrete command 2
class SellOrder : public Command {
    private:
        StockTrade* m_stock;
    public:
        SellOrder(StockTrade* stock) {
            m_stock = stock;
        }
        void execute() {
            m_stock->sell();
        }
};


// Invoker
class StockAgent {
    public:
        void order( Command* command ) {
            commandList.push_back( command );
            command->execute();
        }
    private:
        vector<Command*> commandList;
};


int main (int argc, char const* argv[]) {

    StockAgent* agent = new StockAgent();//Invoker

    StockTrade* stock = new StockTrade();// Receiver
    BuyOrder* buy1 = new BuyOrder( stock );//Concrete command
    BuyOrder* buy2 = new BuyOrder( stock );
    SellOrder* sell1 = new SellOrder( stock ); //Concrete command

    agent->order(buy1);
    agent->order(buy2);
    agent->order(sell1);





    return 0;
}
