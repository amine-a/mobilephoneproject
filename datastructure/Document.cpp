// ----------------------------------------------------------------------------
// -- Source of Document class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "Document.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    Document::Document(int documentID)
    :AbstractPhoneFile(documentID)
    {
    }

    Document::Document(const Document& documentToCopy)
    :AbstractPhoneFile(documentToCopy)
    {
    }

    Document::~Document()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    void Document::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement documentNode;

	documentNode = doc.createElement("document");
	documentNode.setAttribute("id", this->getID());
	this->phoneFileAttributestoXml(doc, documentNode);

	node.appendChild(documentNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    AbstractPhoneFile* Document::clone() const
    {
	return new Document(*this);
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    Document& Document::operator=(const Document& documentToCopy)
    {
	if(this != &documentToCopy)
	{
	    AbstractPhoneFile::operator=(documentToCopy);
	}

	return *this;
    }
}
