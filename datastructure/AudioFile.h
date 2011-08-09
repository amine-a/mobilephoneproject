// ----------------------------------------------------------------------------
// -- Header of AudioFile class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef AUDIOFILE_H_
#define AUDIOFILE_H_

#include "AbstractPhoneFile.h"

namespace datastructure
{
    /**
     * This class allows to store information about audio files.
     */
    class AudioFile: public AbstractPhoneFile
    {
	public:
	    /**
	     * Audio class constructor.
	     * @param audioFileID identifier of the audio file.
	     */
	    AudioFile(int audioFileID);

	    /**
	     * AudioFile class copy constructor.
	     * @param audioFileToCopy AudioFile object to copy.
	     */
	    AudioFile(const AudioFile& audioFileToCopy);

	    /**
	     * Destructor of AudioFile class.
	     */
	    virtual ~AudioFile();

	    /**
	     * @see AbstractPhoneFile::clone()
	     */
	    virtual AbstractPhoneFile* clone() const;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual AudioFile& operator=(const AudioFile& audioFileToCopy);
    };

}

#endif /* AUDIOFILE_H_ */
