#include<gtk/gtk.h>
#include<stdio.h>
#include"header.h"
GtkWidget *menumat;

void matrix_menu(){

GtkWidget *b1,*b2,*b3,*b4,*b5,*b6,*b7,*b8,*b9,*grid;

menumat=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(menumat), "MATRIX OPERATIONS");
gtk_container_set_border_width(GTK_CONTAINER(menumat), 10);

grid = gtk_grid_new();
   b1 = gtk_button_new_with_label ("ADDITION");
   g_signal_connect (b1, "clicked", G_CALLBACK (spinwindow),NULL);
       gtk_grid_attach (GTK_GRID (grid), b1, 0, 0, 1, 1);

   b2 = gtk_button_new_with_label ("SUBTRACTION");
   g_signal_connect (b2, "clicked", G_CALLBACK (spinwindow2),NULL);
       gtk_grid_attach (GTK_GRID (grid), b2, 0, 1, 1, 1);

   b3 = gtk_button_new_with_label ("TRANSPOSE");
   g_signal_connect (b3, "clicked", G_CALLBACK (spinwindow3),NULL);
       gtk_grid_attach (GTK_GRID (grid), b3, 0, 2, 1, 1);

   b4 = gtk_button_new_with_label ("SCALAR MULTIPLICATION");
   g_signal_connect (b4, "clicked", G_CALLBACK (spinwindow5),NULL);
       gtk_grid_attach (GTK_GRID (grid), b4, 0, 3, 1, 1);

   b5 = gtk_button_new_with_label ("MULTIPLICATION");
   g_signal_connect (b5, "clicked", G_CALLBACK (spinwindow9),NULL);
       gtk_grid_attach (GTK_GRID (grid), b5, 0, 4, 1, 1);

   b6 = gtk_button_new_with_label ("TRACE");
   g_signal_connect (b6, "clicked", G_CALLBACK (spinwindow4),NULL);
       gtk_grid_attach (GTK_GRID (grid), b6, 0, 5, 1, 1);

   b7 = gtk_button_new_with_label ("DETERMINANT");
   g_signal_connect (b7, "clicked", G_CALLBACK (spinwindow6),NULL);
       gtk_grid_attach (GTK_GRID (grid), b7, 0, 6, 1, 1);

   b8 = gtk_button_new_with_label ("ADJOINT");
   g_signal_connect (b8, "clicked", G_CALLBACK (spinwindow7),NULL);
       gtk_grid_attach (GTK_GRID (grid), b8, 0, 7, 1, 1);

   b9 = gtk_button_new_with_label ("INVERSE");
   g_signal_connect (b9, "clicked", G_CALLBACK (spinwindow8),NULL);
       gtk_grid_attach (GTK_GRID (grid), b9, 0, 8, 1, 1);

         gtk_container_add (GTK_CONTAINER (menumat), grid);
         gtk_window_move(GTK_WINDOW(menumat), 100, 110);
         gtk_widget_show_all (menumat);

  return;
}



