// ----------------------------------------------------------------------------
// -- Header of AbstractTextMessage class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef ABSTRACTTEXTMESSAGE_H_
#define ABSTRACTTEXTMESSAGE_H_

#include "AbstractPhoneNumberCommunication.h"

namespace datastructure
{
    /**
    * Abstract class.
    * This class allows to manage text messages of mobile phones.
    */
    class AbstractTextMessage: public AbstractPhoneNumberCommunication
    {
	protected:
	    QString	content;

	public:

	    /**
	     * AbstractTextMessage class constructor.
	     * @param textMessageID identifier of the text message.
	     */
	    AbstractTextMessage(int textMessageID);

	    /**
	     * Copy constructor of AbstractTextMessage class.
	     * @param TextMessageToCopy AbstractTextMessage object to copy.
	     * @param copyPhoneNumbers if true copy the phone number list.
	     */
	    AbstractTextMessage(const AbstractTextMessage& textMessageToCopy, bool copyPhoneNumbers=true);

	    /**
	     * AbstractTextMessage class destructor.
	     */
	    virtual ~AbstractTextMessage();

	    /**
	     * Allows to access of text message content.
	     * @return text message content.
	     */
	    QString getContent() const;

	    /**
	     * Changes the content value.
	     * @param content new content value.
	     */
	    void setContent(QString content);

	    /**
	     * @see AbstractCommunication::clone()
	     */
	    virtual AbstractCommunication* clone() const = 0;

	    /**
	     * @see AbstractCommunication::cloneWithNewAddressBook(const AddressBook& addressBook)
	     */
	    virtual AbstractCommunication* cloneWithNewAddressBook(const AddressBook& addressBook) const = 0;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const = 0;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual AbstractTextMessage& operator=(const AbstractTextMessage& textMessageToCopy);
    };
}

#endif /* ABSTRACTTEXTMESSAGE_H_ */
