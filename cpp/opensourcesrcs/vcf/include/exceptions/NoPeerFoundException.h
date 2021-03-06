/* Generated by Together */

#ifndef NOPEERFOUNDEXCEPTION_H
#define NOPEERFOUNDEXCEPTION_H



namespace VCF {

class FRAMEWORK_API NoPeerFoundException : public BasicException {
public:
	NoPeerFoundException( const String & message ):
	  BasicException( message ){};

	NoPeerFoundException():
		BasicException( NO_PEER ){};

	NoPeerFoundException( const String & message, const int lineNumber ):
		BasicException(message, lineNumber){};

	virtual ~NoPeerFoundException(){};
};

};

#endif //NOPeerFOUNDEXCEPTION_H