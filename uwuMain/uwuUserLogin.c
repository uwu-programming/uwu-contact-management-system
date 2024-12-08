#include "uwuUserLogin.h"

// function to create a new node
struct UwUUserNode* createNewNode(string username, string password){
    struct UwUUserNode *uwuNewNode = (struct UwUUserNode*)malloc(sizeof(struct UwUUserNode)); // point to newly created node
    struct UwUUserLoginDetail *uwuNewUser = (struct UwUUserLoginDetail*)malloc(sizeof(struct UwUUserLoginDetail)); // new struct for storing the username and password
    
    // assign the username and password to user login detail struct
    index i = 0, j = 0;
    for (; username[i] != '\0'; i++)
        uwuNewUser -> username[i] = username[i];
    uwuNewUser -> username[i] = '\0'; // add terminate character

    for (; password[j] != '\0'; j++)
        uwuNewUser -> password[j] = password[j];
    uwuNewUser -> password[j] = '\0'; // add terminate character

    // let the new node's user point to the newly created user struct
    uwuNewNode -> user = uwuNewUser;

    return uwuNewNode; // return the pointer to new node
}

// function to insert a new node (in front)
void addNode(string username, string password){
    struct UwUUserNode *uwuNewNode = createNewNode(username, password); // create a new node
    uwuNewNode -> next = uwuUserHeadNode; // makes the new node's next points to address of head
    uwuUserHeadNode = uwuNewNode; // makes the new node the head
    UwUUserNodeCount++; // increment the node count by 1
}

// read and store all users from the file
void readUsersFromFile(string filePath){
    char username[MAX_CHAR_LENGTH], password[MAX_CHAR_LENGTH];
    uwuUserLoginFile = fopen(USERS_CSV, READ); // open the file

    if (uwuUserLoginFile != NULL){
        // loop until output fscanf is not 2 (didn't read 2 string from files)
        while(fscanf(uwuUserLoginFile, "%s %s", username, password) == 2){
            addNode(username, password); // create a new node of this user data
        }
    }
}

// function to check if the entered username and password are from an eligible user
boolean checkEligibleLogin(string username, string password){
    struct UwUUserNode *tempNode = uwuUserHeadNode; // define a temporary UwUUserNode to traverse through the linked list
    index i = 0; // index to keep track of number of traversed node
    boolean correctUsername = uwuTrue, correctPassword = uwuTrue; // use to keep track if the comparison is right
    boolean validLogin = uwuFalse; // use to check if a right user has appeared
    string nodeUsername, nodePassword; // use to store username and password from node

    // loop all of the node in linked list to compare
    while (i < UwUUserNodeCount && !(validLogin)){
        // reset the boolean value
        correctUsername = uwuTrue; 
        correctPassword = uwuTrue;

        // access the username and password from node
        nodeUsername = tempNode -> user -> username;
        nodePassword = tempNode -> user -> password;

        // iterate and compare username
        for (index namei = 0; (username[namei] != '\0' || nodeUsername[namei] != '\0') && correctUsername; namei++)
            correctUsername = checkCharEqual(username[namei], nodeUsername[namei]);

        // iterate and compare password
        for (index passwordi = 0; (password[passwordi] != '\0' || nodePassword[passwordi] != '\0') && correctPassword; passwordi++)
            correctPassword = checkCharEqual(password[passwordi], nodePassword[passwordi]);

        // check if username and password match any of the one in linked list
        validLogin = (correctUsername == uwuTrue && correctPassword == uwuTrue ? uwuTrue : uwuFalse);
        tempNode = tempNode -> next; // point to next node
        i++; // increment the loop count
    }

    return validLogin;
}