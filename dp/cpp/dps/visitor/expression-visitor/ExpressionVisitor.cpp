#include "ExpressionVisitor.h"

void JVMVisitor::visit(Constant *arg)
{
	std::cout << std::string("iload ") << arg->getVal() << std::endl;
}

void JVMVisitor::visit(Plus *plus)
{
	generate(plus->getLeft());
	generate(plus->getRight());
	std::cout << std::string("iadd") << std::endl;
}

void JVMVisitor::visit(Sub *sub)
{
	generate(sub->getLeft());
	generate(sub->getRight());
	std::cout << std::string("isub") << std::endl;
}

void JVMVisitor::generate(Expr *expr)
{
		expr->accept(this);
}

void DOTNETVisitor::visit(Constant *arg)
{
	std::cout << std::string("ldarg ") << arg->getVal() << std::endl;
}

void DOTNETVisitor::visit(Plus *plus)
{
	generate(plus->getLeft());
	generate(plus->getRight());
	std::cout << std::string("add") << std::endl;
}

void DOTNETVisitor::visit(Sub *sub)
{
	generate(sub->getLeft());
	generate(sub->getRight());
	std::cout << std::string("sub") << std::endl;
}

void DOTNETVisitor::generate(Expr *expr)
{
		expr->accept(this);
}

void HTMLVisitor::visit(Constant *arg)
{
	std::cout << std::string("iload ") << arg->getVal() << std::endl;
}

void HTMLVisitor::visit(Plus *plus)
{
	generate(plus->getLeft());
	generate(plus->getRight());
	std::cout << std::string("iadd") << std::endl;
}

void HTMLVisitor::visit(Sub *sub)
{
	generate(sub->getLeft());
	generate(sub->getRight());
	std::cout << std::string("isub") << std::endl;
}

void HTMLVisitor::generate(Expr *expr)
{
	getHeader();
	expr->accept(this);
	getFooter();
}

void HTMLVisitor::getHeader()
{
	std::cout << std::string("<html> <head> <title>Expr</title> </head> <body> <h1>For the expression</h1> <table border='1'> <tr> <th>Node</th> <th>Value</th></tr>") << std::endl;
}

void HTMLVisitor::getFooter()
{
	std::cout << std::string("</table> </body> </html>") << std::endl;
}
