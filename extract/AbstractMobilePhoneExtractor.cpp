// ----------------------------------------------------------------------------
// -- Source of AbstractMobilePhoneExtractor class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#include "AbstractMobilePhoneExtractor.h"

namespace extract
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------
    AbstractMobilePhoneExtractor::AbstractMobilePhoneExtractor() throw(ExtractionException)
    :extractionDir(QDir::current()), messageList(), deleteTmpFiles(false)
    {
    }

    AbstractMobilePhoneExtractor::AbstractMobilePhoneExtractor(const AbstractMobilePhoneExtractor& mobilePhoneExtractorToCopy)
    :extractionDir(mobilePhoneExtractorToCopy.extractionDir), messageList(mobilePhoneExtractorToCopy.messageList),
     deleteTmpFiles(mobilePhoneExtractorToCopy.deleteTmpFiles)
    {
    }

    AbstractMobilePhoneExtractor::~AbstractMobilePhoneExtractor()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    const QDir& AbstractMobilePhoneExtractor::getExtractionDir() const
    {
	return this->extractionDir;
    }

    bool AbstractMobilePhoneExtractor::tmpFilesIsDeleted() const
    {
	return this->deleteTmpFiles;
    }

    const QStringList& AbstractMobilePhoneExtractor::getMessageList() const
    {
	return this->messageList;
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void AbstractMobilePhoneExtractor::setExtractionDir(QString extractionPath) throw(ExtractionException)
    {
	this->extractionDir.setPath(extractionPath);

	if(! this->extractionDir.exists())
	{
	    this->extractionDir = QDir::current();
	    throw ExtractionException("Extraction directory is invalid.");
	}
    }

    void AbstractMobilePhoneExtractor::setDeleteTmpFiles(bool deleteTmpFiles)
    {
	this->deleteTmpFiles = deleteTmpFiles;
    }

    void AbstractMobilePhoneExtractor::addMessage(QString message)
    {
	this->messageList.push_back(message);
    }
}

