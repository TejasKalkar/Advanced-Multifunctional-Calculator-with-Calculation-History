#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include"header.h"

void stats()
{   printf("\033[0;33m");
    printf("Welcome to Statistics Part of Our Calculator\n\n");

    printf("\033[0;31m");
    printf("Choose the corresponding number for following operations :->\n");

    printf("\033[0;35m");
    printf("1 -> Mean for Ungrouped Data\n");
    printf("2 -> Mean for Discrete Frequency Distribution\n");
    printf("3 -> Mean for Continuous Frequency Distribution\n");
    printf("4 -> Median for Ungrouped Data\n");
    printf("5 -> Median for Discrete Frequency Distribution\n");
    printf("6 -> Median for Continuous Frequency Distribution\n");
    printf("7 -> Mode for Ungrouped Data\n");
    printf("8 -> Mode for Discrete Frequency Distribution\n");
    printf("9 -> Mode for Continuous Frequency Distribution\n");
    printf("10 -> Finding Standard Deviation and Variance for grouped/Ungrouped Data\n");
    printf("11 -> Finding the unknown among Mean,Median,Mode\n");

     printf("\033[0m");
    int num;
    scanf("%d",&num);

    switch(num)
    {
        case 1:
        mean_ungrpdata();
        break;

        case 2:
        mean_dis_fre_dis();
        break;

        case 3:
        mean_con_fre_dis();
        break;

        case 4:
        medi_ungrpdata();
        break;

        case 5:
        medi_dis_fre_dis();
        break;

        case 6:
        medi_con_fre_dis();
        break;

        case 7:
        mode_ungrpdata();
        break;

        case 8:
        mode_dis_fre_dis();
        break;

        case 9:
        mode_con_fre_dis();
        break;

        case 10:
        std_dev_varia();
        break;

        case 11:
        Unknown();
        break;
    }
    return;
}



void Unknown()
{
    system("cls"); //use cls for windows
    printf("\033[0;33m");
    printf("Please select the 2 Known Quantities from the corresponding numbers as shown below :->\n\n");

    printf("\033[0;32m");
    printf("1 -> Mean\n"
           "2 -> Median\n"
           "3 -> Mode\n");

    int kno1,kno2;
    char* unkno;
    double unknown,known1,known2;

    scanf("%d%d",&kno1,&kno2);
    printf("\033[0;33m");
    printf("Please enter values of these two quantities in the same order you entered their corresponding numbers previously\n");
    scanf("%lf%lf",&known1,&known2);


    if(!(kno1 == 3 || kno2 ==3))
    {
        unkno ="Mode";
        if(kno1 ==1)
        {
            unknown = 3*known2 -2*known1;
        }
        else
        {
            unknown = 3*known1 -2*known2;
        }
    }

    else if(!(kno1 == 2)|| kno2 == 2)
    {
        unkno = "Median";
        if(kno1 == 1)
        {
            unknown = (2*known1 + known2)/3.0;
        }

        else
        {
            unknown = (2*known2 + known1)/3.0;
        }
    }

    else if(!(kno1 == 1) || (kno2 == 1))
    {
        unkno = "Mean";
        if(kno1 == 2)
        {
           unknown = (3*known1 -known2)/2.0 ;
        }

        else
        {
             unknown = (3*known2 -known1)/2.0 ;
        }
    }
    printf("\033[0;34m");
    printf("%s is %lf",unkno,unknown);
    FILE* fp1 = fopen("history.txt","a");
    fprintf(fp1,"In finding the unknown ,Unknown %s is %lf\n",unkno,unknown);
    fclose(fp1);

    printf("\033[0;33;41m");
    printf("\nDo you still want to use this calculator (Y/N) ?\n");
    printf("\033[0m");
    getchar();
    char ch;

    scanf("%c",&ch);
    if(ch == 'y' || ch == 'Y')
    {
        system("cls"); //use cls for windows
        main();
    }
    else
    {
         system("cls"); //use cls for windows
         printf("\033[0;34m");
         printf("exiting...\n");
         printf("\033[0;35m");
         printf("exited");
         exit(1);
    }

}



