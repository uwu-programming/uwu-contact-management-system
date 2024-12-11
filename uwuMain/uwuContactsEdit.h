#ifndef __UWUCONTACTSEDIT_H_INCLUDED__
#define __UWUCONTACTSEDIT_H_INCLUDED__

#include <gtk/gtk.h>

#include "uwuMainUI.h"
#include "uwuContactsUI.h"
#include "uwuUtility.h"
#include "uwuUserContact.h"
#include "uwuUserLogin.h"

// global variable
extern boolean hasEdited;

/*---------------------------------------------------------------*/
// for easier code understanding, create shortcut to determine first or last name
typedef int typeOfName;

enum EnumTypeOfName{
    FIRST_NAME = 0,
    LAST_NAME = 1
};

/*---------------------------------------------------------------*/
// structure to store the entries
static struct UwUContactsEditEntries{
    GObject *uwuEntryFirstName;
    GObject *uwuEntryLastName;
    GObject *uwuEntryPhoneNumber;
    GObject *uwuEntryEmailAddress;
    GObject *uwuEntryGroup;
}uwuEditEntries;

/*---------------------------------------------------------------*/
// function to create the edit UI
void startEditUI(uwuReference reference);

// function to create the alert UI
void alertWindowUI(string alertMessage);

/*---------------------------------------------------------------*/
// buttons function
void functionButtonSave();

void functionButtonCancel();

void functionButtonDelete();

/*---------------------------------------------------------------*/
// entries listen
void entryEdited();

// function for buttons: make the parent window continue listen, and return to certain page
void returnUWUTrue(GtkButton *thisButton, GObject *uwuAlertWindow); // return to contact UI
void returnUWUFalse(GtkButton *thisButton, GObject *uwuAlertWindow); // return to edit UI

/*---------------------------------------------------------------*/
// format verification
// check if it is a valid name
boolean isName(uwuName name, int firstOrLast);

// check if it is a valid phone number
boolean isPhoneNumber(uwuPhoneNumber phoneNumber);

// check if it is a valid email address
boolean isEmailAddress(uwuEmailAddress emailAddress);

// check if the string format is right to be stored
boolean isFormat(string x);

#endif