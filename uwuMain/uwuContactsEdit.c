#include "uwuContactsEdit.h"

/*---------------------------------------------------------------*/
// function to create the edit UI
void startEditUI(uwuReference reference){
    // define variables
    GtkBuilder *uwuBuilder = NULL;
    GObject *uwuWindowBox = NULL;
    GObject *uwuFieldTop = NULL, *uwuFieldMid = NULL, *uwuFieldBottom = NULL;
    GObject *uwuTitleTop = NULL;
    GObject *uwuFrameMid = NULL, *uwuBoxMid = NULL;
    GObject *uwuFirstNameBox = NULL, *uwuLastNameBox = NULL, *uwuPhoneNumberBox = NULL, *uwuEmailAddressBox = NULL, *uwuGroupBox = NULL;
    GObject *uwuLabelFirstName = NULL, *uwuLabelLastName = NULL, *uwuLabelPhoneNumber = NULL, *uwuLabelEmailAddress = NULL, *uwuLabelGroup = NULL;
    GObject *uwuEntryFirstName = NULL, *uwuEntryLastName = NULL, *uwuEntryPhoneNumber = NULL, *uwuEntryEmailAddress = NULL, *uwuEntryGroup = NULL;
    GObject *uwuBottomSpace = NULL, *uwuBottomButtonField = NULL;
    GObject *uwuButtonSave = NULL, *uwuButtonCancel = NULL, *uwuButtonDelete = NULL;

    // get the new .ui file
    uwuBuilder = gtk_builder_new_from_file("uwuContactsEdit.ui");

    // connect the created widget from GtkBuilder
    // link the window box and make it the window's new child
    uwuWindowBox = gtk_builder_get_object(uwuBuilder, "uwuWindowBox");
    gtk_window_set_child(GTK_WINDOW(uwuWindow), GTK_WIDGET(uwuWindowBox));

    // modify uwuWindowBox
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuWindowBox), GTK_ORIENTATION_VERTICAL);

    // link the top, mid, and bot field
    uwuFieldTop = gtk_builder_get_object(uwuBuilder, "uwuFieldTop");
    uwuFieldMid = gtk_builder_get_object(uwuBuilder, "uwuFieldMid");
    uwuFieldBottom = gtk_builder_get_object(uwuBuilder, "uwuFieldBottom");

    // link the top title
    uwuTitleTop = gtk_builder_get_object(uwuBuilder, "uwuTitleTop");

    // link the widget in mid field
    uwuFrameMid = gtk_builder_get_object(uwuBuilder, "uwuFrameMid");
    uwuBoxMid = gtk_builder_get_object(uwuBuilder, "uwuBoxMid");
    uwuFirstNameBox = gtk_builder_get_object(uwuBuilder, "uwuFirstNameBox");
    uwuLastNameBox = gtk_builder_get_object(uwuBuilder, "uwuLastNameBox");
    uwuPhoneNumberBox = gtk_builder_get_object(uwuBuilder, "uwuPhoneNumberBox");
    uwuEmailAddressBox = gtk_builder_get_object(uwuBuilder, "uwuEmailAddressBox");
    uwuGroupBox = gtk_builder_get_object(uwuBuilder, "uwuGroupBox");

    // label and entry
    uwuLabelFirstName = gtk_builder_get_object(uwuBuilder, "uwuLabelFirstName");
    uwuEntryFirstName = gtk_builder_get_object(uwuBuilder, "uwuEntryFirstName");
    uwuLabelLastName = gtk_builder_get_object(uwuBuilder, "uwuLabelLastName");
    uwuEntryLastName = gtk_builder_get_object(uwuBuilder, "uwuEntryLastName");
    uwuLabelPhoneNumber = gtk_builder_get_object(uwuBuilder, "uwuLabelPhoneNumber");
    uwuEntryPhoneNumber = gtk_builder_get_object(uwuBuilder, "uwuEntryPhoneNumber");
    uwuLabelEmailAddress = gtk_builder_get_object(uwuBuilder, "uwuLabelEmailAddress");
    uwuEntryEmailAddress = gtk_builder_get_object(uwuBuilder, "uwuEntryEmailAddress");
    uwuLabelGroup = gtk_builder_get_object(uwuBuilder, "uwuLabelGroup");
    uwuEntryGroup = gtk_builder_get_object(uwuBuilder, "uwuEntryGroup");

    // link the widget in bottom field
    uwuBottomSpace = gtk_builder_get_object(uwuBuilder, "uwuBottomSpace");
    uwuBottomButtonField = gtk_builder_get_object(uwuBuilder, "uwuBottomButtonField");
    uwuButtonSave = gtk_builder_get_object(uwuBuilder, "uwuButtonSave");
    uwuButtonCancel = gtk_builder_get_object(uwuBuilder, "uwuButtonCancel");
    uwuButtonDelete = gtk_builder_get_object(uwuBuilder, "uwuButtonClose");

    // modify top field
    gtk_label_set_label(GTK_LABEL(uwuTitleTop), "UwU Editing");
    gtk_widget_add_css_class(GTK_WIDGET(uwuTitleTop), "uwuEditTitleTop");

    // modify middle field
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldMid), GTK_ORIENTATION_VERTICAL);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuBoxMid), GTK_ORIENTATION_VERTICAL);
    gtk_widget_add_css_class(GTK_WIDGET(uwuFrameMid), "uwuEditFrameMid");
}