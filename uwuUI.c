#include "uwuUI.h"

// main function: creating the root of application (GtkApplication object)
int createGTKAPP(int argc, char *argv[]){
    // define variables
    int status = 0; // int status to be returned to console (check if any error happened)
    GtkApplication *uwuApp = NULL; // GtkApplication pointer to store GtkApplication object later

    // create a GtkApplication pointer and store it in "uwuApp"; "com.uwu.contactmanagement" is our application ID
    uwuApp = gtk_application_new("com.uwu.contactmanagement", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(uwuApp, "activate", G_CALLBACK(startApp), NULL); // make uwuApp listen for the event "activate" (when the app is created); call startApp when "activate" happens; no argument pass to the function
    status = g_application_run(G_APPLICATION(uwuApp), argc, argv); // used when the app is run from console with arguments

    g_object_unref(uwuApp); // free the object from memory after the app is closed
    return status; // return program status to console
}

// function to create the main window and widgets
static void startApp(GtkApplication *uwuApp, gpointer uwuData){
    // create GtkBuilder pointer to
    GtkBuilder *uwuBuilder = gtk_builder_new();
    gtk_builder_add_from_file(uwuBuilder, "uwuMainUI.ui", NULL);
}