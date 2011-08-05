// ----------------------------------------------------------------------------
// -- Header of AbstractCommunication class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef ABSTRACTCOMMUNICATION_H
#define	ABSTRACTCOMMUNICATION_H

#include <QDate>

#include "AbstractMobilePhoneObject.h"
#include "AddressBook.h"

namespace datastructure
{
    /**
     * Abstract class.
     * This class allows to manage mobile phone communications.
     */
    class AbstractCommunication: public AbstractMobilePhoneObject
    {
	protected:
	    QDate		    date;
	    int			    status;
	    bool		    incoming;

	    void communicationAttributesToXml(QDomDocument& doc, QDomNode& node) const;

	public:
	    /**
	     * Status of the communication When the communication is missed.
	     */
	    static const int MISSED_STATUS	= 0;

	    /**
	     * Status of the communication when the phone number is just dialled.
	     */
	    static const int DIALLED_STATUS	= 1;

	    /**
	     * Status of the communication when the communication is received.
	     */
	    static const int RECEIVED_STATUS	= 2;

	    /**
	     * Status of the communication when the message is sent.
	     */
	    static const int SENT_STATUS	= 3;

	    /**
	     * Status of the communication when the message is unsent.
	     */
	    static const int UNSENT_STATUS	= 4;

	    /**
	     * Status of the communication when the message is read.
	     */
	    static const int READ_STATUS	= 5;

	    /**
	     * Constructor with phone number parameter.
	     * @param communicationID identifier of the communication.
	     */
	    AbstractCommunication(int communicationID);

	    /**
	     * Copy constructor.
	     * @param commnunicationToCopy AbstractCommunication object to copy.
	     */
	    AbstractCommunication(const AbstractCommunication& commnunicationToCopy);

	    /**
	     * AbstractCommunication destructor.
	     */
	    virtual ~AbstractCommunication();

	    /**
	     * Allows to access of communication datetime.
	     * @return communication date.
	     */
	    QDate getDate() const;

	    /**
	     * Changes datetime value.
	     * @param date new datetime value.
	     */
	    void setDate(QDate date);

	    /**
	     * Allows to access of communication status.
	     * @return communication status.
	     */
	    int getStatus() const;

	    /**
	     * Changes status value.
	     * @param status new status value.
	     */
	    void setStatus(int status);

	    /**
	     * Allows to know if the communication is incoming.
	     * @return true if the communication is incoming, else false.
	     */
	    bool isIncoming() const;

	    /**
	     * Changes incoming value.
	     * @param incoming new incoming value.
	     */
	    void setIncoming(bool incoming);

	    /**
	     * Converts the status into string.
	     * @return status in string format.
	     */
	    QString statusToString() const;

	    /**
	     * Clone the communication in the new object.
	     * @return a clone of the AbstractCommunication object.
	     */
	    virtual AbstractCommunication* clone() const = 0;

	    /**
	     * Clone the communication in the new object with a new address book.
	     * This method allows to clone correctly the Contact pointers in the PhoneNumber and EmailAddress object.
	     * @param addressBook new address book with the Contact list.
	     * @return a clone of the AbstractCommunication object with the Contact pointers of the new address book.
	     */
	    virtual AbstractCommunication* cloneWithNewAddressBook(const AddressBook& addressBook) const = 0;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const = 0;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual AbstractCommunication& operator=(const AbstractCommunication& communicationToCopy);
    };
}

#endif	/* ABSTRACTCOMMUNICATION_H */

