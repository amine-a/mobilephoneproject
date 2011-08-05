// ----------------------------------------------------------------------------
// -- Source of CommunicationManager class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "CommunicationManager.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    CommunicationManager::CommunicationManager()
    :AbstractMobilePhoneObject()
    {
    }

    CommunicationManager::CommunicationManager(const CommunicationManager& communicationManagerToCopy)
    :AbstractMobilePhoneObject(communicationManagerToCopy)
    {
    }

    CommunicationManager::~CommunicationManager()
    {
	this->freeMemory();
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    const QList<AbstractCommunication*>& CommunicationManager::getCommunicationList() const
    {
	return this->communicationList;
    }

    AbstractCommunication* CommunicationManager::findCommunicationWithID(int communicationID) const
    {
	QListIterator<AbstractCommunication*> itCommunication(this->communicationList);
	AbstractCommunication* communication = NULL;

	while(itCommunication.hasNext() && communication == NULL)
	{
	    communication = itCommunication.next();

	    if( communication->getID() != communicationID )
		communication = NULL;
	}

	return communication;
    }

    void CommunicationManager::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement communicationListNode;
	AbstractCommunication* communication = NULL;

	if(! this->communicationList.empty())
	{
	    communicationListNode = doc.createElement("communicationList");
	    foreach(communication, this->communicationList)
	    {
		communication->toXml(doc, communicationListNode);
	    }
	}

	node.appendChild(communicationListNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void CommunicationManager::copyCommunicationList(const QList<AbstractCommunication*>& communicationListToCopy)
    {
	AbstractCommunication* communication;

	foreach(communication, communicationListToCopy)
	{
	    this->communicationList.push_back(communication->clone());
	}
    }

    void CommunicationManager::freeMemory()
    {
	while(! this->communicationList.empty())
	    delete this->communicationList.takeFirst();
    }

    void CommunicationManager::addCommunication(AbstractCommunication* communication)
    {
	this->communicationList.push_back(communication);
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    CommunicationManager& CommunicationManager::operator=(const CommunicationManager& communicationManagerToCopy)
    {
	if(this != &communicationManagerToCopy)
	{
	    this->freeMemory();

	    AbstractMobilePhoneObject::operator=(communicationManagerToCopy);
	}

	return *this;
    }
}