void mean_ungrpdata()
{
    system("cls"); //use cls instead for windows
    double sum = 0;
    int count = 0 ;


    char str1[80];
    printf("\033[91m");
    printf("Please enter file name\n");
    getchar();

    scanf("%[^\n]s",str1);

    FILE*fp;
    fp = fopen(str1,"r");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("file could not be opened");
        exit(1);
    }

    double i;
    char str[1000];
    fscanf(fp,"%s,",str);
    while(fscanf(fp,"%lf,",&i) == 1)
    {
        sum = sum + i;
        count++;
    }

    sum = sum/count;
    printf("\033[93m");
    printf("Mean of the Ungrouped data is %lf",sum);

    FILE* fp1 = fopen("history.txt","a");
    fprintf(fp1,"Mean of the Ungrouped data is %lf\n",sum);
    fclose(fp1);
    fclose(fp);
    printf("\033[94m");
    printf("\nDo you still want to use the calculator (y/n)\n");
    getchar();
    char ch ;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
        system("cls"); //use cls for windows
        main();
    }

    else
    {    system("cls"); //use cls for windows
        printf("\033[0;33m");
        printf("exiting...\n");
        printf("\033[0;32m");
        printf("exited\n");
        exit(1);
    }

}

void mean_dis_fre_dis()
{
    system("cls");
    double sigmafx = 0;
    double sigmaf = 0;
    double f;
    double x;


    char str1[80];
    printf("\033[91m");
    printf("Please enter file name\n");
    getchar();

    scanf("%[^\n]s",str1);
    FILE*fp;
    fp = fopen(str1,"r+");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("file could not be opened");
        exit(1);
    }


    char str[100];
    fgets(str,90,fp);

    int i = 0;
    double p;

    while(fscanf(fp,"%lf",&p) == 1) //here the trick part is using i, p to initialise f,x successively  and also to note that after pointer has reached data then we can store in sigma fx also
    {
        i++;
        if((i%2) == 0)
        {
            x = p;
            sigmafx = sigmafx + (f*x);
        }

        if((i%2) != 0)
        {
            f = p;
            sigmaf = sigmaf + f;
        }
    }

    double mean = (sigmafx)/(sigmaf);
    printf("\033[93m");
    printf("Mean of the discrete frequency table is %lf",mean);

    FILE* fp1 = fopen("history.txt","a");
    fprintf(fp1,"Mean of the discrete frequency table is %lf\n",mean);
    fclose(fp1);
    fclose(fp);


    printf("\033[94m");
    printf("\nDo you still want to use the calculator (y/n)\n");
    getchar();
    char ch ;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
        system("cls"); //use cls for windows
        main();
    }

    else
    {   system("cls"); //use cls for windows
        printf("\033[0;33m");
        printf("exiting...\n");
        printf("\033[0;32m");
        printf("exited\n");
        exit(1);
    }

}

void mean_con_fre_dis()
{   system("cls");
    char str[80];
    printf("\033[91m");
    printf("Please enter file name\n");
    getchar();
    scanf("%[^\n]s",str);

    FILE* fp;
    fp = fopen(str,"r+");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("File could not be opened\n");
        exit(1);
    }


    char str1[100];
    fgets(str1,90,fp);

    double p,lowlim,upplim,f;
    double sigmafx =0 , sigmaf=0; //(here f is frequency and x is class marks)
    int i = 0;
    while(fscanf(fp,"%lf",&p) == 1)
    {   i++;
        if(i==2 || (i-2)%3 ==0)
        {
            lowlim = p;
        }

        if(i%3 == 0)
        {
            upplim = p;
            sigmafx += (((lowlim)+(upplim))/2)*f;
            sigmaf += f;
        }

        if(i == 1 || (i-1)%3 == 0)
        {
            f = p;
        }
    }

    double mean = sigmafx/sigmaf;
    printf("\033[91m");
    printf("Mean of continuous frequency table is  is %lf",mean);

    FILE* fp1 = fopen("history.txt","a");
    fprintf(fp1,"Mean of the continuous frequency table is %lf\n",mean);
    fclose(fp1);
    fclose(fp);
    printf("\033[92m");
    printf("\nDo you still want to use the calculator (y/n)\n");
    getchar();
    char ch ;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
        system("cls"); //use cls for windows
        main();
    }

    else
    {    system("cls"); //use cls for windows
         printf("\033[0;33m");
        printf("exiting...\n");
        printf("\033[0;32m");
        printf("exited\n");
        exit(1);
    }

}

