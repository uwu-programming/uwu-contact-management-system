#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  // since they are using GObject (a spcial object implementation for C, I think), they have the inheritance property too?
  // I forgor what exactly is the term, like you can switch child class to parent class?
  // thats why they all use GtkWidget instead of specify the actual pointer type (you just need to explicitly cast it later), I think
  GtkWidget *button;
  GtkWidget *button2;
  // GtkBox is used to control the size and layout of button (I think kinda like parent Widget in flutter)
  GtkWidget *box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  // gtk_box_new takes GtkOrientation enumeration value as first parameter (can be horizontal or vertical), which decides how its child will be layed out
  // second parameter is spacing
  box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 20);
  // set the allignment of the widget (respect to its child, I think)
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

  // makes the box the child of the window
  // parameters: GtkWindow pointer, GtkWidget pointer
  gtk_window_set_child (GTK_WINDOW (window), box);

  // returns a GtkButton pointer
  button = gtk_button_new_with_label ("uwu time");
  button2 = gtk_button_new_with_label("owo time");

  // connect a widget to an even? I think
  // parameters: GtkWidget pointer, event type?, G_CALLBACK(functionName), data?)
  // G_CALLBACK is to bind an event to a function, so like after listen, it trigger it
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  // connect_swapped allows you to pass argument to the callback function
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);

  gtk_box_append (GTK_BOX (box), button);
  gtk_box_append(GTK_BOX(box), button2);

  gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
