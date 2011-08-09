// ----------------------------------------------------------------------------
// -- Source of Video class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "Video.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    Video::Video(int videoID)
    :AbstractPhoneFile(videoID)
    {
    }

    Video::Video(const Video& videoToCopy)
    :AbstractPhoneFile(videoToCopy)
    {
    }

    Video::~Video()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    void Video::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement videoNode;

	videoNode = doc.createElement("video");
	videoNode.setAttribute("id", this->getID());
	this->phoneFileAttributestoXml(doc, videoNode);

	node.appendChild(videoNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    AbstractPhoneFile* Video::clone() const
    {
	return new Video(*this);
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    Video& Video::operator=(const Video& videoToCopy)
    {
	if(this != &videoToCopy)
	{
	    AbstractPhoneFile::operator=(videoToCopy);
	}

	return *this;
    }
}