void medi_ungrpdata()
{
    system("cls"); //use cls for windows
    printf("\033[1;31m");
    printf("Please tell how many data entries are there in the list \n");
    printf("\033[0m");
    int n,i;
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Length of array should be greater than  0");
        exit(1);
    }


    double* arr;
    arr = (double*)malloc(sizeof(double)*n);
    printf("\033[0;34m");
    printf("please tell all the data entries of your list one by one\n");

    for( i= 0; i<n;i++)
    {
        scanf("%lf",&arr[i]);
    }

    sort(arr,n);


    double median;
    if(n%2 ==0)
    {
        median = ((arr[n/2]) + arr[(n/2)-1])/2;
    }
    else
    {
       median = arr[(n)/2];
    }

    printf("\033[1;31m");

    printf("\nMedian of the data is %lf",median);
    FILE* fp1 = fopen("history.txt","a");
    fprintf(fp1,"Median of the ungrouped data is %lf\n",median);
    fclose(fp1);

    free(arr);

    printf("\033[0m");

    printf("\nDo you still want to use the calculator (y/n)\n");
    getchar();
    char ch ;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
        system("cls"); //use cls for windows
        main();
    }

    else
    {    system("cls"); //use cls for windows
         printf("\033[0;33m");
        printf("exiting...\n");
        printf("\033[0;32m");
        printf("exited\n");
        exit(1);
    }


}

void sort(double* arr ,int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j] >= arr[j+1])
            {
                double temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void medi_dis_fre_dis()
{   system("cls");
    char str[50];
    printf("\033[91m");
    printf("Please enter your File name\n");
    getchar();
    scanf("%[^\n]s",str);


    FILE *fp;
    fp = fopen(str,"r");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("file could not be opened\n");
        exit(1);
    }

    char str1[80];
    fgets(str1,80,fp);

    int i = 0;
    int f;
    int sigmaf = 0,posmed; //posmed is position of median // sigmaf is sum of frequencies taken successively


    while(fscanf(fp,"%d",&f) == 1)
    {
        i++; //used as a parameter to know whether data is reached or frequency is reached

        if((i%2) != 0)
        {
            sigmaf += f;
        }
    }


    if(sigmaf%2 == 0)
    {
        posmed = sigmaf/2;
    }

    if(sigmaf%2 != 0)
    {
        posmed = (sigmaf + 1)/2;
    }


    rewind(fp); //pointer is back to the starting of the file

    char str2[80];
    fgets(str2,80,fp);


    int sigmaf1=0;
    int f1;
    double data,p,median;
    int flag = 0,flag1 = 0;// will help identify which data is median
     i = 0; //another flag to distinguish between data and frequency

    while(fscanf(fp,"%lf",&p) == 1)
    {
        i++;

        if(i%2 !=0)
        {
            f1 = (int)p;
            if(posmed>=sigmaf1 && posmed<= sigmaf1+f1)
            {
                flag = 1;
            }
            sigmaf1 += f1;
        }

        else
        {
            data = p;

            if(flag1 == 1)
            {
                median = median +data;
                median = median/2.0;
                break;
            }

       else if(flag == 1)
            {
                if((sigmaf %2) == 0)
                {
                    median = data;
                    flag1 = 1;
                }
                else
                {
                    median = data;
                    break;
                }
            }
        }

    }

system("cls"); //use cls instead of windows
printf("\033[92m");
printf("Median of distributed frequency table is %lf",median);
FILE* fp1 = fopen("history.txt","a");
fprintf(fp1,"Median of distributed.txt is %lf\n",median);
fclose(fp1);
fclose(fp);

printf("\033[93m");
 printf("\nDo you still want to use the calculator (y/n)\n");
    getchar();
    char ch ;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
        system("cls"); //use cls for windows
        main();
    }

    else
    {    system("cls"); //use cls for windows
         printf("\033[0;33m");
        printf("exiting...\n");
        printf("\033[0;32m");
        printf("exited\n");
        exit(1);
    }
}

