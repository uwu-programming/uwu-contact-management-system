#ifndef __UWUUTILITY_H_INCLUDED__ // preprocessor directive check if this header file is include (ifndef stands for if not define)
#define __UWUUTILITY_H_INCLUDED__ // if current header file hasn't been included, define it (source: https://cplusplus.com/forum/articles/10627/)

// custom typedef for easier access and referencing
typedef char* string;
typedef int boolean;
typedef int index;

typedef char typeName[50];
typedef char typePhoneNumber[13];
typedef char typeEmailAddress[321];
typedef char typeAddress[200];

// enumeration for true and false
enum UwUBoolean{
    uwuTrue = 1,
    uwuFalse = 0
};

// check if char x == char y
boolean checkCharEqual(char x, char y);

#endif // else, do nothing