// ----------------------------------------------------------------------------
// -- Header of Document class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include "AbstractPhoneFile.h"

namespace datastructure
{
    /**
     * This class allows to store information about documents.
     */
    class Document: public AbstractPhoneFile
    {
	public:

	    /**
	     * Document class constructor.
	     * @param documentID identifier of the document.
	     */
	    Document(int documentID);

	    /**
	     * Document class copy constructor.
	     * @param pictureToCopy Document object to copy.
	     */
	    Document(const Document& documentToCopy);

	    /**
	     * Destructor of Document class.
	     */
	    virtual ~Document();

	    /**
	     * @see AbstractPhoneFile::clone()
	     */
	    virtual AbstractPhoneFile* clone() const;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual Document& operator=(const Document& documentToCopy);
    };

}

#endif /* DOCUMENT_H_ */
