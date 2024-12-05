#include "uwuUI.h"

// main function: creating the root of application (GtkApplication object)
createGTKAPP(int argc, char *argv[]){
    // define variables
    int status = 0; // int status to be returned to console (check if any error happened)
    GtkApplication *uwuApp = NULL; // GtkApplication pointer to store GtkApplication object later

    // create a GtkApplication pointer and store it in "uwuApp"; "com.uwu.contactmanagement" is our application ID
    uwuApp = gtk_application_new("com.uwu.contactmanagement", G_APPLICATION_DEFAULT_FLAGS);


    g_object_unref(uwuApp); // free the object from memory after the app is closed
    return status;
}