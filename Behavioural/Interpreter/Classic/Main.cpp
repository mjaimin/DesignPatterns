//Not so good classic example compare to other classic examples
#include <iostream>
#include <string>
class Context
{
    public:
        std::string Name;
        Context(std::string name) : Name(name) {  }
};

class ExpressionBase
{
    public:
        virtual void Interpret(Context *context) = 0;
};


class TerminalExpression : public ExpressionBase
{
    public:
        void Interpret(Context *context)
        {
            std::cout << "Terminal for {0}." << context->Name << std::endl;
        }
};

class NonterminalExpression : public ExpressionBase
{
    public:
        void Interpret(Context *context)
        {
            std::cout << "Nonterminalfor {0}." << context->Name << std::endl;
        }
};
int main()
{
    Context               *context = new Context("hello world!!!");
    NonterminalExpression *root    = new NonterminalExpression();
    {
        TerminalExpression *Expression1 = new TerminalExpression();
        TerminalExpression *Expression2 = new TerminalExpression();
        Expression1->Interpret(context);
        Expression2->Interpret(context);
    }

    root->Interpret(context);
}
