// ----------------------------------------------------------------------------
// -- Source of MainWindow class
// -- Package: GUI
// ----------------------------------------------------------------------------

#include "MainWindow.h"
#include "Call.h"
#include "Email.h"
#include "Document.h"

using namespace std;
using namespace datastructure;

namespace GUI
{
    MobilePhone* createMobilePhoneInstanceToTest()
    {
	MobilePhone*	mobilePhone;

	mobilePhone = new MobilePhone("test");

	return mobilePhone;
    }


    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    MainWindow::MainWindow()
    {
	this->qMdiArea = new QMdiArea();
	MobilePhone* mobilePhone;

	mobilePhone = createMobilePhoneInstanceToTest();

	this->setWindowIcon(QIcon("icons/mobilephone_48px.png"));
	this->setWindowTitle("Mobile phone forensics");

	this->showMobilePhoneData(*mobilePhone);

	this->createMenu();	
	this->setCentralWidget(qMdiArea);
	this->qMdiArea->setViewMode(QMdiArea::TabbedView);
    }

    MainWindow::~MainWindow()
    {
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------
    void MainWindow::showMobilePhoneData(MobilePhone &mobilePhone)
    {
	this->qMdiArea->addSubWindow(new MobilePhoneWidget(mobilePhone));
    }

    void MainWindow::createMenu()
    {
	QMenu *menu;
	QAction *menuAction;
	QToolBar *toolBar;

	// File menu
	menu = this->menuBar()->addMenu("&File");
	toolBar = addToolBar("Toolbar");
	toolBar->setMovable(false);

	menuAction = menu->addAction("&New");
	menuAction->setShortcut(QKeySequence("Ctrl+N"));
	menuAction->setIcon(QIcon("icons/new_48px.png"));
	toolBar->addAction(menuAction);

	menuAction = menu->addAction("&Open");
	menuAction->setShortcut(QKeySequence("Ctrl+O"));
	menuAction->setIcon(QIcon("icons/open_48px.png"));
	toolBar->addAction(menuAction);

	menuAction = menu->addAction("&Quit");
	menuAction->setShortcut(QKeySequence("Ctrl+Q"));
	menuAction->setIcon(QIcon("icons/exit_48px.png"));
	toolBar->addAction(menuAction);
	QObject::connect(menuAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	// Edit menu
	menu = this->menuBar()->addMenu("&Edit");

	// Extract menu
	menu = this->menuBar()->addMenu("&Extract");

	// Help menu
	menu = this->menuBar()->addMenu("&Help");
    }
}




