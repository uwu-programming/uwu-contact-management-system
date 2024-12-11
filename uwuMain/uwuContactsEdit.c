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
    uwuButtonDelete = gtk_builder_get_object(uwuBuilder, "uwuButtonDelete");

    // modify top field
    gtk_label_set_label(GTK_LABEL(uwuTitleTop), "UwU Editing");
    gtk_widget_add_css_class(GTK_WIDGET(uwuTitleTop), "uwuEditTitleTop");

    // modify middle field
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldMid), GTK_ORIENTATION_VERTICAL);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuBoxMid), GTK_ORIENTATION_VERTICAL);
    gtk_box_set_homogeneous(GTK_BOX(uwuBoxMid), TRUE);
    gtk_widget_add_css_class(GTK_WIDGET(uwuFrameMid), "uwuEditFrameMid");

    // modify the labels
    gtk_label_set_label(GTK_LABEL(uwuLabelFirstName), "First name");
    gtk_label_set_label(GTK_LABEL(uwuLabelLastName), "Last name");
    gtk_label_set_label(GTK_LABEL(uwuLabelPhoneNumber), "Phone number");
    gtk_label_set_label(GTK_LABEL(uwuLabelEmailAddress), "Email address");
    gtk_label_set_label(GTK_LABEL(uwuLabelGroup), "Group(s)");
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelFirstName), 260, 0);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelLastName), 260, 0);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelPhoneNumber), 260, 0);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelEmailAddress), 260, 0);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelGroup), 260, 0);
    gtk_label_set_xalign(GTK_LABEL(uwuLabelFirstName), 0);
    gtk_label_set_xalign(GTK_LABEL(uwuLabelLastName), 0);
    gtk_label_set_xalign(GTK_LABEL(uwuLabelPhoneNumber), 0);
    gtk_label_set_xalign(GTK_LABEL(uwuLabelEmailAddress), 0);
    gtk_label_set_xalign(GTK_LABEL(uwuLabelGroup), 0);
    gtk_widget_add_css_class(GTK_WIDGET(uwuLabelFirstName), "uwuEditLabel");
    gtk_widget_add_css_class(GTK_WIDGET(uwuLabelLastName), "uwuEditLabel");
    gtk_widget_add_css_class(GTK_WIDGET(uwuLabelPhoneNumber), "uwuEditLabel");
    gtk_widget_add_css_class(GTK_WIDGET(uwuLabelEmailAddress), "uwuEditLabel");
    gtk_widget_add_css_class(GTK_WIDGET(uwuLabelGroup), "uwuEditLabel");

    // modify bottom field
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldBottom), GTK_ORIENTATION_HORIZONTAL);
    gtk_box_set_homogeneous(GTK_BOX(uwuFieldBottom), TRUE);
    gtk_box_set_homogeneous(GTK_BOX(uwuBottomButtonField), TRUE);

    // modify button
    gtk_widget_set_size_request(GTK_WIDGET(uwuButtonSave), 0, 80);
    gtk_widget_set_size_request(GTK_WIDGET(uwuButtonCancel), 0, 80);
    gtk_widget_set_size_request(GTK_WIDGET(uwuButtonDelete), 0, 80);
}