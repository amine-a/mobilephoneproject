// ----------------------------------------------------------------------------
// -- Source of ExtractionException class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#include "ExtractionException.h"

using namespace std;

namespace extract
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    ExtractionException::ExtractionException(QString message) throw()
    :exception(), message(message)
    {
    }

    ExtractionException::ExtractionException(const ExtractionException& extractionException) throw()
    :exception(extractionException), message(extractionException.message)
    {
    }

    ExtractionException::~ExtractionException() throw()
    {
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString ExtractionException::getMessage() const
    {
	return this->message;
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    const char* ExtractionException::what() const throw()
    {
	return this->message.toStdString().c_str();
    }
}

