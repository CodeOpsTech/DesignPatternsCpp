#include "EncryptionTest.h"

int main(int argc, char **argv)
{
	Encryption *e = new Encryption();
	e->encrypt("hello");
	
    AESAlgorithm tempVar;
	e->setEncryptionAlgorithm(&tempVar);
	e->encrypt("world");
    
    return 0;
}
