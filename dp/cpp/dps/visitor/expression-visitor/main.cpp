#include "ExpressionVisitor.h"

int main(int argc, const char** argv)
{
	// (10 + (20 - 30))  
	Constant tempVar(10);
	Sub tempVar2(new Constant(20), new Constant(30));
	Expr *expr = new Plus(&tempVar, &tempVar2);
	
    	Visitor *v1 = new HTMLVisitor();
	v1->generate(expr);
    
    	Visitor *v2 = new DOTNETVisitor();
	v2->generate(expr);
    
    	return 0;
}