void medi_con_fre_dis()
{
    system("cls"); //use cls instead for windows

    char str[50];
    printf("\033[91m");
    printf("Please enter your File name\n");
    getchar();
    scanf("%[^\n]s",str);


    FILE *fp;
    fp = fopen(str,"r");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("File could not be opened");
        exit(1);
    }

    char str1[100];
    fgets(str1,99,fp);

    double a,b; //used for finding class width of a class
    double h; // h = class width of the class

    fscanf(fp,"%lf",&a);
    fscanf(fp,"%lf%lf",&a,&b);
    h = b-a;

    rewind(fp); // file pointer back to the start

    char str2[100];
    fgets(str2,99,fp);

    double cf = 0,t;//cumulative frequency,//temporary variable to store frequency of successive classes ,
    int i = 0;//used to find whether data is frequency or not
    while(fscanf(fp,"%lf",&t) == 1)
    {
       i++;

       if((i%3) == 1)
       {
        cf += t;
       }
    }
    int N = (int)cf; //total number of observations

    int med_chec = N/2;

    rewind(fp);

    char str3[100];
    fgets(str3,99,fp);

    double p;
     int f,sigmaf = 0;
    int flag =0;
    int cf1,f1;
    double low1;
    i = 0;

    while(fscanf(fp,"%lf",&p) == 1)
    {   i++;
        if(i%3 == 1)
        {   f = (int)p;
            if(sigmaf +f >=N/2)
            {
                cf1 =sigmaf;
                flag = 1;
                f1 = f;
            }
            sigmaf += f;
        }

        if((i%3) == 2)
        {
            if(flag ==1)
            {
                low1 = p;
                break;
            }
        }


    }
     double median;

       double temp = cf1;
        median = (low1) + ((((N/2) - cf1)/(f1*1.0))*(h*1.0));
        printf("Median  of continuous frequency table is %lf\n",median);

        FILE* fp1 = fopen("history.txt","a");
        fprintf(fp1,"Median of continuous.txt is %lf\n",median);
        fclose(fp1);
        fclose(fp);

 printf("\033[93m");
    printf("\n\nDo you still want to use the Calculator : Y/N\n");
    getchar();
    char ch;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
       system("cls");// for windows use cls instead of cls
        main();
    }
    else
    {   system("cls");// for windows use cls instead of cls
        printf("\033[94m");
        printf("\nExiting...\n");
        printf("\033[91m");
        printf("Exited\n");
        exit(1);
    }

}

