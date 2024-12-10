#ifndef __UWUCONTACTSUI_H_INCLUDED__
#define __UWUCONTACTSUI_H_INCLUDED__

#include <gtk/gtk.h>
#include "uwuMainUI.h"
#include "uwuUserLogin.h"
#include "uwuUserContact.h"
#include "uwuUtility.h"

/*---------------------------------------------------------------*/
struct UwUContactButton{
    struct UwUContactInformation *contact;
    GtkWidget *button;
};

extern struct UwUContactButton *uwuContactButtonArray;

/*---------------------------------------------------------------*/
// function to create the contacts UI
void startContactsUI(GObject *uwuWindow);

// function to get label decoration for profile label
void getCurrentUserLabel(string storeTo);

// function to create an array of button according to data in contact linked list
void createContactButtonArray();

// function to remove all buttons from the scroll window
void removeButtonFromWindow(GObject *listbox);

// function to put all button in array to the scroll window
void assembleButtonToWindow(GObject *listBox);

// function to sort name by first name, lexicographical order
void sortContactAscendingName();

#endif