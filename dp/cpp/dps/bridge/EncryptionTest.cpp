#include "EncryptionTest.h"

EncryptionAlgo EncryptionAlgoUtil::DESAlgo = [] () { std::cout << std::string("DES algo") << std::endl; };
EncryptionAlgo EncryptionAlgoUtil::AESAlgo = [] () { std::cout << std::string("AES algo") << std::endl; };
EncryptionAlgo EncryptionAlgoUtil::TDESAlgo = [] () { std::cout << std::string("TDES algo") << std::endl; };

EncryptionAlgo EncryptionContentType::getAlgo()
{
	return algo;
}

void EncryptionContentType::setAlgo(EncryptionAlgo algo)
{
	this->algo = algo;
}

void EncryptionContentType::encrypt()
{
	algo();
}

void ImageContent::encrypt()
{
	EncryptionContentType::encrypt();
	std::cout << std::string("Encrypting Image") << std::endl;
}

void TextContent::encrypt()
{
	EncryptionContentType::encrypt();
	std::cout << std::string("Encrypting Text") << std::endl;
}