void mode_dis_fre_dis()
{
     system("cls"); //use cls instead for windows
    char str[50];
    printf("\033[91m");
    printf("Please enter your file name\n");
    getchar();
    scanf("%[^\n]s",str);


    FILE* fp;
    fp = fopen(str,"r");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("File could not be opened");
        exit(1);
    }

    char str1[100];
    fgets(str1,99,fp);

    int f,maxf =0;
    int i =0;
    while(fscanf(fp,"%d",&f)==1)
    {   i++;
        if((i%2) == 1)
        {
            if(maxf<=f)
            {
                maxf = f;
            }
        }
    }

    rewind(fp);
    char str2[100];
    fgets(str2,99,fp);
    double data,mode;
    int f1;
    while(fscanf(fp,"%d %lf",&f1,&data) == 2)
    {
        if(f1 == maxf)
        {   printf("\033[94m");
            printf("Mode is %lf\n",data);
            FILE* fp1 = fopen("history.txt","a");
            fprintf(fp1,"Mode of distributed.txt is %lf\n",data);
            fclose(fp1);
        }
    }

    fclose(fp);
     printf("\033[93m");
    printf("\n\nDo you still want to use the Calculator : Y/N\n");
    getchar();
    char ch2;
    scanf("%c",&ch2);

    if(ch2 =='y' || ch2 == 'Y')
    {
       system("cls");// for windows use cls instead of cls
        main();
    }
    else
    {   system("cls");// for windows use cls instead of cls
        printf("\033[94m");
        printf("\nExiting...\n");
        printf("\033[91m");
        printf("Exited\n");
        exit(1);
    }
}

void mode_ungrpdata()
{
    system("cls");
    printf("\033[91m");
    printf("Please enter number of elements in the data set\n");
    int num;
    scanf("%d",&num);

    int i,j,maxcount =0;
    double arr[num];

    printf("\033[92m");
    printf("Please enter elements in the data set\n");
    for(i=0;i<num;i++)
    {
        scanf("%lf",&arr[i]);
    }

    int count;

    for(i=0;i<num;i++)
    {    count =0;
        for(j=0;j<num;j++)
        {
            if(arr[i] == arr[j])
            {
                count ++;
            }
            if(count >= maxcount)
            {
                maxcount = count;
            }
        }
    }
    int k,flag=0,temp=INT_MIN;
    for(i=0;i<num;i++)
    {   int count =0;
        flag = 0;
        for(j=0;j<num;j++)
        {
            if(arr[i] == arr[j])
            {
                count ++;
            }
        }
        if(count == maxcount)
        {
            for(k=0;k<i;k++)
            {
                if(arr[i] == arr[k])
                {
                    flag = 1;
                }
            }
            if(flag == 0&&arr[i]!=temp){
            temp=arr[i];
            printf("\033[93m");
            printf("Mode  of ungrouped data is %lf\n",arr[i]);
            FILE* fp1 = fopen("history.txt","a");
            fprintf(fp1,"Mode  of ungrouped data is %lf\n",arr[i]);
            fclose(fp1);
            }
        }


    }

     printf("\033[93m");
    printf("\n\nDo you still want to use the Calculator : Y/N\n");
    getchar();
    char ch;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
       system("cls");// for windows use cls instead of cls
        main();
    }
    else
    {   system("cls");// for windows use cls instead of cls
        printf("\033[94m");
        printf("\nExiting...\n");
        printf("\033[91m");
        printf("Exited\n");
        exit(1);
    }
}




void mode_con_fre_dis()
{
    system("cls"); //use cls instead for windows
    char str[50];
    printf("\033[91m");
    printf("Please enter your file name\n");
    getchar();
    scanf("%[^\n]s",str);


    FILE* fp;
    fp = fopen(str,"r");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("File could not be opened");
        exit(1);
    }

    char str2[99];
    fgets(str2,98,fp);

    int count = 0;
    double i;

    while(fscanf(fp,"%lf",&i) == 1)
    {
        count++;
    }

    int n_f = count/3;
    double farr[n_f];

    rewind(fp);

    char str1[99];
    fgets(str1,98,fp);

    count = 0;
    int fele = 0;
    int maxfele = 0;
    int indexmaxfele = 0;
    int flag = 0;
    double low,high;

    while(fscanf(fp,"%lf",&i) == 1)
    {
        count ++;
        if((count%3) == 1)
        {
            farr[fele] = (int)i;
            if (maxfele <= farr[fele])
            {
                maxfele = farr[fele];
                indexmaxfele = fele;
            }
            fele++;
        }

        if((count%3) == 2)
        {
            if(flag == 2 || flag == 3)
            {
                continue;
            }

            flag = 1;
            low = i;
        }

        if((count%3) == 0)
        {
            if(flag == 2 || flag == 3)
            {
                continue;
            }

            if(flag == 1)
            {
                high = i;
            }
        }
    }


