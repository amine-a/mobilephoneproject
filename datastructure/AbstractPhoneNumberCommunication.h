// ----------------------------------------------------------------------------
// -- Header of AbstractPhoneNumberCommunication class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef ABSTRACTPHONENUMBERCOMMUNICATION_H
#define ABSTRACTPHONENUMBERCOMMUNICATION_H

#include "AbstractCommunication.h"
#include "PhoneNumber.h"

namespace datastructure
{
    /**
     * Abstract class to manage the communications using phone numbers.
     */
    class AbstractPhoneNumberCommunication: public AbstractCommunication
    {
	protected:
	    QList<PhoneNumber*>	    phoneNumberList;

	    void copyPhoneNumberList(const QList<PhoneNumber*>& phoneNumberListToCopy);
	    void copyPhoneNumberListWithAddressBook(const QList<PhoneNumber *> &phoneNumberListToCopy, const AddressBook& addressBook);
	    void phoneNumberListToXml(QDomDocument& doc, QDomNode& node) const;
	    void freeMemory();

	public:

	    /**
	     * AbstractPhoneNumberCommunication constructor.
	     * @param phoneNumberCommunicationID identifier of the communication.
	     */
	    AbstractPhoneNumberCommunication(int phoneNumberCommunicationID);

	    /**
	     * AbstractPhoneNumberCommunication copy constructor.
	     * @param phoneNumberCommunicationToCopy AbstractPhoneNumberCommunication object to copy.
	     * @param copyPhoneNumbers if true copy the phone number list.
	     */
	    AbstractPhoneNumberCommunication(const AbstractPhoneNumberCommunication& phoneNumberCommunicationToCopy, bool copyPhoneNumbers=true);

	    /**
	     * AbstractPhoneNumberCommunication copy destructor.
	     */
	    virtual ~AbstractPhoneNumberCommunication();

	    /**
	     * Allows to get the phone number list of the communication.
	     * @return phone number list.
	     */
	    const QList<PhoneNumber*>& getPhoneNumberList() const;

	    /**
	     * Adds a phone number to the communication.
	     * @param phoneNumber phone number to add.
	     */
	    void addPhoneNumber(PhoneNumber* phoneNumber);

	    /**
	     * @see AbstractCommunication::clone()
	     */
	    virtual AbstractCommunication* clone() const = 0;

	    /**
	     * @see AbstractCommunication::cloneWithNewAddressBook()
	     */
	    virtual AbstractCommunication* cloneWithNewAddressBook(const AddressBook& addressBook) const = 0;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const = 0;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual AbstractPhoneNumberCommunication& operator=(const AbstractPhoneNumberCommunication& phoneNumberCommunicationToCopy);
    };
}

#endif // ABSTRACTPHONENUMBERCOMMUNICATION_H
