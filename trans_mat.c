#include<gtk/gtk.h>
#include"header.h"

extern GtkWidget* menumat;
GtkWidget *spin2;
void spinwindow3() {
    spin2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin2),"Input Rows and Columns");
    gtk_container_set_border_width(GTK_CONTAINER(spin2),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin2), grid);

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
    g_signal_connect(submit_button,"clicked",G_CALLBACK(spinsubmit3),NULL);

    gtk_window_move(GTK_WINDOW(spin2), 350, 110);
    gtk_widget_show_all(spin2);
}

int r3,c3;
void spinsubmit3(GtkWidget *button,gpointer data){

    r3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"rows_spin")));
    c3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"cols_spin")));

    trans_mat();

    //printf("%d %d",r,c);

}

GtkWidget *t,*trans,*rebtn3,*X3,*Y3;
double **arr5,**transarr;
GtkWidget ***mat5,***res3;
void trans_mat(){
    int a=r3;
    int b=c3;

    arr5 = malloc(a * sizeof(double *));
    for (int i = 0; i < a; i++) {
        arr5[i] = malloc(b * sizeof(double));
    }

    transarr = malloc(b * sizeof(double *));
    for (int i = 0; i < b; i++) {
        transarr[i] = malloc(a * sizeof(double));
    }

    mat5 = malloc(a * sizeof(GtkWidget **));
    res3 = malloc(b * sizeof(GtkWidget **));
    for (int i = 0; i < a; i++) {
        mat5[i] = malloc(b * sizeof(GtkWidget *));
    }
    for (int i = 0; i < b; i++) {
        res3[i] = malloc(a * sizeof(GtkWidget *));
    }


   GtkWidget*m1=gtk_grid_new();
   GtkWidget*r=gtk_grid_new();

   GtkWidget*btn;
   int i=0,j=0;

   t = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(t),"Matrix-1");
    gtk_container_set_border_width(GTK_CONTAINER(t),10);

    gtk_window_move(GTK_WINDOW(t), 680, 110);

   btn = gtk_button_new_with_label("TRANSPOSE");
    g_signal_connect(btn,"clicked",G_CALLBACK(transpose),NULL);
    gtk_grid_attach(GTK_GRID(m1),btn,1,a,1,1);

   trans = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(trans),"Result");
    gtk_container_set_border_width(GTK_CONTAINER(trans),10);

   rebtn3 = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn3,"clicked",G_CALLBACK(recalculate3),NULL);
    gtk_grid_attach(GTK_GRID(r),rebtn3,0,b,1,1);

   X3 = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X3,"clicked",G_CALLBACK(exitt),NULL);
    gtk_grid_attach(GTK_GRID(r),X3,0,b+1,1,1);

    Y3 = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y3,"clicked",G_CALLBACK(exitY3),NULL);
    gtk_grid_attach(GTK_GRID(r),Y3,0,b+2,1,1);

    gtk_window_move(GTK_WINDOW(trans), 1200, 240);

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            mat5[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat5[i][j], j, i, 1, 1);
        }
     }

     for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            res3[i][j] = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res3[i][j], j, i, 1, 1);
        }
     }

    gtk_container_add(GTK_CONTAINER(t),m1);
    gtk_container_add(GTK_CONTAINER(trans),r);


    gtk_widget_show_all(t);

    gtk_widget_hide(trans);
}

void transpose(){
int i=0,j=0;
    for (i = 0; i < r3; i++) {
        for (j = 0; j < c3; j++) {
            arr5[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat5[i][j])));
            transarr[j][i] = arr5[i][j];
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
    fputs("Transpose of matrix\n",p);
    fputs("Matrix:\n",p);

    for (i = 0; i < r3; i++) {
        for (j = 0; j < c3; j++) {
            fprintf(p,"%lf ",arr5[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Result:\n",p);
    for (i = 0; i < c3; i++) {
        for (j = 0; j < r3; j++) {
            fprintf(p,"%lf ",transarr[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fclose(p);

    char buffer[1000];
    for (i = 0; i < c3; i++) {
        for (j = 0; j < r3; j++) {
            sprintf(buffer, "%lf  ", transarr[i][j]);
            gtk_label_set_text(GTK_LABEL(res3[i][j]), buffer);
        }
    }

    gtk_widget_show_all(trans);

}

void recalculate3(){
     return;
}

void exitt() {

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

    for (int i = 0; i < r3; i++) {
        free(arr5[i]);
        free(mat5[i]);
    }
    free(arr5);
    free(mat5);

    for (int i = 0; i < c3; i++) {
        free(res3[i]);
        free(transarr[i]);
    }
    free(res3);
    free(transarr);

    gtk_main_quit();
}


void exitY3(){

    gtk_widget_destroy(t);
    gtk_widget_destroy(trans);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin2);

    system("cls");
    main();
}

