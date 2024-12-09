#include "uwuContactsUI.h"

void wwww(){
    printf("uwaaaa");
}

// function to create the contacts window and widgets
void startContactsUI(GObject *uwuWindow){
    // define variables
    GtkBuilder *uwuBuilder = NULL;
    GObject *uwuWindowBox = NULL;
    GObject *uwuFieldTop = NULL, *uwuFieldBottom = NULL;

    // create GtkBuilder
    uwuBuilder = gtk_builder_new_from_file("uwuContactsUI.ui");

    // connect the created widget from GtkBuilder
    // link the window box and make it the window's new child
    uwuWindowBox = gtk_builder_get_object(uwuBuilder, "uwuWindowBox");
    gtk_window_set_child(GTK_WINDOW(uwuWindow), GTK_WIDGET(uwuWindowBox));

    // link the top and bottom field (GtkBox)
    uwuFieldTop = gtk_builder_get_object(uwuBuilder, "uwuFieldTop");
    uwuFieldBottom = gtk_builder_get_object(uwuBuilder, "uwuFieldBottom");

    // modify top and bottom field
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldTop), "uwuContactFieldTop");
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldBottom), "uwuContactFieldBottom");

      GObject *button = gtk_builder_get_object(uwuBuilder, "a");
    g_signal_connect(button, "clicked", G_CALLBACK(wwww), NULL);
}