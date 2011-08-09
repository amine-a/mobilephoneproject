// ----------------------------------------------------------------------------
// -- Header of ExtractionException class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#ifndef EXTRACTIONEXCEPTION_H
#define EXTRACTIONEXCEPTION_H

#include <QString>
#include <iostream>
#include <exception>

namespace extract
{
    /**
     * Exception for extraction error of the mobile phone data.
     */
    class ExtractionException: public std::exception
    {
	private:
	    QString	message;

	public:

	    /**
	     * ExtractionException class constructor.
	     * @param message message to describe the exception.
	     */
	    ExtractionException(QString message) throw();

	    /**
	     * ExtractionException class copy constructor.
	     * @param extractionException instance of ExtractionException to copy.
	     */
	    ExtractionException(const ExtractionException& extractionException) throw();

	    /**
	     * ExtractionException class destructor.
	     */
	    virtual ~ExtractionException() throw();

	    /**
	     * Allows to have a description of the exception.
	     * @return a null terminated character sequence containing a generic description of the exception.
	     */
	    virtual const char* what() const throw();

	    /**
	     * Allows to get a message to describe the exception.
	     * @return message to describe the exception.
	     */
	    QString getMessage() const;
    };
}

#endif // EXTRACTIONEXCEPTION_H
