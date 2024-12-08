#include "uwuUserContact.h"
#include "uwuUtility.h"

// function to create a new contact node
struct UwUContactNode* createNewContactNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address){
    struct UwUContactNode *uwuNewNode = (struct UwUContactNode*)malloc(sizeof(struct UwUContactNode));
    struct UwUContactInformation *uwuNewContact = (struct UwUContactInformation*)malloc(sizeof(struct UwUContactInformation));

    uwuNewContact -> firstName = (uwuName*)firstName;
    uwuNewContact -> lastName = (uwuName*)lastName;
    uwuNewContact -> phoneNumber = (uwuPhoneNumber*)phoneNumber;
    uwuNewContact -> emailAddress = (uwuEmailAddress*)emailAddress;
    uwuNewContact -> address = (uwuAddress*)address;

    uwuNewNode -> contact = uwuNewContact;

    return uwuNewNode;
}

// function to insert a new contact node
void contactAddNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address){
    struct UwUContactNode *uwuNewNode = createNewContactNode(firstName, lastName, phoneNumber, emailAddress, address);
    uwuNewNode -> next = uwuContactHeadNode;
    uwuContactHeadNode = uwuNewNode;
    UwUContactNodeCount++;
}

// read and store all contact from the file
void readContactFromFile(string filePath){
    // variables to store the read value
    uwuName *firstName, *lastName;
    uwuPhoneNumber *phoneNumber;
    uwuEmailAddress *emailAddress;
    uwuAddress *address;

    boolean continueReading = uwuTrue; // check if it is EOF

    uwuUserContactFile = fopen(filePath, READ);
    if (uwuUserContactFile != NULL){
        while(continueReading){
            // allocate new address for the string
            firstName = malloc(sizeof(firstName));
            lastName = malloc(sizeof(lastName));
            phoneNumber = malloc(sizeof(phoneNumber));
            emailAddress = malloc(sizeof(emailAddress));
            address = malloc(sizeof(address));

            // read a specific field
            continueReading = uwuReadContactField(*firstName);
            continueReading = uwuReadContactField(*lastName);
            continueReading = uwuReadContactField(*phoneNumber);
            continueReading = uwuReadContactField(*emailAddress);
            continueReading = uwuReadContactField(*address);

            // create a node and insert it to linked list
            contactAddNode(*firstName, *lastName, *phoneNumber, *emailAddress, *address);
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
}