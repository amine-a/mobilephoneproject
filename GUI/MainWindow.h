// ----------------------------------------------------------------------------
// -- Header of MainWindow class
// -- Package: GUI
// ----------------------------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "MobilePhoneWidget.h"

namespace GUI
{
    /**
     * This class allows to manage the main window of the application.
     */
    class MainWindow: public QMainWindow
    {
	private:
	    QMdiArea* qMdiArea;

	    /**
	     * Adds a sub window in the main window to show mobile phone data.
	     * @param mobilePhone mobile phone with data to display.
	     */
	    void showMobilePhoneData(datastructure::MobilePhone& mobilePhone);

	    /**
	     * Create the menu and the toolbar menu.
	     */
	    void createMenu();

	public:

	    /**
	     * MainWindow class constructor without parameters.
	     */
	    MainWindow();

	    /**
	     * Destructor of MainWindow class.
	     */
	    virtual ~MainWindow();
    };
}

#endif // MAINWINDOW_H
