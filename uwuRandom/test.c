#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;

  // gtk_application_window_new creates a GtkApplicationWindow (type of GtkWidget pointer)
  window = gtk_application_window_new (app);
  // set the title, first argument is GtkWindow pointer, second argument is string
  gtk_window_set_title (GTK_WINDOW (window), "uwu time");
  // set the default size of window, first argument is GtkWindow pointer, second and third arguments are width length respectively
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  // present the window to user
  gtk_window_present (GTK_WINDOW (window)); // note that every time when you want to do something with the GtkWindow pointer, you explicitly cast it with GTK_WINDOW macro
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  // create GtkApplication pointer using gtk_application_new function, first parameter is reverse DNS (application ID), second parameter can just copy
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  // whatever the fuck this is, copy it; at least I know the first parameter is the GtkApplication pointer
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  // g_application_run is used for command line I think
  status = g_application_run (G_APPLICATION (app), argc, argv);
  // free the object with unref function
  g_object_unref (app);

  return status;
}
