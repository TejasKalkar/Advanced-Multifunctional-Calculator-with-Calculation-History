#include <gtk/gtk.h>
#include "header.h"

GtkWidget* spin8;
extern GtkWidget* menumat;
void spinwindow9() {
    spin8 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin8), "Input Rows and Columns");
    gtk_container_set_border_width(GTK_CONTAINER(spin8), 10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin8), grid);

    GtkWidget *rows_label = gtk_label_new("ROWS OF MATRIX-1   :");
    gtk_grid_attach(GTK_GRID(grid), rows_label, 0, 0, 1, 1);

    GtkAdjustment *adjustment_rows = gtk_adjustment_new(1, 1, 100, 1, 0, 0);
    GtkWidget *rows_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_rows), 1, 0);
    gtk_grid_attach(GTK_GRID(grid), rows_spin, 1, 0, 1, 1);

    GtkWidget *cols_label = gtk_label_new("COLUMNS OF MATRIX-1:");
    gtk_grid_attach(GTK_GRID(grid), cols_label, 0, 1, 1, 1);

    GtkAdjustment *adjustment_cols = gtk_adjustment_new(1, 1, 100, 1, 0, 0);
    GtkWidget *cols_spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_cols), 1, 0);
    gtk_grid_attach(GTK_GRID(grid), cols_spin, 1, 1, 1, 1);

    GtkWidget *cols_label2 = gtk_label_new("COLUMNS OF MATRIX-2:");
    gtk_grid_attach(GTK_GRID(grid), cols_label2, 0, 2, 1, 1);

    GtkAdjustment *adjustment_cols2 = gtk_adjustment_new(1, 1, 100, 1, 0, 0);
    GtkWidget *cols_spin2 = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_cols2), 1, 0);
    gtk_grid_attach(GTK_GRID(grid), cols_spin2, 1, 2, 1, 1);

    GtkWidget *submit_button = gtk_button_new_with_label("SUBMIT");
    gtk_grid_attach(GTK_GRID(grid), submit_button, 0, 3, 2, 1);

    g_object_set_data(G_OBJECT(submit_button), "rows_spin", rows_spin);
    g_object_set_data(G_OBJECT(submit_button), "cols_spin", cols_spin);
    g_object_set_data(G_OBJECT(submit_button), "cols_spin2", cols_spin2);
    g_signal_connect(submit_button, "clicked", G_CALLBACK(spinsubmit9), NULL);

    gtk_window_move(GTK_WINDOW(spin8), 350, 110);
    gtk_widget_show_all(spin8);
}

int a9, b9, c;

void spinsubmit9(GtkWidget *button, gpointer data) {
    a9 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button), "rows_spin")));
    b9 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button), "cols_spin")));
    c = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button), "cols_spin2")));

   // printf("%d %d %d",a9,b9,c);

    multiply_mat();
}

GtkWidget *M1, *M2, *mul, *rebtn9, *X9, *Y9;
double **arr13, **arr14, **mularr;
GtkWidget ***mat11, ***mat12, ***res9;

void multiply_mat() {
    arr13 = malloc(a9 * sizeof(double *));
    arr14 = malloc(b9 * sizeof(double *));
    mularr = malloc(a9 * sizeof(double *));
    for (int i = 0; i < a9; i++) {
        arr13[i] = malloc(b9 * sizeof(double));
        mularr[i] = malloc(c * sizeof(double));
    }

    for (int i = 0; i < b9; i++) {
    arr14[i] = malloc(c * sizeof(double));
    }

    mat11 = (GtkWidget ***)malloc(a9 * sizeof(GtkWidget **));
    mat12 = (GtkWidget ***)malloc(b9 * sizeof(GtkWidget **));
    res9 = (GtkWidget ***)malloc(a9 * sizeof(GtkWidget **));
    for (int i = 0; i < a9; i++) {
        mat11[i] = (GtkWidget **)malloc(b9 * sizeof(GtkWidget *));
        res9[i] = (GtkWidget **)malloc(c * sizeof(GtkWidget *));
    }

    for (int i = 0; i < b9; i++) {
        mat12[i] = (GtkWidget **)malloc(c * sizeof(GtkWidget *));
    }

    GtkWidget *m1 = gtk_grid_new();
    GtkWidget *m2 = gtk_grid_new();
    GtkWidget *r = gtk_grid_new();

    GtkWidget *btn;
    int i = 0, j = 0;

    M1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(M1), "Matrix-1");
    gtk_container_set_border_width(GTK_CONTAINER(M1), 10);
    gtk_window_move(GTK_WINDOW(M1), 680, 110);

    M2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(M2), "Matrix-2");
    gtk_container_set_border_width(GTK_CONTAINER(M2), 10);
    gtk_window_move(GTK_WINDOW(M2), 680, 350);

    btn = gtk_button_new_with_label("MULTIPLY");
    g_signal_connect(btn, "clicked", G_CALLBACK(multiplication), NULL);
    gtk_grid_attach(GTK_GRID(m2), btn, 1, b9, 1, 1);

    mul = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(mul), "Result");
    gtk_container_set_border_width(GTK_CONTAINER(mul), 10);

    rebtn9 = gtk_button_new_with_label("RECALCULATE");
    g_signal_connect(rebtn9, "clicked", G_CALLBACK(recalculate9), NULL);
    gtk_grid_attach(GTK_GRID(r), rebtn9, 0, a9, 1, 1);

    X9 = gtk_button_new_with_label("TERMINATE");
    g_signal_connect(X9, "clicked", G_CALLBACK(exitm), NULL);
    gtk_grid_attach(GTK_GRID(r), X9, 0, a9+1, 1, 1);

    Y9 = gtk_button_new_with_label("EXIT TO MAIN");
    g_signal_connect(Y9,"clicked",G_CALLBACK(exitY9),NULL);
    gtk_grid_attach(GTK_GRID(r),Y9,0,a9+2,1,1);

    gtk_window_move(GTK_WINDOW(mul), 1200, 240);

    for (i = 0; i < a9; i++) {
        for (j = 0; j < b9; j++) {
            mat11[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m1), mat11[i][j], j, i, 1, 1);
        }
    }

    for (i = 0; i < b9; i++) {
        for (j = 0; j < c; j++) {
            mat12[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(m2), mat12[i][j], j, i, 1, 1);
        }
    }

    for (i = 0; i < a9; i++) {
        for (j = 0; j < c; j++) {
            res9[i][j] = gtk_label_new(NULL);
            gtk_grid_attach(GTK_GRID(r), res9[i][j], j, i, 1, 1);
        }
    }

    gtk_container_add(GTK_CONTAINER(M1), m1);
    gtk_container_add(GTK_CONTAINER(M2), m2);
    gtk_container_add(GTK_CONTAINER(mul), r);

    gtk_widget_show_all(M1);
    gtk_widget_show_all(M2);
    gtk_widget_hide(mul);
}

