#include <iostream>
#include <string>
#include <list>
/// Context class
class Context
{
   // Constructor
public:
	std::string Input;
   int         Output;
   Context(std::string input) : Input(input), Output(0) {}

   // Gets or sets input
      // Gets or sets output
   
    bool InputStrStartsWith( std::string number )
    {
    if (Input.compare(0, number.length(), number) == 0)
    {
        return true;
    }
    return false;
    }
};

/// AbstractExpression class
class Expression
{
public:

   virtual std::string One()  = 0;
   virtual std::string Four() = 0;
   virtual std::string Five() = 0;
   virtual std::string Nine() = 0;
   virtual int Multiplier()   = 0;

   void interpret(Context *context)
   {
      if (context->Input.length() == 0)
      {
         return;
      }

      if (context->InputStrStartsWith(Nine()))
      {
         context->Output  += (9 * Multiplier());
         context->Input  = context->Input.substr(2);
      }
      else if (context->InputStrStartsWith(Four()))
      {
         context->Output += (4 * Multiplier());
         context->Input = context->Input.substr(2);
      }
      else if (context->InputStrStartsWith(Five()))
      {
         context->Output += (5 * Multiplier());
         context->Input = context->Input.substr(1);
      }

      while (context->InputStrStartsWith(One()))
      {
          context->Output += (1 * Multiplier());
          context->Input   = context->Input.substr(1);
      }
   }


};

/// A 'TerminalExpression' class
/// Thousand checks for the Roman Numeral M
class ThousandExpression : public Expression
{
public:
   std::string One() { return "M"; }
   std::string Four() { return " "; }
   std::string Five() { return " "; }
   std::string Nine() { return " "; }
   int Multiplier() { return 1000; }
};

/// A 'TerminalExpression' class
/// Hundred checks C, CD, D or CM
class HundredExpression : public Expression
{
public:
   std::string One() { return "C"; }
   std::string Four() { return "CD"; }
   std::string Five() { return "D"; }
   std::string Nine() { return "CM"; }
   int Multiplier() { return 100; }
};

/// TerminalExpression' class
/// Ten checks for X, XL, L and XC
class TenExpression : public Expression
{
public:
   std::string One() { return "X"; }
   std::string Four() { return "XL"; }
   std::string Five() { return "L"; }
   std::string Nine() { return "XC"; }
   int Multiplier() { return 10; }
};

/// A 'TerminalExpression' class
/// One checks for I, II, III, IV, V, VI, VI, VII, VIII, IX
class OneExpression : public Expression
{
public:

   std::string One() { return "I"; }
   std::string Four() { return "IV"; }
   std::string Five() { return "V"; }
   std::string Nine() { return "IX"; }
   int Multiplier() { return 1; }
};
int main()
{
   std::string roman    = "MCMXXVIII";
   Context     *context = new Context(roman);

   // Build the 'parse tree'
   std::list<Expression *> tree;

   tree.push_back(new ThousandExpression());
   tree.push_back(new HundredExpression());
   tree.push_back(new TenExpression());
   tree.push_back(new OneExpression());

   // Interpret
   for (std::list<Expression *>::iterator it = tree.begin(); it != tree.end(); ++it)
   {
      (*it)->interpret(context);
   }

 //  Console.WriteLine("{0} = {1}",
                    std::cout <<  "roman " << roman << "= " <<  context->Output << std::endl;
}
