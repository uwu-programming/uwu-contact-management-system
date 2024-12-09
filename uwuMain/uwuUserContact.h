#ifndef __UWUUSERCONTACT_H_INCLUDED__
#define __UWUUSERCONTACT_H_INCLUDED__

#include "uwuUtility.h"
#include "uwuUserLogin.h"

/*---------------------------------------------------------------*/
// constant path to the contact folder
#define PATH_TO_CONTACT_DATA "contacts/"

// global variables
extern FILE *uwuUserContactFile;

/*---------------------------------------------------------------*/
// structure to store a user's contact information
struct UwUContactInformation{
    uwuName firstName;
    uwuName lastName;
    uwuPhoneNumber phoneNumber;
    uwuEmailAddress emailAddress;
    uwuAddress address;
};

/*---------------------------------------------------------------*/
// linked list for userContact
extern int UwUContactNodeCount;

// node
struct UwUContactNode{
    struct UwUContactInformation *contact;
    struct UwUContactNode *next;
};

// head
extern struct UwUContactNode *uwuContactHeadNode;

// create a new contact node
static struct UwUContactNode* createNewContactNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address);

// insert new node into contact linked list
static void contactAddNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address);

/*---------------------------------------------------------------*/
// read all the contacts from [username].csv and store them into a linked list
void readContactFromFile(string username);

// read a specific field from [username].csv
boolean uwuReadContactField(string storeTo);

#endif