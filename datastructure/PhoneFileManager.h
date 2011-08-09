// ----------------------------------------------------------------------------
// -- Header of PhoneFileManager class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef PHONEFILEMANAGER_H
#define PHONEFILEMANAGER_H

#include <QList>

#include "AbstractMobilePhoneObject.h"
#include "AbstractPhoneFile.h"

namespace datastructure
{
    /**
     * This class allows to manage the file list of a mobile phone.
     */
    class PhoneFileManager: public AbstractMobilePhoneObject
    {
	private:
	    QList<AbstractPhoneFile*> phoneFileList;

	    void copyPhoneFileList(const QList<AbstractPhoneFile*>& phoneFileListToCopy);
	    void freeMemory();

	public:

	    /**
	     * PhoneFileManager class constructor.
	     */
	    PhoneFileManager();

	    /**
	     * PhoneFileManager class copy constructor.
	     * @param PhoneFileManagerToCopy PhoneFileManager object to copy.
	     */
	    PhoneFileManager(const PhoneFileManager& phoneFileManagerToCopy);

	    /**
	     * PhoneFileManager class destructor.
	     */
	    virtual ~PhoneFileManager();

	    /**
	     * Allows to get the file list of a mobile phone.
	     * @return file list.
	     */
	    const QList<AbstractPhoneFile*>& getPhoneFileList() const;

	    /**
	     * Adds a file in the list.
	     * @param phoneFile AbstractPhoneFile object to add.
	     */
	    void addPhoneFile(AbstractPhoneFile* phoneFile);

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual PhoneFileManager& operator=(const PhoneFileManager& phoneFileManagerToCopy);
    };
}

#endif // PHONEFILEMANAGER_H
