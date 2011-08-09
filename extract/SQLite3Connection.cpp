// ----------------------------------------------------------------------------
// -- Source of Sqlite3Connection class
// -- Namespace: extract
// ----------------------------------------------------------------------------


#include "SQLite3Connection.h"

namespace extract
{
    // -----------------------------------------------------------------
    // -- Constructors and destructors
    // -----------------------------------------------------------------

    SQLite3Connection::SQLite3Connection(QString pathToDatabase) throw(SQLiteException)
    :pathToDatabase(pathToDatabase), database(NULL), exceptionMessageList()
    {
	if( sqlite3_open(this->pathToDatabase.toStdString().c_str() , &this->database) )
	{
	    this->exceptionMessageList.push_back(QString("Can't open database: ").append(sqlite3_errmsg(this->database)));
	    throw SQLiteException(this->pathToDatabase, this->exceptionMessageList.last());
	}
    }

    SQLite3Connection::~SQLite3Connection()
    {
	if(this->database)
	    sqlite3_close(this->database);
    }

    // -----------------------------------------------------------------
    // -- Access methods
    // -----------------------------------------------------------------

    QString SQLite3Connection::getPathToDatabse() const
    {
	return this->pathToDatabase;
    }

    // -----------------------------------------------------------------
    // -- Other methods
    // -----------------------------------------------------------------

    void SQLite3Connection::execQuery(QString query, int (*functionToCall)(void*,int,char**,char**), void* firstArgument) throw(SQLiteException)
    {
	char* sqlMessage = NULL;

	if( sqlite3_exec(this->database, query.toStdString().c_str(), functionToCall, firstArgument, &sqlMessage) != SQLITE_OK )
	{
	    this->exceptionMessageList.push_back(sqlMessage);
	    sqlite3_free(sqlMessage);
	    throw SQLiteException(this->pathToDatabase, this->exceptionMessageList.last());
	}
    }
}
