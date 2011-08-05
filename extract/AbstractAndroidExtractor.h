// ----------------------------------------------------------------------------
// -- Header of AsbtractAndroidExtractor class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#ifndef ABSTRACTANDROIDEXTRACTOR_H
#define ABSTRACTANDROIDEXTRACTOR_H

#include "AbstractMobilePhoneExtractor.h"
#include <QFile>
#include <SQLite3Connection.h>

namespace extract
{
    /**
     * This abstract class allows to extract data of android mobile phones.
     */
    class AbstractAndroidExtractor: public AbstractMobilePhoneExtractor
    {
	private:
	    QString deviceSerial;

	public:

	    /**
	     * AbstractAndroidExtractor class constructor.
	     * @param deviceSerial device serial to find the device with adb tool (see "adb -s ANDROID_SERIAL").
	     * @throws ExtractionException if there is a error during the creation of the AbstractMobilePhoneExtractor object.
	     */
	    AbstractAndroidExtractor(QString deviceSerial) throw(ExtractionException);

	    /**
	     * AbstractAndroidExtractor class copy constructor.
	     * @param androidExtractorToCopy AsbtractAndroidExtractor object to copy.
	     */
	    AbstractAndroidExtractor(const AbstractAndroidExtractor& androidExtractorToCopy);

	    /**
	     * AbstractAndroidExtractor class destructor.
	     */
	    virtual ~AbstractAndroidExtractor();

	    /**
	     * Allows to get the device serial.
	     * @return device serial (see "adb -s ANDROID_SERIAL").
	     */
	    QString getDeviceSerial() const;

	    /**
	     * @see AbstractMobilePhoneExtractor::logicalAcquisition()
	     */
	    virtual datastructure::MobilePhone* logicalAcquisition() throw(ExtractionException);

	    /**
	     * @see AbstractMobilePhoneExtractor::physicalAcquisition()
	     */
	    virtual datastructure::MobilePhone* physicalAcquisition() throw(ExtractionException);

	protected:
	    QFile* dbFileContact;
	    QFile* dbFileEmail;
	    QFile* dbFileEmailBody;
	    QFile* dbFileSMS;

	    /**
	     * Allows to recover a db file of the android mobile phone.
	     * Create a new process to use adb tool of the android SDK.
	     * @param pathToDBFile path in the android device to the db file.
	     */
	    QFile* recoverDBFile(QString pathToDBFile) throw(ExtractionException);

	    /**
	     * Puts a executable file in the android device and executes it.
	     * The executable file is placed in /data/local/tmp.
	     * @param pathToExecFile path to the executable file.
	     */
	    void execInDevice(QString pathToExecFile) throw(ExtractionException);

	    /**
	     * Allows to recover all db files of the android mobile phone.
	     */
	    virtual void recoverDBFiles() throw(ExtractionException) = 0;

	    /**
	     * Recovers the contact list and add them in the mobile phone.
	     * @param mobilePhone mobile phone where add the contacts.
	     */
	    virtual void recoverContactsInDB(datastructure::MobilePhone* mobilePhone) throw(ExtractionException) = 0;

	    /**
	     * Recovers the file list and add them in the mobile phone.
	     * @param mobilePhone mobile phone where add the files.
	     */
	    virtual void recoverFilesInDB(datastructure::MobilePhone* mobilePhone) throw(ExtractionException) = 0;

	    /**
	     * Recovers the communication list and add them in the mobile phone.
	     * @param mobilePhone mobile phone where add the communications.
	     */
	    virtual void recoverCommunicationsInDB(datastructure::MobilePhone* mobilePhone) throw(ExtractionException) = 0;
    };
}


#endif // ABSTRACTANDROIDEXTRACTOR_H
