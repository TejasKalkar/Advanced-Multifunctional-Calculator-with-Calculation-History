#include<gtk/gtk.h>
#include<math.h>
#include"header.h"

extern GtkWidget* menumat;
GtkWidget* spin7;
void spinwindow8() {
    spin7 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin7),"Input Order");
    gtk_container_set_border_width(GTK_CONTAINER(spin7),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin7), grid);

    GtkWidget *order_label = gtk_label_new("ORDER OF MATRIX   :");
    gtk_grid_attach(GTK_GRID(grid),order_label,0,0,1,1);

    GtkAdjustment *adjustment_order = gtk_adjustment_new(1,1,100,1,0,0);
    GtkWidget *order_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_order),1,0);
    gtk_grid_attach(GTK_GRID(grid),order_spin,1,0,1,1);

    GtkWidget *submit_button = gtk_button_new_with_label("SUBMIT");
    gtk_grid_attach(GTK_GRID(grid),submit_button,0,1,2,1);

    g_object_set_data(G_OBJECT(submit_button),"order_spin",order_spin);
    g_signal_connect(submit_button,"clicked",G_CALLBACK(spinsubmit8),NULL);

    gtk_window_move(GTK_WINDOW(spin7), 350, 110);
    gtk_widget_show_all(spin7);
}

int o4;
void spinsubmit8(GtkWidget *button,gpointer data){

    o4 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"order_spin")));
    inv_mat();

}

GtkWidget *in,*INV,*rebtn8,*X8,*Y8;
double **arr11,**arr12;
GtkWidget ***mat10,***res8;
void inv_mat(){
    int a=o4;
    int i=0;

    arr11 = malloc(a*sizeof(double *));
    arr12 = malloc(a*sizeof(double *));
    for (int i = 0; i < a; i++) {
        arr11[i] = malloc(a*sizeof(double));
        arr12[i] = malloc(a*sizeof(double));
    }

    mat10 =(GtkWidget ***) malloc(a*sizeof(GtkWidget **));
    res8 = (GtkWidget ***)malloc(a*sizeof(GtkWidget **));
    for (int i = 0; i < a; i++) {
        mat10[i] = (GtkWidget **)malloc(a*sizeof(GtkWidget *));
        res8[i] = (GtkWidget **)malloc(a*sizeof(GtkWidget *));
    }


   GtkWidget*m1=gtk_grid_new();
   GtkWidget*r=gtk_grid_new();

   GtkWidget*btn;
   i=0;
   int j=0;

   in = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(in),"Matrix");
    gtk_container_set_border_width(GTK_CONTAINER(in),10);

    gtk_window_move(GTK_WINDOW(in), 680, 110);

   btn = gtk_button_new_with_label("INVERSE");
    g_signal_connect(btn,"clicked",G_CALLBACK(inverse),NULL);
    gtk_grid_attach(GTK_GRID(m1),btn,1,a,1,1);

   INV = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(INV),"Result");
    gtk_container_set_border_width(GTK_CONTAINER(INV),10);

   rebtn8 = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn8,"clicked",G_CALLBACK(recalculate8),NULL);
    gtk_grid_attach(GTK_GRID(r),rebtn8,0,a,1,1);

   X8 = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X8,"clicked",G_CALLBACK(exitin),NULL);
    gtk_grid_attach(GTK_GRID(r),X8,0,a+1,1,1);

   Y8 = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y8,"clicked",G_CALLBACK(exitY8),NULL);
    gtk_grid_attach(GTK_GRID(r),Y8,0,a+2,1,1);

    gtk_window_move(GTK_WINDOW(INV), 1200, 240);

     for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            mat10[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat10[i][j], j, i, 1, 1);
        }
     }

     for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            res8[i][j] = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res8[i][j], j, i, 1, 1);
        }
     }

    gtk_container_add(GTK_CONTAINER(in),m1);
    gtk_container_add(GTK_CONTAINER(INV),r);


    gtk_widget_show_all(in);

    gtk_widget_hide(INV);
}

void inverse(){
int i=0,j=0;

    for (i = 0; i < o4; i++) {
        for (j = 0; j < o4; j++) {
            arr11[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat10[i][j])));
        }
    }

    arr12=Inverse_Matrix(arr11,o4);

    FILE* p;
    p=fopen("history.txt","a");

    if(p==NULL){
        printf("unable to open file");
        exit(1);
    }

    fprintf(p,"[%d]\n",hist);
    hist++;
    fputs("Inverse of matrix\n",p);
    fputs("Matrix:\n",p);

    for (i = 0; i < o4; i++) {
        for (j = 0; j < o4; j++) {
            fprintf(p,"%lf ",arr11[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Result:\n",p);
    for (i = 0; i < o4; i++) {
        for (j = 0; j < o4; j++) {
            fprintf(p,"%lf ",arr12[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fclose(p);

    char buffer[1000];
    for (i = 0; i < o4; i++) {
        for (j = 0; j < o4; j++) {
            sprintf(buffer, "%lf  ", arr12[i][j]);
            gtk_label_set_text(GTK_LABEL(res8[i][j]), buffer);
        }
    }


    gtk_widget_show_all(INV);

}

void recalculate8() {
    // Create the recalculation window
    GtkWidget *recalc_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(recalc_window), "Recalculated Result");
    gtk_container_set_border_width(GTK_CONTAINER(recalc_window), 10);

    GtkWidget *recalc_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(recalc_window), recalc_grid);

    int i, j;
    char buffer[1000];

    // Copy values from arr12 (result window) to arr11 for demonstration
    for (i = 0; i < o4; i++) {
        for (j = 0; j < o4; j++) {
            arr11[i][j] = arr12[i][j]; // Copying values from arr12 to arr11
        }
    }

    // Display the copied values in the recalculation window
    for (i = 0; i < o4; i++) {
        for (j = 0; j < o4; j++) {
            sprintf(buffer, "%lf  ", arr11[i][j]);
            GtkWidget *label = gtk_label_new(buffer);
            gtk_grid_attach(GTK_GRID(recalc_grid), label, j, i, 1, 1);
        }
    }

    gtk_window_move(GTK_WINDOW(recalc_window), 1200, 40);
    gtk_widget_show_all(recalc_window);
}


void exitin(){

    char star[100];

    for (int i=0;i<99;i++){
        star[i]='*';
    }
    star[99]='\n';
    FILE *p;
    p=fopen("history.txt","a");

    if(p==NULL){
        exit(1);
    }

    fputs(star,p);
    fclose(p);

    for (int i = 0; i < o4; i++){
        free(arr11[i]);
        free(mat10[i]);
        free(res8[i]);
        free(arr12[i]);
    }
    free(arr11);
    free(arr12);
    free(mat10);
    free(res8);

    gtk_main_quit ();
}


double **Inverse_Matrix(double **matr, int n)
{
    int i, j;
    double **adj = Adjoint_Matrix(matr, n);
    double determinant = detercal(matr, n);

    if(determinant==0.0){
        invalid_win();
        gtk_widget_destroy(menumat);
        gtk_widget_destroy(in);
        gtk_widget_destroy(spin7);
        main();
    }

    double **inv = malloc(sizeof(double *) * n);
    for (i = 0; i < n; i++)
    {
        inv[i] = (double *)malloc(sizeof(double) * n);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            inv[i][j] = (1.0 / determinant) * (adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        free(adj[i]);
    }
    free(adj);

    return inv;
}

void invalid_win() {
    GtkWidget* dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Invalid input: Determinant is zero");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}


void exitY8(){

    gtk_widget_destroy(in);
    gtk_widget_destroy(INV);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin7);

    system("cls");
    main();
}
