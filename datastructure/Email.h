// ----------------------------------------------------------------------------
// -- Header of Email class
// -- Namespace: datastructure
// ----------------------------------------------------------------------------

#ifndef EMAIL_H_
#define EMAIL_H_

#include "AbstractCommunication.h"
#include "EmailAddress.h"

namespace datastructure
{
    /**
     * This class allows to manage email communications.
     */
    class Email: public AbstractCommunication
    {
	protected:
	    QString		    displayName;
	    QString		    subject;
	    QString		    body;

	    QList<EmailAddress*>    fromList;
	    QList<EmailAddress*>    toList;
	    QList<EmailAddress*>    ccList;
	    QList<EmailAddress*>    cciList;

	    static void copyEmailAddressList(QList<EmailAddress *>& emailAddressListDest, const QList<EmailAddress *> &emailAddressListToCopy);
	    static void copyEmailAddressListWithAddressBook(QList<EmailAddress *>& emailAddressListDest, const QList<EmailAddress *> &emailAddressListToCopy, const AddressBook& addressBook);
	    static void emailAddressListToXml(const QList<EmailAddress*>& emailAddressList, QString name, QDomDocument& doc, QDomNode& node);
	    void freeMemory();

	public:
	    /**
	     * Email class constructor.
	     * @param emailID identifier of email.
	     */
	    Email(int emailID);

	    /**
	     * Copy constructor of Email class.
	     * @param emailToCopy Email object to copy.
	     * @param copyEmailAddresses if true copy the email address lists.
	     */
	    Email(const Email& emailToCopy, bool copyEmailAddresses=true);

	    /**
	     * Email class destructor.
	     */
	    virtual ~Email();

	    /**
	     * Allows to access of email subject (object of email).
	     * @return email subject.
	     */
	    QString getSubject() const;

	    /**
	     * Changes the subject value.
	     * @param subject new subject value.
	     */
	    void setSubject(QString subject);

	    /**
	     * Allows to access of email body.
	     * @return email body.
	     */
	    QString getBody() const;

	    /**
	     * Changes the body value.
	     * @param body new body value.
	     */
	    void setBody(QString body);

	    /**
	     * Allows to access of email display name.
	     * @return email display name.
	     */
	    QString getDisplayName() const;

	    /**
	     * Changes the display name value.
	     * @param displayName new display name value.
	     */
	    void setDisplayName(QString displayName);

	    /**
	     * Allows to access of the fromList.
	     * @return email address list.
	     */
	    const QList<EmailAddress*>& getFromList() const;

	    /**
	     * Adds a email address to the fromList.
	     * @param emailAddress email address to add.
	     */
	    void addInFromList(EmailAddress* emailAddress);

	    /**
	     * Allows to access of the toList.
	     * @return email address list.
	     */
	    const QList<EmailAddress*>& getToList() const;

	    /**
	     * Adds a email address to the toList.
	     * @param emailAddress email address to add.
	     */
	    void addInToList(EmailAddress* emailAddress);

	    /**
	     * Allows to access of the ccList.
	     * @return email address list.
	     */
	    const QList<EmailAddress*>& getCCList() const;

	    /**
	     * Adds a email address to the ccList.
	     * @param emailAddress email address to add.
	     */
	    void addInCCList(EmailAddress* emailAddress);

	    /**
	     * Allows to access of the cciList.
	     * @return email address list.
	     */
	    const QList<EmailAddress*>& getCCIList() const;

	    /**
	     * Adds a email address to the cciList.
	     * @param emailAddress email address to add.
	     */
	    void addInCCIList(EmailAddress* emailAddress);

	    /**
	     * @see AbstractCommunication::clone()
	     */
	    virtual AbstractCommunication* clone() const;

	    /**
	     * @see AbstractCommunication::cloneWithNewAddressBook(const AddressBook& addressBook)
	     */
	    virtual AbstractCommunication* cloneWithNewAddressBook(const AddressBook& addressBook) const;

	    /**
	     * @see AbstractMobilePhoneObject::toXml()
	     */
	    virtual void toXml(QDomDocument& doc, QDomNode& node) const;

	    /**
	     * @see AbstractMobilePhoneObject::operator=()
	     */
	    virtual Email& operator=(const Email& emailToCopy);
    };
}

#endif /* EMAIL_H_ */
