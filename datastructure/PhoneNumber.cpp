// ----------------------------------------------------------------------------
// -- Source of PhoneNumber class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "PhoneNumber.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    PhoneNumber::PhoneNumber(QString value)
    :AbstractMobilePhoneObject(), value(value), contact(NULL)
    {
    }

    PhoneNumber::PhoneNumber(QString value, Contact* contact)
    :AbstractMobilePhoneObject(), value(value), contact(contact)
    {
    }

    PhoneNumber::PhoneNumber(const PhoneNumber& phoneNumberToCopy)
    :AbstractMobilePhoneObject(phoneNumberToCopy), value(phoneNumberToCopy.getValue()),
     contact(phoneNumberToCopy.contact)
    {
    }

    PhoneNumber::~PhoneNumber()
    {
    	this->contact = NULL; // The contact is deleted in AddressBook class
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString PhoneNumber::getValue() const
    {
	return this->value;
    }

    Contact* PhoneNumber::getContact() const
    {
	return this->contact;
    }

    void  PhoneNumber::toXml(QDomDocument& doc, QDomNode& node) const
    {
	this->textToXml(this->value, "phoneNumber", doc, node);
    }

    // -----------------------------------------------------------------
    // -- OPERATORS
    // -----------------------------------------------------------------

    PhoneNumber& PhoneNumber::operator=(const PhoneNumber& phoneNumberToCopy)
    {
        if( this != &phoneNumberToCopy )
        {
	    AbstractMobilePhoneObject::operator=(phoneNumberToCopy);

	    this->value	    = phoneNumberToCopy.value;
	    this->contact   = phoneNumberToCopy.contact;
        }

	return *this;
    }
}
