#include <iostream>
#include <string>
#include <list>
class IExpression
{
public:
	virtual int Interpret( void ) = 0;
};

class NumberExpression: public IExpression
{
private:
	int number;
public:
	NumberExpression( int num )
	{
		number = num - 48;
	}
	int Interpret()
	{
		return number;
	}
};

class AddExpression: public IExpression
{
private:
	IExpression* leftExpression;
	IExpression* rightExpression;
public:
	AddExpression( IExpression* left, IExpression* right )
	{
		leftExpression = left;
		rightExpression = right;
	}
	int Interpret()
	{
		return leftExpression->Interpret() + rightExpression->Interpret();
	}
};

class SubstractExpression : public IExpression
{
private:
	IExpression* leftExpression;
	IExpression* rightExpression;
public:
	SubstractExpression( IExpression* left, IExpression* right )
	{
		leftExpression = left;
		rightExpression = right;
	}
	int Interpret()
	{
		return leftExpression->Interpret() - rightExpression->Interpret();
	}
};

class TokenReader
{
private:

public:
	IExpression* ReadToken( std::list<char>& tokenList )
	{
		return ReadNextToken(tokenList);
	}
	IExpression* ReadNextToken( std::list<char>& tokenList )
	{
		int i;
		
		std::list<char>::iterator itr = tokenList.begin();
		//Limiting Arithmatic operation for single digit numbers only 
		//if operation is performed on numbers greater then 9 then
		//list<char> would require list <string> and unnecessary 
		//parsing will involved, so keeping example simple
		if( ((*itr) >= 48 ) && ((*itr) <= 57 ) )// checking asci value for 0 to 9
		{
			i = (*itr);
			tokenList.pop_front();
			return new NumberExpression(i);
		}
		else
		{
			return ReadNonNumberedToken( tokenList );
		}

	}
	IExpression* ReadNonNumberedToken( std::list<char>& tokenList )
	{
		std::list<char>::iterator itr = tokenList.begin();
		char c = (*itr);
		tokenList.pop_front();
		IExpression* left = ReadNextToken( tokenList );
		IExpression* right = ReadNextToken( tokenList );
		if ( c == '+' )
		{
			return new AddExpression(left, right);
		}
		else if ( c == '-')
		{
			return new SubstractExpression(left,right);
		}
		else 
			return NULL;
	}
};

int main()
{
	std::list<char> tokenList;
	tokenList.push_back('+');
	tokenList.push_back('-');
	tokenList.push_back('9');
	tokenList.push_back('2');
	tokenList.push_back('3'); // ((9-2)+3)
	TokenReader* tokenReader = new TokenReader();
	IExpression* expression = tokenReader->ReadToken(tokenList);

	std::cout << expression->Interpret() << std::endl;
	tokenList.clear();
	tokenList.push_back('+');
	tokenList.push_back('-');
	tokenList.push_back('9');
	tokenList.push_back('5');
	tokenList.push_back('-');
	tokenList.push_back('8');
	tokenList.push_back('2');// (9 + 5) - (8 - 2) = 9// need to correct the math in this program
	
	std::cout << tokenReader->ReadToken(tokenList)->Interpret() << std::endl;
}