#include <QApplication>

#include "MainWindow.h"
#include "AndroidExtractorV2.h"

using namespace std;
using namespace GUI;
using namespace datastructure;
using namespace extract;

int GUIApp(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();

    return app.exec();
}

int extractorApp(char* pathToDevice, char* extractionPath)
{
    AbstractAndroidExtractor*	androidExtractor;
    MobilePhone*	mobilePhone;

    androidExtractor = new AndroidExtractorV2(QString(pathToDevice));

    try
    {
	mobilePhone = androidExtractor->logicalAcquisition();
	cout << *mobilePhone << endl;

	// androidExtractor->physicalAcquisition(QString(extractionPath));
    }
    catch(ExtractionException& e)
    {
	qDebug() << e.getMessage();
    }

    delete androidExtractor;

    return 0;
}

int main(int argc, char* argv[])
{
    //return dataStructureApp();
    return extractorApp(argv[1], argv[2]);
    //return GUIApp(argc, argv);
}
