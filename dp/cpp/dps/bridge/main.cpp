#include "EncryptionTest.h"

int main(int argc, char **argv)
{
	EncryptionContentType *contentType = new TextContent();
	contentType->encrypt();
	contentType->setAlgo(EncryptionAlgoUtil::TDESAlgo);
	contentType->encrypt();
    
	return 0;
}
