#include<gtk/gtk.h>
#include"header.h"

extern GtkWidget* menumat;
GtkWidget *spin1;
void spinwindow2() {
    spin1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin1),"Input Rows and Columns");
    gtk_container_set_border_width(GTK_CONTAINER(spin1),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin1), grid);

    GtkWidget *rows_label = gtk_label_new("ROWS OF MATRIX-1   :");
    gtk_grid_attach(GTK_GRID(grid),rows_label,0,0,1,1);

    GtkAdjustment *adjustment_rows = gtk_adjustment_new(1,1,100,1,0,0);
    GtkWidget *rows_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_rows),1,0);
    gtk_grid_attach(GTK_GRID(grid),rows_spin,1,0,1,1);

    GtkWidget *cols_label = gtk_label_new("COLUMNS OF MATRIX-1:");
    gtk_grid_attach(GTK_GRID(grid),cols_label,0,1,1,1);

    GtkAdjustment *adjustment_cols = gtk_adjustment_new(1,1,100,1,0,0);
    GtkWidget *cols_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_cols),1,0);
    gtk_grid_attach(GTK_GRID(grid),cols_spin,1,1,1,1);

    GtkWidget *submit_button = gtk_button_new_with_label("SUBMIT");
    gtk_grid_attach(GTK_GRID(grid),submit_button,0,2,2,1);


    g_object_set_data(G_OBJECT(submit_button),"rows_spin",rows_spin);
    g_object_set_data(G_OBJECT(submit_button),"cols_spin",cols_spin);
    g_signal_connect(submit_button,"clicked",G_CALLBACK(spinsubmit2),NULL);

    gtk_window_move(GTK_WINDOW(spin1), 350, 110);
    gtk_widget_show_all(spin1);
}

GtkWidget *s1,*s2,*sub,*rebtn2,*X2,*Y2;
int p2,q2;
double **arr3, **arr4, **difarr;
GtkWidget ***mat3,***mat4,***res2;

int r2,c2;
void spinsubmit2(GtkWidget *button,gpointer data){

    r2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"rows_spin")));
    c2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"cols_spin")));

    sub_mat();

    //printf("%d %d",r,c);

}

void sub_mat(){

     int a=r2;
     int b=c2;
    // Allocate memory for matrices
    arr3 = malloc(a*sizeof(double *));
    arr4 = malloc(a*sizeof(double *));
    difarr = malloc(a*sizeof(double *));
    for (int i = 0; i < a; i++) {
        arr3[i] = malloc(b*sizeof(double));
        arr4[i] = malloc(b*sizeof(double));
        difarr[i] = malloc(b*sizeof(double));
    }

    mat3 =(GtkWidget ***) malloc(a*sizeof(GtkWidget **));
    mat4 = (GtkWidget ***)malloc(a*sizeof(GtkWidget **));
    res2 = (GtkWidget ***)malloc(a*sizeof(GtkWidget **));
    for (int i = 0; i < a; i++) {
        mat3[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
        mat4[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
        res2[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
    }


   GtkWidget*m1=gtk_grid_new();
   GtkWidget*m2=gtk_grid_new();
   GtkWidget*r=gtk_grid_new();

   GtkWidget*btn;
   int i=0,j=0;

   s1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(s1),"Matrix-1");
    gtk_container_set_border_width(GTK_CONTAINER(s1),10);

    gtk_window_move(GTK_WINDOW(s1), 680, 110);

   s2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(s2),"Matrix-2");
    gtk_container_set_border_width(GTK_CONTAINER(s2),10);

    gtk_window_move(GTK_WINDOW(s2), 680, 350);

   btn = gtk_button_new_with_label("SUBTRACT");
    g_signal_connect(btn,"clicked",G_CALLBACK(subtraction),NULL);
    gtk_grid_attach(GTK_GRID(m2),btn,1,a,1,1);

   sub = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(sub),"Result");
    gtk_container_set_border_width(GTK_CONTAINER(sub),10);

   rebtn2 = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn2,"clicked",G_CALLBACK(recalculate2),NULL);
    gtk_grid_attach(GTK_GRID(r),rebtn2,0,a,1,1);

   X2 = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X2,"clicked",G_CALLBACK(exits),NULL);
    gtk_grid_attach(GTK_GRID(r),X2,0,a+1,1,1);

    Y2 = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y2,"clicked",G_CALLBACK(exitY2),NULL);
    gtk_grid_attach(GTK_GRID(r),Y2,0,a+2,1,1);

    gtk_window_move(GTK_WINDOW(sub), 1200, 240);

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            mat3[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat3[i][j], j, i, 1, 1);
        }
     }

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            mat4[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m2), mat4[i][j], j, i, 1, 1);
        }
     }

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            res2[i][j] = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res2[i][j], j, i, 1, 1);
        }
     }

    gtk_container_add(GTK_CONTAINER(s1),m1);
    gtk_container_add(GTK_CONTAINER(s2),m2);
    gtk_container_add(GTK_CONTAINER(sub),r);


    gtk_widget_show_all(s1);
    gtk_widget_show_all(s2);

    gtk_widget_hide(sub);


}

void subtraction(){
    int i=0,j=0;
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            arr3[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat3[i][j])));
            arr4[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat4[i][j])));
            difarr[i][j] = arr3[i][j] - arr4[i][j];
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
    fputs("Subtarction of matrices\n",p);
    fputs("Matrix1:\n",p);

    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            fprintf(p,"%lf ",arr3[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Matrix2:\n",p);

    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            fprintf(p,"%lf ",arr4[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Result:\n",p);
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            fprintf(p,"%lf ",difarr[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fclose(p);

    char buffer[1000];
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            sprintf(buffer, "%lf  ", difarr[i][j]);
            gtk_label_set_text(GTK_LABEL(res2[i][j]), buffer);
        }
    }

    //printf("%lf\n",sumarr[0][0]);

    gtk_widget_show_all(sub);
}

void recalculate2(){

int i, j;

    for (i = 0; i < r2; i++){
        for (j = 0; j < c2; j++){
            gtk_entry_set_text(GTK_ENTRY(mat3[i][j]),"");
            gtk_entry_set_text(GTK_ENTRY(mat4[i][j]),"");
        }
    }

    for (i = 0; i < r2; i++){
        for (j = 0; j < c2; j++){
            char buffer[1000];
            sprintf(buffer,"%lf",difarr[i][j]);
            gtk_entry_set_text(GTK_ENTRY(mat3[i][j]),buffer);
        }
    }

    gtk_window_move(GTK_WINDOW(sub), 1200, 240);
    gtk_widget_hide(sub);
}

void exits(){
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
    fputc('\n',p);
    fclose(p);

     for (int i = 0; i < r2; i++) {
        free(arr3[i]);
        free(arr4[i]);
        free(difarr[i]);
        free(mat3[i]);
        free(mat4[i]);
        free(res2[i]);
     }
    free(arr3);
    free(arr4);
    free(difarr);
    free(mat3);
    free(mat4);
    free(res2);

    gtk_main_quit ();

}

void exitY2(){
    gtk_widget_destroy(s1);
    gtk_widget_destroy(s2);
    gtk_widget_destroy(sub);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin1);

    system("cls");
    main();
}
