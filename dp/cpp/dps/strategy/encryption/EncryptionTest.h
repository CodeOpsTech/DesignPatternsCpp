#ifndef ENCRYPTIONTEST
#define ENCRYPTIONTEST

#include <string>
#include <vector>
#include <iostream>

class EncryptionAlgo
{
public:
	virtual void encrypt(const std::string &str) = 0;
};

class DESAlgorithm : public EncryptionAlgo
{
public:
	virtual void encrypt(const std::string &str);
};
class AESAlgorithm : public EncryptionAlgo
{
public:
	virtual void encrypt(const std::string &str);
};
class TDESAlgorithm : public EncryptionAlgo
{
public:
	virtual void encrypt(const std::string &str);
};

class Encryption
{
private:
	EncryptionAlgo *algo = new DESAlgorithm();
public:
	virtual ~Encryption()
	{
		delete algo;
	}

	Encryption();
	Encryption(EncryptionAlgo *algo);
	virtual void encrypt(const std::string &str);
	virtual void setEncryptionAlgorithm(EncryptionAlgo *algo);
	virtual EncryptionAlgo *getEncryptionAlgorithm();
};



class EncryptionTest
{
	static void main(std::vector<std::string> &args);
};


#endif	//#ifndef ENCRYPTIONTEST
