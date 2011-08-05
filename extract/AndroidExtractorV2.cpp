#include "AndroidExtractorV2.h"
#include "Email.h"
#include "SMS.h"
#include <typeinfo>

using namespace datastructure;

namespace extract
{
    // -----------------------------------------------------------------
    // -- Constants
    // -----------------------------------------------------------------

    const QString DEVICE_PATH_TO_DBCONTACTS	= "/data/data/com.android.providers.contacts/databases/contacts2.db";
    const QString DEVICE_PATH_TO_DBDOWNLOADS	= "/data/data/com.android.providers.downloads/databases/downloads.db";
    const QString DEVICE_PATH_TO_DBMMSSMS	= "/data/data/com.android.providers.telephony/databases/mmssms.db";
    const QString DEVICE_PATH_TO_DBTELEPHONY	= "/data/data/com.android.providers.telephony/databases/telephony.db";
    const QString DEVICE_PATH_TO_DBEMAIL	= "/data/data/com.android.email/databases/EmailProvider.db";
    const QString DEVICE_PATH_TO_DBEMAILBODY	= "/data/data/com.android.email/databases/EmailProviderBody.db";

    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    AndroidExtractorV2::AndroidExtractorV2(QString deviceSerial) throw(ExtractionException)
    :AbstractAndroidExtractor(deviceSerial)
    {
	// TODO : check if the device is compatible.
    }

    AndroidExtractorV2::AndroidExtractorV2(const AndroidExtractorV2& androidExtractorV2ToCopy)
    :AbstractAndroidExtractor(androidExtractorV2ToCopy)
    {
    }

    AndroidExtractorV2::~AndroidExtractorV2()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- DB files
    // -----------------------------------------------------------------

    void AndroidExtractorV2::recoverDBFiles() throw(ExtractionException)
    {
	try{this->dbFileContact =  this->recoverDBFile(DEVICE_PATH_TO_DBCONTACTS);}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	try{this->dbFileSMS =  this->recoverDBFile(DEVICE_PATH_TO_DBMMSSMS);}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	try{this->dbFileEmail = this->recoverDBFile(DEVICE_PATH_TO_DBEMAIL);}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	try{this->dbFileEmailBody = this->recoverDBFile(DEVICE_PATH_TO_DBEMAILBODY);}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	try{delete this->recoverDBFile(DEVICE_PATH_TO_DBTELEPHONY);}
	catch(ExtractionException excep){this->addMessage(excep.what());}

	try{delete this->recoverDBFile(DEVICE_PATH_TO_DBDOWNLOADS);}
	catch(ExtractionException excep){this->addMessage(excep.what());}
    }

    // -----------------------------------------------------------------
    // -- Recovering of files list
    // -----------------------------------------------------------------

    void AndroidExtractorV2::recoverFilesInDB(datastructure::MobilePhone* mobilePhone) throw(ExtractionException)
    {
	// TODO
	mobilePhone->getDeviceName();
    }

    // -----------------------------------------------------------------
    // -- Recovering of contact list
    // -----------------------------------------------------------------

    static int addContact(void *mobilePhone, int argc, char **colValues, char **colNames)
    {
	Contact* contact = NULL;
	colNames = NULL; // Not used
	argc = 0; // Not used

	contact = new Contact( QString(colValues[0]).toInt() );
	contact->setName(colValues[1]);


	((MobilePhone*)(mobilePhone))->getAddressBook().addContact(contact);

	return 0;
    }

    static int addInfoContact(void *mobilePhone, int argc, char **colValues, char **colNames)
    {
	Contact* contact = NULL;
	QString infoValue, infoName;
	argc = 0; // Not used

	contact = ((MobilePhone*)(mobilePhone))->getAddressBook().findContactWithID( QString(colValues[0]).toInt() );
	if(contact)
	{
	    infoName = colNames[1];
	    infoValue = colValues[1];

	    if(infoName == "phoneNumber")
	    {
		infoValue.replace("-", "");
		contact->addPhoneNumber(infoValue);
	    }
	    else if(infoName == "emailAddress")
	    {
		contact->addEmailAddress(infoValue);
	    }
	    else if(infoName == "org")
	    {
		contact->addOrg(infoValue);
	    }
	    else if(infoName == "group")
	    {
		contact->addGroup(infoValue);
	    }
	}

	return 0;
    }

