// ----------------------------------------------------------------------------
// -- Header of CommunicationManager class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H

#include "AbstractCommunication.h"

namespace datastructure
{
    /**
     * This class allows to manage the communication list of a mobile phone.
     */
    class CommunicationManager: public AbstractMobilePhoneObject
    {
	private:
	    QList<AbstractCommunication*> communicationList;

	    void copyCommunicationList(const QList<AbstractCommunication*>& communicationListToCopy);
	    void freeMemory();

	public:

	    /**
	     * CommunicationManager class constructor.
	     */
	    CommunicationManager();

	    /**
	     * CommunicationManager class copy constructor
	     * @param communicationManagerToCopy CommunicationManager object to copy.
	     */
	    CommunicationManager(const CommunicationManager& communicationManagerToCopy);

	    /**
	     * CommunicationManager class destructor.
	     */
	    virtual ~CommunicationManager();

	    /**
	     * Allows to access of communication list.
	     * @return communication list.
	     */
	    const QList<AbstractCommunication*>& getCommunicationList() const;

	    /**
	     * Adds a communication in the communication manager.
	     * @param communication AbstractCommunication object to add.
	     */
	    void addCommunication(AbstractCommunication* communication);

	    /**
	     * Finds the communication with his identifier.
	     * @return communication found or null if not found
	     */
	    AbstractCommunication* findCommunicationWithID(int communicationID) const;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual CommunicationManager& operator=(const CommunicationManager& communicationManagerToCopy);
    };
}

#endif // COMMUNICATIONMANAGER_H
