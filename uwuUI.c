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
    // define variables
    GtkBuilder *uwuBuilder = NULL; // GtkBuilder pointer
    GObject *uwuWindow = NULL; // pointer for window widget
    GObject *uwuWindowBox = NULL; // pointer for window's child, the box layout
    GObject *uwuLabelName = NULL, *uwuEntryName = NULL; // pointer for name's label and text field widget

    // create a GtkBuilder object and store it to uwuBuilder
    uwuBuilder = gtk_builder_new();
    gtk_builder_add_from_file(uwuBuilder, "uwuMainUI.ui", NULL); // add the main ui GtkBuilder.ui file into the object

    // connect the created widget to GtkBuilder object
    // create the window widget
    uwuWindow = gtk_builder_get_object(uwuBuilder, "uwuWindow");
    gtk_window_set_application(GTK_WINDOW(uwuWindow), uwuApp);

    // get the box widget
    uwuWindowBox = gtk_builder_get_object(uwuBuilder, "uwuWindowBox");
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuWindowBox), GTK_ORIENTATION_VERTICAL);

    // create an entry field with label for insert username
    uwuLabelName = gtk_builder_get_object(uwuBuilder, "uwuLabelName");
    gtk_label_set_label(GTK_LABEL(uwuLabelName), "it is uwu time");
    printf("%s\n", gtk_label_get_text(GTK_LABEL(uwuLabelName)));
    uwuEntryName = gtk_builder_get_object(uwuBuilder, "uwuEntryName");
    g_signal_connect(uwuEntryName, "changed", G_CALLBACK(uwuDebug), NULL);

    // make window visible
    gtk_widget_set_visible(GTK_WIDGET(uwuWindow), TRUE);

    // free the builder object
    g_object_unref(uwuBuilder);
}

// test function for debug use
static void uwuDebug(){
    printf("uwu\n");
}