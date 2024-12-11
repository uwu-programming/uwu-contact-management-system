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
    g_signal_connect(uwuButtonSave, "clicked", G_CALLBACK(functionButtonSave), NULL);
    g_signal_connect(uwuButtonCancel, "clicked", G_CALLBACK(functionButtonCancel), NULL);
}

/*---------------------------------------------------------------*/
// the alert UI
void alertWindowUI(string alertMessage){
    gtk_widget_set_sensitive(GTK_WIDGET(uwuWindow), FALSE);

    GtkBuilder *uwuBuilder = NULL;
    GObject *uwuAlertWindow = NULL, *uwuWindowBox = NULL;
    GObject *uwuFieldTop = NULL, *uwuFieldBottom = NULL;
    GObject *uwuLabelAlert = NULL;
    GObject *uwuConfirmButton = NULL, *uwuCancelButton = NULL;

    uwuBuilder = gtk_builder_new_from_file("uwuAlertUI.ui");
    
    uwuAlertWindow = gtk_builder_get_object(uwuBuilder, "uwuWindow");
    uwuWindowBox = gtk_builder_get_object(uwuBuilder, "uwuWindowBox");

    uwuFieldTop = gtk_builder_get_object(uwuBuilder, "uwuFieldTop");
    uwuFieldBottom = gtk_builder_get_object(uwuBuilder, "uwuFieldBottom");

    uwuLabelAlert = gtk_builder_get_object(uwuBuilder, "uwuLabelAlert");
    uwuConfirmButton = gtk_builder_get_object(uwuBuilder, "uwuConfirmButton");
    uwuCancelButton = gtk_builder_get_object(uwuBuilder, "uwuCancelButton");

    gtk_window_set_resizable(GTK_WINDOW(uwuAlertWindow), FALSE);
    gtk_window_set_default_size(GTK_WINDOW(uwuAlertWindow), 300, 200);
    gtk_window_set_title(GTK_WINDOW(uwuAlertWindow), "UwU Alert!");

    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldTop), 0, 150);
    gtk_box_set_homogeneous(GTK_BOX(uwuFieldBottom), TRUE);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuWindowBox), GTK_ORIENTATION_VERTICAL);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldBottom), GTK_ORIENTATION_HORIZONTAL);

    gtk_label_set_label(GTK_LABEL(uwuLabelAlert), alertMessage);
    gtk_button_set_label(GTK_BUTTON(uwuConfirmButton), "Yes");
    gtk_button_set_label(GTK_BUTTON(uwuCancelButton), "No");
    g_signal_connect(uwuConfirmButton, "clicked", G_CALLBACK(returnUWUTrue), uwuAlertWindow);
    g_signal_connect(uwuCancelButton, "clicked", G_CALLBACK(returnUWUFalse), uwuAlertWindow);

    g_signal_connect(uwuAlertWindow, "close-request", G_CALLBACK(returnUWUFalse), uwuAlertWindow);

    gtk_window_present(GTK_WINDOW(uwuAlertWindow));
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

    printf("%d??", isPhoneNumber(phoneNumber));
}

void functionButtonCancel(){
    if (!(hasEdited))
        startContactsUI();
    else
        alertWindowUI("You still have unsave changes,\ndo you want to abandon the changes?");
}

/*---------------------------------------------------------------*/
// entries listen
void entryEdited(){
    hasEdited = uwuTrue;
}

/*---------------------------------------------------------------*/
// function for buttons: make the parent window continue listen, and return to certain page
// return to contact UI
void returnUWUTrue(GtkButton *thisButton, GObject *uwuAlertWindow){
    gtk_window_destroy(GTK_WINDOW(uwuAlertWindow));
    gtk_widget_set_sensitive(GTK_WIDGET(uwuWindow), TRUE);
    startContactsUI();
}

// return to edit UI
void returnUWUFalse(GtkButton *thisButton, GObject *uwuAlertWindow){
    gtk_window_destroy(GTK_WINDOW(uwuAlertWindow));
    gtk_widget_set_sensitive(GTK_WIDGET(uwuWindow), TRUE);
}

/*---------------------------------------------------------------*/
// check if the string is name format
boolean isName(uwuName name, typeOfName firstOrLast){
    // remove extra ' '
    for (index i = 0; name[i] != '\0'; i++){
        if ((name[i] == ' ' && name[i+1] == ' ') || name[0] == ' '){
            for (index j = i; name[j] != '\0'; j++){
                name[j] = name[j+1];
            }
            i--;
        }
    }
    // check if it is empty string
    if (sizeOfString(name) == 0 && firstOrLast == FIRST_NAME)
        return uwuFalse;
    // check if they are all character
    for (index i = 0; name[i] != '\0'; i++)
        if (!(name[i] >= 'A' && name[i] <= 'Z') && !(name[i] >= 'a' && name[i] <= 'z') && name[i] != ' ')
            return uwuFalse;
    return uwuTrue;
}

// check if the string is phone number format
boolean isPhoneNumber(uwuPhoneNumber phoneNumber){
    boolean isPhone = uwuFalse;

    // check if string only has numbers
    for (index i = 0; phoneNumber[i] != '\0'; i++)
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
            return uwuFalse;

    // check if it follows the malaysia format
    index k = 0;
    if (phoneNumber[0] == '6') // check if the phone number starts with '6'
        k++; // if so, offset + 1 when checking

    // check for all the possible starting format
    for (index i = 0; i < PHONE_FORMAT_NUMBER && !(isPhone); i++){
        isPhone = uwuTrue;
        for (index j = 0; j < sizeOfString(PHONE_FORMAT_START[i]); j++){
            // check if the starting of phone number match the format start
            if (phoneNumber[j+k] != PHONE_FORMAT_START[i][j]){
                isPhone = uwuFalse;
            }
        }
        // check if the length is correct
        if ((sizeOfString(phoneNumber) - k) != PHONE_FORMAT_LENGTH[i])
            isPhone = uwuFalse;
    }
    return isPhone;
}

// check if the email is correct