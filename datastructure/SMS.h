// ----------------------------------------------------------------------------
// -- Header of SMS class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef SMS_H_
#define SMS_H_

#include "AbstractTextMessage.h"

namespace datastructure
{
	/**
	 * This class allows to manage SMS text messages.
	 */
	class SMS: public AbstractTextMessage
	{
		public:

		    /**
		     * SMS class constructor.
		     * @param smsID identifier of the SMS.
		     */
		    SMS(int smsID);

		    /**
		     * SMS class copy constructor.
		     * @param smsToCopy SMS object to copy.
		     * @param copyPhoneNumbers if true copy the phone number list.
		     */
		    SMS(const SMS& smsToCopy, bool copyPhoneNumbers=true);

		    /**
		     * SMS class destructor.
		     */
		    virtual ~SMS();

		    /**
		     * @see AbstractCommunication::clone()
		     */
		    virtual AbstractCommunication* clone() const;

		    /**
		     * @see AbstractCommunication::cloneWithNewAddressBook(const AddressBook& addressBook)
		     */
		    virtual AbstractCommunication* cloneWithNewAddressBook(const AddressBook& addressBook) const;

		    /**
		     * @see AbstractMobilePhoneObject::toXml()
		     */
		    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

		    /**
		     * @see AbstractMobilePhoneObject::operator=()
		     */
		    virtual SMS& operator=(const SMS& smsToCopy);
	};
}

#endif /* SMS_H_ */
