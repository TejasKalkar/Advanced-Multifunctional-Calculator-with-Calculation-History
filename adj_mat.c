#include<gtk/gtk.h>
#include<math.h>
#include"header.h"

extern GtkWidget* menumat;
GtkWidget *spin6;
void spinwindow7() {
    spin6 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin6),"Input Order");
    gtk_container_set_border_width(GTK_CONTAINER(spin6),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin6), grid);

    GtkWidget *order_label = gtk_label_new("ORDER OF MATRIX   :");
    gtk_grid_attach(GTK_GRID(grid),order_label,0,0,1,1);

    GtkAdjustment *adjustment_order = gtk_adjustment_new(1,1,100,1,0,0);
    GtkWidget *order_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_order),1,0);
    gtk_grid_attach(GTK_GRID(grid),order_spin,1,0,1,1);

    GtkWidget *submit_button = gtk_button_new_with_label("SUBMIT");
    gtk_grid_attach(GTK_GRID(grid),submit_button,0,1,2,1);

    g_object_set_data(G_OBJECT(submit_button),"order_spin",order_spin);
    g_signal_connect(submit_button,"clicked",G_CALLBACK(spinsubmit7),NULL);

    gtk_window_move(GTK_WINDOW(spin6), 350, 110);
    gtk_widget_show_all(spin6);
}

int o3;
void spinsubmit7(GtkWidget *button,gpointer data){

    o3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"order_spin")));
    adj_mat();

}

GtkWidget *aj,*AJ,*rebtn7,*X7,*Y7;
double **arr9,**arr10;
GtkWidget ***mat9,***res7;
void adj_mat(){
    int a=o3;
    int i=0;

    arr9 = malloc(a*sizeof(double *));
    arr10 = malloc(a*sizeof(double *));
    for (int i = 0; i < a; i++) {
        arr9[i] = malloc(a*sizeof(double));
        arr10[i] = malloc(a*sizeof(double));
    }

    mat9 =(GtkWidget ***) malloc(a*sizeof(GtkWidget **));
    res7 = (GtkWidget ***)malloc(a*sizeof(GtkWidget **));
    for (int i = 0; i < a; i++) {
        mat9[i] = (GtkWidget **)malloc(a*sizeof(GtkWidget *));
        res7[i] = (GtkWidget **)malloc(a*sizeof(GtkWidget *));
    }


   GtkWidget*m1=gtk_grid_new();
   GtkWidget*r=gtk_grid_new();

   GtkWidget*btn;
   i=0;
   int j=0;

   aj = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(aj),"Matrix");
    gtk_container_set_border_width(GTK_CONTAINER(aj),10);

    gtk_window_move(GTK_WINDOW(aj), 680, 110);

   btn = gtk_button_new_with_label("ADJOINT");
    g_signal_connect(btn,"clicked",G_CALLBACK(adjoint),NULL);
    gtk_grid_attach(GTK_GRID(m1),btn,1,a,1,1);

   AJ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(AJ),"Result");
    gtk_container_set_border_width(GTK_CONTAINER(AJ),10);

   rebtn7 = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn7,"clicked",G_CALLBACK(recalculate7),NULL);
    gtk_grid_attach(GTK_GRID(r),rebtn7,0,a,1,1);

   X7 = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X7,"clicked",G_CALLBACK(exitaj),NULL);
    gtk_grid_attach(GTK_GRID(r),X7,0,a+1,1,1);

    Y7 = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y7,"clicked",G_CALLBACK(exitY7),NULL);
    gtk_grid_attach(GTK_GRID(r),Y7,0,a+2,1,1);

    gtk_window_move(GTK_WINDOW(AJ), 1200, 240);

     for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            mat9[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat9[i][j], j, i, 1, 1);
        }
     }

     for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            res7[i][j] = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res7[i][j], j, i, 1, 1);
        }
     }

    gtk_container_add(GTK_CONTAINER(aj),m1);
    gtk_container_add(GTK_CONTAINER(AJ),r);


    gtk_widget_show_all(aj);

    gtk_widget_hide(AJ);
}

void adjoint(){
int i=0,j=0;

    for (i = 0; i < o3; i++) {
        for (j = 0; j < o3; j++) {
            arr9[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat9[i][j])));
        }
    }

    arr10=Adjoint_Matrix(arr9,o3);

    FILE* p;
    p=fopen("history.txt","a");

    if(p==NULL){
        printf("unable to open file");
        exit(1);
    }

    fprintf(p,"[%d]\n",hist);
    hist++;
    fputs("Adjoint of matrix\n",p);
    fputs("Matrix:\n",p);

    for (i = 0; i < o3; i++) {
        for (j = 0; j < o3; j++) {
            fprintf(p,"%lf ",arr9[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Result:\n",p);
    for (i = 0; i < o3; i++) {
        for (j = 0; j < o3; j++) {
            fprintf(p,"%lf ",arr10[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fclose(p);

    char buffer[1000];
    for (i = 0; i < o3; i++) {
        for (j = 0; j < o3; j++) {
            sprintf(buffer, "%lf  ", arr10[i][j]);
            gtk_label_set_text(GTK_LABEL(res7[i][j]), buffer);
        }
    }


    gtk_widget_show_all(AJ);

}

void recalculate7(){
     return;
}

void exitaj(){

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

    for (int i = 0; i < o3; i++){
        free(arr9[i]);
        free(mat9[i]);
        free(res7[i]);
        free(arr10[i]);
    }
    free(arr9);
    free(arr10);
    free(mat9);
    free(res7);

    gtk_main_quit ();
}


double **Adjoint_Matrix(double **matr, int n)
{
    int i, j, row, col;
    double **cofact = (double **)malloc(sizeof(double *) * n);
    double **adj = (double **)malloc(sizeof(double *) * n);
    double **submatr = (double **)malloc(sizeof(double *) * (n - 1));

    for (i = 0; i < n; i++)
    {
        cofact[i] = (double *)malloc(sizeof(double) * n);
        adj[i] = (double *)malloc(sizeof(double) * n);
    }

    for (i = 0; i < n - 1; i++)
    {
        submatr[i] = (double *)malloc(sizeof(double) * (n - 1));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) //using i and j we will traverse through all the elements of the matrix
        {
            int r = 0, c = 0;  // these will be used to generate sub matrix
            for (row = 0; row < n; row++)
            {
                if (row != i)  // will help to exclude row of arr[i][j]element
                {
                    c = 0; // on creating every row of sub matrix column should become 0
                    for (col = 0; col < n; col++)
                    {
                        if (col != j)  // will help to exclude column of arr[i][j]
                        {
                            submatr[r][c] = matr[row][col];
                            c++;
                        }
                    }
                    r++;
                }
            }

            cofact[i][j] = pow(-1.0, i + j) * detercal(submatr, n - 1);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j] = cofact[j][i];
        }
    }

    for (i = 0; i < n; i++)
    {
        free(cofact[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        free(submatr[i]);
    }
    free(cofact);
    free(submatr);

    return adj;
}

void exitY7(){

    gtk_widget_destroy(aj);
    gtk_widget_destroy(AJ);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin6);

    system("cls");
    main();
}

