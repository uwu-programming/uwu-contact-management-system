#include "uwuContactsUI.h"
#include "uwuUserLogin.h"

// function to create the contacts window and widgets
void startContactsUI(GObject *uwuWindow){
    // define variables
    GtkBuilder *uwuBuilder = NULL;
    GObject *uwuWindowBox = NULL;
    GObject *uwuFieldTop = NULL, *uwuFieldBottom = NULL;
    GObject *uwuFieldProfile = NULL, *uwuFieldSearch = NULL, *uwuFieldSetting = NULL;
    GObject *uwuProfileLabel = NULL;

    // create GtkBuilder
    uwuBuilder = gtk_builder_new_from_file("uwuContactsUI.ui");

    // connect the created widget from GtkBuilder
    // link the window box and make it the window's new child
    uwuWindowBox = gtk_builder_get_object(uwuBuilder, "uwuWindowBox");
    gtk_window_set_child(GTK_WINDOW(uwuWindow), GTK_WIDGET(uwuWindowBox));

    // modify uwuWindowBox
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuWindowBox), GTK_ORIENTATION_VERTICAL); // arrange from top to bottom

    // link the top and bottom field (GtkBox)
    uwuFieldTop = gtk_builder_get_object(uwuBuilder, "uwuFieldTop");
    uwuFieldBottom = gtk_builder_get_object(uwuBuilder, "uwuFieldBottom");

    // link the three field on top field
    uwuFieldProfile = gtk_builder_get_object(uwuBuilder, "uwuFieldProfile");
    uwuFieldSearch = gtk_builder_get_object(uwuBuilder, "uwuFieldSearch");
    uwuFieldSetting = gtk_builder_get_object(uwuBuilder, "uwuFieldSetting");
    uwuProfileLabel = gtk_builder_get_object(uwuBuilder, "uwuProfileLabel");

    // modify top and bottom field
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldTop), "uwuContactFieldTop");
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldBottom), "uwuContactFieldBottom");
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldTop), GTK_ORIENTATION_HORIZONTAL);

    // modify profile field
    uwuLabelString *userLabel;
    userLabel = malloc(sizeof(userLabel));
    getCurrentUserLabel(*userLabel);
    gtk_label_set_label(GTK_LABEL(uwuProfileLabel), (const char*)(userLabel));

    // testing
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldProfile), "uwup");
}

void getCurrentUserLabel(string storeTo){
    index i = 0, j = 0;
    string decoration = "Current user: ";

    for (; decoration[i] != '\0'; i++)
        storeTo[i] = decoration[i];
    for (; CURRENT_USER[j] != '\0'; j++)
        storeTo[i++] = CURRENT_USER[j];
    storeTo[i] = '\0';
    printf("%s", storeTo);
}