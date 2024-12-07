  #include <gtk/gtk.h>
   
   /* The provider below provides application wide CSS data. */
   GtkCssProvider *provider;
   
   static void
   fullscreen_changed(GSimpleAction *action, GVariant *value, GtkWindow *win) {
     if (g_variant_get_boolean (value))
       gtk_window_maximize (win);
    else
      gtk_window_unmaximize (win);
    g_simple_action_set_state (action, value);
  }
  
  static void
  color_activated(GSimpleAction *action, GVariant *parameter) {
    char *color = g_strdup_printf ("label.lb {background-color: %s;}", g_variant_get_string (parameter, NULL));
    /* Change the CSS data in the provider. */
    /* Previous data is thrown away. */
    gtk_css_provider_load_from_data (provider, color, -1);
    g_free (color);
    g_action_change_state (G_ACTION (action), parameter);
  }
  
  static void
  app_shutdown (GApplication *app, GtkCssProvider *provider) {
    gtk_style_context_remove_provider_for_display (gdk_display_get_default(), GTK_STYLE_PROVIDER (provider));
  }
  
  static void
  app_activate (GApplication *app) {
    GtkWindow *win = GTK_WINDOW (gtk_application_window_new (GTK_APPLICATION (app)));
    gtk_window_set_title (win, "menu");
    gtk_window_set_default_size (win, 400, 300);
  
    GtkWidget *lb = gtk_label_new (NULL);
    gtk_widget_add_css_class (lb, "lb"); /* the class is used by CSS Selector */
    gtk_window_set_child (win, lb);
  
    GSimpleAction *act_fullscreen
      = g_simple_action_new_stateful ("fullscreen", NULL, g_variant_new_boolean (FALSE));
    g_signal_connect (act_fullscreen, "change-state", G_CALLBACK (fullscreen_changed), win);
    g_action_map_add_action (G_ACTION_MAP (win), G_ACTION (act_fullscreen));
  
    gtk_application_window_set_show_menubar (GTK_APPLICATION_WINDOW (win), TRUE);
  
    gtk_window_present (win);
  }
  
  static void
  app_startup (GApplication *app) {
    GVariantType *vtype = g_variant_type_new("s");
    GSimpleAction *act_color
      = g_simple_action_new_stateful ("color", vtype, g_variant_new_string ("red"));
    g_variant_type_free (vtype);
    GSimpleAction *act_quit
      = g_simple_action_new ("quit", NULL);
    g_signal_connect (act_color, "activate", G_CALLBACK (color_activated), NULL);
    g_signal_connect_swapped (act_quit, "activate", G_CALLBACK (g_application_quit), app);
    g_action_map_add_action (G_ACTION_MAP (app), G_ACTION (act_color));
    g_action_map_add_action (G_ACTION_MAP (app), G_ACTION (act_quit));
  
    GMenu *menubar = g_menu_new ();
    GMenu *menu = g_menu_new ();
    GMenu *section = g_menu_new ();
    GMenuItem *menu_item_fullscreen = g_menu_item_new ("Full Screen", "win.fullscreen");
    GMenuItem *menu_item_red = g_menu_item_new ("Red", "app.color::red");
    GMenuItem *menu_item_green = g_menu_item_new ("Green", "app.color::green");
    GMenuItem *menu_item_blue = g_menu_item_new ("Blue", "app.color::blue");
    GMenuItem *menu_item_quit = g_menu_item_new ("Quit", "app.quit");
  
    g_menu_append_item (section, menu_item_fullscreen);
    g_menu_append_item (section, menu_item_red);
    g_menu_append_item (section, menu_item_green);
    g_menu_append_item (section, menu_item_blue);
    g_menu_append_item (section, menu_item_quit);
    g_object_unref (menu_item_red);
    g_object_unref (menu_item_green);
    g_object_unref (menu_item_blue);
    g_object_unref (menu_item_fullscreen);
    g_object_unref (menu_item_quit);
  
    g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
    g_menu_append_section (menu, "Color", G_MENU_MODEL (section));
    g_menu_append_section (menu, NULL, G_MENU_MODEL (section));
    g_menu_append_submenu (menubar, "Menu", G_MENU_MODEL (menu));
    g_object_unref (section);
    g_object_unref (section);
    g_object_unref (section);
    g_object_unref (menu);
  
    gtk_application_set_menubar (GTK_APPLICATION (app), G_MENU_MODEL (menubar));
  
    provider = gtk_css_provider_new ();
    /* Initialize the css data */
    gtk_css_provider_load_from_data (provider, "label.lb {background-color: red;}", -1);
    /* Add CSS to the default GdkDisplay. */
   gtk_style_context_add_provider_for_display (gdk_display_get_default (),
         GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
   g_signal_connect (app, "shutdown", G_CALLBACK (app_shutdown), provider);
   g_object_unref (provider); /* release provider, but it's still alive because the display owns it */
 }
 
 #define APPLICATION_ID "com.github.ToshioCP.menu"
 
 int
 main (int argc, char **argv) {
   GtkApplication *app;
   int stat;
 
   app = gtk_application_new (APPLICATION_ID, G_APPLICATION_DEFAULT_FLAGS);
   g_signal_connect (app, "startup", G_CALLBACK (app_startup), NULL);
   g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
 
   stat =g_application_run (G_APPLICATION (app), argc, argv);
   g_object_unref (app);
   return stat;
 }