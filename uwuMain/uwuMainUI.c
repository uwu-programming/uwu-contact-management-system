#include "uwuMainUI.h"
#include "uwuUserLogin.h"
#include "uwuUtility.h"
#include "uwuContactsUI.h"
#include "uwuUserContact.h"

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

// function to create the login window and widgets
static void startApp(GtkApplication *uwuApp, gpointer uwuData){
    // define variables
    GtkBuilder *uwuBuilder = NULL; // GtkBuilder pointer
    GObject *uwuWindow = NULL; // pointer for window widget
    GObject *uwuWindowBox = NULL; // pointer for window's child, the box layout
    GObject *uwuFieldTop = NULL, *uwuFieldMiddle = NULL, *uwuFieldBottom = NULL; // pointer for the three field
    GObject *uwuTitleTop = NULL; // pointer for the title on top field
    GObject *uwuFieldName = NULL, *uwuFieldPassword = NULL; // box widget for positioning name and password field
    GObject *uwuFieldLabelName = NULL, *uwuFieldEntryName = NULL, *uwuFieldLabelPassword = NULL, *uwuFieldEntryPassword = NULL;
    GObject *uwuLabelName = NULL, *uwuEntryName = NULL; // pointer for name's label and text field widget
    GObject *uwuLabelPassword = NULL, *uwuEntryPassword = NULL; // pointer for password's label and text field widget
    GObject *uwuFieldButtonLogin = NULL, *uwuFieldButtonSignup = NULL; // pointer to the login and signup button field
    GObject *uwuButtonLogin = NULL, *uwuButtonSignup = NULL; // pointer for login and signup button
    GObject *uwuInputUsername = NULL, *uwuInputPassword = NULL;

    // create a GtkBuilder object and store it to uwuBuilder
    uwuBuilder = gtk_builder_new();
    gtk_builder_add_from_file(uwuBuilder, "uwuMainUI.ui", NULL); // add the main ui GtkBuilder.ui file into the object

    // connect the created widget from GtkBuilder
    // create the window widget
    uwuWindow = gtk_builder_get_object(uwuBuilder, "uwuWindow");
    gtk_window_set_application(GTK_WINDOW(uwuWindow), uwuApp); // bind the window to GtkApplication
    gtk_window_set_default_size(GTK_WINDOW(uwuWindow), 1000, 600); // set the default size
    gtk_widget_set_size_request(GTK_WIDGET(uwuWindow), 1000, 600); // set minimum size of the window
    gtk_window_set_title(GTK_WINDOW(uwuWindow), "UwU Contact Management System"); // set the window's title

    // link the css file
    uwuCssSource = gtk_css_provider_new();
    gtk_css_provider_load_from_path(uwuCssSource, "uwuUI.css");
    gtk_style_context_add_provider_for_display(gdk_display_get_default(), GTK_STYLE_PROVIDER(uwuCssSource), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // get the window box widget
    uwuWindowBox = gtk_builder_get_object(uwuBuilder, "uwuWindowBox");
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuWindowBox), GTK_ORIENTATION_VERTICAL);

    // link the three fields (three box widget: top, mid, bottom) from uwuMainUI
    uwuFieldTop = gtk_builder_get_object(uwuBuilder, "uwuFieldTop");
    uwuFieldMiddle = gtk_builder_get_object(uwuBuilder, "uwuFieldMiddle");
    uwuFieldBottom = gtk_builder_get_object(uwuBuilder, "uwuFieldBottom");

    // link name and password field
    uwuFieldName = gtk_builder_get_object(uwuBuilder, "uwuFieldName");
    uwuFieldLabelName = gtk_builder_get_object(uwuBuilder, "uwuFieldLabelName");
    uwuFieldEntryName = gtk_builder_get_object(uwuBuilder, "uwuFieldEntryName");
    uwuFieldPassword = gtk_builder_get_object(uwuBuilder, "uwuFieldPassword");
    uwuFieldLabelPassword = gtk_builder_get_object(uwuBuilder, "uwuFieldLabelPassword");
    uwuFieldEntryPassword = gtk_builder_get_object(uwuBuilder, "uwuFieldEntryPassword");

    // modify top field
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldTop), "top");
    gtk_widget_set_valign(GTK_WIDGET(uwuFieldTop), GTK_ALIGN_CENTER);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldTop), GTK_ALIGN_CENTER);
    gtk_box_set_homogeneous(GTK_BOX(uwuFieldTop), TRUE);
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldTop), 900, 250);

    // top title
    uwuTitleTop = gtk_builder_get_object(uwuBuilder, "uwuTitleTop");
    gtk_widget_add_css_class(GTK_WIDGET(uwuTitleTop), "uwuTopTitle");
    gtk_label_set_label(GTK_LABEL(uwuTitleTop), "UwU Contact Management System");
    gtk_widget_set_valign(GTK_WIDGET(uwuTitleTop), GTK_ALIGN_CENTER);
    gtk_widget_set_halign(GTK_WIDGET(uwuTitleTop), GTK_ALIGN_CENTER);

    // modify middle field
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldMiddle), GTK_ORIENTATION_VERTICAL);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldMiddle), GTK_ALIGN_CENTER); // align center for horizontal
    gtk_widget_set_valign(GTK_WIDGET(uwuFieldMiddle), GTK_ALIGN_CENTER); // align center for vertical
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldMiddle), "uwutest2");
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldMiddle), 900, 200);
    gtk_box_set_homogeneous(GTK_BOX(uwuFieldMiddle), TRUE);

    // modify name and password field (horizontal orientation)
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldName), GTK_ORIENTATION_HORIZONTAL);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldPassword), GTK_ORIENTATION_HORIZONTAL);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldName), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(uwuFieldName), GTK_ALIGN_CENTER);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldPassword), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(uwuFieldPassword), GTK_ALIGN_CENTER);

    // modify label and entry field of name and password
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldEntryName), "uwutest");
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldEntryPassword), "uwutest");
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldLabelName), GTK_ORIENTATION_VERTICAL);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldLabelPassword), GTK_ORIENTATION_VERTICAL);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldEntryName), GTK_ORIENTATION_VERTICAL);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldEntryPassword), GTK_ORIENTATION_VERTICAL);
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldLabelName), 270, 60);
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldLabelPassword), 270, 60);
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldEntryName), 400, 60);
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldEntryPassword), 400, 60);

    // link the label and entry field for username from uwuMainUI to here
    uwuLabelName = gtk_builder_get_object(uwuBuilder, "uwuLabelName");
    uwuEntryName = gtk_builder_get_object(uwuBuilder, "uwuEntryName");
    gtk_label_set_label(GTK_LABEL(uwuLabelName), "Username:"); // set label of uwuLabelName to "Username: "
    gtk_widget_add_css_class(GTK_WIDGET(uwuLabelName), "uwuMainPageLabel"); // add uwuMainPageLabel class to uwuLabelName (for css)
    gtk_widget_add_css_class(GTK_WIDGET(uwuEntryName), "uwuMainPageEntry"); // add uwuMainPageEntry class to uwuEntryName (for css)
    gtk_widget_set_halign(GTK_WIDGET(uwuLabelName), GTK_ALIGN_END);
    gtk_widget_set_halign(GTK_WIDGET(uwuEntryName), GTK_ALIGN_END);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelName), 0, 60);
    gtk_widget_set_size_request(GTK_WIDGET(uwuEntryName), 380, 60);

    // link the label and entry field for password from uwuMainUI to here
    uwuLabelPassword = gtk_builder_get_object(uwuBuilder, "uwuLabelPassword");
    uwuEntryPassword = gtk_builder_get_object(uwuBuilder, "uwuEntryPassword");
    gtk_label_set_label(GTK_LABEL(uwuLabelPassword), "Password:"); // set label of uwuLabelPassword to "Password: "
    gtk_widget_add_css_class(GTK_WIDGET(uwuLabelPassword), "uwuMainPageLabel"); // add uwuMainPageLabel class to uwuLabelPassword (for css)
    gtk_widget_add_css_class(GTK_WIDGET(uwuEntryPassword), "uwuMainPageEntry"); // add uwuMainPageEntry class to uwuEntryPassword (for css)
    gtk_widget_set_halign(GTK_WIDGET(uwuLabelPassword), GTK_ALIGN_END);
    gtk_widget_set_halign(GTK_WIDGET(uwuEntryPassword), GTK_ALIGN_END);
    gtk_widget_set_size_request(GTK_WIDGET(uwuLabelPassword), 0, 60);
    gtk_widget_set_size_request(GTK_WIDGET(uwuEntryPassword), 380, 60);

    // structure for storing the entries
    UwUEntries.uwuEntryUsername = GTK_ENTRY(uwuEntryName);
    UwUEntries.uwuEntryPassword = GTK_PASSWORD_ENTRY(uwuEntryPassword);

    // modify bottom field
    gtk_widget_add_css_class(GTK_WIDGET(uwuFieldBottom), "bot");
    gtk_orientable_set_orientation(GTK_ORIENTABLE(uwuFieldBottom), GTK_ORIENTATION_HORIZONTAL);
    gtk_box_set_homogeneous(GTK_BOX(uwuFieldBottom), TRUE);
    gtk_widget_set_valign(GTK_WIDGET(uwuFieldBottom), GTK_ALIGN_CENTER);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldBottom), GTK_ALIGN_CENTER);
    gtk_widget_set_size_request(GTK_WIDGET(uwuFieldBottom), 600, 150);

    // modify the button field
    uwuFieldButtonLogin = gtk_builder_get_object(uwuBuilder, "uwuFieldButtonLogin");
    uwuFieldButtonSignup = gtk_builder_get_object(uwuBuilder, "uwuFieldButtonSignup");
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldButtonLogin), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(uwuFieldButtonLogin), GTK_ALIGN_CENTER);
    gtk_widget_set_halign(GTK_WIDGET(uwuFieldButtonSignup), GTK_ALIGN_CENTER);
    gtk_widget_set_valign(GTK_WIDGET(uwuFieldButtonSignup), GTK_ALIGN_CENTER);

    // modify the buttons
    uwuButtonLogin = gtk_builder_get_object(uwuBuilder, "uwuButtonLogin");
    uwuButtonSignup = gtk_builder_get_object(uwuBuilder, "uwuButtonSignup");
    g_signal_connect(uwuButtonLogin, "clicked", G_CALLBACK(loginFunction), uwuWindow);
    gtk_widget_set_size_request(GTK_WIDGET(uwuButtonLogin), 150, 50);
    gtk_widget_set_size_request(GTK_WIDGET(uwuButtonSignup), 150, 50);

    // make window visible
    gtk_widget_set_visible(GTK_WIDGET(uwuWindow), TRUE);

    // free the builder object
    g_object_unref(uwuBuilder);
}

/*---------------------------------------------------------------*/
// button functions
static void loginFunction(GtkButton *uwuButton, GObject *uwuWindow){
    string username, password;
    username = gtk_editable_get_chars(GTK_EDITABLE(UwUEntries.uwuEntryUsername), 0, -1);
    password = gtk_editable_get_chars(GTK_EDITABLE(UwUEntries.uwuEntryPassword), 0, -1);

    // login and create the contact screen if username and password are right
    if (checkEligibleLogin(username, password) == uwuTrue){        
        startContactsUI(uwuWindow);
    }
}