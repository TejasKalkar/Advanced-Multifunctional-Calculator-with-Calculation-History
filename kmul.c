#include<gtk/gtk.h>
#include"header.h"

extern GtkWidget* menumat;
GtkWidget *spin4;
void spinwindow5() {
    spin4 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin4),"Input Rows and Columns");
    gtk_container_set_border_width(GTK_CONTAINER(spin4),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin4), grid);

    GtkWidget *rows_label = gtk_label_new("ROWS OF MATRIX   :");
    gtk_grid_attach(GTK_GRID(grid),rows_label,0,0,1,1);

    GtkAdjustment *adjustment_rows = gtk_adjustment_new(1,1,100,1,0,0);
    GtkWidget *rows_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_rows),1,0);
    gtk_grid_attach(GTK_GRID(grid),rows_spin,1,0,1,1);

    GtkWidget *cols_label = gtk_label_new("COLUMNS OF MATRIX:");
    gtk_grid_attach(GTK_GRID(grid),cols_label,0,1,1,1);

    GtkAdjustment *adjustment_cols = gtk_adjustment_new(1,1,100,1,0,0);
    GtkWidget *cols_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_cols),1,0);
    gtk_grid_attach(GTK_GRID(grid),cols_spin,1,1,1,1);

    GtkWidget *submit_button = gtk_button_new_with_label("SUBMIT");
    gtk_grid_attach(GTK_GRID(grid),submit_button,0,2,2,1);

    g_object_set_data(G_OBJECT(submit_button),"rows_spin",rows_spin);
    g_object_set_data(G_OBJECT(submit_button),"cols_spin",cols_spin);
    g_signal_connect(submit_button,"clicked",G_CALLBACK(spinsubmit5),NULL);

    gtk_window_move(GTK_WINDOW(spin4), 350, 110);
    gtk_widget_show_all(spin4);
}

int r5,c5;
void spinsubmit5(GtkWidget *button,gpointer data){

    r5 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"rows_spin")));
    c5 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"cols_spin")));

    Kmul_mat();

    //printf("%d %d",r,c);

}

GtkWidget *k,*kmul,*rebtn5,*X5,*lbl,*Y5;
double **arr7,**kmularr,C;
GtkWidget ***mat7,***res5;
void Kmul_mat(){
    int a=r5;
    int b=c5;

    // Allocate memory for matrices
    arr7 = malloc(a*sizeof(double *));
    kmularr = malloc(a*sizeof(double *));
    for (int i = 0; i < a; i++) {
        arr7[i] = malloc(b*sizeof(double));
        kmularr[i] = malloc(b*sizeof(double));
    }

    mat7 =(GtkWidget ***) malloc(a*sizeof(GtkWidget **));
    res5 = (GtkWidget ***)malloc(a*sizeof(GtkWidget **));
    for (int i = 0; i < a; i++) {
        mat7[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
        res5[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
    }


   GtkWidget*m1=gtk_grid_new();
   GtkWidget*r=gtk_grid_new();

   GtkWidget*btn,*y;
   int i=0,j=0;

   k = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(k),"Matrix");
    gtk_container_set_border_width(GTK_CONTAINER(k),10);

    gtk_window_move(GTK_WINDOW(k), 680, 110);

   y = gtk_label_new("ENTER-SCALAR :");
    gtk_grid_attach(GTK_GRID(m1),y,0,a,1,1);

   lbl = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(m1),lbl,1,a,1,1);

   btn = gtk_button_new_with_label("SCALAR-MUL");
    g_signal_connect(btn,"clicked",G_CALLBACK(KMUL),NULL);
    gtk_grid_attach(GTK_GRID(m1),btn,1,a+1,1,1);

   kmul = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(kmul),"Result");
    gtk_container_set_border_width(GTK_CONTAINER(kmul),10);

   rebtn5 = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn5,"clicked",G_CALLBACK(recalculate5),NULL);
    gtk_grid_attach(GTK_GRID(r),rebtn5,0,a,1,1);

   X5 = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X5,"clicked",G_CALLBACK(exitk),NULL);
    gtk_grid_attach(GTK_GRID(r),X5,0,a+1,1,1);

    Y5 = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y5,"clicked",G_CALLBACK(exitY5),NULL);
    gtk_grid_attach(GTK_GRID(r),Y5,0,a+2,1,1);

    gtk_window_move(GTK_WINDOW(kmul), 1200, 240);

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            mat7[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat7[i][j], j, i, 1, 1);
        }
     }

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            res5[i][j] = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res5[i][j], j, i, 1, 1);
        }
     }

    gtk_container_add(GTK_CONTAINER(k),m1);
    gtk_container_add(GTK_CONTAINER(kmul),r);


    gtk_widget_show_all(k);

    gtk_widget_hide(kmul);
}

void KMUL(){
int i=0,j=0;

    C=atof(gtk_entry_get_text(GTK_ENTRY(lbl)));
    for (i = 0; i < r5; i++) {
        for (j = 0; j < c5; j++) {
            arr7[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat7[i][j])));
            kmularr[i][j] = C*arr7[i][j];
        }
    }

    FILE* p;
    p=fopen("history.txt","a");

    if(p==NULL){
        printf("unable to open file");
        exit(1);
    }

    fprintf(p,"[%d]\n",hist);
    hist++;
    fputs("ScalarMultiplication of matrix\n",p);
    fputs("Matrix:\n",p);

    for (i = 0; i < r5; i++) {
        for (j = 0; j < c5; j++) {
            fprintf(p,"%lf ",arr7[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Result:\n",p);
    for (i = 0; i < r5; i++) {
        for (j = 0; j < c5; j++) {
            fprintf(p,"%lf ",kmularr[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fclose(p);

    char buffer[1000];
    for (i = 0; i < r5; i++) {
        for (j = 0; j < c5; j++) {
            sprintf(buffer, "%lf  ", kmularr[i][j]);
            gtk_label_set_text(GTK_LABEL(res5[i][j]), buffer);
        }
    }

    gtk_widget_show_all(kmul);

}

void recalculate5(){
     return;
}

void exitk(){

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

    for (int i = 0; i < r5; i++){
        free(arr7[i]);
        free(mat7[i]);
        free(res5[i]);
        free(kmularr[i]);
    }
    free(arr7);
    free(kmularr);
    free(mat7);
    free(res5);

    gtk_main_quit ();
}

void exitY5(){

    gtk_widget_destroy(k);
    gtk_widget_destroy(kmul);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin4);

    system("cls");
    main();
}
