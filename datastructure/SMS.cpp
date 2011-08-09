// ----------------------------------------------------------------------------
// -- Source of SMS class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "SMS.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    SMS::SMS(int smsID)
    :AbstractTextMessage(smsID)
    {
    }

    SMS::SMS(const SMS& smsToCopy, bool copyPhoneNumbers)
    :AbstractTextMessage(smsToCopy, copyPhoneNumbers)
    {
    }

    SMS::~SMS()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    AbstractCommunication* SMS::clone() const
    {
	return new SMS(*this);
    }

    AbstractCommunication* SMS::cloneWithNewAddressBook(const AddressBook& addressBook) const
    {
	SMS* sms = NULL;

	sms = new SMS(*this, false);
	sms->copyPhoneNumberListWithAddressBook(this->phoneNumberList, addressBook);

	return sms;
    }

    void SMS::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement smsNode;

	smsNode = doc.createElement("sms");
	smsNode.setAttribute("id", this->getID());

	this->communicationAttributesToXml(doc, smsNode);
	this->textToXml(this->content, "content", doc, smsNode);
	this->phoneNumberListToXml(doc, smsNode);

	node.appendChild(smsNode);
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    SMS& SMS::operator=(const SMS& smsToCopy)
    {
	if(this != &smsToCopy)
	{
	    AbstractTextMessage::operator=(smsToCopy);
	}

	return *this;
    }

}
