#ifndef __UWUUSERLOGIN_H_INCLUDED__
#define __UWUUSERLOGIN_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uwuUtility.h"

/*---------------------------------------------------------------*/
// define constant macro

#define READ "r" // macro for reading file
#define WRITE "w" // macro for writing file
#define APPEND "a" // macro for appending file

// constant path to users.csv
#define USERS_CSV "users.csv"

// global variables
extern FILE *uwuUserLoginFile; // FILE pointer to point to users.csv
extern string CURRENT_USER;

// structure to store username and correspond password
struct UwUUserLoginDetail{
    uwuName username;
    uwuPassword password;
};

/*---------------------------------------------------------------*/
// linked list for userLoginDetail
extern int UwUUserNodeCount; // keep track of number of node

// node
struct UwUUserNode{
    struct UwUUserLoginDetail *user; // the structure for user
    struct UwUUserNode *next; // point to next node
};

// head
extern struct UwUUserNode *uwuUserHeadNode;

// create a new user node
static struct UwUUserNode* createNewUserNode(string username, string password);

// insert new node into user linked list
static void userAddNode(string username, string password);

/*---------------------------------------------------------------*/
// read all the users from the users.csv and store them into a linked list
void readUsersFromFile(string filePath);

/*---------------------------------------------------------------*/
// check if the input username and password are from a eligible user
boolean checkEligibleLogin(string username, string password);

#endif