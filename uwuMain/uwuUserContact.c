#include "uwuUserContact.h"
#include "uwuUtility.h"

// declare value for extern
int UwUContactNodeCount = 0;
FILE *uwuUserContactFile = NULL;
struct UwUContactNode *uwuContactHeadNode = NULL;

// function to create a new contact node
static struct UwUContactNode* createNewContactNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address){
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
    for (; address[m] != '\0'; m++)
        uwuNewContact -> address[m] = address[m];
    uwuNewContact -> address[m] = '\0';

    uwuNewNode -> contact = uwuNewContact;

    return uwuNewNode;
}

// function to insert a new contact node
static void contactAddNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address){
    struct UwUContactNode *uwuNewNode = createNewContactNode(firstName, lastName, phoneNumber, emailAddress, address);
    uwuNewNode -> next = uwuContactHeadNode;
    uwuContactHeadNode = uwuNewNode;
    UwUContactNodeCount++;
}

// read and store all contact from the file
void readContactFromFile(string filePath){
    // variables to store the read value
    uwuName firstName, lastName;
    uwuPhoneNumber phoneNumber;
    uwuEmailAddress emailAddress;
    uwuAddress address;

    boolean continueReading = uwuTrue; // check if it is EOF

    uwuUserContactFile = fopen(filePath, READ);
    if (uwuUserContactFile != NULL){
        while(continueReading){
            // read a specific field
            continueReading = uwuReadContactField(firstName);
            continueReading = uwuReadContactField(lastName);
            continueReading = uwuReadContactField(phoneNumber);
            continueReading = uwuReadContactField(emailAddress);
            continueReading = uwuReadContactField(address);

            // create a node and insert it to linked list
            contactAddNode(firstName, lastName, phoneNumber, emailAddress, address);
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

/*
int main(){
    index i = 0;
    //uwuUserContactFile = fopen("contacts/uwuSunshine.csv", READ);
    readContactFromFile("contacts/uwuSunshine.csv");
    struct UwUContactNode *temp = uwuContactHeadNode;
    while (i < UwUContactNodeCount){
        printf("%s\n", temp -> contact ->phoneNumber);
        i++;
        temp = temp -> next;
    }
    printf("aaa");
}*/
