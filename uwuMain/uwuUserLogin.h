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

// constant path to users.csv
#define USERS_CSV "users.csv"

// maximum character store
#define MAX_CHAR_LENGTH 1024

// global variables
static FILE *uwuUserLoginFile; // FILE pointer to point to users.csv
static string CURRENT_USER;

// structure to store username and correspond password
struct UwUUserLoginDetail{
    char username[MAX_CHAR_LENGTH];
    char password[MAX_CHAR_LENGTH];
};

/*---------------------------------------------------------------*/
// linked list for userLoginDetail
static int UwUUserNodeCount = 0; // keep track of number of node

// node
struct UwUUserNode{
    struct UwUUserLoginDetail *user; // the structure for user
    struct UwUUserNode *next; // point to next node
};

// head
static struct UwUUserNode *uwuUserHeadNode = NULL;

// create a new user node
struct UwUUserNode* createNewUserNode(string username, string password);

// insert new node into user linked list
void userAddNode(string username, string password);

/*---------------------------------------------------------------*/
// read all the users from the users.csv and store them into a linked list
void readUsersFromFile(string filePath);

/*---------------------------------------------------------------*/
// check if the input username and password are from a eligible user
boolean checkEligibleLogin(string username, string password);

#endif