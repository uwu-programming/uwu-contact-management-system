#include <gtk/gtk.h>

static void appActivate (GApplication *app, gpointer user_data)
{
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "mystyle.css");

    gtk_style_context_add_provider_for_display(gdk_display_get_default(),
                                               GTK_STYLE_PROVIDER(cssProvider),
                                               GTK_STYLE_PROVIDER_PRIORITY_USER);


    GtkWidget *win = gtk_application_window_new (GTK_APPLICATION (app));

    gtk_window_set_default_size (GTK_WINDOW (win), 400, 300);

    GtkWidget  *vBox = gtk_box_new (GTK_ORIENTATION_VERTICAL,10);
    gtk_window_set_child (GTK_WINDOW (win), vBox);


    /*     Create a red Button    */
    GtkWidget *button1 = gtk_button_new_with_label("Red");
    gtk_widget_set_name(button1, "myButton_red");
    gtk_widget_set_size_request(button1, 160, 130);

    /*     Create a yellow Button    */
    GtkWidget *button2 = gtk_button_new_with_label("Yellow");
    gtk_widget_set_name(button2, "myButton_yellow");
    gtk_widget_set_size_request(button2, 160, 130);

    /*     Create a green Button    */
    GtkWidget *button3 = gtk_button_new_with_label("Green");
    gtk_widget_set_name(button3, "myButton_green");
    gtk_widget_set_size_request(button3, 160, 130);

    /*     Create a blue Button    */
    GtkWidget *button4 = gtk_button_new_with_label("Blue");
    gtk_widget_set_name(button4, "myButton_blue");
    gtk_widget_set_size_request(button4, 160, 130);

    /*     Putting all together      */
    gtk_box_append (GTK_BOX (vBox), button1);
    gtk_box_append (GTK_BOX (vBox), button2);
    gtk_box_append (GTK_BOX (vBox), button3);
    gtk_box_append (GTK_BOX (vBox), button4);

    gtk_widget_set_visible(win, true);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    app = gtk_application_new ("testing.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (appActivate), NULL);

    return g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return 0;
}