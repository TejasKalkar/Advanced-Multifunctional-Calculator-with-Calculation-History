#include<gtk/gtk.h>
#include"header.h"
#include<math.h>
#include<string.h>
#include <stdlib.h>

int b1,b2;
char str[100];

GtkWidget*number;
void base_conv(){

    GtkWidget *spin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(spin),"Input base1 and base2");
    gtk_container_set_border_width(GTK_CONTAINER(spin),10);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(spin), grid);

    GtkWidget *b1_label = gtk_label_new("BASE 1:");
    gtk_grid_attach(GTK_GRID(grid),b1_label,0,0,1,1);

    GtkAdjustment *adjustment_b1 = gtk_adjustment_new(1,2,36,1,0,0);
    GtkWidget *B1 = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_b1),1,0);
    gtk_grid_attach(GTK_GRID(grid),B1,1,0,1,1);

    GtkWidget *b2_label = gtk_label_new("BASE 2:");
    gtk_grid_attach(GTK_GRID(grid),b2_label,0,1,1,1);

    GtkAdjustment *adjustment_b2 = gtk_adjustment_new(1,2,36,1,0,0);
    GtkWidget *B2 = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment_b2),1,0);
    gtk_grid_attach(GTK_GRID(grid),B2,1,1,1,1);

    GtkWidget *n_label = gtk_label_new("NUMBER:");
    gtk_grid_attach(GTK_GRID(grid),n_label,0,2,1,1);

    number=gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid),number,1,2,1,1);

    GtkWidget* submit_button = gtk_button_new_with_label("SUBMIT");
    gtk_grid_attach(GTK_GRID(grid),submit_button,0,3,2,1);

    g_object_set_data(G_OBJECT(submit_button),"B1",B1);
    g_object_set_data(G_OBJECT(submit_button),"B2",B2);
    g_object_set_data(G_OBJECT(submit_button),"number",number);
    g_signal_connect(submit_button,"clicked",G_CALLBACK(basesubmit),NULL);

    gtk_window_move(GTK_WINDOW(spin), 350, 110);
    gtk_widget_show_all(spin);

}

void basesubmit(GtkWidget *button,gpointer data){

    b1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"B1")));
    b2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(g_object_get_data(G_OBJECT(button),"B2")));
    strcpy(str,gtk_entry_get_text(GTK_ENTRY(g_object_get_data(G_OBJECT(button),"number"))));

    //printf("%d %d %s",b1,b2,str);
    baseconvertor(b1,b2,str);
}

GtkWidget *b_window,*finalnumber;
void create_win_baseconv(){

     b_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_window_set_title(GTK_WINDOW(b_window), "RESULT");
     gtk_container_set_border_width(GTK_CONTAINER(b_window),10);

     GtkWidget*grid=gtk_grid_new();
     GtkWidget*label_for_base;
     label_for_base=gtk_label_new("THE NUMBER IN BASE 2 IS : ");
     gtk_label_set_markup(GTK_LABEL(label_for_base), "<span foreground='blue'>THE NUMBER IN BASE 2 IS : </span>");
     gtk_grid_attach(GTK_GRID(grid), label_for_base, 0, 0, 4, 1);
     finalnumber=gtk_label_new(NULL);

     gtk_grid_attach(GTK_GRID(grid), finalnumber, 4, 0, 1, 1);
     gtk_container_add(GTK_CONTAINER(b_window),grid);

     gtk_widget_hide(b_window);
}


char inp_num[100];
char out_num[100];
int deci_count;

char* basefinal(double base10num, int baseout)
{
    int whole = (int)base10num; //integer part of num1
    int bef_dec = 0; // count number of elements before the decimal point
    //char str[50];

    for(int i = 0; whole != 0; i++)
    {
        int val1 = whole % baseout;
        whole = whole / baseout;

        if(val1 <= 9)
        {
            out_num[bef_dec] = (char)(val1 + 48);
            bef_dec += 1;
        }

        else if(val1 > 9)
        {
            out_num[bef_dec] = (char)(val1 + 55);
            bef_dec += 1;
        }
    }

    for(int i = 0; i < bef_dec / 2; i++)
    {
        char temp = out_num[i];
        out_num[i] = out_num[bef_dec - i - 1];
        out_num[bef_dec - i - 1] = temp;
    }


    bef_dec += 1;

    double decinum = base10num - (int)base10num;
    double int_dec;
    int num3;


    for(int i = 0; i < deci_count; i++)
    {
        int_dec = decinum * baseout;
        num3 = (int)int_dec; //integer part of decimal
        for(int i = 0; i < deci_count; i++)
        {
           int_dec = decinum * baseout;
           num3 = (int)int_dec;

            if(num3 <= 9)
            {
                out_num[bef_dec] = (char)(num3 + '0');
                bef_dec++;
            }

            else
            {
                out_num[bef_dec] = (char)(num3 + 'A' - 10);
                bef_dec++;
            }

            decinum = int_dec - num3;

            if(i == deci_count - 1)
            {
                break;
            }
        }
    }
    return out_num;
}

