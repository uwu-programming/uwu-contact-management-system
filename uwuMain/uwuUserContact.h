#ifndef __UWUUSERCONTACT_H_INCLUDED__
#define __UWUUSERCONTACT_H_INCLUDED__

#include "uwuUtility.h"
#include "uwuUserLogin.h"

/*---------------------------------------------------------------*/
// constant path to the contact folder
#define PATH_TO_CONTACT_DATA "contacts/"
#define CONTACT_FILE_EXTENSION ".csv"

// global variables
extern FILE *uwuUserContactFile;

/*---------------------------------------------------------------*/
// structure to store a user's contact information
struct UwUContactInformation{
    uwuName firstName;
    uwuName lastName;
    uwuPhoneNumber phoneNumber;
    uwuEmailAddress emailAddress;
    uwuName group;
    uwuReference referenceNumber;
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
static struct UwUContactNode* createNewContactNode(string firstName, string lastName, string phoneNumber, string emailAddress, string group);

// insert new node into contact linked list
static void contactAddNode(string firstName, string lastName, string phoneNumber, string emailAddress, string group);

// function to rewrite a contatc
void contactRewrite(struct UwUContactInformation *thisNode, string firstName, string lastName, string phoneNumber, string emailAddress, string group);

/*---------------------------------------------------------------*/
// read all the contacts from [username].csv and store them into a linked list
void readContactFromFile(string username);

// read a specific field from [username].csv
boolean uwuReadContactField(string storeTo);

#endif