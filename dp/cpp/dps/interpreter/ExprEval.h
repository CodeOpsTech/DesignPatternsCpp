#ifndef EXPREVAL
#define EXPREVAL

#include <string>
#include <vector>
#include <iostream>

class Expr
{
public:
	virtual int eval() = 0;
	virtual ~Expr(); 
};

class Constant : public Expr
{
public:
	int val = 0;
	Constant(int arg);
	virtual int eval() override;
};

class Plus : public Expr
{
private:
	Expr *left, *right;
public:
	virtual ~Plus()
	{
		delete left;
		delete right;
	}

	Plus(Expr *arg1, Expr *arg2);
	virtual int eval() override;
};

class Sub : public Expr
{
private:
	Expr *left, *right;
public:
	virtual ~Sub()
	{
		delete left;
		delete right;
	}

	Sub(Expr *arg1, Expr *arg2);
	virtual int eval() override;
};

#endif	//#ifndef EXPREVAL
