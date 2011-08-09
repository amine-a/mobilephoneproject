// ----------------------------------------------------------------------------
// -- Header of PhoneNumber class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef PHONENUMBER_H
#define	PHONENUMBER_H

#include "Contact.h"

namespace datastructure
{
    class Contact; // required to compile

    /**
     * This class allows to store information about a phone number.
     */
    class PhoneNumber: public AbstractMobilePhoneObject
    {
	private:
	    QString     value;
	    Contact*	contact;

	public:

	    /**
	     * Constructor of PhoneNumber class without owner.
	     * @param value phone number.
	     */
	    PhoneNumber(QString value);

	    /**
	     * Constructor of PhoneNumber class with owner.
	     * @param value phone number.
	     * @param contact the owner of the phone number (copies the pointer !).
	     */
	    PhoneNumber(QString value, Contact* contact);

	    /**
	     * Copy constructor.
	     * @param phoneNumberToCopy phone number to copy (the pointer of the contact is copied !).
	     */
	    PhoneNumber(const PhoneNumber& phoneNumberToCopy);

	    /**
	     * Destructor of PhoneNumber class
	     */
	    virtual ~PhoneNumber();

	    /**
	     * Allows accessing value of the phone number.
	     * @return value of the number phone.
	     */
	    QString getValue() const;

	    /**
	     * Allows accessing owner of the phone number.
	     * @return owner of the phone number (null if no owner).
	     */
	    Contact* getContact() const;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual PhoneNumber& operator=(const PhoneNumber& phoneNumberToCopy);
    };
}

#endif	/* PHONENUMBER_H */
