#ifndef __UWUUSERLOGIN_H_INCLUDED__
#define __UWUUSERLOGIN_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>

// define constant macro
// constant path to users.csv
#define USERS_CSV "users.csv"

#define READ "r" // macro for reading file
#define WRITE "w" // macro for writing file

// global variables
FILE *uwuUserLoginFile; // FILE pointer to point to users.csv

// structure to store username and correspond password
struct UwUUserLoginDetail{
    char *username;
    char *password;
};

// linked list for userLoginDetail
static int UwUUserNodeCount = 0; // keep track of number of node

// node
struct UwUUserNode{
    struct UwUUserLoginDetail *user;
    struct UwUUserNode *next;
};

// head
struct UwUUserNode *uwuUserHeadNode = NULL;

// create a new node
struct UwUUserNode* createNewNode(char *username, char *password);

// insert node into linked list
void insertNode(struct UwUUserNode **head, char *username, char *password);

#endif