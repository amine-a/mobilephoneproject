// ----------------------------------------------------------------------------
// -- Source of AbstractTextMessage class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "AbstractTextMessage.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    AbstractTextMessage::AbstractTextMessage(int textMessageID)
    :AbstractPhoneNumberCommunication(textMessageID), content("")
    {
    }

    AbstractTextMessage::AbstractTextMessage(const AbstractTextMessage& textMessageToCopy, bool copyPhoneNumbers)
    :AbstractPhoneNumberCommunication(textMessageToCopy, copyPhoneNumbers), content(textMessageToCopy.content)
    {
    }

    AbstractTextMessage::~AbstractTextMessage()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString AbstractTextMessage::getContent() const
    {
	return this->content;
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void AbstractTextMessage::setContent(QString content)
    {
	this->content = content;
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------
    AbstractTextMessage& AbstractTextMessage::operator=(const AbstractTextMessage& textMessageToCopy)
    {
	if(this != &textMessageToCopy)
	{
	    AbstractPhoneNumberCommunication::operator =(textMessageToCopy);

	    this->content = content;
	}

	return *this;
    }
}
