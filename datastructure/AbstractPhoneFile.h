// ----------------------------------------------------------------------------
// -- Header of AbstractPhoneFile class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef ABSTRACTPHONEFILE_H_
#define ABSTRACTPHONEFILE_H_

#include <QDate>

#include "AbstractMobilePhoneObject.h"

namespace datastructure
{
    /**
    * Abstract class.
    * This class allows to store information about phone files.
    */
    class AbstractPhoneFile: public AbstractMobilePhoneObject
    {
	protected:
	    QString	path;
	    QString 	name;
	    int 	size;
	    QDate 	createdDate;

	    void phoneFileAttributestoXml(QDomDocument& doc, QDomNode& node) const;

	public:

	    /**
	     * PhoneFile class constructor.
	     * @param phoneFileID identifier of the file.
	     */
	    AbstractPhoneFile(int phoneFileID);

	    /**
	     * PhoneFile class copy constructor.
	     * @param PhoneFileToCopy PhoneFile object to copy.
	     */
	    AbstractPhoneFile(const AbstractPhoneFile& PhoneFileToCopy);

	    /**
	     * Destructor of PhoneFile class.
	     */
	    virtual ~AbstractPhoneFile();

	    /**
	     * Allows to access of path to the file.
	     * @return path to the file (without name).
	     */
	    QString getPath() const;

	    /**
	     * Changes the path value.
	     * @param path new path value.
	     */
	    void setPath(QString path);

	    /**
	     * Allows to access of file name.
	     * @return file name.
	     */
	    QString getName() const;

	    /**
	     * Changes the name value.
	     * @param name new name value.
	     */
	    void setName(QString name);

	    /**
	     * Allows to access of file size.
	     * @return file size (Bytes).
	     */
	    int getSize() const;

	    /**
	     * Changes the size value.
	     * @param size new size value.
	     */
	    void setSize(int size);

	    /**
	     * Allows to access of created date.
	     * @return created date of the file.
	     */
	    QDate getCreatedDate() const;

	    /**
	     * Changes the created date value.
	     * @param createdDate new created date value.
	     */
	    void setCreatedDate(QDate createdDate);

	    /**
	     * Clone the AbstractPhoneFile object in the new object.
	     */
	    virtual AbstractPhoneFile* clone() const = 0;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const = 0;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual AbstractPhoneFile& operator=(const AbstractPhoneFile& phoneFileToCopy);
	};

} /* namespace mobilephonedatastructure */
#endif /* ABSTRACTPHONEFILE_H_ */
