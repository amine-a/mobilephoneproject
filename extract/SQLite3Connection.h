// ----------------------------------------------------------------------------
// -- Header of SQLite3Connection class
// -- Namespace: extract
// ----------------------------------------------------------------------------

#ifndef SQLITE3CONNECTION_H
#define SQLITE3CONNECTION_H

#include <sqlite3.h>
#include <QStringList>

#include "SQLiteException.h"

namespace extract
{
    /**
     * This class allows to connect to the SQlite database.
     * Uses the sqlite3 library.
     */
    class SQLite3Connection
    {
	private:
	    QString	    pathToDatabase;
	    sqlite3*	    database;
	    QStringList	    exceptionMessageList;

	public:

	    /**
	     * SQLite3Connection class constructor.
	     * @param pathToDatabase path to the sqlite file.
	     * @throws SQLiteException if the database connection can not be open.
	     */
	    SQLite3Connection(QString pathToDatabase) throw(SQLiteException);

	    /**
	     * SQLite3Connection class destructor.
	     * Closes the database connection.
	     */
	    virtual ~SQLite3Connection();

	    /**
	     * Allows to get the path to the database.
	     * @return path to the sqlite file.
	     */
	    QString getPathToDatabse() const;

	    /**
	     * Executes the query in the database.
	     * @param query query to be executed in the database.
	     * @param functionToCall function to call to manage the results query (for more information see the SQLite documentatin about callback in sqlite3_exec).
	     * @param firstArgument first argument to functionToCall.
	     * @throws SQLiteException if there are a error during the query execution.
	     */
	    void execQuery(QString query, int (*functionToCall)(void*,int,char**,char**), void* firstArgument) throw(SQLiteException);
    };
}

#endif // SQLITE3CONNECTION_H
