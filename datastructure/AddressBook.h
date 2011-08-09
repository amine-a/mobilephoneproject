// ----------------------------------------------------------------------------
// -- Header of AddressBook class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef ADDRESSBOOK_H_
#define ADDRESSBOOK_H_

#include <QList>

#include "AbstractMobilePhoneObject.h"
#include "Contact.h"

namespace datastructure
{
    /**
     * This class manages mobile phone contacts.
     */
    class AddressBook: public AbstractMobilePhoneObject
    {
	private:
	    QList<Contact*>	contactList;

	    void copyContactList(const QList<Contact*>& contactList);

	public:

	    /**
	     * Constructor of AddressBook class.
	     */
	    AddressBook();

	    /**
	     * Copy constructor of AddressBook class.
	     * The list of contacts is copied.
	     * @param addressBookToCopy AddressBook object to copy.
	     */
	    AddressBook(const AddressBook& addressBookToCopy);

	    /**
	     * Destructor of AddressBook class.
	     */
	    virtual ~AddressBook();

	    /**
	     * Finds the contact with a phone number.
	     * @param phoneNumberValue phone number of the contact.
	     * @return PhoneNumber object found or null if not found.
	     */
	    PhoneNumber* findPhoneNumber(QString phoneNumberValue) const;

	    /**
	     * Finds the contact with a email address.
	     * @param addressEmailValue email address of the contact.
	     * @return EmailAddress object found or null if not found.
	     */
	    EmailAddress* findEmailAddress(QString addressEmailValue) const;

	    /**
	     * Finds the contact with his identifier.
	     * @param contactID identifier of the contact.
	     * @return contact found or null if not found
	     */
	    Contact* findContactWithID(int contactID);

	    /**
	     * Finds the contact with his name.
	     * @param name contact name.
	     * @return contact found or null if not found
	     */
	    Contact* findContactWithName(QString name);

	    /**
	     * Allows to access of contact list.
	     * @return contact list.
	     */
	    const QList<Contact*>& getContactList() const;

	    /**
	     * Adds a contact in the address book.
	     * @param contact contact to add.
	     */
	    void addContact(Contact* contact);

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual AddressBook& operator=(const AddressBook& addressBookToCopy);
    };
}

#endif /* ADDRESSBOOK_H_ */
