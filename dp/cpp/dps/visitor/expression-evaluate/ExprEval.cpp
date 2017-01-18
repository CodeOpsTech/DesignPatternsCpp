#include "ExprEval.h"

Target Expr::t = Target::DOTNET;

void Expr::setTarget(Target target)
{
	t = target;
}

Constant::Constant(int arg)
{
	val = arg;
}

void Constant::genCode()
{
	if (t == Target::JVM)
	{
		std::cout << std::string("bipush ") << val << std::endl;
	}
	else
	{ // DOTNET
		std::cout << std::string("ldarg ") << val << std::endl;
	}
}

Plus::Plus(Expr *arg1, Expr *arg2)
{
	left = arg1;
	right = arg2;
}

void Plus::genCode()
{
	left->genCode();
	right->genCode();
	if (t == Target::JVM)
	{
		std::cout << std::string("iadd") << std::endl;
	}
	else
	{ // DOTNET
		std::cout << std::string("add") << std::endl;
	}
}

Sub::Sub(Expr *arg1, Expr *arg2)
{
	left = arg1;
	right = arg2;
}

void Sub::genCode()
{
	left->genCode();
	right->genCode();
	if (t == Target::JVM)
	{
		std::cout << std::string("isub") << std::endl;
	}
	else
	{ // DOTNET
		std::cout << std::string("sub") << std::endl;
	}
}
