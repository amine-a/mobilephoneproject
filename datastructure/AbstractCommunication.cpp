// ----------------------------------------------------------------------------
// -- Source of AbstractCommunication class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "AbstractCommunication.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    AbstractCommunication::AbstractCommunication(int communicationID)
    :AbstractMobilePhoneObject(communicationID), date(), status(-1), incoming(false)
    {
    }

    AbstractCommunication::AbstractCommunication(const AbstractCommunication& communicationToCopy)
    :AbstractMobilePhoneObject(communicationToCopy), date(communicationToCopy.date),
     status(communicationToCopy.status), incoming(communicationToCopy.incoming)
    {
    }

    AbstractCommunication::~AbstractCommunication()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QDate AbstractCommunication::getDate() const
    {
	return this->date;
    }

    void AbstractCommunication::setDate(QDate date)
    {
	this->date = date;
    }

    int AbstractCommunication::getStatus() const
    {
	return this->status;
    }

    void AbstractCommunication::setStatus(int status)
    {
	this->status = status;
    }

    bool AbstractCommunication::isIncoming() const
    {
	return this->incoming;
    }

    void AbstractCommunication::setIncoming(bool incoming)
    {
	this->incoming = incoming;
    }

    void AbstractCommunication::communicationAttributesToXml(QDomDocument& doc, QDomNode& node) const
    {
	this->textToXml(this->date.toString("yyyy.MM.dd"), "date", doc, node);
	this->textToXml(this->statusToString(), "status", doc, node);
	this->textToXml(this->incoming ? "true" : "false", "incoming", doc, node);
	this->textToXml(this->isDeleted() ? "true" : "false", "deleted", doc, node);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    QString AbstractCommunication::statusToString() const
    {
	QString display;

	switch( this->status )
	{
	    case AbstractCommunication::MISSED_STATUS:
		display = "Missed";
		break;

	    case AbstractCommunication::DIALLED_STATUS:
		display = "Dialled";
		break;

	    case AbstractCommunication::RECEIVED_STATUS:
		display = "Received";
		break;

	    case AbstractCommunication::SENT_STATUS:
		display = "Dialled";
		break;

	    case AbstractCommunication::UNSENT_STATUS:
		display = "Unsent";
		break;

	    case AbstractCommunication::READ_STATUS:
		display = "Read";
		break;

	    default:
		display = "unknown status";
	}

	return display;
    }

    // -----------------------------------------------------------------
    // -- OPERATORS
    // -----------------------------------------------------------------

    AbstractCommunication& AbstractCommunication::operator=(const AbstractCommunication& communicationToCopy)
    {
	if(this != &communicationToCopy)
	{
	    AbstractMobilePhoneObject::operator=(communicationToCopy);

	    this->date = communicationToCopy.date;
	    this->status = communicationToCopy.status;
	    this->incoming = communicationToCopy.incoming;
	}

	return *this;
    }
}


