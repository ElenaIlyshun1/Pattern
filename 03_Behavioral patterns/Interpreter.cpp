#include<iostream>
#include<vector>
using namespace std;
class Context
{
public:
	vector<string> lexema;
	bool isValid;
	string vocabulary;
	int index;
	Context()
	{
		lexema={};
		isValid = false;
		index = 0;
		vocabulary = "cin";
	}
};
class AbstractExpression
{
public:
	virtual void Interpret(Context *cont)=0;
};
class TerminalExpression:public AbstractExpression
{
public:
	void Interpret(Context *cont)
	{
		int ind = cont->index;
		cont->isValid = (cont->lexema.at(ind) == cont->vocabulary);

	}
};
class NonTerminalExpression :public AbstractExpression
{
		AbstractExpression*termEx;
		AbstractExpression*nonTermEx;
public:
	void Interpret(Context *cont)
	{
		if (cont->index < cont->lexema.size())
		{
			termEx = new TerminalExpression();
			termEx->Interpret(cont);
			cont->index++;
			if (cont->isValid)
			{
				nonTermEx = new NonTerminalExpression();
				nonTermEx->Interpret(cont);
			}
			else cout << "its not recognized expression\n";
		}
		else cout << "your string is valid\n";
	}
};
void main()
{
	Context*c = new Context();
	c->lexema = {
		"cin",
		"cin",
		"cin"
	};
	auto expr = new NonTerminalExpression();
	expr->Interpret(c);

}