    void AndroidExtractorV2::recoverContactsInDB(MobilePhone* mobilePhone) throw(ExtractionException)
    {
	SQLite3Connection* sqlite3Connection = NULL;
	QString		   sqlQuery;

	if(! this->dbFileContact)
	    throw ExtractionException("the information about the contacts can not be recovered because the database was not found.");

	try
	{
	    sqlite3Connection = new SQLite3Connection(this->dbFileContact->fileName());

	    // Contact ID and contact name
	    sqlQuery  = "SELECT con._id, data.data1 as name";
	    sqlQuery += " FROM contacts con, data, mimetypes mime";
	    sqlQuery += " WHERE con._id = data.raw_contact_id";
	    sqlQuery += " AND data.mimetype_id=mime._id and mime.mimetype LIKE '%name'";
	    sqlite3Connection->execQuery(sqlQuery, addContact, mobilePhone);

	    try
	    {
		// Phone numbers
		sqlQuery = "SELECT con._id, data.data1 as phoneNumber";
		sqlQuery += " FROM contacts con, data, mimetypes mime";
		sqlQuery += " where con._id = data.raw_contact_id";
		sqlQuery += " AND data.mimetype_id=mime._id and mime.mimetype LIKE '%phone_v2'";
		sqlite3Connection->execQuery(sqlQuery, addInfoContact, mobilePhone);
	    }
	    catch(SQLiteException& excep)
	    {
		this->addMessage(excep.what());
	    }

	    try
	    {
		// Email addresses
		sqlQuery = "SELECT con._id, data.data1 as emailAddress";
		sqlQuery += " FROM contacts con, data, mimetypes mime";
		sqlQuery += " where con._id = data.raw_contact_id";
		sqlQuery += " AND data.mimetype_id=mime._id and mime.mimetype LIKE '%email_v2'";
		sqlite3Connection->execQuery(sqlQuery, addInfoContact, mobilePhone);
	    }
	    catch(SQLiteException& excep)
	    {
		this->addMessage(excep.what());
	    }

	    try
	    {
		// Organizations
		sqlQuery = "SELECT con._id, data.data1 as org";
		sqlQuery += " FROM contacts con, data, mimetypes mime";
		sqlQuery += " where con._id = data.raw_contact_id";
		sqlQuery += " AND data.mimetype_id=mime._id and mime.mimetype LIKE '%organization'";
		sqlite3Connection->execQuery(sqlQuery, addInfoContact, mobilePhone);
	    }
	    catch(SQLiteException& excep)
	    {
		this->addMessage(excep.what());
	    }

	    delete sqlite3Connection;
	}
	catch(SQLiteException& excep)
	{
	    this->addMessage(excep.what());
	}
    }

    // -----------------------------------------------------------------
    // -- Recovering of communication list
    // -----------------------------------------------------------------

    static void addEmailAddressIn(Email* email, AddressBook& addressBook, char* colValue, char* colName)
    {
	EmailAddress*	emailAddress = NULL;
	QStringList	emailAddressList;
	QString		emailAddressForeach;
	QString		emailAddressValue;
	QString		qcolName(colName);

	emailAddressList = QString(colValue).replace("", "#").replace("", "\n").split("\n");
	foreach(emailAddressForeach, emailAddressList)
	{
	    emailAddressValue = emailAddressForeach.split("#").first();

	    if(! emailAddressValue.isEmpty())
	    {
		emailAddress = addressBook.findEmailAddress(emailAddressValue);

		if(! emailAddress)
		    emailAddress = new EmailAddress(emailAddressValue);

		if(qcolName == "formList")
		    email->addInFromList(emailAddress);
		else if(qcolName == "toList")
		    email->addInToList(emailAddress);
		else if(qcolName == "ccList")
		    email->addInCCList(emailAddress);
		else if(qcolName == "bccList")
		    email->addInCCIList(emailAddress);
	    }
	}
    }

