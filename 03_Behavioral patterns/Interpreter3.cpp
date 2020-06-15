//#include<iostream>
//#include<string>
//using namespace std;
//class Context
//{
//public:
//	string lexema;
//	bool isValid;
//	Context()
//	{
//		lexema = "";
//		isValid = false;
//	}
//};
//class AbstractExpression
//{
//public:
//	virtual void Interpret(Context *cont) = 0;
//};
//class TerminalExpressionCin :public AbstractExpression
//{
//public:
//	void Interpret(Context *cont)
//	{
//		if (const char*beg=strstr((cont->lexema).c_str(), "cin"))
//		{
//			int i = beg - cont->lexema.c_str();
//			cont->lexema.erase(cont->lexema.begin() + i, cont->lexema.begin()+i+3);
//			cont->isValid = true;
//			
//		}
//		else
//			cont->isValid = false;
//	}
//};
//class TerminalExpressionCout :public AbstractExpression
//{
//public:
//	void Interpret(Context *cont)
//	{
//		if (const char*beg = strstr((cont->lexema).c_str(), "cout"))
//		{
//			int i = beg - cont->lexema.c_str();
//			cont->lexema.erase(cont->lexema.begin() + i, cont->lexema.begin() + i + 4);
//			cont->isValid = true;
//
//		}
//		else
//			cont->isValid = false;
//	}
//};
//class NonTerminalExpression :public AbstractExpression
//{
//	AbstractExpression*termEx;
//	AbstractExpression*nonTermEx;
//public:
//	void Interpret(Context *cont)
//	{
//		if (cont->lexema.size()!=0)
//		{
//			termEx = new TerminalExpressionCin();
//			termEx->Interpret(cont);
//			delete termEx;
//			if (cont->isValid == false)
//			{
//				termEx = new TerminalExpressionCout();
//				termEx->Interpret(cont);
//				delete termEx;
//			}
//			if (cont->isValid)
//			{
//				nonTermEx = new NonTerminalExpression();
//				nonTermEx->Interpret(cont);
//				delete nonTermEx;
//			}
//			else cout << "its not recognized expression\n";
//		}
//		else cout << "your string is valid\n";
//	}
//};
//void main()
//{
//	Context*c = new Context();
//	c->lexema = "cincoutcin";
//	auto expr = new NonTerminalExpression();
//	expr->Interpret(c);
//
//}