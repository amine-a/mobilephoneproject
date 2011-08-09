// ----------------------------------------------------------------------------
// -- Header of SQLiteException class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#ifndef SQLITEEXCEPTION_H
#define SQLITEEXCEPTION_H

#include <exception>
#include <sqlite3.h>
#include <QString>

namespace extract
{
    /**
     * Exception for SQLite errors.
     */
    class SQLiteException: public std::exception
    {
	private:
	    QString pathToDatabase;
	    QString message;

	public:
	    /**
	     * SQLiteException constructor.
	     * @param pathToDatabase path to sqlite file where the error is occured.
	     * @param message message to describe the exception.
	     */
	    SQLiteException(QString pathToDatabase, QString message) throw();

	    /**
	     * SQLiteException copy constructor.
	     * @param sqliteExceptionToCopy SQLiteException object to copy.
	     */
	    SQLiteException(const SQLiteException& sqliteExceptionToCopy) throw();

	    /**
	     * ExtractionException class destructor.
	     */
	    virtual ~SQLiteException() throw();

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

	    /**
	     * Allows to get the database name.
	     * @return database name where the error is occured.
	     */
	    QString getPathToDatabase() const;
    };
}

#endif // SQLITEEXCEPTION_H