double base10(char* inp_num, int basein)
{
    int size = strlen(inp_num);
    char point = '.';
    int bef_dec = 0; // number of integers before the decimal point
    double sum1 = 0; // answer of decimal values before the decimal point
    double sum2 = 0; // answer of decimal values after the decimal point

    while(inp_num[bef_dec] != point)
    {
        bef_dec++;
        if((bef_dec > size - 1))
        {
            break;
        }
    }

    bef_dec = bef_dec - 1;

    for(int i = bef_dec, j = 0; j < size; j++, i--)
    {
        char ch;
        ch = inp_num[j];
        if(ch == point)
        {
            break;
        }

        if(ch >= '0' && ch <= '9')
        {
            sum1 += pow(basein, (double)i) * ((int)ch - '0');
        }

        if(ch >= 'A' && ch <= 'Z')
        {
            sum1 += pow(basein, (double)i) * ((int)ch - 'A' + 10);
        }

    }

    int check_dot = 0;
    for(int i = 0; i < size; i++)
    {
        if(inp_num[i] == point)
        {
            check_dot = 1;
            break;
        }
    }

    if(check_dot == 0)
    {
        return sum1;
    }

    else
    {
        deci_count = size - bef_dec - 2; // number of digits after the decimal points // here 2 is subtracted because size-1 is total digits and (size -1)-1 because we have to exclude .

        for(int i = -1, j = size - deci_count; j < size; j++, i++)//
        {
            char ch;
            ch = inp_num[j];

            if(ch >= '0' && ch <= '9')
            {
                sum2 += pow(basein, i) * ((int)ch - '0');
            }

            if(ch >= 'A' && ch <= 'Z')
            {
                sum2 += pow(basein, i) * ((int)ch - 'A' + 10);
            }

        }

        double roundedans = sum1 + sum2;
        roundedans = round(roundedans * pow(10, deci_count)) / pow(10, deci_count);//used for rounding the number  //example -> if the number of values after the point is 5 then return 4 values


        return(roundedans);
    }
}


void baseconvertor(int b1,int b2,char *str)//used for checking whether input number is valid or not with respect to basein
{
    int basein;
    int baseout;
    int valid_num = 0;  // To check if input numbers is not greater than basein
    strcpy(inp_num,str);
    basein=b1;
    baseout=b2;

    for(int i = 0; i < strlen(inp_num); i++) // This loop is for checking if the input number lies in basein
    {
        char ch = inp_num[i];
        if(ch >= 'A' && ch <= 'Z')
        {
            int a = (int)ch - 'A' + 10; //used for converting A,B,C,D,E to their decimal equivalent 10,11,12,13,... in base system
            if(a >= basein)
            {
                valid_num++;
                break;
            }
        }


        if(ch >= '0' && ch <= '9')
        {
            int a = (int)ch - '0'; // used to for converting character digits to integer digits //ascii value of 0 is 48
            if(a >= basein)
            {
                valid_num++;
                break;
            }
        }

    }

    if(basein > 1 && basein < 37 && baseout > 1 && baseout < 37 && valid_num == 0) //if anywhere  valid_num had incremented that means base is lesser than its digits hence the loop should break
    {
        char* final = basefinal(base10(inp_num, basein), baseout);
        FILE* fp = fopen("history.txt","a");
        if(fp == NULL)
        {   printf("\033[31m");
            printf("Filecould not be opened");
            exit(1);
        }
        fprintf(fp,"%s in base %d is equal to %s in base %d\n",inp_num,basein,final,baseout);

        create_win_baseconv();

        char temp[100];
        strcpy(temp,final);

            gtk_label_set_text(GTK_LABEL(finalnumber), temp);
            gtk_window_move(GTK_WINDOW(b_window),700,100);
            gtk_widget_show_all(b_window);

    }

    else
    {   printf("\033[33m");
        printf("Invalid input in base conversion program.Program terminates\n");
        FILE* fp = fopen("history.txt","a");
        if(fp == NULL)
        {   printf("\033[34m");
            printf("File could not be opened");
            exit(1);
        }
        fputs("Invalid input in base conversion program.Program terminates\n",fp);

        create_win_baseconv();

        char temp[100];
        strcpy(temp,"INVALID INPUT");

            gtk_label_set_text(GTK_LABEL(finalnumber), temp);
            gtk_label_set_markup(GTK_LABEL(finalnumber), "<span foreground='red'>INVALID INPUT</span>");
            gtk_window_move(GTK_WINDOW(b_window),700,100);
            gtk_widget_show_all(b_window);
    }
}

