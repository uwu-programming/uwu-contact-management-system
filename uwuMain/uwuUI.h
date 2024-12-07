#ifndef __UWUUI_H_INCLUDED__ // check if uwuUI.h has been included by specifying a define preprocessor
#define __UWUUI_H_INCLUDED__ // if it is not define, then define it as included, as well as include all the subsequent code below

// include gtk
#include <gtk/gtk.h>
// header for builder UI
#include <glib/gstdio.h>

// global variables
static GtkCssProvider *uwuCssSource; // pointer to css file

// fucntion to create GtkApplication object
int createGTKAPP(int argc, char *argv[]);

// function to start running the app after GtkApplication is created
static void startApp(GtkApplication *uwuApp, gpointer uwuData);

// uwuDebug
static void uwuDebug();

#endif // else, do nothing