// ----------------------------------------------------------------------------
// -- Source of PhoneFileManager class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "PhoneFileManager.h"

namespace datastructure
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    PhoneFileManager::PhoneFileManager()
    :AbstractMobilePhoneObject()
    {
    }

    PhoneFileManager::PhoneFileManager(const PhoneFileManager& phoneFileManagerToCopy)
    :AbstractMobilePhoneObject(phoneFileManagerToCopy)
    {
	this->copyPhoneFileList(phoneFileManagerToCopy.phoneFileList);
    }

    PhoneFileManager::~PhoneFileManager()
    {
	this->freeMemory();
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    const QList<AbstractPhoneFile*>& PhoneFileManager::getPhoneFileList() const
    {
	return this->phoneFileList;
    }

    void PhoneFileManager::toXml(QDomDocument& doc, QDomNode& node) const
    {
	QDomElement phoneFileListNode;
	AbstractPhoneFile* phoneFile;

	if(! this->phoneFileList.empty())
	{
	    phoneFileListNode = doc.createElement("phoneFileList");
	    foreach(phoneFile, this->phoneFileList)
	    {
		phoneFile->toXml(doc, phoneFileListNode);
	    }
	}

	node.appendChild(phoneFileListNode);
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void PhoneFileManager::copyPhoneFileList(const QList<AbstractPhoneFile*>& phoneFileListToCopy)
    {
	AbstractPhoneFile* phoneFile;

	foreach(phoneFile, phoneFileListToCopy)
	{
	    this->phoneFileList.push_back(phoneFile->clone());
	}
    }

    void PhoneFileManager::freeMemory()
    {
	while(! this->phoneFileList.empty())
	    delete this->phoneFileList.takeFirst();
    }

    void PhoneFileManager::addPhoneFile(AbstractPhoneFile* phoneFile)
    {
	this->phoneFileList.push_back(phoneFile);
    }

    // -----------------------------------------------------------------
    // -- Operators
    // -----------------------------------------------------------------

    PhoneFileManager& PhoneFileManager::operator=(const PhoneFileManager& phoneFileManagerToCopy)
    {
	if(this != &phoneFileManagerToCopy)
	{
	    AbstractMobilePhoneObject::operator=(phoneFileManagerToCopy);

	    this->freeMemory();
	    this->copyPhoneFileList(phoneFileManagerToCopy.phoneFileList);
	}

	return *this;
    }
}
