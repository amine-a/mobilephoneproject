// ----------------------------------------------------------------------------
// -- Source of AbstractPhoneNumberCommunication class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "AbstractPhoneNumberCommunication.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    AbstractPhoneNumberCommunication::AbstractPhoneNumberCommunication(int phoneNumberCommunicationID)
    :AbstractCommunication(phoneNumberCommunicationID), phoneNumberList()
    {
    }

    AbstractPhoneNumberCommunication::AbstractPhoneNumberCommunication(const AbstractPhoneNumberCommunication& phoneNumberCommunicationToCopy, bool copyPhoneNumbers)
    :AbstractCommunication(phoneNumberCommunicationToCopy), phoneNumberList()
    {
	if(copyPhoneNumbers)
	    this->copyPhoneNumberList(phoneNumberCommunicationToCopy.phoneNumberList);
    }

    AbstractPhoneNumberCommunication::~AbstractPhoneNumberCommunication()
    {
	this->freeMemory();
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    const QList<PhoneNumber*>& AbstractPhoneNumberCommunication::getPhoneNumberList() const
    {
	return this->phoneNumberList;
    }


    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void AbstractPhoneNumberCommunication::copyPhoneNumberList(const QList<PhoneNumber*>& phoneNumberListToCopy)
    {
	PhoneNumber* phoneNumber;

	foreach(phoneNumber, phoneNumberListToCopy)
	{
	    if( phoneNumber->getContact() )
		this->phoneNumberList.push_back(phoneNumber);
	    else
		this->phoneNumberList.push_back(new PhoneNumber(*phoneNumber));
	}
    }

    void AbstractPhoneNumberCommunication::copyPhoneNumberListWithAddressBook(const QList<PhoneNumber *> &phoneNumberListToCopy, const AddressBook& addressBook)
    {
	PhoneNumber* phoneNumberToCopy = NULL;
	PhoneNumber* newPhoneNumber = NULL;

	foreach(phoneNumberToCopy, phoneNumberListToCopy)
	{
	    if( phoneNumberToCopy->getContact() )
		newPhoneNumber = addressBook.findPhoneNumber(phoneNumberToCopy->getValue());
	    else
		newPhoneNumber = new PhoneNumber(phoneNumberToCopy->getValue());

	    if(newPhoneNumber)
		this->phoneNumberList.push_back(newPhoneNumber);
	}
    }

    void AbstractPhoneNumberCommunication::freeMemory()
    {
	PhoneNumber* phoneNumber;

	while(! this->phoneNumberList.empty())
	{
	    phoneNumber = this->phoneNumberList.takeFirst();

	    if(phoneNumber->getContact() == NULL)
		delete phoneNumber;
	}
    }

    void AbstractPhoneNumberCommunication::addPhoneNumber(PhoneNumber *phoneNumber)
    {
	this->phoneNumberList.push_back(phoneNumber);
    }

    void AbstractPhoneNumberCommunication::phoneNumberListToXml(QDomDocument& doc, QDomNode& node) const
    {
	PhoneNumber*	phoneNumber;
	QDomElement	element;

	// phoneNumberList
	if(! this->phoneNumberList.empty())
	{
	    element = doc.createElement("phoneNumberList");
	    foreach(phoneNumber, this->phoneNumberList)
	    {
		phoneNumber->toXml(doc, element);
	    }
	    node.appendChild(element);
	}
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    AbstractPhoneNumberCommunication& AbstractPhoneNumberCommunication::operator=(const AbstractPhoneNumberCommunication& phoneNumberCommunicationToCopy)
    {
	if(this != &phoneNumberCommunicationToCopy)
	{
	    AbstractCommunication::operator =(phoneNumberCommunicationToCopy);
	    this->copyPhoneNumberList(phoneNumberCommunicationToCopy.phoneNumberList);
	}

	return *this;
    }
}
