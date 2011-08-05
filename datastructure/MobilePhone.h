// ----------------------------------------------------------------------------
// -- Source of MobilePhone class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef MOBILEPHONE_H_
#define MOBILEPHONE_H_

#include "AddressBook.h"
#include "CommunicationManager.h"
#include "PhoneFileManager.h"

namespace datastructure
{
    /**
      * This class allows to store information about a mobile phone.
      * Such as contacts, communications or files.
      */
    class MobilePhone: public AbstractMobilePhoneObject
    {
	private:
	    QString		    deviceName;
	    QString		    model;
	    QString		    mobileID;	    // IMEI
	    QString		    subscriberID;   // IMSI

	    AddressBook		    addressBook;
	    PhoneFileManager	    phoneFileManager;
	    CommunicationManager    communicationManager;

	    void copyCommunicationManager(const CommunicationManager& communicationManagerToCopy);

	public:

	    /**
	    * MobilePhone class constructor.
	    * @param deviceName device name of mobile phone.
	    */
	    MobilePhone(QString deviceName);

	    /**
	    * Copy constructor of MobilePhone class.
	    * @param mobilePhoneToCopy MobilePhone object to copy.
	    */
	    MobilePhone(const MobilePhone& mobilePhoneToCopy);

	    /**
	    * MobilePhone class destructor.
	    */
	    virtual ~MobilePhone();

	    /**
	    * Allows to access of device name.
	    * @return device name.
	    */
	    QString getDeviceName() const;

	    /**
	    * Allows to access of subscriber id.
	    * @return subscriber id.
	    */
	    QString getSubscriberID() const;

	    /**
	     * Changes the value of the subscriber ID.
	     * @param subscriberID subscriber ID (IMSI).
	     */
	    void setSubscriberID(QString subscriberID);

	    /**
	    * Allows to access of mobile phone model.
	    * @return mobile phone model.
	    */
	    QString getModel() const;

	    /**
	    * Changes the value of model.
	    * @param model model of mobile phone.
	    */
	    void setModel(QString model);

	    /**
	    * Allows to access of mobile ID.
	    * @return mobile ID (IMEI).
	    */
	    QString getMobileID() const;

	    /**
	    * Changes the value of mobile ID.
	    * @param mobileID mobile ID (IMEI).
	    */
	    void setMobileID(QString model);

	    /**
	    * Allows to access of phone address book.
	    * @return phone address book.
	    */
	    AddressBook& getAddressBook();

	    /**
	     * Allows to access of the manager of the communications to manage call, text messages, sms, ...
	     * @return CommunicationManager object.
	     */
	    CommunicationManager& getCommunicationManager();

	    /**
	     * Allows to access of the manager of the phone file to manage documents, pictures, videos, ...
	     */
	    PhoneFileManager& getPhoneFileManager();

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual MobilePhone& operator=(const MobilePhone& mobilePhoneToCopy);
    };
}

#endif /* MOBILEPHONE_H_ */
