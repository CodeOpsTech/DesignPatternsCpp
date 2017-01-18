#include "ExprEval.h"

int main(int argc, char **argv)
{
	// (10 + (30 - 20))  
	Constant tempVar(10);
	Sub tempVar2(new Constant(30), new Constant(20));
	Expr *expr = new Plus(&tempVar, &tempVar2);
	std::cout << expr->eval() << std::endl;
	return 0;
}
