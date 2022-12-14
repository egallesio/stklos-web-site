//
// simple-gtk.c         -- A Simple example in GTK+
//

#include <gtk/gtk.h>

void hello(GtkWidget *widget, gpointer data)
{
  g_print ("Hello again - %s was pressed\n", (gchar *) data);
}

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
  gtk_main_quit ();
  return FALSE;
}

int main(int argc, char *argv[])
{
  // GtkWidget is the storage type for widgets
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box1;

  // Initalize GTK+
  gtk_init (&argc, &argv);

  // Window
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Hello Buttons!");
  g_signal_connect (G_OBJECT (window), "delete_event",
                     G_CALLBACK (delete_event), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);


  // box1
  box1 = gtk_hbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (window), box1);

  // button1
  button = gtk_button_new_with_label ("Button 1");
  g_signal_connect (G_OBJECT (button), "clicked",
                     G_CALLBACK (hello), (gpointer) "Button 1");
  gtk_box_pack_start (GTK_BOX(box1), button, TRUE, TRUE, 0);
  gtk_widget_show (button);

  // button2
  button = gtk_button_new_with_label ("Button 2");
  g_signal_connect (G_OBJECT (button), "clicked",
                     G_CALLBACK (hello), (gpointer) "Button 2");
  gtk_box_pack_start(GTK_BOX (box1), button, TRUE, TRUE, 0);
  gtk_widget_show (button);

  gtk_widget_show (box1);
  gtk_widget_show (window);

  gtk_main ();
  printf("GTK event loop terminated\n");
  return 0;
}



