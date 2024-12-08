#include "uwuUserContact.h"
#include "uwuUtility.h"

// function to create a new contact node
struct UwUContactNode* createNewContactNode(string firstName, string lastName, string phoneNumber, string emailAddress, string address){
    struct UwUContactNode *uwuNewNode = (struct UwUContactNode*)malloc(sizeof(struct UwUContactNode));
    struct UwUContactInformation *uwuNewContact = (struct UwUContactInformation*)malloc(sizeof(struct UwUContactInformation));
}

// read and store all contact from the file
void readContactFromFile(string filePath){
    // variables to store the read value
    typeName firstName, lastName;
    typePhoneNumber phoneNumber;
    typeEmailAddress emailAddress;
    typeAddress address;

    uwuUserContactFile = fopen(filePath, READ);
    if (uwuUserContactFile != NULL){
        uwuReadContactField(firstName);
    }
}

// read a specific field from file
void uwuReadContactField(string storeTo){
    index i = 0;
    char hold = ' ';
    while (fscanf(uwuUserContactFile, "%c", &hold) == 1){
        if (hold == ']'){
            fscanf(uwuUserContactFile, "%c", &hold); // read ',' or '\n'
            break;
        }else if (hold != '['){
            storeTo[i++] = hold;
        }
    }
    storeTo[i] = '\0';
    printf("%s\n", storeTo);
}

int main(){
    string hold;
    uwuUserContactFile = fopen("contacts/uwuSunshine.csv", READ);
    uwuReadContactField(hold);
    uwuReadContactField(hold);
    uwuReadContactField(hold);
    uwuReadContactField(hold);
    uwuReadContactField(hold);
    uwuReadContactField(hold);
    uwuReadContactField(hold);
    uwuReadContactField(hold);
}