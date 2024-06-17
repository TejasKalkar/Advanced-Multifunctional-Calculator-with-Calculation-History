#include<gtk/gtk.h>
#include"header.h"

GtkWidget *spin5;
extern GtkWidget* menumat;
void spinwindow6() {
    spin5 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin5),"Input Order");
    gtk_container_set_border_width(GTK_CONTAINER(spin5),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin5), grid);

    GtkWidget *order_label = gtk_label_new("ORDER OF MATRIX   :");
    gtk_grid_attach(GTK_GRID(grid),order_label,0,0,1,1);

    GtkAdjustment *adjustment_order = gtk_adjustment_new(1,1,100,1,0,0);
    GtkWidget *order_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_order),1,0);
    gtk_grid_attach(GTK_GRID(grid),order_spin,1,0,1,1);

    GtkWidget *submit_button = gtk_button_new_with_label("SUBMIT");
    gtk_grid_attach(GTK_GRID(grid),submit_button,0,1,2,1);

    g_object_set_data(G_OBJECT(submit_button),"order_spin",order_spin);
    g_signal_connect(submit_button,"clicked",G_CALLBACK(spinsubmit6),NULL);

    gtk_window_move(GTK_WINDOW(spin5), 350, 110);
    gtk_widget_show_all(spin5);
}

int o2;
void spinsubmit6(GtkWidget *button,gpointer data){

    o2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"order_spin")));

    det_mat();

}

GtkWidget *d,*det,*rebtn6,*X6,*Y6;
double **arr8,**subarr,D;
GtkWidget ***mat8,*res6;
void det_mat(){
    int a=o2;
    int i=0;

    arr8 = malloc(a*sizeof(double *));
    subarr = malloc((a-1)*sizeof(double *));
    for ( i = 0; i < a-1; i++) {
        arr8[i] = malloc(a*sizeof(double));
        subarr[i] = malloc((a-1)*sizeof(double));
    }
    arr8[i] = malloc(a*sizeof(double));

    mat8 =(GtkWidget ***) malloc(a*sizeof(GtkWidget **));
    for (int i = 0; i < a; i++) {
        mat8[i] = (GtkWidget **)malloc(a*sizeof(GtkWidget *));
    }


   GtkWidget*m1=gtk_grid_new();
   GtkWidget*r=gtk_grid_new();

   GtkWidget*btn;
   i=0;
   int j=0;

   d = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(d),"Matrix");
    gtk_container_set_border_width(GTK_CONTAINER(d),10);

    gtk_window_move(GTK_WINDOW(d), 680, 110);

   btn = gtk_button_new_with_label("DETERMINANT");
    g_signal_connect(btn,"clicked",G_CALLBACK(determinant),NULL);
    gtk_grid_attach(GTK_GRID(m1),btn,1,a,1,1);

   det = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(det),"Result");
    gtk_container_set_border_width(GTK_CONTAINER(det),10);

   rebtn6 = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn6,"clicked",G_CALLBACK(recalculate6),NULL);
    gtk_grid_attach(GTK_GRID(r),rebtn6,0,a,1,1);

   X6 = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X6,"clicked",G_CALLBACK(exitd),NULL);
    gtk_grid_attach(GTK_GRID(r),X6,0,a+1,1,1);

    Y6 = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y6,"clicked",G_CALLBACK(exitY6),NULL);
    gtk_grid_attach(GTK_GRID(r),Y6,0,a+2,1,1);

    gtk_window_move(GTK_WINDOW(det), 1200, 240);

     for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            mat8[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat8[i][j], j, i, 1, 1);
        }
     }


            res6 = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res6, 0, 0, 1, 1);

    gtk_container_add(GTK_CONTAINER(d),m1);
    gtk_container_add(GTK_CONTAINER(det),r);


    gtk_widget_show_all(d);

    gtk_widget_hide(det);
}

void determinant(){
int i=0,j=0;

    for (i = 0; i < o2; i++) {
        for (j = 0; j < o2; j++) {
            arr8[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat8[i][j])));
        }
    }

    D=detercal(arr8,o2);

    FILE* p;
    p=fopen("history.txt","a");

    if(p==NULL){
        printf("unable to open file");
        exit(1);
    }

    fprintf(p,"[%d]\n",hist);
    hist++;
    fputs("Determinant of matrix\n",p);
    fputs("Matrix:\n",p);

    for (i = 0; i < o2; i++) {
        for (j = 0; j < o2; j++) {
            fprintf(p,"%lf ",arr8[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Result:\n",p);

    fprintf(p,"%lf ",D);

    fputc('\n',p);
    fclose(p);

    char buffer[1000];
            sprintf(buffer, "%lf  ",D);
            gtk_label_set_text(GTK_LABEL(res6), buffer);

    D=0.0;

    gtk_widget_show_all(det);

}

void recalculate6(){
     return;
}

void exitd(){

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

    for (int i = 0; i < o2; i++){
        free(arr8[i]);
        free(mat8[i]);
    }
    free(arr8);
    free(mat8);

    for (int i = 0; i < o2-1; i++){
        free(subarr[i]);
    }
    free(subarr);

    gtk_main_quit ();
}


double detercal(double **matr, int n)
{
    int i, j, k;

    if (n == 1)
    {
        return matr[0][0];
    }

    double **sub_matr = (double **)malloc(sizeof(double *) * (n - 1));

    for (i = 0; i < n - 1; i++)
    {
        sub_matr[i] = (double *)malloc(sizeof(double) * (n - 1));
    }
    double determ = 0;
    //here we are calculating determinant from first row elements of the matrix
    for (k = 0; k < n; k++) // used for first row elements of original matrix
    {
        for (i = 1; i < n; i++) // sub matrix will start getting created from secon row onwards
        {
            for (j = 0; j < n; j++) //used for matching whether column matches with the column of element of first row
            {
                if (j == k)
                {
                    continue;
                }

                else if (j < k)
                {
                    sub_matr[i - 1][j] = matr[i][j];
                }

                else
                {
                    sub_matr[i - 1][j - 1] = matr[i][j];
                }
            }
        }

        int sign;
        if (k % 2 == 0)
        {
            sign = 1;
        }

        else
        {
            sign = -1;
        }

        determ = determ + matr[0][k] * sign * detercal(sub_matr, n - 1);
    }

    for (i = 0; i < n - 1; i++)
    {
        free(sub_matr[i]);
    }

    free(sub_matr);

    return determ;
}

void exitY6(){

    gtk_widget_destroy(d);
    gtk_widget_destroy(det);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin5);

    system("cls");
    main();
}
