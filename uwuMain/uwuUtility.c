#include <stdio.h>
#include "uwuUtility.h"

// check if char x == char y
boolean checkCharEqual(char x, char y){
    return (x == y ? uwuTrue : uwuFalse);
}

// check if string x is in string y
boolean checkStringIsIn(string x, string y){
    boolean isIn = uwuFalse;
    char holdX, holdY;
    int sizeX, sizeY;
    sizeX = sizeOfString(x);
    sizeY = sizeOfString(y);

    index i = 0, j = 0;
    for (i; i < sizeY && j < sizeX; i++){
        holdX = x[j];
        holdY = y[i];

        if (holdX >= 'A' && holdX <= 'Z')
            holdX += 32;
        if (holdY >= 'A' && holdY <= 'Z')
            holdY += 32;

        if (holdX == holdY){
            j++;
        }else{
            j = 0;
        }
    }
    return (j == sizeX ? uwuTrue : uwuFalse);
}

// check the size of string
int sizeOfString(string x){
    index i;
    for (i = 0; x[i] !='\0'; i++);
    return i;
}

// remove extra space in a string
void stringRemoveExtraSpace(string x){
    for (index i = 0; x[i] != '\0'; i++){
        if ((x[i] == ' ' && (x[i+1] == ' ' || x[i+1] == '\0')) || x[0] == ' '){
            for (index j = i; x[j] != '\0'; j++){
                x[j] = x[j+1];
            }
            i--;
        }
    }
}