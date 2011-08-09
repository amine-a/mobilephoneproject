// ----------------------------------------------------------------------------
// -- Header of AbstractMobilePhoneExtractor class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#ifndef ABSTRACTMOBILEPHONEEXTRACTOR_H
#define ABSTRACTMOBILEPHONEEXTRACTOR_H

#include <QDir>

#include "MobilePhone.h"
#include "ExtractionException.h"

namespace extract
{
    /**
     * Abstract class to extract the data of mobile phones.
     * This class must be implemented by subclass with specific methods depending on the type of mobile phone.
     */
    class AbstractMobilePhoneExtractor
    {
	private:
	    QDir	extractionDir;
	    QStringList messageList;
	    bool	deleteTmpFiles;

	protected:

	    /**
	     * Adds a message in the message list.
	     * @param message new message to add.
	     */
	    void addMessage(QString message);

	public:

	    /**
	     * AbstractMobilePhoneExtractor class constructor.
	     * Initialize the extraction directory with the current directory.
	     * @throws ExtractionException if there is a error during the creation of the AbstractMobilePhoneExtractor object.
	     */
	    AbstractMobilePhoneExtractor() throw(ExtractionException);

	    /**
	     * AbstractMobilePhoneExtractor class copy constructor.
	     * @param mobilePhoneExtractorToCopy instance of AbstractMobilePhoneExtractor to copy.
	     */
	    AbstractMobilePhoneExtractor(const AbstractMobilePhoneExtractor& mobilePhoneExtractorToCopy);

	    /**
	     * AbstractMobilePhoneExtractor class destructor.
	     */
	    virtual ~AbstractMobilePhoneExtractor();

	    /**
	     * Allows to get the extraction directory.
	     * @return extraction directory.
	     */
	    const QDir& getExtractionDir() const;

	    /**
	     * Changes the extraction directory.
	     * @param extractionPath path to the extraction directory.
	     * @throws ExtractionException if the extraction path is incorrect.
	     */
	    void setExtractionDir(QString extractionPath) throw(ExtractionException);

	    /**
	     * Allows to know if the temporary files are deleted when the extraction is finished.
	     * @return true if the temporary files are deleted, false else.
	     */
	    bool tmpFilesIsDeleted() const;

	    /**
	     * Allows to indicate if the temporary files are deleted when the extraction is finished.
	     * @param deleteTmpFiles if true the temporary files are deleted.
	     */
	    void setDeleteTmpFiles(bool deleteTmpFiles);

	    /**
	     * Allows to get the extraction message list.
	     * This list contains the list of error messages and warning messages.
	     * @return extraction message list.
	     */
	    const QStringList& getMessageList() const;

	    /**
	     * Allows to do a logical aquisition of mobile phone data.
	     * @throws ExtractionException if there is an error during retrieval.
	     */
	    virtual datastructure::MobilePhone* logicalAcquisition() throw(ExtractionException) = 0;

	    /**
	     * Allows to do a physical aquisition of mobile phone data (tries to recover deleted data).
	     * @throws ExtractionException if there is an error during retrieval.
	     */
	    virtual datastructure::MobilePhone* physicalAcquisition() throw(ExtractionException) = 0;
    };

}

#endif // ABSTRACTMOBILEPHONEEXTRACTOR_H
