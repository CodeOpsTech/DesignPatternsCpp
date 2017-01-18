#ifndef ENCRYPTIONTEST
#define ENCRYPTIONTEST

#include <string>
#include <vector>
#include <iostream>
#include <functional>

using EncryptionAlgo = std::function<void()>;

class EncryptionAlgoUtil
{
public:
	static EncryptionAlgo DESAlgo;
	static EncryptionAlgo AESAlgo;
	static EncryptionAlgo TDESAlgo;
};

class EncryptionContentType
{
public:
	EncryptionAlgo algo = EncryptionAlgoUtil::DESAlgo;
	virtual EncryptionAlgo getAlgo();
	virtual void setAlgo(EncryptionAlgo algo);
	virtual void encrypt();
};

class ImageContent : public EncryptionContentType
{
public:
	virtual void encrypt() override;
};

class TextContent : public EncryptionContentType
{
public:
	virtual void encrypt() override;
};

#endif	//#ifndef ENCRYPTIONTEST
