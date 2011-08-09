// ----------------------------------------------------------------------------
// -- Source of MobilePhoneWidget class
// -- Package: GUI
// ----------------------------------------------------------------------------

#include "MobilePhoneWidget.h"
#include <list>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include "Contact.h"
#include "Call.h"
#include "SMS.h"
#include "Email.h"
#include "Document.h"

using namespace std;
using namespace datastructure;

namespace GUI
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------
    MobilePhoneWidget::MobilePhoneWidget(MobilePhone& mobilePhone)
    :QWidget(), deviceWidget(NULL), contactWidget(NULL), callWidget(NULL)
    {
	this->mobilePhone = &mobilePhone;
	this->setWindowTitle(this->mobilePhone->getDeviceName());

	this->mainLayout = new QHBoxLayout();
	this->setLayout(this->mainLayout);

	this->displayMenu();
	this->displayDeviceInformation();
    }

    MobilePhoneWidget::~MobilePhoneWidget()
    {
	delete this->mobilePhone;
    }

    // -----------------------------------------------------------------
    // -- Useful methods
    // -----------------------------------------------------------------

    QToolButton* MobilePhoneWidget::createMenuButton(QString text, QString iconPath)
    {
	QToolButton *button;

	button = new QToolButton();
	button->setText(text);
	button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	button->setIcon(QIcon(iconPath));
	button->setIconSize(QSize(32, 32));
	button->setCheckable(true);
	button->setAutoRaise(true);
	button->setFixedWidth(100);
	this->buttonList.push_back(button);

	return button;
    }

    void MobilePhoneWidget::uncheckedPushButtons(int currentButtonIndex)
    {
	for(int i=0; i<this->buttonList.size(); i++ )
	{
	    this->buttonList.at(i)->setChecked(i == currentButtonIndex);
	}

	// Remove the current table of the main layout.
	if( this->mainLayout->count() > 1 )
	{
	    delete this->mainLayout->takeAt(1);
	}
    }

    QTableWidget* MobilePhoneWidget::createTable(int columnCount, QStringList& labels)
    {
	QTableWidget*	tableWidget;

	tableWidget = new QTableWidget();
	tableWidget->setColumnCount(columnCount);
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableWidget->setHorizontalHeaderLabels(labels);
	tableWidget->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);

	return tableWidget;
    }

    // -----------------------------------------------------------------
    // -- Menu
    // -----------------------------------------------------------------

    void MobilePhoneWidget::displayMenu()
    {
	QVBoxLayout *menuLayout;
	QToolButton *button;

	menuLayout = new QVBoxLayout();
	menuLayout->setAlignment(Qt::AlignTop);

	button = this->createMenuButton("Information", "icons/phone_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displayDeviceInformation()));

	button = this->createMenuButton("Contacts", "icons/contact_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displayContacts()));

	button = this->createMenuButton("Calls", "icons/call_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displayCalls()));

	button = this->createMenuButton("SMS", "icons/SMS_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displaySMS()));

	button = this->createMenuButton("Emails", "icons/email_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displayEmails()));

	button = this->createMenuButton("Pictures", "icons/picture_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displayPictures()));

	button = this->createMenuButton("Audio files", "icons/audio_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displayAudioFiles()));

	button = this->createMenuButton("Videos", "icons/video_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displayVideos()));

	button = this->createMenuButton("Documents", "icons/document_48px.png");
	menuLayout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), this, SLOT(displayDocuments()));

	this->mainLayout->addLayout(menuLayout);
    }

    // -----------------------------------------------------------------
    // -- Device information
    // -----------------------------------------------------------------

    void MobilePhoneWidget::createDeviceWidget()
    {
	QTableWidgetItem*	item;
	QStringList		labels;
	int			rowNumber;

	labels << "" << "" ;
	this->deviceWidget = this->createTable(2, labels);
	this->deviceWidget->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);

	// Device name
	rowNumber = 0;
	this->deviceWidget->insertRow(rowNumber);

	item = new QTableWidgetItem( "Device name: " );
	this->deviceWidget->setItem(rowNumber, 0, item);

	item = new QTableWidgetItem( this->mobilePhone->getDeviceName() );
	this->deviceWidget->setItem(rowNumber, 1, item);

	// Model
	rowNumber++;
	this->deviceWidget->insertRow(rowNumber);

	item = new QTableWidgetItem( "Model: " );
	this->deviceWidget->setItem(rowNumber, 0, item);

	item = new QTableWidgetItem( this->mobilePhone->getModel() );
	this->deviceWidget->setItem(rowNumber, 1, item);

	// Mobile ID
	rowNumber++;
	this->deviceWidget->insertRow(rowNumber);

	item = new QTableWidgetItem( "Mobile ID: " );
	this->deviceWidget->setItem(rowNumber, 0, item);

	item = new QTableWidgetItem( this->mobilePhone->getMobileID() );
	this->deviceWidget->setItem(rowNumber, 1, item);

	// Subscriber ID
	rowNumber++;
	this->deviceWidget->insertRow(rowNumber);

	item = new QTableWidgetItem( "Subcriber ID: " );
	this->deviceWidget->setItem(rowNumber, 0, item);

	item = new QTableWidgetItem( this->mobilePhone->getSubscriberID() );
	this->deviceWidget->setItem(rowNumber, 1, item);
    }

    void MobilePhoneWidget::displayDeviceInformation()
    {
	this->uncheckedPushButtons(MobilePhoneWidget::DEVICE_BUTTON_INDEX);

	//if( this->deviceWidget == NULL )
	    this->createDeviceWidget();

	this->mainLayout->addWidget(this->deviceWidget);
    }

    // -----------------------------------------------------------------
    // -- Contacts
    // -----------------------------------------------------------------

    void MobilePhoneWidget::createContactWidget()
    {
	QStringList			labels;
	QTableWidgetItem*		item;
	list<Contact>*			contactList;
	list<Contact>::iterator		itContact;
	list<PhoneNumber>::iterator	itPhoneNumber;
	list<EmailAddress>::iterator	itEmailAddress;
	int				rowNumber, colNumber;
	QString				displayString;

	labels << "Name" <<"Type" << "Org" <<"Phone number" << "Email address" << "Deleted";
	this->contactWidget = this->createTable(6, labels);
	this->contactWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
	this->contactWidget->horizontalHeader()->setResizeMode(4, QHeaderView::Stretch);
/*
	contactList = this->mobilePhone->getAddressBook()->getContactList();

	rowNumber=0;
	for(itContact = contactList->begin();
	    itContact != contactList->end();
	    itContact++)
	{
	    this->contactWidget->insertRow(rowNumber);
	    colNumber = 0;

	    // Name
	    item = new QTableWidgetItem( QString(itContact->getName().c_str()) );
	    this->contactWidget->setItem(rowNumber, colNumber++, item);

	    // Type
	    item = new QTableWidgetItem( QString(itContact->getType().c_str()) );
	    this->contactWidget->setItem(rowNumber, colNumber++, item);

	    // Org
	    item = new QTableWidgetItem( QString(itContact->getOrg().c_str()) );
	    contactWidget->setItem(rowNumber, colNumber++, item);

	    // Phone number
	    displayString = "";

	    for(itPhoneNumber = itContact->getPhoneNumberList()->begin();
		itPhoneNumber != itContact->getPhoneNumberList()->end();
		itPhoneNumber++)
	    {
		displayString += "";
		displayString += itPhoneNumber->getValue().c_str();
		displayString += " ";
	    }

	    item = new QTableWidgetItem( displayString );

	    this->contactWidget->setItem(rowNumber, colNumber++, item);

	    // Email address
	    displayString = "";
	    for(itEmailAddress = itContact->getEmailAddressList()->begin();
		itEmailAddress != itContact->getEmailAddressList()->end();
		itEmailAddress++)
	    {
		displayString += "";
		displayString += itEmailAddress->getValue().c_str();
		displayString += " ";
	    }

	    item = new QTableWidgetItem( displayString );
	    this->contactWidget->setItem(rowNumber, colNumber++, item);

	    // Deleted
	    item = new QTableWidgetItem( itContact->isDeleted() ? "yes" : "no");
	    this->contactWidget->setItem(rowNumber, colNumber++, item);

	    rowNumber++;
	}
	*/
    }

    void MobilePhoneWidget::displayContacts()
    {
	this->uncheckedPushButtons(MobilePhoneWidget::CONTACT_BUTTON_INDEX);

	//if( this->contactWidget == NULL )
	    this->createContactWidget();

	this->mainLayout->addWidget(this->contactWidget);
    }

    // -----------------------------------------------------------------
    // -- Calls
    // -----------------------------------------------------------------

    void MobilePhoneWidget::createCallWidget()
    {
	QTableWidgetItem*		    item;
	QStringList			    labels;
	int				    rowNumber, colNumber;
	Call*				    call;

	labels << "Date and time" << "Status" << "Incoming" << "Phone number" << "Duration" << "Deleted";
	this->callWidget = this->createTable(6, labels);
	this->callWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
	this->callWidget->horizontalHeader()->setResizeMode(3, QHeaderView::Stretch);
/*
	rowNumber = 0;
	for(itCommunication = this->mobilePhone->getCommunicationList()->begin();
	    itCommunication != this->mobilePhone->getCommunicationList()->end();
	    itCommunication++)
	{
	    try
	    {
		call = dynamic_cast<Call*>( *itCommunication );

		if( call )
		{
		    colNumber = 0;
		    this->callWidget->insertRow(rowNumber);

		    // Date
		    item = new QTableWidgetItem( call->getDatetime().c_str() );
		    this->callWidget->setItem(rowNumber, colNumber++, item);

		    // Status
		    item = new QTableWidgetItem( call->statusToString().c_str() );
		    this->callWidget->setItem(rowNumber, colNumber++, item);

		    // Incoming
		    item = new QTableWidgetItem( call->isIncoming() ? "Yes" : "No" );
		    this->callWidget->setItem(rowNumber, colNumber++, item);

		    // Phone number
		    item = new QTableWidgetItem( call->getPhoneNumber()->toString().c_str() );
		    this->callWidget->setItem(rowNumber, colNumber++, item);

		    // Duration
		    item = new QTableWidgetItem( call->getDuration().c_str() );
		    this->callWidget->setItem(rowNumber, colNumber++, item);

		    // Deleted
		    item = new QTableWidgetItem( call->isDeleted() ? "Yes" : "No" );
		    this->callWidget->setItem(rowNumber, colNumber++, item);

		    rowNumber++;
		}
	    }
	    catch(const std::bad_cast& excep)
	    {
		// Empty
	    }
	}
*/
    }

    void MobilePhoneWidget::displayCalls()
    {
	this->uncheckedPushButtons(MobilePhoneWidget::CALL_BUTTON_INDEX);

	//if( this->callWidget == NULL )
	    this->createCallWidget();

	this->mainLayout->addWidget(this->callWidget);
    }

    // -----------------------------------------------------------------
    // -- SMS
    // -----------------------------------------------------------------

    void MobilePhoneWidget::createSMSWidget()
    {
	QStringList			labels;
	QTableWidgetItem*		item;
	int				rowNumber, colNumber;
	SMS*				sms;

	labels << "Date and time" << "Status" << "Incoming" << "Phone number" << "Content" << "Deleted";
	this->smsWidget = this->createTable(6, labels);
	this->smsWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
	this->smsWidget->horizontalHeader()->setResizeMode(4, QHeaderView::Stretch);
	this->smsWidget->horizontalHeader()->setResizeMode(5, QHeaderView::Stretch);
/*
	rowNumber = 0;
	for(itCommunication = this->mobilePhone->getCommunicationList()->begin();
	    itCommunication != this->mobilePhone->getCommunicationList()->end();
	    itCommunication++)
	{
	    try
	    {
		sms = dynamic_cast<SMS*>( *itCommunication );

		if( sms )
		{
		    colNumber = 0;
		    this->smsWidget->insertRow(rowNumber);

		    // Date
		    item = new QTableWidgetItem( sms->getDatetime().c_str() );
		    this->smsWidget->setItem(rowNumber, colNumber++, item);

		    // Status
		    item = new QTableWidgetItem( sms->statusToString().c_str() );
		    this->smsWidget->setItem(rowNumber, colNumber++, item);

		    // Incoming
		    item = new QTableWidgetItem( sms->isIncoming() ? "Yes" : "No" );
		    this->smsWidget->setItem(rowNumber, colNumber++, item);

		    // Phone number
		    item = new QTableWidgetItem( sms->getPhoneNumber()->toString().c_str() );
		    this->smsWidget->setItem(rowNumber, colNumber++, item);

		    // Content
		    item = new QTableWidgetItem( sms->getContent().c_str() );
		    this->smsWidget->setItem(rowNumber, colNumber++, item);

		    // Deleted
		    item = new QTableWidgetItem( sms->isDeleted() ? "Yes" : "No" );
		    this->smsWidget->setItem(rowNumber, colNumber++, item);

		    rowNumber++;
		}
	    }
	    catch(const std::bad_cast& excep)
	    {
		// Empty
	    }
	}
*/
    }

    void MobilePhoneWidget::displaySMS()
    {
	this->uncheckedPushButtons(MobilePhoneWidget::SMS_BUTTON_INDEX);

	//if( this->smsWidget == NULL )
	    this->createSMSWidget();

	this->mainLayout->addWidget(this->smsWidget);
    }

    // -----------------------------------------------------------------
    // -- Emails
    // -----------------------------------------------------------------

    void MobilePhoneWidget::createEmailWidget()
    {
	QStringList			labels;
	QTableWidgetItem*		item;
	int				rowNumber, colNumber;
	Email*				email;
	list<EmailAddress>::iterator	itEmailAddress;
	QString				displayString;

	labels << "Date and time" << "Status" << "Incoming" << "Email addresses" << "Subject" << "Content" << "Deleted";
	this->emailWidget = this->createTable(7, labels);
	this->emailWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
	this->emailWidget->horizontalHeader()->setResizeMode(3, QHeaderView::Stretch);
	this->emailWidget->horizontalHeader()->setResizeMode(4, QHeaderView::Stretch);
	this->emailWidget->horizontalHeader()->setResizeMode(5, QHeaderView::Stretch);

	/*
	rowNumber = 0;
	for(itCommunication = this->mobilePhone->getCommunicationList()->begin();
	    itCommunication != this->mobilePhone->getCommunicationList()->end();
	    itCommunication++)
	{
	    try
	    {
		email = dynamic_cast<Email*>( *itCommunication );

		if( email )
		{
		    colNumber = 0;
		    this->emailWidget->insertRow(rowNumber);

		    // Date
		    item = new QTableWidgetItem( email->getDatetime().c_str() );
		    this->emailWidget->setItem(rowNumber, colNumber++, item);

		    // Status
		    item = new QTableWidgetItem( email->statusToString().c_str() );
		    this->emailWidget->setItem(rowNumber, colNumber++, item);

		    // Incoming
		    item = new QTableWidgetItem( email->isIncoming() ? "Yes" : "No" );
		    this->emailWidget->setItem(rowNumber, colNumber++, item);

		    // Email addresses
		    displayString = "";
		    for(itEmailAddress = email->getEmailAddressList()->begin();
			itEmailAddress != email->getEmailAddressList()->end();
			itEmailAddress++)
		    {
			displayString += itEmailAddress->getValue().c_str();
			displayString += " ";
		    }

		    item = new QTableWidgetItem( displayString );
		    this->emailWidget->setItem(rowNumber, colNumber++, item);

		    // Subject
		    item = new QTableWidgetItem( email->getSubject().c_str() );
		    this->emailWidget->setItem(rowNumber, colNumber++, item);

		    // Content
		    item = new QTableWidgetItem( email->getContent().c_str() );
		    this->emailWidget->setItem(rowNumber, colNumber++, item);

		    // Deleted
		    item = new QTableWidgetItem( email->isDeleted() ? "Yes" : "No" );
		    this->emailWidget->setItem(rowNumber, colNumber++, item);

		    rowNumber++;
		}
	    }
	    catch(const std::bad_cast& excep)
	    {
		// Empty
	    }
	}
	*/
    }

    void MobilePhoneWidget::displayEmails()
    {
	this->uncheckedPushButtons(MobilePhoneWidget::EMAIL_BUTTON_INDEX);

	//if( this->smsWidget == NULL )
	    this->createEmailWidget();

	this->mainLayout->addWidget(this->emailWidget);
    }

    // -----------------------------------------------------------------
    // -- Pictures
    // -----------------------------------------------------------------

    void MobilePhoneWidget::displayPictures()
    {
	QTableWidget*		pictureWidget;
	QStringList		labels;

	this->uncheckedPushButtons(5);

	labels << "Overview" << "Name" << "Path" << "Size" << "Created date" <<"deleted";
	pictureWidget = this->createTable(6, labels);

	this->mainLayout->addWidget(pictureWidget);
    }

    // -----------------------------------------------------------------
    // -- Audio files
    // -----------------------------------------------------------------

    void MobilePhoneWidget::displayAudioFiles()
    {
	QTableWidget*		audioWidget;
	QStringList		labels;

	this->uncheckedPushButtons(6);
	labels << "Overview" << "Name" << "Path" << "Size" << "Created date" << "deleted";
	audioWidget = this->createTable(6, labels);

	this->mainLayout->addWidget(audioWidget);
    }

    // -----------------------------------------------------------------
    // -- Videos
    // -----------------------------------------------------------------

    void MobilePhoneWidget::displayVideos()
    {
	QTableWidget*		videoWidget;
	QStringList		labels;

	this->uncheckedPushButtons(7);
	labels << "Overview" << "Name" << "Path" << "Size" << "Created date" << "deleted";
	videoWidget = this->createTable(6, labels);

	this->mainLayout->addWidget(videoWidget);
    }

    // -----------------------------------------------------------------
    // -- Documents
    // -----------------------------------------------------------------

    void MobilePhoneWidget::createDocumentWidget()
    {
	QStringList			    labels;
	QTableWidgetItem*		    item;
	int				    rowNumber, colNumber;
	Document*			    document;
	stringstream			    stringStream;

	labels << "Name" << "Path" << "Size" << "Created date" << "deleted";
	this->documentWidget = this->createTable(5, labels);
	this->documentWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
	this->documentWidget->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
/*
	rowNumber = 0;
	for(itPhoneFile = this->mobilePhone->getFileList()->begin();
	    itPhoneFile != this->mobilePhone->getFileList()->end();
	    itPhoneFile++)
	{
	    try
	    {
		document = dynamic_cast<Document*>( *itPhoneFile );

		if( document )
		{
		    colNumber = 0;
		    this->documentWidget->insertRow(rowNumber);

		    // Name
		    item = new QTableWidgetItem( document->getName().c_str() );
		    this->documentWidget->setItem(rowNumber, colNumber++, item);

		    // Path
		    item = new QTableWidgetItem( document->getPath().c_str() );
		    this->documentWidget->setItem(rowNumber, colNumber++, item);

		    // Size
		    stringStream << document->getSize();
		    item = new QTableWidgetItem( stringStream.str().c_str() );
		    this->documentWidget->setItem(rowNumber, colNumber++, item);

		    // Created date
		    item = new QTableWidgetItem( document->getCreatedDate().c_str() );
		    this->documentWidget->setItem(rowNumber, colNumber++, item);

		    // Deleted
		    item = new QTableWidgetItem( document->isDeleted() ? "Yes" : "No" );
		    this->documentWidget->setItem(rowNumber, colNumber++, item);

		    rowNumber++;
		}
	    }
	    catch(const std::bad_cast& excep)
	    {
		// Empty
	    }
	}
*/
    }


    void MobilePhoneWidget::displayDocuments()
    {
	this->uncheckedPushButtons(MobilePhoneWidget::DOCUMENT_BUTTON_INDEX);

	//if( this->documentWidget == NULL )
	    this->createDocumentWidget();

	this->mainLayout->addWidget(this->documentWidget);
    }
}



