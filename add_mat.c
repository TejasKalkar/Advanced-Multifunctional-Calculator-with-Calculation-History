#include<gtk/gtk.h>
#include"header.h"

GtkWidget*spin;
extern GtkWidget* menumat;
void spinwindow() {
    spin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin),"Input Rows and Columns");
    gtk_container_set_border_width(GTK_CONTAINER(spin),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin), grid);

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
    g_signal_connect(submit_button,"clicked",G_CALLBACK(spinsubmit),NULL);

    gtk_window_move(GTK_WINDOW(spin), 350, 110);
    gtk_widget_show_all(spin);
}

int a,b;

void spinsubmit(GtkWidget *button,gpointer data){

    a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"rows_spin")));
    b = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"cols_spin")));

    add_mat();

    //printf("%d %d",r,c);

}

GtkWidget *a1,*a2,*add,*rebtn,*X,*Y;
double **arr1, **arr2, **sumarr;
GtkWidget ***mat1,***mat2,***res;

void add_mat(){

    arr1 = malloc(a*sizeof(double *));
    arr2 = malloc(a*sizeof(double *));
    sumarr = malloc(a*sizeof(double *));
    for (int i = 0; i < a; i++) {
        arr1[i] = malloc(b*sizeof(double));
        arr2[i] = malloc(b*sizeof(double));
        sumarr[i] = malloc(b*sizeof(double));
    }

    mat1 =(GtkWidget ***) malloc(a*sizeof(GtkWidget **));
    mat2 = (GtkWidget ***)malloc(a*sizeof(GtkWidget **));
    res = (GtkWidget ***)malloc(a*sizeof(GtkWidget **));
    for (int i = 0; i < a; i++) {
        mat1[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
        mat2[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
        res[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
    }


   GtkWidget*m1=gtk_grid_new();
   GtkWidget*m2=gtk_grid_new();
   GtkWidget*r=gtk_grid_new();

   GtkWidget*btn;
   int i=0,j=0;

   a1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(a1),"Matrix-1");
    gtk_container_set_border_width(GTK_CONTAINER(a1),10);

    gtk_window_move(GTK_WINDOW(a1), 680, 110);

   a2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(a2),"Matrix-2");
    gtk_container_set_border_width(GTK_CONTAINER(a2),10);

    gtk_window_move(GTK_WINDOW(a2), 680, 350);

   btn = gtk_button_new_with_label("ADD");
    g_signal_connect(btn,"clicked",G_CALLBACK(addition),NULL);
    gtk_grid_attach(GTK_GRID(m2),btn,1,a,1,1);

   add = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(add),"Result");
    gtk_container_set_border_width(GTK_CONTAINER(add),10);

   rebtn = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn,"clicked",G_CALLBACK(recalculate),NULL);
    gtk_grid_attach(GTK_GRID(r),rebtn,0,a,1,1);

   X = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X,"clicked",G_CALLBACK(exita),NULL);
    gtk_grid_attach(GTK_GRID(r),X,0,a+1,1,1);

   Y = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y,"clicked",G_CALLBACK(exitY),NULL);
    gtk_grid_attach(GTK_GRID(r),Y,0,a+2,1,1);

    gtk_window_move(GTK_WINDOW(add), 1200, 240);

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            mat1[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat1[i][j], j, i, 1, 1);
        }
     }

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            mat2[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m2), mat2[i][j], j, i, 1, 1);
        }
     }

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            res[i][j] = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res[i][j], j, i, 1, 1);
        }
     }

    gtk_container_add(GTK_CONTAINER(a1),m1);
    gtk_container_add(GTK_CONTAINER(a2),m2);
    gtk_container_add(GTK_CONTAINER(add),r);


    gtk_widget_show_all(a1);
    gtk_widget_show_all(a2);

    gtk_widget_hide(add);


}

void addition(){
    int i=0,j=0;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            arr1[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat1[i][j])));
            arr2[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat2[i][j])));
            sumarr[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    char buffer[1000];
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            sprintf(buffer, "%lf  ", sumarr[i][j]);
            gtk_label_set_text(GTK_LABEL(res[i][j]), buffer);
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
    fputs("Addition of matrices\n",p);
    fputs("Matrix1:\n",p);

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            fprintf(p,"%lf ",arr1[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Matrix2:\n",p);

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            fprintf(p,"%lf ",arr2[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Result:\n",p);
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            fprintf(p,"%lf ",sumarr[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fclose(p);

    //printf("%lf\n",sumarr[0][0]);

    gtk_widget_show_all(add);
}

void recalculate(){

    gtk_window_move(GTK_WINDOW(add), 1200, 240);
    gtk_widget_hide(add);
    matrix_menu();

int i, j;

    for (i = 0; i < a; i++){
        for (j = 0; j < b; j++){
            gtk_entry_set_text(GTK_ENTRY(mat1[i][j]),"");
            gtk_entry_set_text(GTK_ENTRY(mat2[i][j]),"");
        }
    }

    for (i = 0; i < a; i++){
        for (j = 0; j < b; j++){
            char buffer[1000];
            sprintf(buffer,"%lf",sumarr[i][j]);
            gtk_entry_set_text(GTK_ENTRY(mat1[i][j]),buffer);
        }
    }

    gtk_widget_hide(add);
}

void exita(){

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

     for (int i = 0; i < a; i++) {
        free(arr1[i]);
        free(arr2[i]);
        free(sumarr[i]);
        free(mat1[i]);
        free(mat2[i]);
        free(res[i]);
     }
    free(arr1);
    free(arr2);
    free(sumarr);
    free(mat1);
    free(mat2);
    free(res);

    gtk_main_quit();

}

void exitY(){
    gtk_widget_destroy(a1);
    gtk_widget_destroy(a2);
    gtk_widget_destroy(add);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin);

    system("cls");
    main();
}