void multiplication() {
    int i = 0, j = 0, k = 0;
    double sum = 0;

    double **arr14_transpose = malloc(c * sizeof(double *));
    for (i = 0; i < c; i++) {
        arr14_transpose[i] = malloc(b9 * sizeof(double));
    }

    for (i = 0; i < b9; i++) {
        for (j = 0; j < c; j++) {
            arr14_transpose[j][i] = atof(gtk_entry_get_text(GTK_ENTRY(mat12[i][j])));
        }
    }

    for (i = 0; i < a9; i++) {
        for (j = 0; j < c; j++) {
            sum = 0;
            for (k = 0; k < b9; k++) {
                arr13[i][k] = atof(gtk_entry_get_text(GTK_ENTRY(mat11[i][k])));
                sum += arr13[i][k] * arr14_transpose[j][k];
            }
            mularr[i][j] = sum;
        }
    }

    char buffer[1000];
    for (i = 0; i < a9; i++) {
        for (j = 0; j < c; j++) {
            sprintf(buffer, "%lf  ", mularr[i][j]);
            gtk_label_set_text(GTK_LABEL(res9[i][j]), buffer);
        }
    }

    FILE *p;
    p = fopen("history.txt", "a");

    if (p == NULL) {
        printf("unable to open file");
        exit(1);
    }

    fprintf(p, "[%d]\n", hist);
    hist++;
    fputs("Multiplication of matrices\n", p);
    fputs("Matrix1:\n", p);

    for (i = 0; i < a9; i++) {
        for (j = 0; j < b9; j++) {
            fprintf(p, "%lf ", arr13[i][j]);
        }
        fputc('\n', p);
    }

    fputc('\n', p);

    fputs("Matrix2:\n", p);

    for (i = 0; i < b9; i++) {
        for (j = 0; j < c; j++) {
            fprintf(p, "%lf ", arr14_transpose[j][i]);
        }
        fputc('\n', p);
    }

    fputc('\n', p);

    fputs("Result:\n", p);
    for (i = 0; i < a9; i++) {
        for (j = 0; j < c; j++) {
            fprintf(p, "%lf ", mularr[i][j]);
        }
        fputc('\n', p);
    }

    fputc('\n', p);

    fclose(p);

    gtk_widget_show_all(mul);
}

void recalculate9() {
    int i, j;

    for (i = 0; i < a9; i++) {
        for (j = 0; j < c; j++) {
            gtk_entry_set_text(GTK_ENTRY(mat11[i][j]), "");
            gtk_entry_set_text(GTK_ENTRY(mat12[i][j]), "");
        }
    }

    for (i = 0; i < a9; i++) {
        for (j = 0; j < c; j++) {
            char buffer[1000];
            sprintf(buffer, "%lf", mularr[i][j]);
            gtk_entry_set_text(GTK_ENTRY(mat11[i][j]), buffer);
        }
    }

    //link the recalculate with all possible operations of the result
    gtk_window_move(GTK_WINDOW(mul), 1200, 240);
    gtk_widget_hide(mul);
}

void exitm() {

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

    for (int i = 0; i < a9; i++) {
        free(arr13[i]);
        free(mularr[i]);
        free(mat11[i]);
        free(res9[i]);
    }
    free(arr13);
    free(mularr);
    free(mat11);

    for (int i = 0; i < b9; i++) {
        free(mat12[i]);
    }
    free(mat12);
    free(res9);

    gtk_main_quit();
}

void exitY9(){

    gtk_widget_destroy(M1);
    gtk_widget_destroy(M2);
    gtk_widget_destroy(mul);
    gtk_widget_destroy(menumat);
    gtk_widget_destroy(spin8);

    system("cls");
    main();
}
