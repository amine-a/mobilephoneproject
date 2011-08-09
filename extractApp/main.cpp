// ----------------------------------------------------------------------------
// -- Test extract namespace
// ----------------------------------------------------------------------------

#include "MobilePhone.h"
#include "AndroidExtractorV2.h"

using namespace std;
using namespace datastructure;
using namespace extract;

/**
 * Extracts the information in the android device.
 * @argc number of arguments.
 * @argv [0] => cmd, [1] => ANDROID_SERIAL, [2] => extraction path
 */
int main(int argc, char* argv[])
{
    AbstractMobilePhoneExtractor* extractor = NULL;
    MobilePhone* mobilePhone = NULL;

    if(argc == 3)
    {
	try
	{
	    extractor = new AndroidExtractorV2( QString(argv[1]) );
	    extractor->setExtractionDir( QString(argv[2]) );
	    mobilePhone = extractor->logicalAcquisition();

	    cout << "==============================================================" << endl;
	    cout << "=== XML" << endl;
	    cout << "==============================================================" << endl;
	    cout << *mobilePhone << endl;

	    cout << "==============================================================" << endl;
	    cout << "=== DEBUG" << endl;
	    cout << "==============================================================" << endl;
	    cout << extractor->getMessageList().join("\n").toStdString() << endl;
	}
	catch(ExtractionException& excep)
	{
	    qDebug() << excep.getMessage();
	}
    }
    else
    {
	qDebug() << "Using: <cmd> <ANDROID_SERIAL> <extraction path>";
    }

    if(extractor)
	delete extractor;

    if(mobilePhone)
	delete mobilePhone;
}
