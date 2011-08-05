// ----------------------------------------------------------------------------
// -- Source of MobilePhone class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "MobilePhone.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    MobilePhone::MobilePhone(QString deviceName)
    :AbstractMobilePhoneObject(), deviceName(deviceName),
     model(""), mobileID(""), subscriberID(""), addressBook(),
     phoneFileManager(), communicationManager()
    {
    }

    MobilePhone::MobilePhone(const MobilePhone& mobilePhoneToCopy)
    :AbstractMobilePhoneObject(mobilePhoneToCopy),
     deviceName(mobilePhoneToCopy.deviceName), model(mobilePhoneToCopy.model),
     mobileID(mobilePhoneToCopy.mobileID), subscriberID(mobilePhoneToCopy.subscriberID),
     addressBook(mobilePhoneToCopy.addressBook), phoneFileManager(mobilePhoneToCopy.phoneFileManager),
     communicationManager()
    {
	this->copyCommunicationManager(mobilePhoneToCopy.communicationManager);
    }

    MobilePhone::~MobilePhone()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString MobilePhone::getDeviceName() const
    {
	return this->deviceName;
    }

    QString MobilePhone::getSubscriberID() const
    {
	return this->subscriberID;
    }

    QString MobilePhone::getModel() const
    {
	return this->model;
    }

    QString MobilePhone::getMobileID() const
    {
	return this->mobileID;
    }

    AddressBook& MobilePhone::getAddressBook()
    {
	return this->addressBook;
    }

    CommunicationManager& MobilePhone::getCommunicationManager()
    {
	return this->communicationManager;
    }

    PhoneFileManager& MobilePhone::getPhoneFileManager()
    {
	return this->phoneFileManager;
    }

    void MobilePhone::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement mobilePhoneNode;

	mobilePhoneNode = doc.createElement("mobilePhone");
	mobilePhoneNode.setAttribute("name", this->deviceName);

	this->textToXml(this->mobileID, "mobileID", doc, mobilePhoneNode);
	this->textToXml(this->model, "model", doc, mobilePhoneNode);
	this->textToXml(this->subscriberID, "subscriberID", doc, mobilePhoneNode);

	this->addressBook.toXml(doc,mobilePhoneNode);
	this->phoneFileManager.toXml(doc, mobilePhoneNode);
	this->communicationManager.toXml(doc, mobilePhoneNode);

	node.appendChild(mobilePhoneNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void MobilePhone::copyCommunicationManager(const CommunicationManager& communicationManagerToCopy)
    {
	/*
	    The pointers of PhoneNumber and EmailAddress must refer to the PhoneNumber and EmailAddress
	    of the addressbook of this mobile phone.
	 */

	AbstractCommunication* communication;

	foreach(communication, communicationManagerToCopy.getCommunicationList())
	{
	    this->communicationManager.addCommunication(communication->cloneWithNewAddressBook(this->addressBook));
	}
    }

    void MobilePhone::setSubscriberID(QString subscriberID)
    {
	this->subscriberID = subscriberID;
    }

    void MobilePhone::setModel(QString model)
    {
	this->model = model;
    }

    void MobilePhone::setMobileID(QString mobileID)
    {
	this->mobileID = mobileID;
    }

    // -----------------------------------------------------------------
    // -- OPERATORS
    // -----------------------------------------------------------------

    MobilePhone& MobilePhone::operator=(const MobilePhone& mobilePhoneToCopy)
    {
	if(this != &mobilePhoneToCopy)
	{
	    AbstractMobilePhoneObject::operator=(mobilePhoneToCopy);

	    this->deviceName	= mobilePhoneToCopy.deviceName;
	    this->model		= mobilePhoneToCopy.model;
	    this->mobileID	= mobilePhoneToCopy.mobileID;
	    this->subscriberID	= mobilePhoneToCopy.subscriberID;


	    this->addressBook	    = mobilePhoneToCopy.addressBook;
	    this->phoneFileManager  = mobilePhoneToCopy.phoneFileManager;
	    this->copyCommunicationManager(mobilePhoneToCopy.communicationManager);
	}

	return *this;
    }

} /* namespace mobilephonedatastructure */
