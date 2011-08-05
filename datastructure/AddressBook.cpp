// ----------------------------------------------------------------------------
// -- Source of AddressBook class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "AddressBook.h"

using namespace std;

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    AddressBook::AddressBook()
    :AbstractMobilePhoneObject()
    {
	// Empty
    }

    AddressBook::AddressBook(const AddressBook& addressBookToCopy)
    :AbstractMobilePhoneObject(addressBookToCopy)
    {
	this->copyContactList(addressBookToCopy.contactList);
    }

    AddressBook::~AddressBook()
    {
	while(! this->contactList.isEmpty())
	    delete this->contactList.takeFirst();
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    const QList<Contact*>& AddressBook::getContactList() const
    {
	return this->contactList;
    }

    void AddressBook::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement addressBookNode;
	Contact* contact;

	if(! this->contactList.empty())
	{
	    addressBookNode = doc.createElement("addressBook");
	    foreach(contact, this->contactList)
	    {
		contact->toXml(doc, addressBookNode);
	    }
	}

	node.appendChild(addressBookNode);
    }

    PhoneNumber* AddressBook::findPhoneNumber(QString phoneNumberValue) const
    {
	QListIterator<Contact*> itContact(this->contactList);
	PhoneNumber* phoneNumber(NULL);

	while(itContact.hasNext() && phoneNumber == NULL)
	{
	    phoneNumber = itContact.next()->getPhoneNumber(phoneNumberValue);
	}

	return phoneNumber;
    }

    EmailAddress* AddressBook::findEmailAddress(QString addressEmailValue) const
    {
	QListIterator<Contact*> itContact(this->contactList);
	EmailAddress* emailAddress(NULL);

	while(itContact.hasNext() && emailAddress == NULL)
	{
	    emailAddress = itContact.next()->getEmailAddress(addressEmailValue);
	}

	return emailAddress;
    }

    Contact* AddressBook::findContactWithID(int contactID)
    {
	QListIterator<Contact*> itContact(this->contactList);
	Contact* contact(NULL);

	while(itContact.hasNext() && contact == NULL)
	{
	    contact = itContact.next();

	    if( contact->getID() != contactID )
		contact = NULL;
	}

	return contact;
    }

    Contact* AddressBook::findContactWithName(QString name)
    {
	QListIterator<Contact*> itContact(this->contactList);
	Contact* contact(NULL);

	while(itContact.hasNext() && contact == NULL)
	{
	    contact = itContact.next();

	    if( contact->getName() != name )
		contact = NULL;
	}

	return contact;
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void AddressBook::copyContactList(const QList<Contact*>& contactList)
    {
	Contact* contact;

	foreach(contact, contactList)
	{
	    this->contactList.push_back( new Contact(*contact) );
	}
    }

    void AddressBook::addContact(Contact* contact)
    {
	this->contactList.push_back(contact);
    }

    // -----------------------------------------------------------------
    // -- OPERATORS
    // -----------------------------------------------------------------

    AddressBook& AddressBook::operator=(const AddressBook& addressBookToCopy)
    {
	if(this != &addressBookToCopy)
	{
	    while(! this->contactList.isEmpty())
		delete this->contactList.takeFirst();

	    this->copyContactList(addressBookToCopy.contactList);
	}

	return *this;
    }
}
