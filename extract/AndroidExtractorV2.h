#ifndef ANDROIDEXTRACTORV2_H
#define ANDROIDEXTRACTORV2_H

#include "AbstractAndroidExtractor.h"

namespace extract
{
    /**
     * This extractor is for Android V2.X
     */
    class AndroidExtractorV2: public AbstractAndroidExtractor
    {
	public:

	    /**
	     * AndroidExtractorV2 class constructor.
	     * @param deviceSerial device serial to find the device with adb tool (see "adb -s ANDROID_SERIAL").
	     * @throws ExtractionException if the device is incompatible with this extractor (depending on OS version).
	     */
	    AndroidExtractorV2(QString deviceSerial) throw(ExtractionException);

	    /**
	     * AndroidExtractorV2 class copy constructor.
	     * @param androidExtractorV2ToCopy AndroidExtractorV2 object to copy.
	     */
	    AndroidExtractorV2(const AndroidExtractorV2& androidExtractorV2ToCopy);

	    /**
	     * AndroidExtractorV2 class destructor.
	     */
	    virtual ~AndroidExtractorV2();

	protected:

	    /**
	     * @see AbstractAndroidExtractor::recoverDBFiles()
	     */
	    virtual void recoverDBFiles() throw(ExtractionException);

	    /**
	     * @see AbstractAndroidExtractor::recoverContactsInDB(datastructure::MobilePhone* mobilePhone)
	     */
	    virtual void recoverContactsInDB(datastructure::MobilePhone* mobilePhone) throw(ExtractionException);

	    /**
	     * @see AbstractAndroidExtractor::recoverFilesInDB(datastructure::MobilePhone* mobilePhone)
	     */
	    virtual void recoverFilesInDB(datastructure::MobilePhone* mobilePhone) throw(ExtractionException);

	    /**
	     * @see AbstractAndroidExtractor::recoverCommunicationsInDB(datastructure::MobilePhone* mobilePhone)
	     */
	    virtual void recoverCommunicationsInDB(datastructure::MobilePhone* mobilePhone) throw(ExtractionException);
    };
}

#endif // ANDROIDEXTRACTORV2_H
