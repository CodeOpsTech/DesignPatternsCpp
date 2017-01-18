#include "EncryptionTest.h"

Encryption::Encryption()
{
}

Encryption::Encryption(EncryptionAlgo *algo)
{
	this->algo = algo;
}

void Encryption::encrypt(const std::string &str)
{
	algo->encrypt(str);
}

void Encryption::setEncryptionAlgorithm(EncryptionAlgo *algo)
{
	this->algo = algo;
}

EncryptionAlgo *Encryption::getEncryptionAlgorithm()
{
	return algo;
}

void DESAlgorithm::encrypt(const std::string &str)
{
	std::cout << std::string("Encrypting ") << str << std::string(" using DES algorithm") << std::endl;
}

void AESAlgorithm::encrypt(const std::string &str)
{
	std::cout << std::string("Encrypting ") << str << std::string(" using AES algorithm") << std::endl;
}

void TDESAlgorithm::encrypt(const std::string &str)
{
	std::cout << std::string("Encrypting ") << str << std::string(" using TDES algorithm") << std::endl;
}
