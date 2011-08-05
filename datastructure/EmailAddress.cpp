// ----------------------------------------------------------------------------
// -- Source of EmailAddress class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "EmailAddress.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    EmailAddress::EmailAddress(QString value)
    :AbstractMobilePhoneObject(), value(value), contact(NULL)
    {
    }

    EmailAddress::EmailAddress(QString value, Contact* contact)
    :AbstractMobilePhoneObject(),value(value), contact(contact)
    {
    }

    EmailAddress::EmailAddress(const EmailAddress& emailAddressToCopy)
    :AbstractMobilePhoneObject(emailAddressToCopy), value(emailAddressToCopy.getValue()),
     contact(emailAddressToCopy.contact)
    {
    }

    EmailAddress::~EmailAddress()
    {
	this->contact = NULL; // The contact is deleted in AddressBook class
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString EmailAddress::getValue() const
    {
	return this->value;
    }

    Contact* EmailAddress::getContact() const
    {
	return this->contact;
    }

    void EmailAddress::toXml(QDomDocument& doc, QDomNode& node) const
    {
	this->textToXml(this->value, "emailAddress", doc, node);
    }

    // -----------------------------------------------------------------
    // -- OPERATORS
    // -----------------------------------------------------------------

    EmailAddress& EmailAddress::operator=(const EmailAddress& emailAddressToCopy)
    {
	if( this != &emailAddressToCopy )
	{
	    AbstractMobilePhoneObject::operator=(emailAddressToCopy);

	    this->value	    = emailAddressToCopy.value;
	    this->contact   = emailAddressToCopy.contact;
	}

	return *this;
    }
}
