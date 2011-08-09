// ----------------------------------------------------------------------------
// -- Source of Contact class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "Contact.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    Contact::Contact(int contactID)
    : AbstractMobilePhoneObject(contactID), name(""), orgList(), groupList()
    {
    }

    Contact::Contact(const Contact& contactToCopy)
    :AbstractMobilePhoneObject(contactToCopy), name(contactToCopy.name),
     orgList(contactToCopy.orgList), groupList(contactToCopy.groupList)
    {
	this->copyPhoneNumberList( contactToCopy.phoneNumberList );
	this->copyEmailAddressList( contactToCopy.emailAddressList );
    }

    Contact::~Contact()
    {
	while(! this->phoneNumberList.isEmpty())
	    delete this->phoneNumberList.takeFirst();

	while(! this->emailAddressList.isEmpty())
	    delete this->emailAddressList.takeFirst();
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString Contact::getName() const
    {
    	return this->name;
    }

    const QStringList& Contact::getOrgList() const
    {
    	return this->orgList;
    }

    const QStringList& Contact::getGroupList() const
    {
    	return this->groupList;
    }

    PhoneNumber* Contact::getPhoneNumber(QString phoneNumberValue)
    {
	QListIterator<PhoneNumber*> itPhoneNumber(this->phoneNumberList);
	PhoneNumber* phoneNumber(NULL);

	while(itPhoneNumber.hasNext() && phoneNumber == NULL)
	{
	    phoneNumber = itPhoneNumber.next();

	    if(phoneNumber->getValue() != phoneNumberValue)
		phoneNumber = NULL;
	}

	return phoneNumber;
    }

    EmailAddress* Contact::getEmailAddress(QString emailAddressValue)
    {
	QListIterator<EmailAddress*> itEmailAddress(this->emailAddressList);
	EmailAddress* emailAddress(NULL);

	while(itEmailAddress.hasNext() && emailAddress == NULL)
	{
	    emailAddress = itEmailAddress.next();

	    if(emailAddress->getValue() != emailAddressValue)
		emailAddress = NULL;
	}

	return emailAddress;
    }

    const QList<PhoneNumber*>& Contact::getPhoneNumberList() const
    {
	return this->phoneNumberList;
    }

    const QList<EmailAddress*>& Contact::getEmailAddressList() const
    {
	return this->emailAddressList;
    }

    void Contact::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement	contactNode;
	QDomElement	element;
	PhoneNumber*	phoneNumber;
	EmailAddress*	emailAddress;
	QString		org, group;

	contactNode = doc.createElement("contact");
	contactNode.setAttribute("id", this->getID());

	this->textToXml(this->name, "name", doc, contactNode);
	this->textToXml(this->isDeleted() ? "true" : "false", "deleted", doc, contactNode);

	// phoneNumberList
	if(! this->phoneNumberList.empty())
	{
	    element = doc.createElement("phoneNumberList");
	    foreach(phoneNumber, this->phoneNumberList)
	    {
		phoneNumber->toXml(doc, element);
	    }
	    contactNode.appendChild(element);
	}

	// emailAddressList
	if(! this->emailAddressList.empty())
	{
	    element = doc.createElement("emailAddressList");
	    foreach(emailAddress, this->emailAddressList)
	    {
		emailAddress->toXml(doc, element);
	    }
	    contactNode.appendChild(element);
	}

	// orgList
	if(! this->orgList.empty())
	{
	    element = doc.createElement("orgList");
	    foreach(org, this->orgList)
	    {
		this->textToXml(org, "org", doc, element);
	    }
	    contactNode.appendChild(element);
	}

	// groupList
	if(! this->groupList.empty())
	{
	    element = doc.createElement("groupList");
	    foreach(group, this->groupList)
	    {
		this->textToXml(group, "group", doc, element);
	    }
	    contactNode.appendChild(element);
	}

	node.appendChild(contactNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void Contact::setName(QString name)
    {
	this->name = name;
    }

    void Contact::addOrg(QString org)
    {
	this->orgList.push_back(org);
    }

    void Contact::addGroup(QString group)
    {
	this->groupList.push_back(group);
    }

    void Contact::addPhoneNumber(QString phoneNumberValue)
    {
	this->phoneNumberList.push_back( new PhoneNumber(phoneNumberValue, this) );
    }

    void Contact::addEmailAddress(QString emailAddressValue)
    {
	this->emailAddressList.push_back( new EmailAddress(emailAddressValue, this) );
    }

    void Contact::copyPhoneNumberList(const QList<PhoneNumber*>& phoneNumberListToCopy)
    {
	PhoneNumber* phoneNumber = NULL;

	foreach(phoneNumber, phoneNumberListToCopy)
	{
	    this->phoneNumberList.push_back( new PhoneNumber(phoneNumber->getValue(), this) );
	}
    }

    void Contact::copyEmailAddressList(const QList<EmailAddress*>& emailAddressListToCopy)
    {
	EmailAddress* emailAddress = NULL;

	foreach(emailAddress, emailAddressListToCopy)
	{
	    this->emailAddressList.push_back( new EmailAddress(emailAddress->getValue(), this) );
	}
    }

    // -----------------------------------------------------------------
    // -- OPERATORS
    // -----------------------------------------------------------------

    Contact& Contact::operator=(const Contact& contactToCopy)
    {
	if( this != &contactToCopy)
	{
	    AbstractMobilePhoneObject::operator=(contactToCopy);

	    // Freeing memory
	    while(! this->phoneNumberList.isEmpty())
		delete this->phoneNumberList.takeFirst();

	    while(! this->emailAddressList.isEmpty())
		delete this->emailAddressList.takeFirst();

	    // Copying data
	    this->name		= contactToCopy.name;
	    this->orgList	= contactToCopy.orgList;
	    this->groupList	= contactToCopy.groupList;

	    this->copyPhoneNumberList( contactToCopy.phoneNumberList );
	    this->copyEmailAddressList( contactToCopy.emailAddressList );
	}

	return *this;
    }
}





