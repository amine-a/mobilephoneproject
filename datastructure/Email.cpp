// ----------------------------------------------------------------------------
// -- Source of Email class
// -- Namespace: mobilephonedatastructure
// ----------------------------------------------------------------------------

#include "Email.h"

using namespace std;

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    Email::Email(int emailID)
    :AbstractCommunication(emailID), displayName(""), subject(""), body(""),
     fromList(), toList(), ccList(), cciList()
    {
    }

    Email::Email(const Email& emailToCopy, bool copyEmailAddresses)
    :AbstractCommunication(emailToCopy), displayName(emailToCopy.displayName),
     subject(emailToCopy.subject), body(emailToCopy.body),
     fromList(), toList(), ccList(), cciList()
    {
	if(copyEmailAddresses)
	{
	    Email::copyEmailAddressList(this->fromList, emailToCopy.fromList);
	    Email::copyEmailAddressList(this->toList, emailToCopy.toList);
	    Email::copyEmailAddressList(this->ccList, emailToCopy.ccList);
	    Email::copyEmailAddressList(this->cciList, emailToCopy.cciList);
	}
    }

    Email::~Email()
    {
	this->freeMemory();
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString Email::getDisplayName() const
    {
	return this->displayName;
    }

    QString Email::getSubject() const
    {
	return this->subject;
    }

    QString Email::getBody() const
    {
	return this->body;
    }

    const QList<EmailAddress*>& Email::getFromList() const
    {
	return this->fromList;
    }

    const QList<EmailAddress*>& Email::getToList() const
    {
	return this->toList;
    }

    const QList<EmailAddress*>& Email::getCCList() const
    {
	return this->ccList;
    }

    const QList<EmailAddress*>& Email::getCCIList() const
    {
	return this->cciList;
    }

    void Email::emailAddressListToXml(const QList<EmailAddress *>& emailAddressList, QString name, QDomDocument& doc, QDomNode& node)
    {
	EmailAddress*	emailAddress = NULL;
	QDomElement	element;

	if(! emailAddressList.empty())
	{
	    element = doc.createElement(name);
	    foreach(emailAddress, emailAddressList)
	    {
		emailAddress->toXml(doc, element);
	    }
	    node.appendChild(element);
	}
    }

    void Email::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement emailNode;

	emailNode = doc.createElement("email");
	emailNode.setAttribute("id", this->getID());

	this->communicationAttributesToXml(doc, emailNode);
	this->textToXml(this->displayName, "displayName", doc, emailNode);
	this->textToXml(this->subject, "subject", doc, emailNode);
	this->textToXml(this->body, "body", doc, emailNode);

	Email::emailAddressListToXml(this->fromList, "fromList", doc, emailNode);
	Email::emailAddressListToXml(this->toList, "toList", doc, emailNode);
	Email::emailAddressListToXml(this->ccList, "ccList", doc, emailNode);
	Email::emailAddressListToXml(this->cciList, "cciList", doc, emailNode);

	node.appendChild(emailNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void Email::setDisplayName(QString displayName)
    {
	this->displayName = displayName;
    }

    void Email::setSubject(QString subject)
    {
	this->subject = subject;
    }

    void Email::setBody(QString body)
    {
	this->body = body;
    }

    void Email::addInFromList(EmailAddress* emailAddress)
    {
	this->fromList.push_back(emailAddress);
    }

    void Email::addInToList(EmailAddress* emailAddress)
    {
	this->toList.push_back(emailAddress);
    }

    void Email::addInCCList(EmailAddress* emailAddress)
    {
	this->ccList.push_back(emailAddress);
    }

    void Email::addInCCIList(EmailAddress* emailAddress)
    {
	this->cciList.push_back(emailAddress);
    }

    AbstractCommunication* Email::clone() const
    {
	return new Email(*this);
    }

    AbstractCommunication* Email::cloneWithNewAddressBook(const AddressBook& addressBook) const
    {
	Email* email = NULL;

	email = new Email(*this, false);
	Email::copyEmailAddressListWithAddressBook(email->fromList, this->fromList, addressBook);
	Email::copyEmailAddressListWithAddressBook(email->toList, this->toList, addressBook);
	Email::copyEmailAddressListWithAddressBook(email->ccList, this->ccList, addressBook);
	Email::copyEmailAddressListWithAddressBook(email->cciList, this->cciList, addressBook);

	return email;
    }

    void Email::copyEmailAddressList(QList<EmailAddress *>& emailAddressListDest, const QList<EmailAddress *> &emailAddressListToCopy)
    {
	EmailAddress* emailAddress;

	foreach(emailAddress, emailAddressListToCopy)
	{
	    if( emailAddress->getContact() )
		emailAddressListDest.push_back(emailAddress);
	    else
		emailAddressListDest.push_back(new EmailAddress(*emailAddress));
	}
    }

    void Email::copyEmailAddressListWithAddressBook(QList<EmailAddress *>& emailAddressListDest, const QList<EmailAddress *> &emailAddressListToCopy, const AddressBook& addressBook)
    {
	EmailAddress* emailAddressToCopy = NULL;
	EmailAddress* newEmailAddress = NULL;

	foreach(emailAddressToCopy, emailAddressListToCopy)
	{
	    if( emailAddressToCopy->getContact() )
		newEmailAddress = addressBook.findEmailAddress(emailAddressToCopy->getValue());
	    else
		newEmailAddress = new EmailAddress(emailAddressToCopy->getValue());

	    if(newEmailAddress)
		emailAddressListDest.push_back(newEmailAddress);
	}
    }

    void Email::freeMemory()
    {
	EmailAddress* emailAddress = NULL;

	while(! this->fromList.empty())
	{
	    emailAddress = this->fromList.takeFirst();

	    if(emailAddress->getContact() == NULL)
		delete emailAddress;
	}

	while(! this->toList.empty())
	{
	    emailAddress = this->toList.takeLast();

	    if(emailAddress->getContact() == NULL)
		delete emailAddress;
	}

	while(! this->ccList.empty())
	{
	    emailAddress = this->ccList.takeLast();

	    if(emailAddress->getContact() == NULL)
		delete emailAddress;
	}

	while(! this->cciList.empty())
	{
	    emailAddress = this->cciList.takeLast();

	    if(emailAddress->getContact() == NULL)
		delete emailAddress;
	}
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    Email& Email::operator=(const Email& emailToCopy)
    {
	if(this != &emailToCopy)
	{
	    AbstractCommunication::operator=(emailToCopy);

	    this->displayName = emailToCopy.displayName;
	    this->subject = emailToCopy.subject;
	    this->body = emailToCopy.body;

	    Email::copyEmailAddressList(this->fromList, emailToCopy.fromList);
	    Email::copyEmailAddressList(this->toList, emailToCopy.toList);
	    Email::copyEmailAddressList(this->ccList, emailToCopy.ccList);
	    Email::copyEmailAddressList(this->cciList, emailToCopy.cciList);
	}

	return *this;
    }

}
