// ----------------------------------------------------------------------------
// -- Header of EmailAddress class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef EMAILADDRESS_H
#define	EMAILADDRESS_H

#include "Contact.h"

namespace datastructure
{
    class Contact; // required to compile

    /**
     * This class allows to store information about a email address.
     */
    class EmailAddress: public AbstractMobilePhoneObject
    {
	private:
	    QString     value;
	    Contact*    contact;

	public:

	    /**
	     * Constructor of EmailAddress class without owner.
	     * @param value email address.
	     */
	    EmailAddress(QString value);

	    /**
	     * Constructor of EmailAddress class with owner.
	     * @param value email address.
	     * @param contact the owner of the email address (the pointer address is just copied!).
	     */
	    EmailAddress(QString value, Contact* contact);

	    /**
	     * Copy constructor.
	     * @param emailAddressToCopy email address to copy (the pointer address of the contact is copied !).
	     */
	    EmailAddress(const EmailAddress& emailAddressToCopy);

	    /**
	     * Destructor of EmailAddress class
	     */
	    virtual ~EmailAddress();

	    /**
	     * Allows accessing value of the email address.
	     * @return value of the email address.
	     */
	    QString getValue() const;

	    /**
	     * Allows accessing owner of the email address.
	     * @return owner of the email address (null if no owner).
	     */
	    Contact* getContact() const;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual EmailAddress& operator=(const EmailAddress& emailAddressToCopy);
    };
}

#endif	/* EMAILADDRESS_H */

