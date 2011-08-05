// ----------------------------------------------------------------------------
// -- Source of Call class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "Call.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    Call::Call(int callID)
    :AbstractPhoneNumberCommunication(callID), duration()
    {
    }

    Call::Call(const Call& callToCopy, bool copyPhoneNumbers)
    :AbstractPhoneNumberCommunication(callToCopy, copyPhoneNumbers), duration(callToCopy.duration)
    {
    }

    Call::~Call()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QTime Call::getDuration() const
    {
	return this->duration;
    }

    void Call::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement	callNode;

	callNode = doc.createElement("call");
	callNode.setAttribute("id", this->getID());

	this->communicationAttributesToXml(doc, callNode);
	this->textToXml(this->duration.toString("HH:mm:ss"), "duration", doc, callNode);
	this->phoneNumberListToXml(doc, callNode);

	node.appendChild(callNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void Call::setDuration(QTime duration)
    {
	this->duration = duration;
    }

    AbstractCommunication* Call::clone() const
    {
	return new Call(*this);
    }

    AbstractCommunication* Call::cloneWithNewAddressBook(const AddressBook& addressBook) const
    {
	Call* call = NULL;

	call = new Call(*this, false);
	call->copyPhoneNumberListWithAddressBook(this->phoneNumberList, addressBook);

	return call;
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    Call& Call::operator=(const Call& callToCopy)
    {
	if(this != &callToCopy)
	{
	    AbstractPhoneNumberCommunication::operator=(callToCopy);

	    this->duration = callToCopy.duration;
	}

	return *this;
    }
}
