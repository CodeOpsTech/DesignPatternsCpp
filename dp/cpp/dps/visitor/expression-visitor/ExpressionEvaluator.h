#ifndef EXPRESSIONEVALUATOR
#define EXPRESSIONEVALUATOR

#include <string>
#include <vector>
#include <iostream>

class Visitor;

class Expr
{
public:
	virtual void accept(Visitor *v) = 0;
};

class Constant : public Expr
{
public:
	int val = 0;
	Constant(int arg);
	virtual int getVal();
	virtual void accept(Visitor *v) override;
};

class Plus : public Expr
{
private:
	Expr *left, *right;
public:
	Plus(Expr *arg1, Expr *arg2);
	virtual Expr *getLeft();
	virtual Expr *getRight();
	virtual void accept(Visitor *v) override;
};

class Sub : public Expr
{
private:
	Expr *left, *right;
public:
	Sub(Expr *arg1, Expr *arg2);
	virtual Expr *getLeft();
	virtual Expr *getRight();
	virtual void accept(Visitor *v) override;
};

#endif //#ifndef EXPRESSIONEVALUATOR