double h = high - low;

rewind(fp);
int flag1 =0;

char str3[99];
fgets(str3,98,fp);
double j,l;
count = 0;
int count5 = -1;
while(fscanf(fp,"%lf",&j) == 1)
{   count++;
    if((count%3) == 1)
    {
        count5++;
    }

    if((count%3) == 2)
    {
        if(count5 == indexmaxfele)
        {
            l = j;

        }
    }
}

double f0,f2;
double f1 = maxfele;
if(indexmaxfele != n_f){
f2 = farr[indexmaxfele+1];
}
else
{
    f2 =0;
}
if(indexmaxfele != 0)
{ f0 = farr[indexmaxfele-1];
}
else
{
 f0 = 0;
}

double mode = l + ((f1 - f0)/(2*f1 - f0 -f2))*h;
printf("\033[94m");
printf("Mode of continuous frequency table is %lf",mode);
FILE* fp1 = fopen("history.txt","a");
fprintf(fp1,"Mode of continuous frequency table is %lf\n",mode);
fclose(fp1);
fclose(fp);

 printf("\033[93m");
    printf("\n\nDo you still want to use the Calculator : Y/N\n");
    getchar();
    char ch;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
       system("cls");// for windows use cls instead of cls
        main();
    }
    else
    {   system("cls");// for windows use cls instead of cls
        printf("\033[94m");
        printf("\nExiting...\n");
        printf("\033[91m");
        printf("Exited\n");
        exit(1);
    }
}

void std_dev_varia()
{
    system("cls"); //Use cls instead for Windows
    printf("\033[91m");
    printf("Please select one of the numbers for corresponding Operations :->\n");
    printf("\033[92m");
    printf("(1) -> Standard Deviation and Variance  for Ungrouped Data\n"
           "(2) -> Standard Deviation and Variance for Grouped Data\n");

    int num ;
    scanf("%d",&num);

    switch(num)
    {
        case 1:
        std_devi_varia_ungrp();
        break;

        case 2:
        std_devi_varia_grp();
        break;
    }
}

void std_devi_varia_ungrp()
{   system("cls"); //Use cls instead for Windows
    printf("\033[91m");
    printf("Please enter number of elements in your data set \n");
    int num,i;
    scanf("%d",&num);

    double arr[num];

    printf("\033[92m");
    printf("Please enter all the elements in Your Data Set\n");

    for(i=0;i<num;i++)
    {
        scanf("%lf",&arr[i]);
    }

   double  sigmax2  = 0 ,sigmax = 0;


   for(i=0;i<num;i++)
   {
        sigmax2 += (arr[i])*(arr[i]);
        sigmax += arr[i];
   }


   double std_dev;

   std_dev = pow(((sigmax2/((1.0)*num))- pow((sigmax/((1.0)*num)),2)),0.5);
   printf("\033[94m");
   printf("Standard deviation for this Ungrouped data will be %lf\n",std_dev);
FILE* fp1 = fopen("history.txt","a");
fprintf(fp1,"Standard deviation for this Ungrouped data will be %lf\n",std_dev);
   printf("\033[91m");
   printf("Variance for this dataset will be %lf\n",(std_dev)*(std_dev));
   fprintf(fp1,"Variance for this Ungrouped dataset will be %lf\n",(std_dev)*(std_dev));
   fclose(fp1);

   printf("\033[93m");
    printf("\n\nDo you still want to use the Calculator : Y/N\n");
    getchar();
    char ch;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
       system("cls");// for windows use cls instead of cls
        main();
    }
    else
    {   system("cls");// for windows use cls instead of cls
        printf("\033[94m");
        printf("\nExiting...\n");
        printf("\033[91m");
        printf("Exited\n");
        exit(1);
    }
}