    static int addEmail(void *mobilePhone, int argc, char **colValues, char **colNames)
    {
	Email*		email = NULL;
	AddressBook&	addressBook = ((MobilePhone*)(mobilePhone))->getAddressBook();

	argc = 0; // Not used

	email = new Email( QString(colValues[0]).toInt() );
	email->setSubject(colValues[2]);

	if(QString(colValues[1]).toInt() == 0)
	    email->setStatus(AbstractCommunication::RECEIVED_STATUS);
	else
	    email->setStatus(AbstractCommunication::READ_STATUS);

	// fromList
	addEmailAddressIn(email, addressBook, colValues[3], colNames[3]);

	// toList
	addEmailAddressIn(email, addressBook, colValues[4], colNames[4]);

	// ccList
	addEmailAddressIn(email, addressBook, colValues[5], colNames[5]);

	// cciList
	addEmailAddressIn(email, addressBook, colValues[6], colNames[6]);

	((MobilePhone*)(mobilePhone))->getCommunicationManager().addCommunication(email);

	return 0;
    }

    static int addEmailBody(void *mobilePhone, int argc, char **colValues, char **colNames)
    {
	AbstractCommunication* communication;
	Email* email = NULL;

	argc = 0; // Not used
	colNames = NULL; // Not used

	communication = ((MobilePhone*)(mobilePhone))->getCommunicationManager().findCommunicationWithID(QString(colValues[0]).toInt());
	if(communication)
	{
	    email = dynamic_cast<Email*>( communication );

	    if(email)
	    {
		email->setBody(colValues[1]);
	    }
	}

	return 0;
    }

    static int addSMS(void *mobilePhone, int argc, char **colValues, char **colNames)
    {
	SMS*		sms = NULL;
	QString		phoneNumberValue(colValues[2]);
	PhoneNumber*	phoneNumber = NULL;

	argc = 0; // Not used
	colNames = NULL; // Not used

	sms = new SMS( QString(colValues[0]).toInt() );

	if(QString(colValues[1]).toInt() == 0)
	    sms->setStatus(AbstractCommunication::RECEIVED_STATUS);
	else
	    sms->setStatus(AbstractCommunication::READ_STATUS);

	phoneNumberValue.replace("-", "");
	phoneNumber = ((MobilePhone*)(mobilePhone))->getAddressBook().findPhoneNumber(phoneNumberValue);

	if(! phoneNumber)
	    phoneNumber = new PhoneNumber(phoneNumberValue);

	sms->addPhoneNumber(phoneNumber);
	sms->setContent(colValues[3]);

	((MobilePhone*)(mobilePhone))->getCommunicationManager().addCommunication(sms);

	return 0;
    }

    void AndroidExtractorV2::recoverCommunicationsInDB(datastructure::MobilePhone* mobilePhone) throw(ExtractionException)
    {
	SQLite3Connection* sqlite3Connection = NULL;
	QString		   sqlQuery;

	if(this->dbFileEmail)
	{
	    try
	    {
		// Emails
		sqlite3Connection = new SQLite3Connection(this->dbFileEmail->fileName());

		sqlQuery  = "SELECT _id, flagRead, subject, fromList, toList, ccList, bccList";
		sqlQuery += "  FROM message";
		sqlite3Connection->execQuery(sqlQuery, addEmail, mobilePhone);

		delete sqlite3Connection;

		if(this->dbFileEmailBody)
		{
		    // Email body
		    sqlite3Connection = new SQLite3Connection(this->dbFileEmailBody->fileName());

		    sqlQuery  = "SELECT _id, textContent FROM Body";
		    sqlite3Connection->execQuery(sqlQuery, addEmailBody, mobilePhone);

		    delete sqlite3Connection;
		}
	    }
	    catch(SQLiteException& excep)
	    {
		this->addMessage(excep.what());
	    }
	}

	if(this->dbFileSMS)
	{
	    try
	    {
		// SMS
		sqlite3Connection = new SQLite3Connection(this->dbFileSMS->fileName());

		sqlQuery  = "SELECT _id, read, address, body FROM sms";
		sqlite3Connection->execQuery(sqlQuery, addSMS, mobilePhone);

		delete sqlite3Connection;
	    }
	    catch(SQLiteException& excep)
	    {
		this->addMessage(excep.what());
	    }
	}
    }
}
