#include "ExprEval.h"

Expr::~Expr() {}

Constant::Constant(int arg)
{
	val = arg;
}

int Constant::eval()
{
	return val;
}

Plus::Plus(Expr *arg1, Expr *arg2)
{
	left = arg1;
	right = arg2;
}

int Plus::eval()
{
	int leftVal = left->eval();
	int rightVal = right->eval();
	return leftVal + rightVal;
}

Sub::Sub(Expr *arg1, Expr *arg2)
{
	left = arg1;
	right = arg2;
}

int Sub::eval()
{
	int leftVal = left->eval();
	int rightVal = right->eval();
	return leftVal - rightVal;
}
