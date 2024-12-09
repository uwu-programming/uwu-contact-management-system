#ifndef __UWUCONTACTSUI_H_INCLUDED__
#define __UWUCONTACTSUI_H_INCLUDED__

#include <gtk/gtk.h>
#include "uwuMainUI.h"
#include "uwuUserLogin.h"
#include "uwuUtility.h"

/*---------------------------------------------------------------*/
// function to create the contacts UI
void startContactsUI(GObject *uwuWindow);

// function to get label decoration for profile label
void getCurrentUserLabel(string storeTo);

// function to create list button according to data in contact linked list

#endif