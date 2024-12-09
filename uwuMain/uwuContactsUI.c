#include "uwuContactsUI.h"
#include "uwuUserLogin.h"
#include "uwuUserContact.h"

// function to create the contacts window and widgets
void startContactsUI(GObject *uwuWindow){
    // define variables
    GtkBuilder *uwuBuilder = NULL;
    GObject *uwuWindowBox = NULL;
    GObject *uwuFieldTop = NULL, *uwuFieldBottom = NULL;
    GObject *uwuFieldProfile = NULL, *uwuFieldSearch = NULL, *uwuFieldSetting = NULL;
    GObject *uwuProfileLabel = NULL, *uwuSearchEntry;

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
    uwuSearchEntry = gtk_builder_get_object(uwuBuilder, "uwuSearchEntry");

    // modify top and bottom field
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldTop), "uwuContactFieldTop");
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldBottom), "uwuContactFieldBottom");
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldTop), GTK_ORIENTATION_HORIZONTAL);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldTop), GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldTop), 0, 80);

    // modify profile field
    uwuLabelString *userLabel;
    userLabel = malloc(sizeof(userLabel));
    //getCurrentUserLabel(*userLabel);
    gtk_label_set_label(GTK_LABEL(uwuProfileLabel), CURRENT_USER);
    gtk_widget_set_size_request(GTK_WIDGET(uwuProfileLabel), 200, 0);

    // modify search field
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldSearch), 600, 0);
    gtk_box_set_homogeneous(GTK_BOX(uwuFieldSearch), TRUE);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldSearch), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuSearchEntry), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(uwuSearchEntry), GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(GTK_WIDGET(uwuSearchEntry), 450, 50);

    // modify setting field
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldSetting), 300, 0);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldSetting), GTK_ALIGN_END);

    // testing
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldProfile), "uwup");
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldSetting), "uwusf");
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldSearch), "uwus");
}

void getCurrentUserLabel(string storeTo){
    index i = 0, j = 0;
    string decoration = "Current user: ";

    for (; decoration[i] != '\0'; i++)
        storeTo[i] = decoration[i];
    storeTo[i++] = '\n';
    for (; CURRENT_USER[j] != '\0'; j++)
        storeTo[i++] = CURRENT_USER[j];
    storeTo[i] = '\0';
}