void std_devi_varia_grp()
{   system("cls");
    printf("Please select following Numbers for corresponding Operations :->\n");

    printf("(1) -> Standard Deviation and Variance for Distributed Frequency Table\n"
           "(2) -> Standard Deviation and Variance for Continuous Frequency Table\n");

    int num;
    scanf("%d",&num);

    switch(num)
    {
        case 1:
        dev_var_distfreq();
        break;

        case 2:
        dev_var_contfreq();
        break;
    }
    printf("\033[93m");
    printf("\n\nDo you still want to use the Calculator : Y/N\n");
    getchar();
    char ch;
    scanf("%c",&ch);

    if(ch =='y' || ch == 'Y')
    {
       system("cls");// for windows use cls instead of cls
        main();
    }
    else
    {   system("cls");// for windows use cls instead of cls
        printf("\033[94m");
        printf("\nExiting...\n");
        printf("\033[91m");
        printf("Exited\n");
        exit(1);
    }
}

void dev_var_distfreq()
{
   system("cls");
    char str[50];
    printf("\033[91m");
    printf("Please enter your File name\n");
    getchar();
    scanf("%[^\n]s",str);


    FILE *fp;
    fp = fopen(str,"r");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("file could not be opened\n");
        exit(1);
    }

    char str1[80];
    fgets(str1,80,fp);

    double i,f,x,std_dev,varia;
    int count = 0;
    double sigmafx2 = 0 ,sigmafx = 0,sigmaf = 0;
    while(fscanf(fp,"%lf",&i) == 1)
    {
        count++;

        if((count%2) == 1)
        {
            f = i;
            sigmaf += f;
        }

        if((count % 2) == 0)
        {
            x = i;
            sigmafx += f*x;
            sigmafx2 += f*x*x;
        }
    }
    varia = (sigmafx2/sigmaf) - ((sigmafx/sigmaf) * (sigmafx/sigmaf));
    std_dev = sqrt(varia);
    fclose(fp);
    printf("\033[91m");
    printf("Standard deviation of this data set will be %lf\n",std_dev);
    FILE*fp1 = fopen("history.txt","a");
    fprintf(fp1,"Standard deviation of this discrete grouped data set will be %lf\n",std_dev);

    printf("\033[94m");
    printf("Variance  of this data set will be %lf\n",varia);
    fprintf(fp1,"Variance  of this discrete grouped data set will be %lf\n",varia);
    fclose(fp1);
}

void dev_var_contfreq()
{
    system("cls");
    char str[50];
    printf("\033[91m");
    printf("Please enter your File name\n");
    getchar();
    scanf("%[^\n]s",str);


    FILE *fp;
    fp = fopen(str,"r");

    if(fp == NULL)
    {   printf("\033[92m");
        printf("file could not be opened\n");
        exit(1);
    }

    char str1[80];
    fgets(str1,80,fp);

    double i,f,x,std_dev,varia,low,upp;
    int count = 0;
    double sigmafx2 = 0 ,sigmafx = 0,sigmaf = 0;

    while(fscanf(fp,"%lf",&i) == 1)
    {
        count++;

        if((count%3) == 1)
        {
            f = i;
            sigmaf += f;
        }

        else if((count%3) == 2)
        {
            low = i;
        }

        else if((count%3) == 0)
        {
            upp = i;
            x = (upp + low)/2.0;

            sigmafx += f*x;
            sigmafx2 += f*x*x;
        }
    }

    varia = (sigmafx2/sigmaf) - ((sigmafx/sigmaf) * (sigmafx/sigmaf));
    std_dev = sqrt(varia);
    fclose(fp);
    printf("\033[92m");
    printf("Standard deviation of this data set will be %lf\n",std_dev);
    FILE*fp1 = fopen("history.txt","a");
    fprintf(fp1,"Standard deviation of this continuous grouped data set will be %lf\n",std_dev);

    printf("\033[94m");
    printf("Variance  of this data set will be %lf\n",varia);
    fprintf(fp1,"Variance  of this discrete grouped data set will be %lf\n",varia);
    fclose(fp1);
}
