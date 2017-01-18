#include "ExpressionEvaluator.h"
#include "ExpressionVisitor.h"

Constant::Constant(int arg)
{
	val = arg;
}

int Constant::getVal()
{
	return val;
}

void Constant::accept(Visitor *v)
{
	v->visit(this);
}

Plus::Plus(Expr *arg1, Expr *arg2)
{
	left = arg1;
	right = arg2;
}

Expr *Plus::getLeft()
{
	return left;
}

Expr *Plus::getRight()
{
	return right;
}

void Plus::accept(Visitor *v)
{
	v->visit(this);
}

Sub::Sub(Expr *arg1, Expr *arg2)
{
	left = arg1;
	right = arg2;
}

Expr *Sub::getLeft()
{
	return left;
}

Expr *Sub::getRight()
{
	return right;
}

void Sub::accept(Visitor *v)
{
	v->visit(this);
}
