#include "uwuContactsEdit.h"

boolean hasEdited = uwuFalse;

/*---------------------------------------------------------------*/
// function to create the edit UI
void startEditUI(uwuReference reference){
    hasEdited = uwuFalse;

    // get original data from the linked list
    struct UwUContactInformation *currentContact = NULL;
    struct UwUContactNode *temp = uwuContactHeadNode;
    for (index i = 0; i < UwUContactNodeCount; i++){
        if (reference == temp->contact->referenceNumber){
            currentContact = temp->contact;
            break;
        }
        temp = temp->next;
    }

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
    gtk_widget_set_size_request(GTK_WIDGET(uwuEntryFirstName), 600, 0);
    gtk_widget_set_size_request(GTK_WIDGET(uwuEntryLastName), 600, 0);
    gtk_widget_set_size_request(GTK_WIDGET(uwuEntryPhoneNumber), 600, 0);
    gtk_widget_set_size_request(GTK_WIDGET(uwuEntryEmailAddress), 600, 0);
    gtk_widget_set_size_request(GTK_WIDGET(uwuEntryGroup), 600, 0);

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
    gtk_widget_set_halign(GTK_WIDGET(uwuFirstNameBox), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuLastNameBox), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuPhoneNumberBox), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuEmailAddressBox), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuGroupBox), GTK_ALIGN_FILL);

    // modify the labels
    gtk_label_set_label(GTK_LABEL(uwuLabelFirstName), "First name");
    gtk_label_set_label(GTK_LABEL(uwuLabelLastName), "Last name");
    gtk_label_set_label(GTK_LABEL(uwuLabelPhoneNumber), "Phone number");
    gtk_label_set_label(GTK_LABEL(uwuLabelEmailAddress), "Email address");
    gtk_label_set_label(GTK_LABEL(uwuLabelGroup), "Group(s)");
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelFirstName), 260, 40);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelLastName), 260, 40);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelPhoneNumber), 260, 40);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelEmailAddress), 260, 40);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelGroup), 260, 40);
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

    // modify entries
    gtk_widget_set_halign(GTK_WIDGET(uwuEntryFirstName), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuEntryLastName), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuEntryPhoneNumber), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuEntryEmailAddress), GTK_ALIGN_FILL);
    gtk_widget_set_halign(GTK_WIDGET(uwuEntryGroup), GTK_ALIGN_FILL);
    gtk_editable_set_text(GTK_EDITABLE(uwuEntryFirstName), currentContact->firstName);
    gtk_editable_set_text(GTK_EDITABLE(uwuEntryLastName), currentContact->lastName);
    gtk_editable_set_text(GTK_EDITABLE(uwuEntryPhoneNumber), currentContact->phoneNumber);
    gtk_editable_set_text(GTK_EDITABLE(uwuEntryEmailAddress), currentContact->emailAddress);
    gtk_editable_set_text(GTK_EDITABLE(uwuEntryGroup), currentContact->group);
    uwuEditEntries.uwuEntryFirstName = uwuEntryFirstName;
    uwuEditEntries.uwuEntryLastName = uwuEntryLastName;
    uwuEditEntries.uwuEntryPhoneNumber = uwuEntryPhoneNumber;
    uwuEditEntries.uwuEntryEmailAddress = uwuEntryEmailAddress;
    uwuEditEntries.uwuEntryGroup = uwuEntryGroup;

    // entries function
    g_signal_connect(uwuEntryFirstName, "changed", entryEdited, NULL);
    g_signal_connect(uwuEntryLastName, "changed", entryEdited, NULL);
    g_signal_connect(uwuEntryPhoneNumber, "changed", entryEdited, NULL);
    g_signal_connect(uwuEntryEmailAddress, "changed", entryEdited, NULL);
    g_signal_connect(uwuEntryGroup, "changed", entryEdited, NULL);

    // modify bottom field
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldBottom), GTK_ORIENTATION_HORIZONTAL);
    gtk_box_set_homogeneous(GTK_BOX(uwuFieldBottom), TRUE);
    gtk_box_set_homogeneous(GTK_BOX(uwuBottomButtonField), TRUE);

    // modify button
    gtk_widget_set_size_request(GTK_WIDGET(uwuButtonSave), 0, 80);
    gtk_widget_set_size_request(GTK_WIDGET(uwuButtonCancel), 0, 80);
    gtk_widget_set_size_request(GTK_WIDGET(uwuButtonDelete), 0, 80);

    // buttons function
    g_signal_connect(uwuButtonCancel, "clicked", G_CALLBACK(functionButtonCancel), NULL);
}

/*---------------------------------------------------------------*/
// buttons function
void functionButtonSave(){
    string firstName, lastName, phoneNumber, emailAddress, group;
    firstName = gtk_editable_get_chars(GTK_EDITABLE(uwuEditEntries.uwuEntryFirstName), 0, -1);
    lastName = gtk_editable_get_chars(GTK_EDITABLE(uwuEditEntries.uwuEntryLastName), 0, -1);
    phoneNumber = gtk_editable_get_chars(GTK_EDITABLE(uwuEditEntries.uwuEntryPhoneNumber), 0, -1);
    emailAddress = gtk_editable_get_chars(GTK_EDITABLE(uwuEditEntries.uwuEntryEmailAddress), 0, -1);
    group = gtk_editable_get_chars(GTK_EDITABLE(uwuEditEntries.uwuEntryGroup), 0, -1);
}

void functionButtonCancel(){
    if (!(hasEdited))
        startContactsUI();
}

/*---------------------------------------------------------------*/
// entries listen
void entryEdited(){
    hasEdited = uwuTrue;
}