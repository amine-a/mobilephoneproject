// ----------------------------------------------------------------------------
// -- Header of Video class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef VIDEO_H_
#define VIDEO_H_

#include "AbstractPhoneFile.h"

namespace datastructure
{
    /**
     * This class allows to store information about videos.
     */
    class Video: public AbstractPhoneFile
    {
	public:
	    /**
	     * Picture class constructor.
	     * @param videoID identifier of the video.
	     */
	    Video(int videoID);

	    /**
	     * Picture class copy constructor.
	     * @param videoToCopy Video object to copy.
	     */
	    Video(const Video& videoToCopy);

	    /**
	     * Destructor of Picture class.
	     */
	    virtual ~Video();

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
	    virtual Video& operator=(const Video& videoToCopy);
    };
}
#endif /* VIDEO_H_ */
