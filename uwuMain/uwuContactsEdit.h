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

// to determine what type of alert message
typedef int typeOfAlert;
enum EnumTypeOfAlert{
    SAVED = 0,
    EDITED = 1
};

static char *ALERT_MESSAGE[] = {
    "You have sucessfully saved the changes!\nUwU",
    "You still have unsave changes,\ndo you want to abandon the changes?"
};

// to determine which error
typedef int entryError;

enum EnumEntryError{
    NO_ERROR = 0,
    EMPTY_ERROR = 1,
    DUPLICATE_ERROR = 2,
    FORMAT_ERROR = 3
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
void alertWindowUI(typeOfAlert alert);

/*---------------------------------------------------------------*/
// buttons function
// save the edit
void functionButtonSave(GtkWidget *thiButton, struct UwUContactInformation *currentContact);

// cancel and go back to contacts UI
void functionButtonCancel();

void functionButtonDelete();

/*---------------------------------------------------------------*/
// rewrite the file
void rewriteContactFile();

/*---------------------------------------------------------------*/
// entries listen
void entryEdited();

// function for buttons: make the parent window continue listen, and return to certain page
void returnUWUTrue(GtkButton *thisButton, GObject *uwuAlertWindow); // return to contact UI
void returnUWUFalse(GtkButton *thisButton, GObject *uwuAlertWindow); // return to edit UI

/*---------------------------------------------------------------*/
// format verification
// check if it is a valid name
entryError isName(uwuName name, typeOfName firstOrLast);

// check if it is a valid phone number
entryError isPhoneNumber(uwuPhoneNumber phoneNumber, uwuReference reference);

// check if it is a valid email address
entryError isEmailAddress(uwuEmailAddress emailAddress, uwuReference reference);

// check if it is a valid group format
entryError isGroupFormat(uwuName group);

#endif