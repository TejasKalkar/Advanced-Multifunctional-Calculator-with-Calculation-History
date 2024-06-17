#include<gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include<limits.h>
#include <unistd.h>
#include"header.h"

void trigo() {
    FILE* fp = fopen("history.txt","a");
    if(fp == NULL)
        {   printf("\033[31m");
            printf("Filecould not be opened");
            exit(1);
        }

    int menu_option;
    long double angle;

    int unit_choice;

    char *str = "\033[1;33m\033[4mWelcome to Trigonometry Calculator!!\033[0m \n";
    int i = 0;
    while(str[i] != '\0')
    {
        printf("%c",str[i]);
        fflush(stdout);
        usleep(40000);
        i++;
    }
    printf("\033[1mChoose angle unit:\033[0m\n");
    printf("\033[1;36m1. Degrees\n");
    printf("2. Radians\n\033[0m");


    printf("\033[1mEnter your choice (1 or 2):\033[0m ");
    scanf("%d", &unit_choice);


    while (unit_choice != 1 && unit_choice != 2) {
        printf("\033[1;31mInvalid input! Please enter 1 for degrees or 2 for radians: \033[0m");
        scanf("%d", &unit_choice);
    }


    char angle_unit[10];
    if (unit_choice == 1)
        strcpy(angle_unit, "degrees");
    else
        strcpy(angle_unit, "radians");

    printf("Current unit->%s",angle_unit);
    while (1) {
        printf("\n\033[1;35mMenu\033[0m\n");
        printf("\033[1;32m1. Sin\n");
        printf("2. Cos\n");
        printf("3. Tan\n");
        printf("4. Cot\n");
        printf("5. Sec\n");
        printf("6. Cosec\n");
        printf("7. Change angle unit\n");
        printf("8. Clear Screen\n");
        printf("9. Exit\n\033[0m");

        printf("\033[1mEnter your choice:\033[0m ");
        if (scanf("%d", &menu_option) != 1 || menu_option < 1 || menu_option > 9 || getchar() != '\n') {
            printf("\033[1;31mError: Invalid menu_option! Please enter an integer between 1 and 9.\033[0m\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        if (menu_option == 9) {
            printf("\033[1mExiting...\nThanks for using our Trigonometry calculator\U0001F64F\033[0m\n");
            system("cls");
            main();
            break;
        }
        else if (menu_option == 8) {

            system("clear||cls");
            continue;
        }
        else if (menu_option == 7) {

            printf("\033[1mChoose angle unit:\033[0m\n");
    printf("\033[1;36m1. Degrees\n");
    printf("2. Radians\n\033[0m");
    printf("\033[1mEnter your menu_option (1 or 2):\033[0m ");
    scanf("%d", &unit_choice);

    while (unit_choice != 1 && unit_choice != 2) {
        printf("\033[1;31mInvalid input! Please enter 1 for degrees or 2 for radians: \033[0m");
        scanf("%d", &unit_choice);
    }

    strcpy(angle_unit, (unit_choice == 1) ? "degrees" : "radians");
    printf("\033[1mAngle unit changed to %s\033[0m\n", angle_unit);
    continue;

        }
        else if (menu_option < 1 || menu_option > 9) {
            printf("\033[1;31mError: Invalid menu_option! Please choose an operation between 1 and 9.\033[0m\n");
            continue;
        }

        printf("\033[1mEnter angle in %s:\033[0m ", angle_unit);
        char input[100];
        scanf("%s", input);

        // Validate input
        if (!isValidNum(input)) {
            printf("\033[1;31mError: Invalid input. Please enter a valid number.\033[0m\n");

            while (getchar() != '\n');
            continue;
        }

        angle = atof(input);

        if (unit_choice == 1) {
            angle = angle * (Pi / 180.0);
        }

        long double result;

        switch (menu_option) {
            case 1:
                result = sine(angle);
                printf("\033[1;32msin %.9Lf %s = \033[0m %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                fprintf(fp, "sin %.9Lf %s = %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                break;
            case 2:
                result = cosine(angle);
                printf("\033[1;32mcos %.9Lf %s = \033[0m %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                fprintf(fp, "cos %.9Lf %s = %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                break;
            case 3:
                result = tangent(angle);
                if (result < LONG_MAX){

                 printf("\033[1;32mtan %.9Lf %s = \033[0m %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                fprintf(fp, "tan %.9Lf %s = %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                }
                else{
                    printf("\033[1;31mtan %.9Lf %s is not defined \033[0m \n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad");
                    fprintf(fp, "tan %.9Lf %s is not defined\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad");
                }

                break;
            case 4:

                result = cotangent(angle);
                if (result < LONG_MAX){
                printf("\033[1;32mcot %.9Lf %s = \033[0m %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                fprintf(fp, "cot %.9Lf %s = %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                }

                else{
                    printf("\033[1;31mcot %.9Lf %s is not defined \033[0m \n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad");
                    fprintf(fp, "cot %.9Lf %s is not defined\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad");
                }

                break;


            case 5:
                result = secant(angle);
                if (result < LONG_MAX){

                 printf("\033[1;32msec %.9Lf %s = \033[0m %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                 fprintf(fp, "sec %.9Lf %s = %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                }
                else{
                    printf("\033[1;31msec %.9Lf %s is not defined \033[0m \n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad");
                    fprintf(fp, "sec %.9Lf %s is not defined\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad");
                }
                break;
            case 6:

                result = cosecant(angle);
                 if (result < LONG_MAX){
                 printf("\033[1;32mcosec %.9Lf %s = \033[0m %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                 fprintf(fp, "cosec %.9Lf %s = %.9Lf\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad", result);
                }
                else{
                    printf("\033[1;31mcosec %.9Lf %s is not defined \033[0m \n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad");
                    fprintf(fp, "cosec %.9Lf %s is not defined\n", (unit_choice == 1) ? atof(input) : angle, (unit_choice == 1) ? "deg" : "rad");
                }
                break;
            default:
                printf("\033[1;31mInvalid choice! Please enter a number between 1 and 9.\033[0m\n");
                continue;
        }



    }
    fprintf(fp, "\n**************************************************************************************\n");

    return;
}

long double power(long double base, int exponent) {
    long double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

long double facto(int n) {
    if (n == 0)
        return 1;
    else
        return n * facto(n - 1);
}

long double sine(long double x) {
    long double result = 0;
    int signature = 1;
    for (int n = 0; n < 20; n++) {
        long double term = power(x, 2 * n + 1) / facto(2 * n + 1);
        result += signature * term;
        signature *= -1;
    }
    return result;
}

long double cosine(long double x) {
    long double result = 0;
    int signature = 1;
    for (int n = 0; n < 20; n++) {
        long double term = power(x, 2 * n) / facto(2 * n);
        result += signature * term;
        signature *= -1;
    }
    return result;
}
long double tangent(long double x) {
    long double Pi2_multiple = 2.0 *x / Pi;
    long double Pi_multiple = x / Pi;

    if (Pi2_multiple - (long)Pi2_multiple == 0 && Pi_multiple - (long)Pi_multiple != 0) {


        return LONG_MAX;
    } else {
        return sine(x) / cosine(x);
    }
}
long double cotangent(long double x) {

    long double Pi_multiple = x / Pi;
    if ((Pi_multiple - (long)Pi_multiple == 0)) {

        return LONG_MAX;
    } else {
        return cosine(x) / sine(x);
    }
}


long double secant(long double x) {
    long double Pi2_multiple = 2.0 *x / Pi;
    long double Pi_multiple = x / Pi;
    if ((Pi2_multiple - (long)Pi2_multiple == 0) && Pi_multiple - (long)Pi_multiple != 0 ) {

        return LONG_MAX;
    } else {
        return 1.0 / cosine(x);
    }
}

long double cosecant(long double x) {
    long double Pi_multiple = x / Pi;
    if ((Pi_multiple - (long)Pi_multiple == 0)) {
        return LONG_MAX;
    } else {
        return 1 / sine(x);
    }

}


bool isValidNum(const char *str) {

     if (!isdigit(*str) && *str != '.' && *str != '-') {
            return false;
        }
        str++;
    while (*str) {
        if (!isdigit(*str) && *str != '.') {
            return false;
        }
        str++;
    }
    return true;


    return 0;
}

int choice;


void inv_trigo(){


   system("cls");
   printf("\033[0;34m");
   printf("\n\n INVERSE FUNCTIONS :\n\n");
   printf("1.)Sin\n");
   printf("2.)Cos\n");
   printf("3.)Tan\n");
   printf("4.)Cosec\n");
   printf("5.)Sec\n");
   printf("6.)Cot\n");
   printf("7.)Exit");
   printf("\nEnter Choice: "); //Input
   scanf("%d",&choice);

   Inverse(choice); //Calling Function



   system("cls");
   main();
}



void Inverse(int choice){ //Defining Function
    double n;
    int choice1;
    switch(choice){
        case 1: printf("Enter value: ");
                scanf("%lf",&n);
                if(0<=n && n<=1){ //Considers the value of input and gives output accordingly
                   double sum=n;
                   double num=1;
                   double fnum=num*n*n*n;
                   double den=2*3;
                   double ratio;
                   ratio=fnum/den;
                   sum=sum+ratio;
                   int i=4,j=1;

                   while(ratio>=0.00001){ //Termination Condition
                    if(n==0){  //Base Case
                        break;
                    }
                    if(n==1){
                        sum=1.57;
                        break;
                    }
                    num=num+2; //Numerator Updation
                    fnum=fnum*num*n*n;  //Final nummerator Updation
                    den=den/(2*j+1);  //Denominator Updation
                    j=j+1;
                    den=den*(i)*(2*j+1);
                    i=i+2;
                    ratio=fnum/den; //Ratio
                    sum=sum+ratio; //Sum is getting updated
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n"); //For checking the conversion pattern
                    scanf("%d",&choice1);
                    if(choice1==1){
                        printf("%lf degrees",(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",sum);
                    }
                    else{ //For checking the valid input
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                            printf("%lf degrees",(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",sum);
                        }
                    }
                }
                else if(-1<=n && n<0){
                   double sum=n;
                   double num=1;
                   double fnum=1*n*n*n;
                   double den=2*3;
                   double ratio;
                   ratio=fnum/den;
                   sum=sum+ratio;
                   int i=4,j=1;

                   while(ratio<=-0.00001){
                    if(n==-1){
                        sum=-1.57;
                        break;
                    }
                    num=num+2;
                    fnum=fnum*num*n*n;
                    den=den/(2*j+1);
                    j=j+1;
                    den=den*(i)*(2*j+1);
                    i=i+2;
                    ratio=fnum/den;
                    sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                         printf("%lf",(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                            printf("%lf",(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",sum);
                        }
                    }

                }
                else{
                    printf("Sin inverse x is not defined\n");
                }
                break;
        case 2: printf("Enter value: ");
                scanf("%lf",&n);
                if(0<=n && n<=1){
                   double sum=n;
                   double num=1;
                   double fnum=1*n*n*n;
                   double den=2*3;
                   double ratio;
                   ratio=fnum/den;
                   sum=sum+ratio;
                   int i=4,j=1;

                   while(ratio>=0.00001){ //Performs the series of respective inverse functions
                    if(n==0){
                        sum=0;
                        break;
                    }
                    if(n==1){
                        sum=1.57;
                        break;
                    }
                    num=num+2;
                    fnum=fnum*num*n*n;
                    den=den/(2*j+1);
                    j=j+1;
                    den=den*(i)*(2*j+1);
                    i=i+2;
                    ratio=fnum/den;
                    sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                         printf("%lf",90-(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",1.57-sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                             printf("%lf",90-(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",1.57-sum);
                        }
                    }
                }
                else if(-1<=n && n<0){
                   double sum=n;
                   double num=1;
                   double fnum=1*n*n*n;
                   double den=2*3;
                   double ratio;
                   ratio=fnum/den;
                   sum=sum+ratio;
                   int i=4,j=1;

                   while(ratio<=-0.00001){
                    if(n==-1){
                        sum=-1.57;
                        break;
                    }
                    num=num+2;
                    fnum=fnum*num*n*n;
                    den=den/(2*j+1);
                    j=j+1;
                    den=den*(i)*(2*j+1);
                    i=i+2;
                    ratio=fnum/den;
                    sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                         printf("%lf",90-(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",1.57-sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                             printf("%lf",90-(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",1.57-sum);
                        }
                    }
                }
                else{
                    printf("Cos inverse x is not defined\n");
                }
                break;
        case 3: printf("Enter value: ");
                scanf("%lf",&n);
                if(-1<n && n<1){
                   double sum=n;
                   double num=n;
                   double den=1;
                   double ratio=n;
                   while(den<=1000){
                        if(n==0){
                          break;
                        }
                        num= num*(-1)*n*n;
                        den=den+2;
                        ratio=num/den;
                        sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                        printf("%lf",(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                            printf("%lf",(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",sum);
                        }
                    }
                }
                else if(n>=1){
                    double sum=-1/n;
                    double num=-1;
                    double den=1; //Deniminator Updation
                    double fden=n; //Final Denominator Updation
                    double ffden=den*fden; //Final Final Denominator Updation
                    double ratio=-1/n;
                    while(ffden<=1000){
                            num= num*(-1);
                            den=den+2;
                            fden=fden*n*n;
                            ffden=den*fden;
                            ratio=num/ffden;
                            sum=sum+ratio;
                        }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                         printf("%.3lf",((1.57+sum)*180)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",1.57+sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                             printf("%lf",((1.57+sum)*180)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",1.57+sum);
                        }
                    }
                }
                else if(n<=-1){
                        double sum=-1/n;
                        double num=-1;
                        double den=1;
                        double fden=n;
                        double ffden=den*fden;
                        double ratio=-1/n;
                        while(den<=1000){
                                num=num*(-1);
                                den=den+2;
                                fden=fden*n*n;
                                ffden=den*fden;
                                ratio=num/ffden;
                                sum=sum+ratio;
                            }
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                            if(choice1==1){
                                printf("%lf",((-1.57+sum)*180)/3.14);
                            }
                            else if(choice1==2){
                                printf("%lf radians",-1.57+sum);
                            }
                            else{
                                do{
                                    printf("Please enter valid input\n");
                                    printf("In which form do want the answer in:\n");
                                    printf("1.)Degree    2.)Radian\n");
                                    scanf("%d",&choice1);
                                }while(choice1<1 || choice1>2);
                                if(choice1==1){
                                    printf("%lf",((-1.57+sum)*180)/3.14);
                                }
                                else if(choice1==2){
                                    printf("%lf radians",-1.57+sum);
                                }
                            }
                }
                break;
        case 4: printf("Enter value: ");
                scanf("%lf",&n);
                if(n>1){
                   double sum=1/n;
                   double num=1;
                   double den=2*3;
                   double fden=n*n*n;
                   double ffden=den*fden;
                   double ratio;
                   ratio=num/ffden;
                   sum=sum+ratio;
                   int i=4,j=1;

                   while(ratio>=0.00001){
                    num=num+2;
                    den=den/(2*j+1);
                    j=j+1;
                    den=den*(i)*(2*j+1);
                    fden=fden*n*n;
                    ffden=den*fden;
                    i=i+2;
                    ratio=num/ffden;
                    sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                        printf("%lf",(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                            printf("%lf",(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",sum);
                        }
                    }
                }
                else if(n<-1){
                   double sum=1/n;
                   double num=1;
                   double den=2*3;
                   double fden=n*n*n;
                   double ffden=den*fden;
                   double ratio;
                   ratio=num/ffden;
                   sum=sum+ratio;
                   int i=4,j=1;

                   while(ratio<=-0.00001){
                    num=num+2;
                    den=den/(2*j+1);
                    j=j+1;
                    den=den*(i)*(2*j+1);
                    fden=fden*n*n;
                    ffden=den*fden;
                    i=i+2;
                    ratio=num/ffden;
                    sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                         printf("%lf",(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                             printf("%lf",(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",sum);
                        }
                    }
                }
                else{
                     printf("Cosec inverse x is not defined\n");
                }
                break;
        case 5: printf("Enter value: ");
                scanf("%lf",&n);
                if(n>1){
                   double sum=1/n;
                   double num=1;
                   double den=2*3;
                   double fden=n*n*n;
                   double ffden=den*fden;
                   double ratio;
                   ratio=num/ffden;
                   sum=sum+ratio;
                   int i=4,j=1;

                   while(ratio>=0.00001){
                    num=num+2;
                    den=den/(2*j+1);
                    j=j+1;
                    den=den*(i)*(2*j+1);
                    fden=fden*n*n;
                    ffden=den*fden;
                    i=i+2;
                    ratio=num/ffden;
                    sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                        printf("%lf",90-(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",1.57-sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                             printf("%lf",90-(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",1.57-sum);
                        }
                    }
                }
                else if(n<-1){
                   double sum=1/n;
                   double num=1;
                   double den=2*3;
                   double fden=n*n*n;
                   double ffden=den*fden;
                   double ratio;
                   ratio=num/ffden;
                   sum=sum+ratio;
                   int i=4,j=1;

                   while(ratio<=-0.00001){
                    num=num+2;
                    den=den/(2*j+1);
                    j=j+1;
                    den=den*(i)*(2*j+1);
                    fden=fden*n*n;
                    ffden=den*fden;
                    i=i+2;
                    ratio=num/ffden;
                    sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                        printf("%lf",90-(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",1.57-sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                            printf("%lf",90-(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",1.57-sum);
                        }
                    }
                }
                else{
                     printf("Sec inverse x is not defined\n");
                }
                break;
        case 6: printf("Enter value: ");
                scanf("%lf",&n);
                if(-1<n && n<1){
                   double sum=n;
                   double num=n;
                   double den=1;
                   double ratio=n;
                   while(den<=1000){
                        if(n==0){
                          break;
                        }
                        num= num*(-1)*n*n;
                        den=den+2;
                        ratio=num/den;
                        sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                        printf("%lf",90-(180*sum)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",1.57-sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                            printf("%lf",90-(180*sum)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",1.57-sum);
                        }
                    }
                }
                else if(n>=1){
                    double sum=1/n;
                    double num=1;
                    double den=1;
                    double fden=n;
                    double ffden=den*fden;
                    double ratio=1/n;
                    while(ffden<=1000){
                            num= num*(-1);
                            den=den+2;
                            fden=fden*n*n;
                            ffden=den*fden;
                            ratio=num/ffden;
                            sum=sum+ratio;
                    }
                    printf("In which form do want the answer in:\n");
                    printf("1.)Degree    2.)Radian\n");
                    scanf("%d",&choice1);
                    if(choice1==1){
                        printf("%lf",(sum*180)/3.14);
                    }
                    else if(choice1==2){
                        printf("%lf radians",sum);
                    }
                    else{
                        do{
                            printf("Please enter valid input\n");
                            printf("In which form do want the answer in:\n");
                            printf("1.)Degree    2.)Radian\n");
                            scanf("%d",&choice1);
                        }while(choice1<1 || choice1>2);
                        if(choice1==1){
                            printf("%lf",(sum*180)/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",sum);
                        }
                    }
                }
                else if(n<=-1){
                        double sum=1/n;
                        double num=1;
                        double den=1;
                        double fden=n;
                        double ffden=den*fden;
                        double ratio=1/n;
                        while(den<=1000){
                                num=num*(-1);
                                den=den+2;
                                fden=fden*n*n;
                                ffden=den*fden;
                                ratio=num/ffden;
                                sum=sum+ratio;
                            }
                        printf("In which form do want the answer in:\n");
                        printf("1.)Degree    2.)Radian\n");
                        scanf("%d",&choice1);
                        if(choice1==1){
                            printf("%lf",(3.14+sum)*180/3.14);
                        }
                        else if(choice1==2){
                            printf("%lf radians",3.14+sum);
                        }
                        else{
                            do{
                                printf("Please enter valid input\n");
                                printf("In which form do want the answer in:\n");
                                printf("1.)Degree    2.)Radian\n");
                                scanf("%d",&choice1);
                            }while(choice1<1 || choice1>2);
                            if(choice1==1){
                                printf("%lf",(3.14+sum)*180/3.14); //Output
                            }
                            else if(choice1==2){
                                printf("%lf radians",3.14+sum);
                            }
                        }
                }
                break;


        default:printf("Please enter valid input\n");
    }

}


void hyperbolic() {
    FILE *fp;
    fp = fopen("history.txt","a");
    double x;
    int menu_option;
    int numScanned;
    char *str = "\033[1;33m\033[4mWelcome to Hyperboilc Calculator!!\033[0m \n";
    int i = 0;
    while(str[i] != '\0')
    {
        printf("%c",str[i]);
        fflush(stdout);
        usleep(40000);
        i++;
    }

    while(1) {
        printf("\n\033[1;35mWhich hyperbolic function do you want to calculate?\033[0m\n");
        printf("\033[1;32m1) sinh(x)\n");
        printf("2) cosh(x)\n");
        printf("3) tanh(x)\n");
        printf("4) coth(x)\n");
        printf("5) sech(x)\n");
        printf("6) csch(x)\n");
        printf("7) Clear screen\n");
        printf("8) Exit\033[0m\n");
        printf("\033[1mEnter your choice (1-8): \033[0m");

        numScanned = scanf("%d", &menu_option);


        if (numScanned != 1) {
            printf("Invalid input. Please enter an integer.\n");

            while (getchar() != '\n');
            continue;
        }

        if (menu_option == 8) {
            printf("\033[1mExiting...\nThanks for using our Hyperbolic calculator\U0001F64F\033[0m\n");
            system("cls");
            main();
            break;
        }
        printf("\033[1mEnter the value of x(in rad): \033[0m");
        switch(menu_option) {

            case 1:

                scanf("%lf", &x);
                printf("\033[1;32msinh(%.9lf rad) = %.10lf\n", x, sinh(x));
                fprintf(fp,"sinh(%.9lf rad) = %.10lf\n", x, sinh(x));
                break;
            case 2:

                scanf("%lf", &x);
                printf("\033[1;32mcosh(%.9lf rad) = %.10lf\033[0m\n", x, cosh(x));
                fprintf(fp,"cosh(%.9lf rad) = %.10lf\n", x, cosh(x));
                break;
            case 3:

                scanf("%lf", &x);
                printf("\033[1;32mtanh(%.9lf rad) = %.10lf\033[0m\n", x, tanh(x));
                fprintf(fp,"tanh(%.9lf rad) = %.10lf\n", x, tanh(x));
                break;
            case 4:

                scanf("%lf", &x);
                printf("\033[1;32mcoth(%.9lf rad) = %.10lf\033[0m\n", x, coth(x));
                fprintf(fp,"coth(%.9lf rad) = %.10lf\n", x, coth(x));
                break;
            case 5:

                scanf("%lf", &x);
                printf("\033[1;32msech(%.9lf rad) = %.10lf\033[0m\n", x, sech(x));
                fprintf(fp,"sech(%.9lf rad) = %.10lf\n", x, sech(x));
                break;
            case 6:

                scanf("%lf", &x);
                printf("\033[1;32mcsch(%.9lf rad) = %.10lf\033[0m\n", x, csch(x));
                fprintf(fp,"csch(%.9lf rad) = %.10lf\n", x, csch(x));
                break;
            case 7:
                system("cls || clear");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    fprintf(fp,"\n************************************************************************************8\n");
    fclose(fp);
    return;
}
double Power(double x, int n) {
    if (n == 0)
        return 1.0;
    else if (n > 0)
        return x * Power(x, n - 1);
    else
        return 1.0 / Power(x, -n);
}

double exp(double x) {
    double result = 1.0;
    double term = 1.00;

    for (int i = 1; i <= 500; ++i) {
        term *= x / i;
        result += term;
    }
    return result;
}


double sinh(double x) {
    return (exp(x) - exp(-x)) / 2.0;
}

double cosh(double x) {
    return (exp(x) + exp(-x)) / 2.0;
}

double tanh(double x) {
    return sinh(x) / cosh(x);
}


double coth(double x) {
    return 1.0 / tanh(x);
}


double sech(double x) {
    return 1.0 / cosh(x);
}


double csch(double x) {
    return 1.0 / sinh(x);
}
