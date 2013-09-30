#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

class ChineseExp {
public:
   ChineseExp() {}
   virtual ~ChineseExp() {}
   virtual double Interprete(map<string, int> myDict) = 0;     // Here use map to implement the Context
};

class ChineseNum : public ChineseExp {
private:
   string numString;
public:
   virtual ~ChineseNum() {}
   ChineseNum(string num) : numString(num) {}
   virtual double Interprete(map<string, int> myDict)
   {
      return (double)myDict[numString];
   }
};

class ChineseAdd : public ChineseExp {
private:
   ChineseExp *leftOperator;
   ChineseExp *rightOperator;
public:
   virtual ~ChineseAdd()
   {
      delete leftOperator;
      delete rightOperator;
   }

   ChineseAdd(ChineseExp *left, ChineseExp *right)
   {
      leftOperator  = left;
      rightOperator = right;
   }

   virtual double Interprete(map<string, int> myDict)
   {
      return(leftOperator->Interprete(myDict) + rightOperator->Interprete(myDict));
   }
};

class ChineseSub : public ChineseExp {
private:
   ChineseExp *leftOperator;
   ChineseExp *rightOperator;
public:
   virtual ~ChineseSub()
   {
      delete leftOperator;
      delete rightOperator;
   }

   ChineseSub(ChineseExp *left, ChineseExp *right)
   {
      leftOperator  = left;
      rightOperator = right;
   }

   virtual double Interprete(map<string, int> myDict)
   {
      return(leftOperator->Interprete(myDict) - rightOperator->Interprete(myDict));
   }
};

class ChineseMul : public ChineseExp {
private:
   ChineseExp *leftOperator;
   ChineseExp *rightOperator;
public:
   virtual ~ChineseMul()
   {
      delete leftOperator;
      delete rightOperator;
   }

   ChineseMul(ChineseExp *left, ChineseExp *right)
   {
      leftOperator  = left;
      rightOperator = right;
   }

   virtual double Interprete(map<string, int> myDict)
   {
      return(leftOperator->Interprete(myDict) * rightOperator->Interprete(myDict));
   }
};

class ChineseDiv : public ChineseExp {
private:
   ChineseExp *leftOperator;
   ChineseExp *rightOperator;
public:
   // Class ChineseDiv
   virtual ~ChineseDiv()
   {
      delete leftOperator;
      delete rightOperator;
   }

   ChineseDiv(ChineseExp *left, ChineseExp *right)
   {
      leftOperator  = left;
      rightOperator = right;
   }

   virtual double Interprete(map<string, int> myDict)
   {
      return(leftOperator->Interprete(myDict) / rightOperator->Interprete(myDict));
   }
};

//  Class Evaluator, construct the syntax tree This is not the part of Interpreter Pattern
class Evaluator {
private:
   ChineseExp *myExpression;
   ChineseExp *ExpConstruct(stack<string> *numStack)
   {
      ChineseExp *t;
      string     tmp = (*numStack).top();

      if (IsNumber(tmp) == 0)
      {
         t = new ChineseNum(tmp);
         (*numStack).pop();
      }
      if (IsNumber(tmp) == 2)
      {
         string temp = tmp;
         (*numStack).pop();
         if (temp.compare("+") == 0)
         {
            t = new ChineseAdd(ExpConstruct(numStack), myExpression);
         }
         else if (temp.compare("-") == 0)
         {
            t = new ChineseSub(ExpConstruct(numStack), myExpression);
         }
         else if (temp.compare("*") == 0)
         {
            t = new ChineseMul(ExpConstruct(numStack), myExpression);
         }
         else if (temp.compare("/") == 0)
         {
            t = new ChineseDiv(ExpConstruct(numStack), myExpression);
         }
      }
      return t;
   }

   int IsNumber(string tString)
   {
      int b4 = tString.compare("+");
      int b5 = tString.compare("-");
      int b6 = tString.compare("*");
      int b7 = tString.compare("/");

      if ((b4 == 0) || (b5 == 0) || (b6 == 0) || (b7 == 0))
      {
         return 2;
      }
      return 0;
   }

public:
   Evaluator() {}

   ~Evaluator()
   {
      delete myExpression;
   }

   void Construct(string expression)
   {
      int n = expression.length();

      stack<string> number;
      for (int i = 0; i < n; i += 1)
      {
         string temp = expression.substr(i, 1);
         number.push(temp);
      }
      int stackSize = number.size();
      while (stackSize != 0)
      {
         myExpression = ExpConstruct(&number);
         stackSize    = number.size();
      }
   }

   double Interprete(map<string, int> myDict)
   {
      return myExpression->Interprete(myDict);
   }
};
int main()
{
   // Construct the Context first
   map<string, int> Dict;

   /*Dict["一"] = 1;
    *  Dict["二"] = 2;
    *  Dict["三"] = 3;
    *  Dict["四"] = 4;
    *  Dict["五"] = 5;
    *  Dict["六"] = 6;
    *  Dict["七"] = 7;
    *  Dict["八"] = 8;
    *  Dict["九"] = 9;*/
   //for simplicity changed code from chinese to English strings
   Dict["1"] = 1;
   Dict["2"] = 2;
   Dict["3"] = 3;
   Dict["4"] = 4;
   Dict["5"] = 5;
   Dict["6"] = 6;
   Dict["7"] = 7;
   Dict["8"] = 8;
   Dict["9"] = 9;
   Evaluator myEvaluator = Evaluator();
   myEvaluator.Construct("4+5-3");
   double result = myEvaluator.Interprete(Dict);
   std::cout << result << std::endl;
}
