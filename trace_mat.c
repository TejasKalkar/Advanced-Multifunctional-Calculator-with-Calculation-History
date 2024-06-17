#include<gtk/gtk.h>
#include"header.h"

extern GtkWidget* menumat;
GtkWidget *spin3;
void spinwindow4() {
    spin3 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin3),"Input Order");
    gtk_container_set_border_width(GTK_CONTAINER(spin3),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin3), grid);

    GtkWidget *order_label = gtk_label_new("ORDER OF MATRIX   :");
    gtk_grid_attach(GTK_GRID(grid),order_label,0,0,1,1);

    GtkAdjustment *adjustment_order = gtk_adjustment_new(1,1,100,1,0,0);
    GtkWidget *order_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_order),1,0);
    gtk_grid_attach(GTK_GRID(grid),order_spin,1,0,1,1);

    GtkWidget *submit_button = gtk_button_new_with_label("SUBMIT");
    gtk_grid_attach(GTK_GRID(grid),submit_button,0,1,2,1);

    g_object_set_data(G_OBJECT(submit_button),"order_spin",order_spin);
    g_signal_connect(submit_button,"clicked",G_CALLBACK(spinsubmit4),NULL);

    gtk_window_move(GTK_WINDOW(spin3), 350, 110);
    gtk_widget_show_all(spin3);
}

int o;
void spinsubmit4(GtkWidget *button,gpointer data){

    o = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"order_spin")));
    trace_mat();

    //printf("%d %d",r,c);

}

GtkWidget *tr,*Trace,*rebtn4,*X4,*Y4;
double **arr6,T=0.0;
GtkWidget ***mat6,*res4;
void trace_mat(){
    int a=o;
    int b=o;


    arr6 = malloc(a*sizeof(double *));
    for (int i = 0; i < a; i++) {
        arr6[i] = malloc(b*sizeof(double));
    }

    mat6 =(GtkWidget ***) malloc(a*sizeof(GtkWidget **));
    for (int i = 0; i < a; i++) {
        mat6[i] = (GtkWidget **)malloc(b*sizeof(GtkWidget *));
    }


   GtkWidget*m1=gtk_grid_new();
   GtkWidget*r=gtk_grid_new();

   GtkWidget*btn;
   int i=0,j=0;

   tr = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(tr),"Matrix");
    gtk_container_set_border_width(GTK_CONTAINER(tr),10);

    gtk_window_move(GTK_WINDOW(tr), 680, 110);

   btn = gtk_button_new_with_label("TRACE");
    g_signal_connect(btn,"clicked",G_CALLBACK(trace),NULL);
    gtk_grid_attach(GTK_GRID(m1),btn,1,a,1,1);

   Trace = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Trace),"Result");
    gtk_container_set_border_width(GTK_CONTAINER(Trace),10);

   rebtn4 = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn4,"clicked",G_CALLBACK(recalculate4),NULL);
    gtk_grid_attach(GTK_GRID(r),rebtn4,0,1,1,1);

   X4 = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X4,"clicked",G_CALLBACK(exittr),NULL);
    gtk_grid_attach(GTK_GRID(r),X4,0,2,1,1);

    Y4 = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y4,"clicked",G_CALLBACK(exitY4),NULL);
    gtk_grid_attach(GTK_GRID(r),Y4,0,3,1,1);

    gtk_window_move(GTK_WINDOW(Trace), 1200, 240);

     for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            mat6[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat6[i][j], j, i, 1, 1);
        }
     }


            res4 = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res4, 0, 0, 1, 1);


    gtk_container_add(GTK_CONTAINER(tr),m1);
    gtk_container_add(GTK_CONTAINER(Trace),r);


    gtk_widget_show_all(tr);

    gtk_widget_hide(Trace);
}

void trace(){


int i=0,j=0;
    for (i = 0; i < o; i++) {
        for (j = 0; j < o; j++) {
            arr6[i][j] = atof(gtk_entry_get_text(GTK_ENTRY(mat6[i][j])));
            if(i==j){
                T+=arr6[i][j];
            }
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
    fputs("Trace of matrix\n",p);
    fputs("Matrix:\n",p);

    for (i = 0; i < o; i++) {
        for (j = 0; j < o; j++) {
            fprintf(p,"%lf ",arr6[i][j]);
        }
        fputc('\n',p);
    }

    fputc('\n',p);

    fputs("Result:\n",p);

    fprintf(p,"%lf ",T);

    fputc('\n',p);
    fclose(p);

    char buffer[1000];
            sprintf(buffer, "%lf  ", T);
            gtk_label_set_text(GTK_LABEL(res4), buffer);

    T=0.0;
    gtk_widget_show_all(Trace);

}

void recalculate4(){
     return;
}

void exittr(){

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

    for (int i = 0; i < o; i++) {
        free(arr6[i]);
        free(mat6[i]);

     }
    free(arr6);
    free(mat6);
    gtk_main_quit ();
}

void exitY4(){

    gtk_widget_destroy(tr);
    gtk_widget_destroy(trace);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin3);

    system("cls");
    main();
}
