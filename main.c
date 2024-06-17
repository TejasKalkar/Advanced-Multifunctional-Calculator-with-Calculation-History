//gcc -o main main.c $(pkg-config --cflags --libs gtk+-3.0)
#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include<limits.h>
#include <unistd.h>
#include"header.h"
 
int hist=1;
int current_operation=-1;
int main(int argc,char *argv[]){

  gtk_init(&argc,&argv);
  printf("\033[0;31m");
  printf("\033[6mCALCULATOR\033[0m\n");
  printf("\033[0;34m");
  printf("1-> MATRIX OPERATIONS\n");
  printf("2-> BASE CONVERTER\n");
  printf("3-> STATISTICS\n");
  printf("4-> BASIC\n");
  printf("5-> TRIGONOMETRY\n");
  printf("6-> PHASOR ALGEBRA\n");

  int n;
  scanf("%d",&n);

  switch(n){

       case 1:
           system("cls");
           printf("\033[6mINSTRUCTIONS\033[0m\n");
           printf("\033[0;31m");
           printf("USE TAB TO MOVE TO NEXT CELL\n");
           printf("YOU CAN ALSO USE ARROW KEYS TO MOVE UP AND DOWN\n");
           printf("\033[6mPRESS ENTER TO CONTINUE\033[0m\n");
           getchar();
           matrix_menu();
           break;

       case 2:
           system("cls");
           base_conv();
           break;

       case 3:
           system("cls");
           stats();
           break;

       case 4:
           system("cls");
           basic();
           break;

       case 5:
                system("cls");
        		int tri ;
        		// scanf("%d",&tri);
        		if(tri==1){
             		system("cls");
                 trigo();
        
        }
        else if(tri==2){
            system("cls");
            inv_trigo();
        }
        else if(tri==3){
            system("cls");
                    hyperbolic();

        }
            //    switch(tri){

        //          case 1:
        //             system("cls");
        //             trigo();
        //             break;
        //          case 2:
        //             inv_trigo();
        //             break;
        //          case 3:
        //              system("cls");
        //             hyperbolic();
        //             break;
        //          default:
        //             break;
        //    }
           break;

       case(6):
       phasors();
           break;

  }

  gtk_main();
  return 0;
}

