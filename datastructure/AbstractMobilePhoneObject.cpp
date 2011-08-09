// ----------------------------------------------------------------------------
// -- Source of AbstractMobilePhoneObject class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "AbstractMobilePhoneObject.h"

using namespace std;

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    AbstractMobilePhoneObject::AbstractMobilePhoneObject()
    :objectID(-1), deleted(false)
    {
    }

    AbstractMobilePhoneObject::AbstractMobilePhoneObject(int objectID)
    :objectID(objectID), deleted(false)
    {
    }

    AbstractMobilePhoneObject::AbstractMobilePhoneObject(const AbstractMobilePhoneObject& mobilePhoneObject)
    :objectID(mobilePhoneObject.objectID), deleted(mobilePhoneObject.deleted)
    {
    }

    AbstractMobilePhoneObject::~AbstractMobilePhoneObject()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    int AbstractMobilePhoneObject::getID() const
    {
	return this->objectID;
    }

    bool AbstractMobilePhoneObject::isDeleted() const
    {
	return this->deleted;
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void AbstractMobilePhoneObject::setID(int objectID)
    {
	this->objectID = objectID;
    }

    void AbstractMobilePhoneObject::textToXml(QString text, QString name, QDomDocument& doc, QDomNode& node) const
    {
	QDomElement element;

	text = text.trimmed();

	if(! text.isEmpty())
	{
	    element = doc.createElement(name);
	    element.appendChild(doc.createTextNode(text));
	    node.appendChild(element);
	}
    }

    // -----------------------------------------------------------------
    // -- OPERATORS
    // -----------------------------------------------------------------

    AbstractMobilePhoneObject& AbstractMobilePhoneObject::operator=(const AbstractMobilePhoneObject& mobilePhoneObject)
    {
	if( this != &mobilePhoneObject)
	{
	    this->deleted   = mobilePhoneObject.deleted;
	    this->objectID  = mobilePhoneObject.objectID;
	}

	return *this;
    }

    ostream& operator<<(ostream &flux,  const AbstractMobilePhoneObject& mobilePhoneObject)
    {
	/*
	QDomImplementation impl = QDomDocument().implementation();
	// document with document type
	QString name = "stone";
	QString publicId = "-//XADECK//DTD Stone 1.0 //EN";
	QString systemId = "http://www-imagis.imag.fr/DTD/stone1.dtd";
	QDomDocument doc(impl.createDocumentType(name,publicId,systemId));
	*/

	QDomDocument doc;
	mobilePhoneObject.toXml(doc, doc);

	flux << doc.toString().toStdString().c_str();
	return flux;
    }
}
