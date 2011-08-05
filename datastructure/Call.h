// ----------------------------------------------------------------------------
// -- Header of Call class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef CALL_H_
#define CALL_H_

#include <QTime>
#include "AbstractPhoneNumberCommunication.h"

namespace datastructure
{
    /**
     * This class allows to manage calls.
     */
    class Call: public AbstractPhoneNumberCommunication
    {
	protected:

	    QTime   duration;

	public:

	    /**
	     * Constructor of Call class.
	     * @param callID identifier of the call.
	     */
	    Call(int callID);

	    /**
	     * Copy constructor.
	     * @param callToCopy Call class to copy.
	     * @param copyPhoneNumbers if true copy the phone number list.
	     */
	    Call(const Call& callToCopy, bool copyPhoneNumbers=true);

	    /**
	     * Call Destructor.
	     */
	    virtual ~Call();

	    /**
	     * Allows to access of call duration.
	     * @return call duration.
	     */
	    QTime getDuration() const;

	    /**
	     * Changes the duration value.
	     * @param duration new duration value.
	     */
	    void setDuration(QTime duration);

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
	    virtual Call& operator=(const Call& callToCopy);
    };
}

#endif /* CALL_H_ */
