#ifndef __UWUCONTACTSEDIT_H_INCLUDED__
#define __UWUCONTACTSEDIT_H_INCLUDED__

#include <gtk/gtk.h>

#include "uwuMainUI.h"
#include "uwuUtility.h"

/*---------------------------------------------------------------*/
// structure to store the entries
struct UwUContactsEditEntries{
    GObject *uwuEntryFirstName;
    GObject *uwuEntryLastName;
    GObject *uwuEntryPhoneNumber;
    GObject *uwuEntryEmailAddress;
    GObject *uwuEntryGroup;
};

/*---------------------------------------------------------------*/
// function to create the edit UI
void startEditUI(uwuReference reference);

#endif