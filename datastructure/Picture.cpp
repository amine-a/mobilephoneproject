// ----------------------------------------------------------------------------
// -- Source of Picture class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "Picture.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    Picture::Picture(int pictureID)
    :AbstractPhoneFile(pictureID)
    {
    }

    Picture::Picture(const Picture& pictureToCopy)
    :AbstractPhoneFile(pictureToCopy)
    {
    }

    Picture::~Picture()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    void Picture::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement pictureNode;

	pictureNode = doc.createElement("picture");
	pictureNode.setAttribute("id", this->getID());
	this->phoneFileAttributestoXml(doc, pictureNode);

	node.appendChild(pictureNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    AbstractPhoneFile* Picture::clone() const
    {
	return new Picture(*this);
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    Picture& Picture::operator=(const Picture& pictureToCopy)
    {
	if(this != &pictureToCopy)
	{
	    AbstractPhoneFile::operator=(pictureToCopy);
	}

	return *this;
    }
}
