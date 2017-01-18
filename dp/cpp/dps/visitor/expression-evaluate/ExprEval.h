#ifndef EXPREVAL
#define EXPREVAL

#include <string>
#include <vector>
#include <iostream>

enum class Target
{
	JVM,
	DOTNET
};

class Expr
{
public:
	static Target t;
	static void setTarget(Target target);
	virtual void genCode() = 0;
};

class Constant : public Expr
{
public:
	int val = 0;
	Constant(int arg);
	virtual void genCode() override;
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
	virtual void genCode() override;
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
	virtual void genCode() override;
};

#endif	//#ifndef EXPREVAL
