// ----------------------------------------------------------------------------
// -- Test datastructure namespace
// ----------------------------------------------------------------------------

#include "MobilePhone.h"
#include "Call.h"
#include "SMS.h"
#include "Email.h"
#include "Picture.h"
#include "Document.h"

using namespace std;
using namespace datastructure;

void addContacts(MobilePhone* mobilePhone)
{
    Contact* contact;

    contact = new Contact(1);
    contact->setName("FirstName LastName");
    contact->addPhoneNumber("0000000000");
    contact->addEmailAddress("LastName@gmail.com");

    mobilePhone->getAddressBook().addContact(contact);
}

void addCommunications(MobilePhone* mobilePhone)
{
    Call* call;
    SMS* sms;
    Email* email;
    PhoneNumber* phoneNumber;
    EmailAddress* emailAddress;

    call = new Call(1);
    call->setDuration(QTime(0, 1, 0));
    call->setDate(QDate::currentDate());
    call->setStatus(AbstractCommunication::DIALLED_STATUS);
    call->setIncoming(true);
    phoneNumber = mobilePhone->getAddressBook().findPhoneNumber("0000000000");

    if(phoneNumber != NULL)
	call->addPhoneNumber(phoneNumber);

    mobilePhone->getCommunicationManager().addCommunication(call);

    sms = new SMS(2);
    sms->setContent("Hello SMS !!");
    sms->setDate(QDate::currentDate());
    sms->setStatus(AbstractCommunication::SENT_STATUS);
    sms->setIncoming(false);
    sms->addPhoneNumber(new PhoneNumber("0000000001"));
    mobilePhone->getCommunicationManager().addCommunication(sms);

    email = new Email(3);
    email->setSubject("Super Hello");
    email->setBody("Hello Email !!");
    email->setDate(QDate::currentDate());
    email->setStatus(AbstractCommunication::RECEIVED_STATUS);
    email->setIncoming(true);
    emailAddress = mobilePhone->getAddressBook().findEmailAddress("LastName@gmail.com");

    if(emailAddress != NULL)
	email->addInFromList(emailAddress);

    email->addInCCList(new EmailAddress("cc@gmail.com"));
    email->addInCCIList(new EmailAddress("cci@gmail.com"));
    email->addInToList(new EmailAddress("to@gmail.com"));

    mobilePhone->getCommunicationManager().addCommunication(email);
}

void addPhoneFiles(MobilePhone* mobilePhone)
{
    Picture* picture;
    Document* document;

    picture = new Picture(1);
    picture->setPath("/data/local/tmp");
    picture->setName("picture1.png");
    picture->setSize(100);
    picture->setCreatedDate(QDate::currentDate());
    mobilePhone->getPhoneFileManager().addPhoneFile(picture);

    document = new Document(2);
    document->setPath("/data/local/tmp");
    document->setName("document1.png");
    document->setSize(1000);
    document->setCreatedDate(QDate::currentDate());
    mobilePhone->getPhoneFileManager().addPhoneFile(document);
}

int main(int argc, char* argv[])
{
    argc = 0; // Not used
    argv = NULL; // Not used

    MobilePhone* mobilePhone;
    MobilePhone* copyMobilePhone;


    mobilePhone = new MobilePhone("Nokia N95-2 8GB");
    mobilePhone->setMobileID("356983013130486");
    mobilePhone->setSubscriberID("272017210752529");
    mobilePhone->setModel("Nokia N00");

    addContacts(mobilePhone);
    addPhoneFiles(mobilePhone);
    addCommunications(mobilePhone);

    copyMobilePhone = new MobilePhone(*mobilePhone);

    cout << *mobilePhone << endl;

    delete mobilePhone;
    delete copyMobilePhone;

    return 0;
}
