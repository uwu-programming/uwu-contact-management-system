#include "uwuMainUI.h"
#include "uwuUserLogin.h"
#include "uwuUtility.h"
#include "uwuContactsUI.h"
#include "uwuUserContact.h"

// define value for extern variable
struct UwUContactButton *uwuContactButtonArray = NULL;

// function to create the contacts window and widgets
void startContactsUI(GObject *uwuWindow){
    // define variables
    GtkBuilder *uwuBuilder = NULL;
    GObject *uwuWindowBox = NULL;
    GObject *uwuFieldTop = NULL, *uwuFieldBottom = NULL;
    GObject *uwuFieldProfile = NULL, *uwuFieldSearch = NULL, *uwuFieldSetting = NULL;
    GObject *uwuProfileLabel = NULL, *uwuSearchEntry;
    GObject *uwuFrameFieldBottom = NULL, *uwuFrameScrollWindow, *uwuContactListBox = NULL;

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

    // link the widget in bottom field
    uwuFrameFieldBottom = gtk_builder_get_object(uwuBuilder, "uwuFrameFieldBottom");
    uwuFrameScrollWindow = gtk_builder_get_object(uwuBuilder, "uwuFrameScrollWindow");
    uwuContactListBox = gtk_builder_get_object(uwuBuilder, "uwuContactListBox");

    // modify top and bottom field
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldTop), "uwuContactFieldTop");
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldBottom), "uwuContactFieldBottom");
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldTop), GTK_ORIENTATION_HORIZONTAL);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldTop), GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldTop), 0, 80);
    gtk_widget_set_valign(GTK_WIDGET(uwuFieldBottom), GTK_ALIGN_FILL);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldBottom), GTK_ORIENTATION_VERTICAL);

    // modify profile field
    uwuLabelString userLabel;
    getCurrentUserLabel(userLabel);
    gtk_label_set_label(GTK_LABEL(uwuProfileLabel), userLabel);
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

    // modify frame field and contact list box
    gtk_frame_set_label(GTK_FRAME(uwuFrameFieldBottom), "UwU contacts");
    gtk_widget_set_valign(GTK_WIDGET(uwuFrameFieldBottom), GTK_ALIGN_FILL);
    gtk_widget_set_valign(GTK_WIDGET(uwuFrameScrollWindow), GTK_ALIGN_FILL);
    gtk_widget_set_valign(GTK_WIDGET(uwuContactListBox), GTK_ALIGN_FILL);
    gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(uwuFrameScrollWindow), 450);

    // gtets
    readContactFromFile("contacts/uwuSunshine.csv");

    // insert the contact button
    createContactButtonArray();
    sortContactAscendingName();
    assembleButtonToWindow(uwuContactListBox);

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

void createContactButtonArray(){
    free(uwuContactButtonArray); // free the previous address
    uwuContactButtonArray = malloc(sizeof(struct UwUContactButton) * UwUContactNodeCount); // allocate memory for array

    struct UwUContactNode *temp = uwuContactHeadNode;
    for (index i = 0; i < UwUContactNodeCount; i++){
        uwuContactButtonArray[i].contact = temp -> contact;

        GtkWidget *buttonBox, *firstNameBox, *lastNameBox, *phoneNumberBox, *emailAddressBox, *groupBox;
        GtkWidget *firstNameLabel, *lastNameLabel, *phoneNumberLabel, *emailAddressLabel, *groupLabel;
        buttonBox = malloc(sizeof(GtkWidget));
        firstNameBox = malloc(sizeof(GtkWidget));
        lastNameBox = malloc(sizeof(GtkWidget));
        phoneNumberBox = malloc(sizeof(GtkWidget));
        emailAddressBox = malloc(sizeof(GtkWidget));
        groupBox = malloc(sizeof(GtkWidget));
        buttonBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        firstNameBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        lastNameBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        phoneNumberBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        emailAddressBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        groupBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

        firstNameLabel = malloc(sizeof(GtkWidget));
        lastNameLabel = malloc(sizeof(GtkWidget));
        phoneNumberLabel = malloc(sizeof(GtkWidget));
        emailAddressLabel = malloc(sizeof(GtkWidget));
        groupLabel = malloc(sizeof(GtkWidget));
        firstNameLabel = gtk_label_new(temp->contact->firstName);
        lastNameLabel = gtk_label_new(temp->contact->lastName);
        phoneNumberLabel = gtk_label_new(temp->contact->phoneNumber);
        emailAddressLabel = gtk_label_new(temp->contact->emailAddress);
        groupLabel = gtk_label_new(temp->contact->address);
        
        gtk_box_append(GTK_BOX(firstNameBox), GTK_WIDGET(firstNameLabel));
        gtk_box_append(GTK_BOX(lastNameBox), GTK_WIDGET(lastNameLabel));
        gtk_box_append(GTK_BOX(phoneNumberBox), GTK_WIDGET(phoneNumberLabel));
        gtk_box_append(GTK_BOX(emailAddressBox), GTK_WIDGET(emailAddressLabel));
        gtk_box_append(GTK_BOX(groupBox), GTK_WIDGET(groupLabel));

        gtk_box_append(GTK_BOX(buttonBox), GTK_WIDGET(firstNameBox));
        gtk_box_append(GTK_BOX(buttonBox), GTK_WIDGET(lastNameBox));
        gtk_box_append(GTK_BOX(buttonBox), GTK_WIDGET(phoneNumberBox));
        gtk_box_append(GTK_BOX(buttonBox), GTK_WIDGET(emailAddressBox));
        gtk_box_append(GTK_BOX(buttonBox), GTK_WIDGET(groupBox));

        GtkWidget *button = malloc(sizeof(GtkWidget));
        button = gtk_button_new();
        gtk_button_set_child(GTK_BUTTON(button), GTK_WIDGET(buttonBox));

        uwuContactButtonArray[i].button = button;
        temp = temp -> next;
    }
}

// function to remove all buttons from the scroll window
void removeButtonFromWindow(GObject *listbox){
    gtk_list_box_remove_all(GTK_LIST_BOX(listbox));
}

// function to put all button in array to the scroll window
void assembleButtonToWindow(GObject *listBox){
    for (index i = 0; i < UwUContactNodeCount; i++){
        gtk_list_box_prepend(GTK_LIST_BOX(listBox), GTK_WIDGET(uwuContactButtonArray[i].button));
    }
}

// function to sort name by first name, lexicographical order
void sortContactAscendingName(){
    struct UwUContactButton hold;
    for (index i = 0; i < UwUContactNodeCount - 1; i++){
        for (index j = 0; j < UwUContactNodeCount - i - 1; j++){
            if (strcmp(uwuContactButtonArray[j].contact->firstName, uwuContactButtonArray[j+1].contact->firstName) <= 0){
                hold.contact = uwuContactButtonArray[j].contact;
                hold.button = uwuContactButtonArray[j].button;
                uwuContactButtonArray[j] = uwuContactButtonArray[j+1];
                uwuContactButtonArray[j+1].contact = hold.contact;
                uwuContactButtonArray[j+1].button = hold.button;
            }
        }
    }
}