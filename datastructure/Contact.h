// ----------------------------------------------------------------------------
// -- Header of Contact class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef CONTACT_H
#define	CONTACT_H

#include <QList>
#include <QStringList>

#include "AbstractMobilePhoneObject.h"
#include "PhoneNumber.h"
#include "EmailAddress.h"

namespace datastructure
{
    class PhoneNumber; // required to compile
    class EmailAddress; // required to compile

    /**
     * This class allows to manage a mobile phone contact.
     */
    class Contact: public AbstractMobilePhoneObject
    {
	private:
	    QString		    name;
	    QStringList		    orgList;
	    QStringList		    groupList;

	    QList<PhoneNumber*>	    phoneNumberList;
	    QList<EmailAddress*>    emailAddressList;

	    void copyPhoneNumberList(const QList<PhoneNumber*>& phoneNumberListToCopy);
	    void copyEmailAddressList(const QList<EmailAddress*>& emailAddressListToCopy);

	public:

	    /**
	     * Contact class constructor.
	     * @param contactID identifier of the contact.
	     */
	    Contact(int contactID);

	    /**
	     * Copy Constructor of Contact class.
	     * @param contactToCopy contact to copy in the new object.
	     */
	    Contact(const Contact& contactToCopy);

	    /**
	     * Destructor of Contact class.
	     */
	    virtual ~Contact();

	    /**
	     * Allows to access of contact name.
	     * @return contact name.
	     */
	    QString getName() const;

	    /**
	     * Changes the name value.
	     * @param name new name value.
	     */
	    void setName(QString name);

	    /**
	     * Allows to access of the contact organisations.
	     * @return contact organisations.
	     */
	    const QStringList& getOrgList() const;

	    /**
	     * Adds a organisation to the contact.
	     * @param org organisation name to add.
	     */
	    void addOrg(QString org);

	    /**
	     * Allows to access of group list of the contact.
	     * @return group list.
	     */
	    const QStringList& getGroupList() const;

	    /**
	     * Adds a group name to the contact.
	     * @pram group group name to add.
	     */
	    void addGroup(QString group);

	    /**
	     * Adds a phone number to the contact.
	     * @param phoneNumberValue number phone to add.
	     */
	    void addPhoneNumber(QString phoneNumberValue);

	    /**
	     * Adds a email address to the contact.
	     * @param emailAddressValue email address to add.
	     */
	    void addEmailAddress(QString emailAddressValue);

	    /**
	     * Checks if the contact has the phone number and return the PhoneNumber object if it exists.
	     * @param phoneNumberValue phone number.
	     * @return the PhoneNumber object or null if not found.
	     */
	    PhoneNumber* getPhoneNumber(QString phoneNumberValue);

	    /**
	     * Checks if the contact has the email address and return the EmailAddress object if it exists.
	     * @param emailAddressValue email address.
	     * @return the EmailAddress object or null if not found.
	     */
	    EmailAddress* getEmailAddress(QString emailAddressValue);

	    /**
	     * Allows to access of the phone number list.
	     * @return phone number list of the contact.
	     */
	    const QList<PhoneNumber*>& getPhoneNumberList() const;

	    /**
	     * Allows to access of the email address list.
	     * @return email address list of the contact.
	     */
	    const QList<EmailAddress*>& getEmailAddressList() const;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual Contact& operator=(const Contact& contactToCopy);
    };
}

#endif	/* CONTACT_H */

