// ----------------------------------------------------------------------------
// -- Header of Picture class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef PICTURE_H_
#define PICTURE_H_

#include "AbstractPhoneFile.h"

namespace datastructure
{
    /**
    * This class allows to store information about pictures.
    */
    class Picture: public AbstractPhoneFile
    {
	public:
	    /**
	     * Picture class constructor.
	     * @param pictureID identifier of the picture.
	     */
	    Picture(int pictureID);

	    /**
	     * Picture class copy constructor.
	     * @param pictureToCopy Picture object to copy.
	     */
	    Picture(const Picture& pictureToCopy);

	    /**
	     * Destructor of Picture class.
	     */
	    virtual ~Picture();

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
	    virtual Picture& operator=(const Picture& pictureToCopy);
    };
}
#endif /* PICTURE_H_ */
