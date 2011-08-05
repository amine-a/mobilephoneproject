// ----------------------------------------------------------------------------
// -- Source of SQLiteException class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#include "SQLiteException.h"

using namespace std;

namespace extract
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    SQLiteException::SQLiteException(QString pathToDatabase, QString message) throw()
    :exception(), pathToDatabase(pathToDatabase), message(message)
    {
    }

    SQLiteException::SQLiteException(const SQLiteException& sqliteExceptionToCopy) throw()
    :exception(sqliteExceptionToCopy)
    {
    }

    SQLiteException::~SQLiteException() throw()
    {
	// Empty
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    const char* SQLiteException::what() const throw()
    {
	return QString("Error in the \""+this->pathToDatabase+ "\" database: "+this->message).toStdString().c_str();
    }

    QString SQLiteException::getMessage() const
    {
	return this->message;
    }

    QString SQLiteException::getPathToDatabase() const
    {
	return this->pathToDatabase;
    }
}
