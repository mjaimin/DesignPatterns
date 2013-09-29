#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

class ChineseExp{
public:
	ChineseExp();
	virtual ~ChineseExp();
	virtual double Interprete(map<string,int> myDict) = 0; // Here use map to implement the Context
};

class ChineseNum : public ChineseExp{
public:
	virtual ~ChineseNum();
	ChineseNum(string num);
	virtual double Interprete(map<string,int> myDict);
private:
	string numString;
};

class ChineseAdd : public ChineseExp{
public:
	virtual ~ChineseAdd();
	ChineseAdd(ChineseExp* left, ChineseExp* right);
	virtual double Interprete(map<string,int> myDict);
private:
	ChineseExp* leftOperator;
	ChineseExp* rightOperator;
};


class ChineseSub : public ChineseExp{
public:
	virtual ~ChineseSub();
	ChineseSub(ChineseExp* left, ChineseExp* right);
	virtual double Interprete(map<string,int> myDict);
private:
	ChineseExp* leftOperator;
	ChineseExp* rightOperator;
};

class ChineseMul : public ChineseExp{
public:
	virtual ~ChineseMul();
	ChineseMul(ChineseExp* left, ChineseExp* right);
	virtual double Interprete(map<string,int> myDict);
private:
	ChineseExp* leftOperator;
	ChineseExp* rightOperator;
};

class ChineseDiv : public ChineseExp{
public:
	virtual ~ChineseDiv();
	ChineseDiv(ChineseExp* left, ChineseExp* right);
	virtual double Interprete(map<string,int> myDict);
private:
	ChineseExp* leftOperator;
	ChineseExp* rightOperator;
};


//  Class Evaluator, construct the syntax tree This is not the part of Interpreter Pattern
class Evaluator{
public:
	~Evaluator();
	Evaluator();
	void Construct(string expression);
	double Interprete(map<string,int> myDict);
private:
	ChineseExp* myExpression;
	ChineseExp* ExpConstruct(stack<string>* numStack);
	int IsNumber(string tString);
};

// Abstract Expression
ChineseExp::ChineseExp(){

}

ChineseExp::~ChineseExp(){

}

// Class ChineseNum
ChineseNum::ChineseNum( string num ) : numString(num){

}

double ChineseNum::Interprete(map<string,int> myDict) {
	return (double)myDict[numString];
}

ChineseNum::~ChineseNum() {

}

// Class ChineseAdd
ChineseAdd::~ChineseAdd(){
	delete leftOperator;
	delete rightOperator;
}

ChineseAdd::ChineseAdd( ChineseExp* left, ChineseExp* right ) {
	leftOperator = left;
	rightOperator = right;
}

double ChineseAdd::Interprete(map<string,int> myDict) {
	return (leftOperator->Interprete(myDict) + rightOperator->Interprete(myDict));
}

// Class ChineseSub
ChineseSub::~ChineseSub(){
	delete leftOperator;
	delete rightOperator;
}

ChineseSub::ChineseSub( ChineseExp* left, ChineseExp* right ) {
	leftOperator = left;
	rightOperator = right;
}

double ChineseSub::Interprete(map<string,int> myDict) {
	return (leftOperator->Interprete(myDict) - rightOperator->Interprete(myDict));
}

// Class ChineseMul
ChineseMul::~ChineseMul(){
	delete leftOperator;
	delete rightOperator;
}

ChineseMul::ChineseMul( ChineseExp* left, ChineseExp* right ) {
	leftOperator = left;
	rightOperator = right;
}

double ChineseMul::Interprete(map<string,int> myDict) {
	return (leftOperator->Interprete(myDict) * rightOperator->Interprete(myDict));
}

// Class ChineseDiv
ChineseDiv::~ChineseDiv(){
	delete leftOperator;
	delete rightOperator;
}

ChineseDiv::ChineseDiv( ChineseExp* left, ChineseExp* right ) {
	leftOperator = left;
	rightOperator = right;
}

double ChineseDiv::Interprete(map<string,int> myDict) {
	return (leftOperator->Interprete(myDict) / rightOperator->Interprete(myDict));
}


// Class Evaluator
Evaluator::~Evaluator(){
	delete myExpression;
}

Evaluator::Evaluator( ){
	
}

void Evaluator::Construct(string expression){
	int n = expression.length();
	stack<string> number;
	for (int i = 0; i < n; i += 2){
		string temp = expression.substr(i, 2);
		number.push(temp);
	}
	while (((int)number.size()) != 0){
		myExpression = ExpConstruct(&number);
	}

}

double Evaluator::Interprete( map<string,int> myDict ){
	return myExpression->Interprete(myDict);
}

ChineseExp* Evaluator::ExpConstruct( stack<string>* numStack ){
			ChineseExp* t;
	if (IsNumber((*numStack).top()) == 0){
		t = new ChineseNum((*numStack).top());
		(*numStack).pop();
	}
	if (IsNumber((*numStack).top()) == 2){
		string temp = (*numStack).top();
		(*numStack).pop();
		if (temp.compare("¼Ó") == 0){
			t = new ChineseAdd(ExpConstruct(numStack),myExpression);
		} else if (temp.compare("¼õ") == 0){
			t = new ChineseSub(ExpConstruct(numStack),myExpression);
		} else if (temp.compare("³Ë") == 0){
			t = new ChineseMul(ExpConstruct(numStack),myExpression);
		} else if (temp.compare("³ý") == 0){
			t = new ChineseDiv(ExpConstruct(numStack),myExpression);
		}
	}
	return t;
}

int Evaluator::IsNumber( string tString ){
	int b4 = tString.compare("¼Ó");
	int b5 = tString.compare("¼õ");
	int b6 = tString.compare("³Ë");
	int b7 = tString.compare("³ý");
	if ((b4 == 0) || (b5 == 0) || (b6 == 0) || (b7 == 0)){
		return 2;
	}
	return 0;
}

int main(){
	// Construct the Context first
	map<string,int> Dict;
	Dict["一"] = 1;
	Dict["二"] = 2;
	Dict["三"] = 3;
	Dict["四"] = 4;
	Dict["五"] = 5;
	Dict["六"] = 6;
	Dict["七"] = 7;
	Dict["八"] = 8;
	Dict["九"] = 9;
	Evaluator myEvaluator = Evaluator();
	myEvaluator.Construct("五加二");
	double result = myEvaluator.Interprete(Dict);
	std::cout<<result<<std::endl;
	while(1){

	}
}
