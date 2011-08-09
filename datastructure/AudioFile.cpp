// ----------------------------------------------------------------------------
// -- Source of AudioFile class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#include "AudioFile.h"

namespace datastructure
{
	// -----------------------------------------------------------------
	// -- Constructors and destructors
	// -----------------------------------------------------------------

	AudioFile::AudioFile(int audioFileID)
	:AbstractPhoneFile(audioFileID)
	{
	}

	AudioFile::AudioFile(const AudioFile& audioFileToCopy)
	:AbstractPhoneFile(audioFileToCopy)
	{
	}

	AudioFile::~AudioFile()
	{
	    // Empty
	}

	// -----------------------------------------------------------------
	// -- Access methods
	// -----------------------------------------------------------------

	void AudioFile::toXml(QDomDocument& doc, QDomNode& node) const
	{
	    QDomElement audioFileNode;

	    audioFileNode = doc.createElement("audioFile");
	    audioFileNode.setAttribute("id", this->getID());
	    this->phoneFileAttributestoXml(doc, audioFileNode);

	    node.appendChild(audioFileNode);
	}

	// -----------------------------------------------------------------
	// -- Other methods
	// -----------------------------------------------------------------

	AbstractPhoneFile* AudioFile::clone() const
	{
	    return new AudioFile(*this);
	}

	// -----------------------------------------------------------------
	// -- Operators
	// -----------------------------------------------------------------

	AudioFile& AudioFile::operator=(const AudioFile& audioFileToCopy)
	{
	    if(this != &audioFileToCopy)
	    {
		AbstractPhoneFile::operator=(audioFileToCopy);
	    }

	    return *this;
	}
}
