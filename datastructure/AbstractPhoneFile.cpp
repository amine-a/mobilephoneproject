// ----------------------------------------------------------------------------
// -- Source of AbstractPhoneFile class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "AbstractPhoneFile.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    AbstractPhoneFile::AbstractPhoneFile(int phoneFileID)
    :AbstractMobilePhoneObject(phoneFileID), path(""), name(""), size(-1), createdDate()
    {
    }

    AbstractPhoneFile::AbstractPhoneFile(const AbstractPhoneFile& PhoneFileToCopy)
    :AbstractMobilePhoneObject(PhoneFileToCopy), path(PhoneFileToCopy.path),
     name(PhoneFileToCopy.name), size(PhoneFileToCopy.size), createdDate(PhoneFileToCopy.createdDate)
    {
    }

    AbstractPhoneFile::~AbstractPhoneFile()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString AbstractPhoneFile::getPath() const
    {
	return this->path;
    }

    QString AbstractPhoneFile::getName() const
    {
	return this->name;
    }

    int AbstractPhoneFile::getSize() const
    {
	return this->size;
    }

    QDate AbstractPhoneFile::getCreatedDate() const
    {
	return this->createdDate;
    }

    void AbstractPhoneFile::phoneFileAttributestoXml(QDomDocument& doc, QDomNode& node) const
    {
	this->textToXml(this->path, "path", doc, node);
	this->textToXml(this->name, "name", doc, node);
	this->textToXml(QString::number(this->size), "size", doc, node);
	this->textToXml(this->createdDate.toString("yyyy.MM.dd"), "createdDate", doc, node);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void AbstractPhoneFile::setPath(QString path)
    {
	this->path = path;
    }

    void AbstractPhoneFile::setName(QString name)
    {
	this->name = name;
    }

    void AbstractPhoneFile::setSize(int size)
    {
	this->size = size;
    }

    void AbstractPhoneFile::setCreatedDate(QDate createdDate)
    {
	this->createdDate = createdDate;
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    AbstractPhoneFile& AbstractPhoneFile::operator=(const AbstractPhoneFile& phoneFileToCopy)
    {
	if(this != &phoneFileToCopy)
	{
	    AbstractMobilePhoneObject::operator=(phoneFileToCopy);

	    this->path		= phoneFileToCopy.path;
	    this->name		= phoneFileToCopy.name;
	    this->size		= phoneFileToCopy.size;
	    this->createdDate	= phoneFileToCopy.createdDate;
	}

	return *this;
    }



}
