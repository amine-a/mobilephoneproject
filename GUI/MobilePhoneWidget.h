// ----------------------------------------------------------------------------
// -- Header of MainWindow class
// -- Package: GUI
// ----------------------------------------------------------------------------

#ifndef MOBILEPHONEWIDGET_H
#define MOBILEPHONEWIDGET_H

#include <QtGui>
#include "MobilePhone.h"

namespace GUI
{
    /**
     * Widget for showing mobile phone data.
     * Used in the MainWindow class to create a new tab.
     */
    class MobilePhoneWidget: public QWidget
    {
	Q_OBJECT

	private:

	    datastructure::MobilePhone* mobilePhone;
	    QHBoxLayout*		mainLayout;
	    QList<QToolButton *>	buttonList;

	    // Table widgets
	    QTableWidget*		deviceWidget;
	    QTableWidget*		contactWidget;
	    QTableWidget*		callWidget;
	    QTableWidget*		smsWidget;
	    QTableWidget*		emailWidget;
	    QTableWidget*		documentWidget;


	    // Button index
	    static const int		DEVICE_BUTTON_INDEX	= 0;
	    static const int		CONTACT_BUTTON_INDEX	= 1;
	    static const int		CALL_BUTTON_INDEX	= 2;
	    static const int		SMS_BUTTON_INDEX	= 3;
	    static const int		EMAIL_BUTTON_INDEX	= 4;
	    static const int		DOCUMENT_BUTTON_INDEX	= 8;




	    /**
	     * Displays the menu of this widget.
	     */
	    void displayMenu();

	    /**
	     * Allows to uncheked push buttons in the menu.
	     * @param currentButtonIndex index of the current button in the menu.
	     */
	    void uncheckedPushButtons(int currentButtonIndex);

	    /**
	     * Creates a menu button.
	     * @param text label of the button.
	     * @param iconPath icon path.
	     */
	    QToolButton* createMenuButton(QString text, QString iconPath);

	    /**
	     * Create a table to display information in the main layout.
	     * @param columnCount column count of the table.
	     * @param labels horizontal header labels of the table.
	     * @return table widget without rows.
	     */
	    QTableWidget* createTable(int columnCount, QStringList& labels);

	    /**
	     * Allows to create the widget for display device information.
	     */
	    void createDeviceWidget();

	    /**
	     * Allows to create the widget for display the list of contacts.
	     */
	    void createContactWidget();

	    /**
	     * Allows to create the widget for display the list of calls.
	     */
	    void createCallWidget();

	    /**
	     * Allows to create the widget for display the list of SMS.
	     */
	    void createSMSWidget();

	    /**
	     * Allows to create the widget for display the list of emails.
	     */
	    void createEmailWidget();

	    /**
	     * Allows to create the widget for display the list of documents.
	     */
	    void createDocumentWidget();

	public slots:

	    /**
	     * Displays the information about the mobile phone.
	     */
	    void displayDeviceInformation();

	    /**
	     * Displays the list of contacts.
	     */
	    void displayContacts();

	    /**
	     * Displays the list of calls.
	     */
	    void displayCalls();

	    /**
	     * Displays the list of SMS.
	     */
	    void displaySMS();

	    /**
	     * Displays the list of emails.
	     */
	    void displayEmails();

	    /**
	     * Displays the list of emails.
	     */
	    void displayPictures();

	    /**
	     * Displays the list of audio files.
	     */
	    void displayAudioFiles();

	    /**
	     * Displays the list of videos.
	     */
	    void displayVideos();

	    /**
	     * Displays the list of documents.
	     */
	    void displayDocuments();

	public:

	    /**
	     * MobilePhoneWidget class constructor.
	     * @param mobilePhone mobile phone with data to display.
	     */
	    MobilePhoneWidget(datastructure::MobilePhone& mobilePhone);

	    /**
	     * MobilePhoneWidget class destructor.
	     */
	    virtual ~MobilePhoneWidget();
    };
}

#endif // MOBILEPHONEWIDGET_H
