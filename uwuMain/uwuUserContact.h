#ifndef __UWUUSERCONTACT_H_INCLUDED__
#define __UWUUSERCONTACT_H_INCLUDED__

#include "uwuUtility.h"
#include "uwuUserLogin.h"

/*---------------------------------------------------------------*/
// constant path to the contact folder
#define PATH_TO_CONTACT_DATA "contacts/"

// global variables
static FILE *uwuUserContactFile;

/*---------------------------------------------------------------*/
// structure to store a user's contact information
struct UwUContactInformation{
    typeName firstName;
    typeName lastName;
    typePhoneNumber phoneNumber;
    typeEmailAddress emailAddress;
    typeAddress address;
};

/*---------------------------------------------------------------*/
// linked list for userContact
static int UwUContactNodeCount = 0;

// node
struct UwUContactNode{
    struct UwUContactInformation *contact;
    struct UwUContactNode *next;
};

// head
static struct UwUContactNode *uwuContactHeadNode = NULL;

// create a new contact node
struct UwUContactNode* createNewContactNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address);

// insert new node into contact linked list
void contactAddNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address);

/*---------------------------------------------------------------*/
// read all the contacts from [username].csv and store them into a linked list
void readContactFromFile(string username);

// read a specific field from [username].csv
void uwuReadContactField(string storeTo);

#endif