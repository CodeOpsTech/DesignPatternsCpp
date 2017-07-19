/* Generated by Together */

#pragma warning (disable : 4786) //vector warnings about string too long...

#ifndef DATAOBJECT_H
#define DATAOBJECT_H



namespace VCFCOM{
/**
 * base implementation of IDataObject 
 */

class APPKIT_API DataRendering : public VCF::Object{
public:
	DataRendering( FORMATETC * formatETC, STGMEDIUM * stgMedium, IUnknown* newStorageOwner );
	virtual ~DataRendering();

	FORMATETC       m_formatETC;             
    STGMEDIUM       m_storage;            
    IUnknown*       m_owner;     
	
	virtual VCF::String toString();

	bool operator == ( const DataRendering& dataRenderToCompare )const
	{	
		bool result = false;
		
		result = ( (this->m_formatETC.cfFormat == dataRenderToCompare.m_formatETC.cfFormat) &&
		           (this->m_formatETC.dwAspect == dataRenderToCompare.m_formatETC.dwAspect) &&		
				   (this->m_formatETC.tymed == dataRenderToCompare.m_formatETC.tymed) );

		return result;
	};

	bool operator == ( const FORMATETC& formatETCToCompare )const
	{	
		bool result = false;
		
		result = ( (this->m_formatETC.cfFormat == formatETCToCompare.cfFormat) &&
		           (this->m_formatETC.dwAspect == formatETCToCompare.dwAspect) &&		
				   (this->m_formatETC.tymed == formatETCToCompare.tymed) );

		return result;
	};
};	


/**
*This class implements IDataObject directly but also uses a member variable
*taht can point to a reference to some already existing IDataObject instance
*/
class APPKIT_API COMDataObject : public IDataObject, public COMObject, public VCF::DataObjectPeer {
public:    

   	COMDataObject( IDataObject* outerDataObject=NULL );

	virtual ~COMDataObject();

	/**
     * Adds a new data type that the dataobject supports. 
     */
	virtual void addSupportedData( const unsigned long & dataType, VCF::ClipboardDataObject* data );  
	
	virtual VCF::ClipboardDataObject* getSupportedData( const unsigned long & dataType );

    /**
     * is the data type passed in supported by the data object ?
     */
    virtual bool isTypeSupported(const unsigned long & dataType );    
	
	virtual bool supportsInterface( REFIID riid, void** object );

	void clearRenderings();

	
	COMOBJ_QUERY_INTERFACE_IMPL;

	STDMETHODIMP_(ULONG) AddRef(void);

    STDMETHODIMP_(ULONG) Release(void);

	
	STDMETHODIMP GetData( FORMATETC * formatETC, STGMEDIUM * stgMedium );
	
	STDMETHODIMP GetDataHere( FORMATETC * formatETC, STGMEDIUM * stgMedium );
	
	STDMETHODIMP QueryGetData( FORMATETC * formatETC );
	
	STDMETHODIMP GetCanonicalFormatEtc( FORMATETC * formatETCIn, FORMATETC * formatETCOut );	
	
	STDMETHODIMP SetData( FORMATETC * formatETC, STGMEDIUM * stgMedium, BOOL releaseData );
	
	STDMETHODIMP EnumFormatEtc( DWORD dwDirection, IEnumFORMATETC ** ppenumFormatetc );
	
	STDMETHODIMP DAdvise( FORMATETC * formatETC, DWORD advf, IAdviseSink * pAdvSink,  DWORD * pdwConnection );
	
	STDMETHODIMP DUnadvise( DWORD dwConnection );
	
	STDMETHODIMP EnumDAdvise( IEnumSTATDATA ** ppenumAdvise );
 
private:
	DataRendering* findDataRenderingForType( FORMATETC* formatETC );

	UINT translateFrameworkFormat( const unsigned long& dataType );
	FORMATETC translateFrameworkFormatToFormatETC( const unsigned long& dataType );
	VCF::String translateClipboardFmt( const UINT& fmtType );

	std::vector< DataRendering* > m_renderings;
	std::map<unsigned long, VCF::ClipboardDataObject*> m_dataMap;

	IDataObject* m_outerDataObject;
};


class APPKIT_API EnumFormatETC : public IEnumFORMATETC, public EnumObject<FORMATETC> {
public:

	EnumFormatETC():
		EnumObject<FORMATETC>(){};

	EnumFormatETC( const EnumFormatETC& enumObj ):
		EnumObject<FORMATETC>( enumObj ){};

	virtual ~EnumFormatETC(){};
	
	COMOBJ_QUERY_INTERFACE_IMPL;

	COMOBJ_ADD_REF_IMPL;

	COMOBJ_RELEASE_IMPL;	

	STDMETHODIMP Next( ULONG elementsRequested, FORMATETC *elementList, ULONG *elementsFetched ){
		return EnumObject<FORMATETC>::Next( elementsRequested, elementList, elementsFetched );
	};

	STDMETHODIMP Skip( ULONG elementsToSkip ){
		return EnumObject<FORMATETC>::Skip( elementsToSkip );
	};

	STDMETHODIMP Reset(void){
		return EnumObject<FORMATETC>::Reset();
	};

	STDMETHODIMP Clone( IEnumFORMATETC** enumFmtEtc ){
		EnumObject<FORMATETC>* enumFmt = NULL;
		//HRESULT result = EnumObject<FORMATETC>::Clone( &enumFmt );
		enumFmt = new EnumFormatETC( *this );
		*enumFmtEtc = (IEnumFORMATETC*)(COMObject*)enumFmt;
		return NOERROR;//result;//E_NOTIMPL;
	};


	virtual bool supportsInterface( REFIID riid, void** object ){
		bool result = 0 != (IID_IEnumFORMATETC == riid);
		if ( true == result ){
			*object = (IEnumFORMATETC*)(COMObject*)this;
		}
		return 	result;
	};

	
};


};
#endif //DATAOBJECT_HCT_H