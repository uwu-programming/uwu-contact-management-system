#include "uwuUserLogin.h"

// function to create a new node
struct UwUUserNode* createNewNode(char *username, char *password){
    struct UwUUserNode *uwuNewNode = (struct UwUUserNode*)malloc(sizeof(struct UwUUserNode)); // point to newly created node
    struct UwUUserLoginDetail *uwuNewUser = (struct UwUUserLoginDetail*)malloc(sizeof(struct UwUUserLoginDetail)); // new struct for storing the username and password
    
    // assign the username and password to user login detail struct
    uwuNewUser -> username = username;
    uwuNewUser -> password = password;

    // let the new node's user point to the newly created user struct
    uwuNewNode -> user = uwuNewUser;

    return uwuNewNode; // return the pointer to new node
}

// function to insert a new node (in front)
void insertNode(struct UwUUserNode **head, char *username, char *password){
    struct UwUUserNode *uwuNewNode = createNewNode(username, password); // create a new node
    uwuNewNode -> next = *head; // makes the new node's next points to address of head
    *head = uwuNewNode; // makes the new node the head
}

int main(){
    insertNode(&uwuUserHeadNode, "aaaa", "bbbbb");
    insertNode(&uwuUserHeadNode, "aaaa", "bbbbb");
    insertNode(&uwuUserHeadNode, "aaaa", "bbbbb");
    struct UwUUserNode *temp = uwuUserHeadNode;
    while(temp != NULL){
        printf("%saaaa\n", temp->user->username);
        temp = temp -> next;
    }
    return 0;
}