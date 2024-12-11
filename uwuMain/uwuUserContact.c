#include "uwuUserContact.h"
#include "uwuUtility.h"

// declare value for extern
int UwUContactNodeCount = 0;
FILE *uwuUserContactFile = NULL;
struct UwUContactNode *uwuContactHeadNode = NULL;

// function to create a new contact node
struct UwUContactNode* createNewContactNode(string firstName, string lastName, string phoneNumber, string emailAddress, string group){
    struct UwUContactNode *uwuNewNode = (struct UwUContactNode*)malloc(sizeof(struct UwUContactNode));
    struct UwUContactInformation *uwuNewContact = (struct UwUContactInformation*)malloc(sizeof(struct UwUContactInformation));

    index i = 0, j = 0, k = 0, l = 0, m = 0;
    for (; firstName[i] != '\0'; i++)
        uwuNewContact -> firstName[i] = firstName[i];
    uwuNewContact -> firstName[i] = '\0';
    for (; lastName[j] != '\0'; j++)
        uwuNewContact -> lastName[j] = lastName[j];
    uwuNewContact -> lastName[j] = '\0';
    for (; phoneNumber[k] != '\0'; k++)
        uwuNewContact -> phoneNumber[k] = phoneNumber[k];
    uwuNewContact -> phoneNumber[k] = '\0';
    for (; emailAddress[l] != '\0'; l++)
        uwuNewContact -> emailAddress[l] = emailAddress[l];
    uwuNewContact -> emailAddress[l] = '\0';
    for (; group[m] != '\0'; m++)
        uwuNewContact -> group[m] = group[m];
    uwuNewContact -> group[m] = '\0';

    uwuNewContact -> referenceNumber = UwUContactNodeCount;

    uwuNewNode -> contact = uwuNewContact;

    return uwuNewNode;
}

// function to insert a new contact node
static void contactAddNode(string firstName, string lastName, string phoneNumber, string emailAddress, string group){
    struct UwUContactNode *uwuNewNode = createNewContactNode(firstName, lastName, phoneNumber, emailAddress, group);
    uwuNewNode -> next = uwuContactHeadNode;
    uwuContactHeadNode = uwuNewNode;
    UwUContactNodeCount++;
}

// function to rewrite values in a contact
void contactRewrite(struct UwUContactInformation *thisNode, string firstName, string lastName, string phoneNumber, string emailAddress, string group){
    index i = 0, j = 0, k = 0, l = 0, m = 0;
    for (; firstName[i] != '\0'; i++)
        thisNode -> firstName[i] = firstName[i];
    thisNode -> firstName[i] = '\0';
    for (; lastName[j] != '\0'; j++)
        thisNode -> lastName[j] = lastName[j];
    thisNode -> lastName[j] = '\0';
    for (; phoneNumber[k] != '\0'; k++)
        thisNode -> phoneNumber[k] = phoneNumber[k];
    thisNode -> phoneNumber[k] = '\0';
    for (; emailAddress[l] != '\0'; l++)
        thisNode -> emailAddress[l] = emailAddress[l];
    thisNode -> emailAddress[l] = '\0';
    for (; group[m] != '\0'; m++)
        thisNode -> group[m] = group[m];
    thisNode -> group[m] = '\0';
}

// read and store all contact from the file
void readContactFromFile(string username){
    filePath path;
    index i = 0, j = 0, k = 0;
    for (; PATH_TO_CONTACT_DATA[i] != '\0'; i++)
        path[i] = PATH_TO_CONTACT_DATA[i];
    for (; username[j] != '\0'; j++)
        path[i++] = username[j];
    for (; CONTACT_FILE_EXTENSION[k] != '\0'; k++)
        path[i++] = CONTACT_FILE_EXTENSION[k];
    path[i] = '\0';

    // variables to store the read value
    uwuName firstName, lastName;
    uwuPhoneNumber phoneNumber;
    uwuEmailAddress emailAddress;
    uwuName group;

    boolean continueReading = uwuTrue; // check if it is EOF

    uwuUserContactFile = fopen(path, READ);
    if (uwuUserContactFile != NULL){
        while(continueReading){
            // read a specific field
            continueReading = uwuReadContactField(firstName);
            continueReading = uwuReadContactField(lastName);
            continueReading = uwuReadContactField(phoneNumber);
            continueReading = uwuReadContactField(emailAddress);
            continueReading = uwuReadContactField(group);

            // create a node and insert it to linked list
            contactAddNode(firstName, lastName, phoneNumber, emailAddress, group);
        }
    }
}

// read a specific field from file
boolean uwuReadContactField(string storeTo){
    index i = 0;
    char hold = ' ';
    while (fscanf(uwuUserContactFile, "%c", &hold) == 1){
        if (hold == ']'){
            storeTo[i] = '\0';
            hold = getc(uwuUserContactFile); // read ',' or '\n'
            // check if it is end of file
            if (hold == EOF)
                return uwuFalse; // if so, return false and stop reading
            else
                break; // else, just break the loop and proceed to next field
        }else if (hold != '['){
            storeTo[i++] = hold;
        }
    }
    return uwuTrue;
}