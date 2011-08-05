
// ----------------------------------------------------------------------------
// -- Header of AbstractMobilePhoneObject class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef ABSTRACTMOBILEPHONEOBJECT_H
#define ABSTRACTMOBILEPHONEOBJECT_H

#include <iostream>
#include <QDebug>
#include <QString>
#include <QtXml/QDomDocument>

namespace datastructure
{
    /**
     * The AbstractMobilePhoneObject class is the base class of all object of datastructure namespace.
     */
    class AbstractMobilePhoneObject
    {
	private:
	    int	    objectID;
	    bool    deleted;

	protected:
	    /**
	     * Adds a text in the node in the xml format.
	     * If the text is empty, this function does anything.
	     * @param text text to add in the node.
	     * @param name name of the new xml element.
	     * @param doc QDomDocument object.
	     * @param node node where add new elements.
	     */
	    void textToXml(QString text, QString name, QDomDocument& doc, QDomNode& node) const;

	public:
	    /**
	     * AbstractMobilePhoneObject class constructor without parameters.
	     */
	    AbstractMobilePhoneObject();

	    /**
	     * AbstractMobilePhoneObject class constructor with parameter.
	     * @param objectID identifier of the object.
	     */
	    AbstractMobilePhoneObject(int objectID);

	    /**
	     * AbstractMobilePhoneObject class copy constructor.
	     */
	    AbstractMobilePhoneObject(const AbstractMobilePhoneObject& mobilePhoneObject);

	    /**
	     *  AbstractMobilePhoneObject class destructor.
	     */
	    virtual ~AbstractMobilePhoneObject();

	    /**
	     * Allows to get the identifier of the object.
	     * @return object ID.
	     */
	    int getID() const;

	    /**
	     * Changes the value of the identifier of the object.
	     * @param objectID new value of object ID.
	     */
	    void setID(int objectID);

	    /**
	     * Allows to know if the object is deleted.
	     * @return true if the object is deleted, else false.
	     */
	    bool isDeleted() const;

	    /**
	     * Changes the value of deleted attribute.
	     * @param deleted new value of deleted attribute.
	     */
	    void setDeleted(bool deleted);

	    /**
	     * Adds information about the object in the QDomDocument object.
	     * This method must be implemented in subclasses.
	     * @param doc QDomDocument object.
	     * @param node node where add new elements.
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const = 0;

	    /**
	     * Affectation operator for AbstractMobilePhoneObject class.
	     * @param mobilePhoneObject AbstractMobilePhoneObject to copy.
	     * @return affected AbstractMobilePhoneObject.
	     */
	    virtual AbstractMobilePhoneObject& operator=(const AbstractMobilePhoneObject& mobilePhoneObject);
    };

    /**
      * Output flux operator for AbstractMobilePhoneObject class.
      * @param flux ouput flux.
      * @param mobilePhoneObject object to send into the flux.
      * @return display flux.
      */
    std::ostream& operator<<(std::ostream &flux,  const AbstractMobilePhoneObject& mobilePhoneObject);
}

#endif // ABSTRACTMOBILEPHONEOBJECT_H
