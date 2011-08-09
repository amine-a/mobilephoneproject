// ----------------------------------------------------------------------------
// -- Source of AsbtractAndroidExtractor class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#include <QProcess>

#include "AbstractAndroidExtractor.h"

using namespace datastructure;

namespace extract
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    AbstractAndroidExtractor::AbstractAndroidExtractor(QString deviceSerial) throw(ExtractionException)
    :AbstractMobilePhoneExtractor(), deviceSerial(deviceSerial), dbFileContact(NULL)
    {
    }

    AbstractAndroidExtractor::AbstractAndroidExtractor(const AbstractAndroidExtractor& androidExtractorToCopy)
    :AbstractMobilePhoneExtractor(androidExtractorToCopy), deviceSerial(deviceSerial),
     dbFileContact(androidExtractorToCopy.dbFileContact)
    {
    }

    AbstractAndroidExtractor::~AbstractAndroidExtractor()
    {
	if(this->dbFileContact)
	    delete this->dbFileContact;

	if(this->dbFileEmail)
	    delete this->dbFileEmail;

	if(this->dbFileEmailBody)
	    delete this->dbFileEmailBody;

	if(this->dbFileSMS)
	    delete this->dbFileSMS;
    }

    QString AbstractAndroidExtractor::getDeviceSerial() const
    {
	return this->deviceSerial;
    }

    // -----------------------------------------------------------------
    // -- Aquisition methods
    // -----------------------------------------------------------------

    MobilePhone* AbstractAndroidExtractor::logicalAcquisition() throw(ExtractionException)
    {
	MobilePhone* mobilePhone = NULL;

	mobilePhone = new MobilePhone("MobileTest"); // TODO

	try{this->recoverDBFiles();}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	try{this->recoverFilesInDB(mobilePhone);}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	try{this->recoverContactsInDB(mobilePhone);}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	try{this->recoverCommunicationsInDB(mobilePhone);}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	return mobilePhone;
    }

    MobilePhone* AbstractAndroidExtractor::physicalAcquisition() throw(ExtractionException)
    {
	// TODO

	//this->execInDevice("GingerBreak");
	//this->execInDevice("psneuter");

	return NULL;
    }

    // -----------------------------------------------------------------
    // -- adb tool
    // -----------------------------------------------------------------

    QFile* AbstractAndroidExtractor::recoverDBFile(QString pathToDBFile) throw(ExtractionException)
    {
	QProcess    process;
	QStringList arguments;
	QString	    exportFileName;
	QFile*	    newFile = NULL;

	exportFileName = pathToDBFile.section("/", -1);
	exportFileName = this->getExtractionDir().path()+QDir::separator()+exportFileName;

	//qDebug() << "File name: " << exportFileName;

	// Recovering of the db file with adb tool
	arguments << "-s"
		  << this->getDeviceSerial()
		  << "pull"
		  << pathToDBFile
		  << exportFileName;

	process.start("adb", arguments);
	process.waitForFinished();
	process.close();

	if( process.exitStatus() == QProcess::CrashExit )
	    throw ExtractionException("Error during the copy of " +pathToDBFile+ " file.");

	// Checking if the file was created
	newFile = new QFile(exportFileName);
	if( ! newFile->exists() )
	    throw ExtractionException("Error during the copy of " +pathToDBFile+ " file.");

	return newFile;
    }

    void AbstractAndroidExtractor::execInDevice(QString pathToExecFile) throw(ExtractionException)
    {
	QProcess    process;
	QStringList arguments;
	QString	    execFileName;

	execFileName = pathToExecFile.section(QDir::separator(), -1);

	// Puts the file in /data/local/tmp/
	arguments << "-s"
		  << this->getDeviceSerial()
		  << "push"
		  << pathToExecFile
		  << ("/data/local/tmp/"+execFileName);

	process.start("adb", arguments);
	process.waitForFinished();
	process.close();

	if( process.exitStatus() == QProcess::CrashExit )
	    throw ExtractionException("Error during the copy of " +execFileName+ " file.");

	// Changes file permission
	arguments.clear();
	arguments << "-s"
		  << this->getDeviceSerial()
		  << "shell"
		  << "chmod"
		  << "777"
		  << ("/data/local/tmp/"+execFileName);

	process.start("adb", arguments);
	process.waitForFinished();
	process.close();

	if( process.exitStatus() == QProcess::CrashExit )
	    throw ExtractionException("Error during the change permission of " +execFileName+ " file.");

	// Executes the program in the device
	arguments.clear();
	arguments << "-s"
		  << this->getDeviceSerial()
		  << ("/data/local/tmp/"+execFileName);

	process.start("adb", arguments);
	process.waitForFinished();
	process.close();

	if( process.exitStatus() == QProcess::CrashExit )
	    throw ExtractionException("Error during the execute of " +execFileName+ " file.");
    }
}

