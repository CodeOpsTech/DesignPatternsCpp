#ifndef EXPRESSIONVISITOR
#define EXPRESSIONVISITOR

#include <string>
#include <vector>
#include <iostream>

#include "ExpressionEvaluator.h"

class Visitor
{
public:
	virtual void visit(Constant *constant) = 0;
	virtual void visit(Plus *plus) = 0;
	virtual void visit(Sub *sub) = 0;
	virtual void generate(Expr *expr) = 0;
};

class JVMVisitor : public Visitor
{
public:
	virtual void visit(Constant *arg);
	virtual void visit(Plus *plus);
	virtual void visit(Sub *sub);
	virtual void generate(Expr *expr);
};

class DOTNETVisitor : public Visitor
{
public:
	virtual void visit(Constant *arg);
	virtual void visit(Plus *plus);
	virtual void visit(Sub *sub);
	virtual void generate(Expr *expr);
};

class HTMLVisitor : public Visitor
{
public:
	virtual void visit(Constant *arg);
	virtual void visit(Plus *plus);
	virtual void visit(Sub *sub);
	virtual void generate(Expr *expr);
	virtual void getHeader();
	virtual void getFooter();
};

#endif //#ifndef EXPRESSIONVISITOR
