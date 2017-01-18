#include "ExprEval.h"

int main(int argc, char **argv)
{
	Expr::setTarget(Target::DOTNET);
	// (10 + (20 - 30))  
	Constant tempVar(10);
	Sub tempVar2(new Constant(20), new Constant(30));
	Expr *expr = new Plus(&tempVar, &tempVar2);
	expr->genCode();
    
	return 0;
}
