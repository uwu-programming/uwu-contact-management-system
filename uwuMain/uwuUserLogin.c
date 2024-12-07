#include "uwuUserLogin.h"

// function to create a new node
struct UwUUserNode* createNewNode(string username, string password){
    struct UwUUserNode *uwuNewNode = (struct UwUUserNode*)malloc(sizeof(struct UwUUserNode)); // point to newly created node
    struct UwUUserLoginDetail *uwuNewUser = (struct UwUUserLoginDetail*)malloc(sizeof(struct UwUUserLoginDetail)); // new struct for storing the username and password
    
    // assign the username and password to user login detail struct
    size_t i = 0, j = 0;
    for (; username[i] != '\0'; i++)
        uwuNewUser -> username[i] = username[i];
    uwuNewUser -> username[i] = '\0';

    for (; password[j] != '\0'; j++)
        uwuNewUser -> password[j] = password[j];
    uwuNewUser -> password[j] = '\0';

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
        while(fscanf(uwuUserLoginFile, "%s %s", username, password) == 2){
            addNode(username, password);
        }
    }
}

int main(){
    addNode("aaaadwddwd", "bbbbb");
    addNode( "aaawdda", "bbbbb");
    addNode("aadwdwdaa", "bbbbb");
    readUsersFromFile(USERS_CSV);
    struct UwUUserNode *temp = uwuUserHeadNode;
    while(temp -> next != NULL){
        printf("%s %s\n", temp->user->username, temp -> user -> password);
        temp = temp -> next;
    }
    return 0;
}