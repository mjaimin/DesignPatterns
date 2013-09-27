#include <iostream>
using namespace std;

class Strategy {
public:
   virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
   virtual void AlgorithmInterface()
   {
      cout << "AlgorithmInterface implemented by ConcreteStrategyA\n" << endl;
   }
};

class ConcreteStrategyB : public Strategy {
public:
   virtual void AlgorithmInterface()
   {
      cout << "AlgorithmInterface implemented by ConcreteStrategyB\n" << endl;
   }
};

class Context {
private:
   Strategy *m_strategy;
public:
   Context(Strategy *strategy) : m_strategy(strategy) { }

   void changeStrategy(Strategy *strategy)
   {
      m_strategy = strategy;
   }

   void ContextInterface()//execute
   {
      if (NULL != m_strategy)
      {
         m_strategy->AlgorithmInterface();
      }
   }
};

int main(int argc, char const *argv[])
{
   Context *context = new Context(new ConcreteStrategyA());

   context->ContextInterface();
   context->changeStrategy(new ConcreteStrategyB());
   context->ContextInterface();

   return 0;
}
