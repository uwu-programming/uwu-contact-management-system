#ifndef __UWUUTILITY_H_INCLUDED__ // preprocessor directive check if this header file is include (ifndef stands for if not define)
#define __UWUUTILITY_H_INCLUDED__ // if current header file hasn't been included, define it (source: https://cplusplus.com/forum/articles/10627/)

#include <ctype.h>
#include <string.h>

// constant macro
#define MAX_CHAR_LENGTH 1024

/*---------------------------------------------------------------*/
// custom typedef for easier access and referencing
typedef char* string;
typedef int boolean;
typedef int index;

typedef int uwuReference;
typedef char uwuName[50];
typedef uwuName uwuPassword;
typedef char uwuPhoneNumber[13];
typedef char uwuEmailAddress[321];
typedef char uwuMaxString[MAX_CHAR_LENGTH];

typedef char uwuLabelString[50+20];
typedef char filePath[256];

/*---------------------------------------------------------------*/
// phone format condition
#define PHONE_FORMAT_NUMBER 5
static char *PHONE_FORMAT_START[] = {"01", "011", "03", "08", "0"};
static int PHONE_FORMAT_LENGTH[] = {10, 11, 10, 9, 8};

/*---------------------------------------------------------------*/
// enumeration for true and false
enum UwUBoolean{
    uwuTrue = 1,
    uwuFalse = 0
};

/*---------------------------------------------------------------*/
// check if char x == char y
boolean checkCharEqual(char x, char y);

// check if string x is in string y
boolean checkStringIsIn(string x, string y);

// check size of a string
int sizeOfString(string x);

// remove the extra space in a string
void stringRemoveExtraSpace(string x);

#endif // else, do nothing