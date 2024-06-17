#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include"header.h"

void basic()
{   printf("\033[93m"); //Bright Yellow Colour
    printf("Welcome to Basic Part of Our Calculator !!\n\n\n");


    printf("\033[94m"); //Bright Blue Colour
    printf("Choose following numbers for corresponding operation:-> \n");



    printf("0 -> For Exiting out of this Calculator\n"
           "1 -> Currency Conversion\n"
           "2 -> length,weight,volume,time,Area units Interconversion\n"
           "3 -> Temperature units Interconversion\n"
           "4 -> Area and Volume Calculator of General Shapes\n"
           "5 -> Basic Integration\n");




        printf("\033[0m"); //Restore to default Colour

    int num;
    scanf("%d",&num);

    switch(num)
    {
        case 0:
        system("cls");// for windows use cls instead of cls
        printf("\033[33m"); //Red Colour
        printf("Exiting...\n");
        printf("\033[91m");
        printf("Exited");
        return ;

        case 1:
        currency_converter();
        break;

        case 2:
        system_unit_conv();
        break;

        case 3:
        temp_unit_interconv();
        break;

        case 4:
        Cal();
        break;

        case 5:
        integration();
        break;

    }

return;
}


//Currency Converter
void currency_converter()
{   FILE*fptr=fopen("history.txt","a");
    system("cls"); // for windows use cls instead of cls

    printf("\033[91m"); //For Bright Red Colour
    printf("Choose following numbers for selcting Currency 1 and Currency 2 for Conversion\n");


    printf("\033[093m"); //For Bright Yellow Colour
    printf("1 -> Indian Rupee\n"
          "2 -> Euro\n"
          "3 -> Australian Dollar\n"
          "4 -> Brazilian Real\n"
          "5 -> Canadian Dollar\n"
          "6 -> Japanese Yen\n"
          "7 -> United States Dollar\n"
          "8 -> British Pound Sterling\n"
          "9 -> Russian Ruble\n"
          "10 -> Singapore Dollar\n"
          "11 -> Afghan Afghani\n"
          "12 -> Armenian Dram\n"
          "13 -> Azerbaijani Manat\n"
          "14 -> Bangladeshi Taka\n"
          "15 -> Cambodian Riel\n"
          "16 -> Chinese Yuan\n"
          "17 -> Georgian Lari\n"
          "18 -> Hong Kong Dollar\n"
          "19 -> Indonesian Rupiah\n"
          "20 -> Kazakhstani Tenge\n"
          "21 -> Lao Kip\n"
          "22 -> Malaysian Ringgit\n"
          "23 -> South Korean Won\n"
          "24 -> Sri Lankan Rupee\n"
          "25 -> Maldivian Rufiyaa\n"
          "26 -> Pakistani Rupee\n"
          "27 -> Philippine Peso\n"
          "28 -> Thai Baht\n"
          "29 -> Taiwanese Dollar\n"
          "30 -> Vietnamese Dong\n"
          );

    int curr1 , curr2;

    printf("\033[92m"); //For Green Colour
    printf("\n\nEnter corresponding number for choosing Currency 1\n");
    scanf("%d",&curr1);

    printf("Enter corresponding number for choosing Currency 2\n");
    scanf("%d",&curr2);


    char** arr=(char**)malloc(sizeof(char*)*30) ;
    int i;
    for(i=0;i<30;i++)
    {
        arr[i] = (char*)malloc(sizeof(char)*100);
    }

   strcpy(arr[0],"Indian Rupee");
    strcpy(arr[1],"Euro");
    strcpy(arr[2],"Australian Dollar");
    strcpy(arr[3],"Brazilian Real");
    strcpy(arr[4],"Canadian Dollar");
    strcpy(arr[5],"Japanese Yen");
    strcpy(arr[6],"United States Dollar");
    strcpy(arr[7],"British Pound Sterling");
    strcpy(arr[8],"Russian Ruble");
    strcpy(arr[9],"Singapore Dollar");
    strcpy(arr[10],"Afghan Afghani");
    strcpy(arr[11],"Armenian Dram");
    strcpy(arr[12],"Azerbaijani Manat");
    strcpy(arr[13],"Bangladeshi Taka");
    strcpy(arr[14],"Cambodian Riel");
    strcpy(arr[15],"Chinese Yuan");
    strcpy(arr[16],"Georgian Lari");
    strcpy(arr[17],"Hong Kong Dollar");
    strcpy(arr[18],"Indonesian Rupiah");
    strcpy(arr[19],"Kazakhstani Tenge");
    strcpy(arr[20],"Lao Kip");
    strcpy(arr[21],"Malaysian Ringgit");
    strcpy(arr[22],"South Korean Won");
    strcpy(arr[23],"Sri Lankan Rupee");
    strcpy(arr[24],"Maldivian Rufiyaa");
    strcpy(arr[25],"Pakistani Rupee");
    strcpy(arr[26],"Philippine Peso");
    strcpy(arr[27],"Thai Baht");
    strcpy(arr[28],"Taiwanese Dollar");
    strcpy(arr[29],"Vietnamese Dong");

    double amount1;
    printf("\033[33m"); // For Yellow Colour
    printf("Please Enter amount of currency 1 (%s)\n",arr[curr1-1]);
    scanf("%lf",&amount1);

     double curr[30] = {1,89.11416,54.24705,16.33513,60.6913,0.5455,83.61136,104.15461,0.89592,61.43377,1.06,0.21,48.95,0.75,0.020,11.37,31.11,10.63,0.0053,0.17,0.0041,17.61,0.061,0.25,5.42,0.29,1.46,2.24,2.57,0.0034};

    double amount2 = ((curr[curr1 -1])/(curr[curr2 -1])) * amount1;
    printf("\033[92m"); //For Green Colour
    printf("%lf amount of %s will be equal to %lf amount of %s",amount1,arr[curr1-1],amount2,arr[curr2-1]);
    fprintf(fptr,"%lf amount of %s will be equal to %lf amount of %s\n",amount1,arr[curr1-1],amount2,arr[curr2-1]);

     for(i=0;i<30;i++)
    {
        free(arr[i]);
    }

    free(arr);
    printf("\033[93m"); // For Bright Yellow Colour
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
        printf("\033[32m"); //For Green Colour
        printf("\nExiting...\n");
        printf("\033[91m");
        printf("Exited\n");
        exit(1);
    }


}





void temp_unit_interconv()
{
    FILE*fptr=fopen("history.txt","a");
    char str1[100];
      char str2[100];
    system("cls"); // for windows use cls instead of cls

    printf("\033[93m");//bright yellow
    printf("\nChoose following numbers for choosing  temperature scale 1 and temperature scale 2\n"
           "1 -> Celsius (°C)\n"
           "2 -> Fahrenheit (°F)\n"
           "3 -> Kelvin (K)\n"
           "4 -> Rankine (°R)\n"
           "5 -> Réaumur (°Ré)\n"
           "6 -> Newton (°N)\n"
           "7 -> Your Own Scale 😎\n");


    int temp1,temp2;
    printf("\033[94m");//bright blue
    printf("Enter corresponding number for choosing temperature scale 1\n");
    scanf("%d",&temp1);

    printf("\033[35m");//Magenta
     printf("Enter corresponding number for choosing temperature scale 2\n");
    scanf("%d",&temp2);

    double mp1,mp2,random1,random2,diff1,diff2;

    if(temp1 == 7)
    {   printf("\033[32m"); //Green
        printf("Enter number of divisions between the melting point and boiling point of water on your temperature scale 1 \n");
        scanf("%lf",&diff1);

        printf("\033[93m"); //Bright Yellow
        printf("Enter melting point of water in Your temperature Scale 1\n");
        scanf("%lf",&mp1);

        printf("\033[31m"); //Red
        printf("\nWith what name would you like to call your own created temperature scale1\n");
        getchar();
        fgets(str1,90,stdin);
        str1[strlen(str1)-1]='\0';
    }
    else
    {
        if(temp1 == 1)
        {
            diff1 = 100;  mp1 = 0;

        }
        else if(temp1 == 2)
        {
            diff1 = 180;  mp1 = 32;
        }
        else if(temp1 == 3)
        {
            diff1 = 100;  mp1 = 273;
        }
        else if(temp1 == 4)
        {
            diff1 = 180; mp1 = 491.67;
        }
        else if(temp1 == 5)
        {
            diff1 = 80; mp1 = 0;
        }
        else if(temp1 == 6)
        {
            diff1 = 33; mp1 = 0;
        }
    }


// for temp2
    if(temp2 == 7)
    {   printf("\033[31m"); //Red
        printf("Enter number of divisions between the melting point and boiling point of water on your temperature scale 2 \n");
        scanf("%lf",&diff2);

        printf("\033[32m");
        printf("Enter melting point of water in Your temperature Scale 2\n");
        scanf("%lf",&mp2);

        printf("\033[33m");
        printf("\nWith what name would you like to call your own created temperature scale2\n");
        getchar();
        fgets(str2,90,stdin);
        str2[strlen(str2)-1]='\0';
    }
    else
    {
        if(temp2 == 1)
        {
            diff2 = 100;  mp2 = 0;

        }
        else if(temp2 == 2)
        {
            diff2 = 180;  mp2 = 32;
        }
        else if(temp2 == 3)
        {
            diff2 = 100;  mp2 = 273;
        }
        else if(temp2 == 4)
        {
            diff2 = 180; mp2 = 491.67;
        }
        else if(temp2 == 5)
        {
            diff2 = 80; mp2 = 0;
        }
        else if(temp2 == 6)
        {
            diff2 = 33; mp2 = 0;
        }
    }


char** arr1 = (char**)malloc(sizeof(char*)*8);
int i;
for(i=0;i<8;i++)
{
    arr1[i] = (char*)malloc(sizeof(char)*100);
}
strcpy(arr1[0],"Celsius");
strcpy(arr1[1],"Fahrenheit");
strcpy(arr1[2],"Kelvin");
strcpy(arr1[3],"Rankine");
strcpy(arr1[4],"Réaumur");
strcpy(arr1[5],"Newton");
if((temp1 ==7 && temp2 != 7))
strcpy(arr1[6],str1);
else if((temp2 == 7 && temp1 != 7))
strcpy(arr1[6],str2);

else if(temp1 == 7 && temp2 ==7)
{
    strcpy(arr1[6],str1);
    strcpy(arr1[7],str2);
}

printf("\033[34m");
printf("\nEnter Temperature in you temperature Scale 1\n");
scanf("%lf",&random1);

random2 = (((random1 - mp1)/diff1)*diff2)+mp2;
if(!(temp1 == 7 && temp2 == 7))
{   printf("\033[91m");
    printf("\n%lf degree %s is equal to %lf degree %s",random1,arr1[temp1-1],random2,arr1[temp2-1]);
    fprintf(fptr,"\n%lf degree %s is equal to %lf degree %s\n",random1,arr1[temp1-1],random2,arr1[temp2-1]);
}

else
{   printf("\033[92m");
    printf("\n%lf degree %s is equal to %lf degree %s",random1,arr1[temp1-1],random2,arr1[temp2]);
    fprintf(fptr,"\n%lf degree %s is equal to %lf degree %s\n",random1,arr1[temp1-1],random2,arr1[temp2]);
}

for(i=0;i<7;i++)
{
    free(arr1[i]);
}
free(arr1);

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
        printf("\033[91m");
        printf("\nExiting...\n");
        printf("\033[92m");
        printf("Exited\n");
        exit(1);
    }

}



void system_unit_conv()
{
    FILE*fptr=fopen("history.txt","a");
     system("cls"); // for windows use cls instead of cls
     printf("\033[31m"); //For Red Colour
     printf("Choose the Corresponding number for choosing the following Physical Quantity\n");
     printf("\033[93m");
     printf("1 -> Length\n"
            "2 -> Mass\n"
            "3 -> Time\n"
            "4 -> Volume\n"
            "5 -> Area\n");

    printf("\033[0m"); //Back to Defeault Colour

     int num;
     scanf("%d",&num);

    switch(num)
    {
        case 1:
        length();
        break;

        case 3:
        TIME();
        break;

        case 2:
        mass();
        break;

        case 4:
        volume();
        break;

        case 5:
        area();
        break;
    }


}

void length()
{
    FILE*fptr=fopen("history.txt","a");
    system("cls"); // for windows use cls instead of cls
    printf("\033[91m"); //For Bright Red Colour

    printf("Choose the following numbers for choosing unit1 and unit2 of length\n");
    printf("\033[93m"); //For Bright Yellow Colour
    printf("1 -> League\n"
           "2 -> Fathom\n"
           "3 -> Chain\n"
           "4 -> Rod\n"
           "5 -> Hand\n"
           "6 -> Furlong\n"
           "7 -> Parsec\n"
           "8 -> Astronomical unit\n"
           "9 -> Light Year\n"
           "10 -> Foot\n"
           "11 -> inch\n"
           "12 -> mile\n"
           "13 -> Nautical mile\n"
           "14 -> metre\n"
           "15 -> Yard\n");

  int unit1;
  printf("\033[32m"); //For Green Colour
  printf("Choose number for choosing unit 1\n");
  scanf("%d",&unit1);

  int unit2;
  printf("Choose number for choosing unit 2\n");
  scanf("%d",&unit2);

double arr[15] = {4828.03,1.8288,20.1168,5.0292,0.1016,201.168,3.0857E16,1.496E9,9.461E15,0.3048,2.54E-2,1.609E3,1852,1,0.9144};

double amt1,amt2;
printf("\033[34m"); // For Blue Colour
char len_u[15][20] = {"League","Fathom","Chain","Rod","Hand","Furlong","Parsec","Astronomical unit","Light Year","Foot","inch","mile","Nautical mile","metre","Yard"};

printf("Please enter amount of unit 1 (%s)\n",len_u[unit1 -1]);
scanf("%lf",&amt1);

amt2 = ((arr[unit1 -1])/arr[unit2-1])*amt1;

printf("\033[35m"); //For Magenta Colour
printf("%lf %s  is equal to %E %s",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);
fprintf(fptr,"%lf %s  is equal to %E %s\n",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);

printf("\033[93m"); // For Bright Yellow Colour
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
        printf("\033[32m"); //For Green Colour
        printf("\nExiting...\n");
        printf("\033[91m");
        printf("Exited\n");
        exit(1);
    }

}

void TIME()
{
    FILE*fptr=fopen("history.txt","a");
    system("cls"); // for windows use cls instead of cls

    printf("\033[31m");
    printf("Choose the following numbers for choosing unit1 and unit2 of time\n");

    printf("\033[32m");
    printf("1 -> second\n"
           "2 -> Megasecond\n"
           "3 -> millisecond\n"
           "4 -> Minute\n"
           "5 -> Hour\n"
           "6 -> Day\n"
           "7 -> Week\n"
           "8 -> Fortnight\n"
           "9 -> Month\n"
           "10 -> Year\n"
           "11 -> Decade\n"
           "12 -> Century\n"
           "13 -> Millenium\n"
           "14 -> Aeon\n");

  int unit1;
  printf("\033[33m");
  printf("Choose number for choosing unit 1\n");
  scanf("%d",&unit1);

  int unit2;
  printf("\033[34m");
  printf("Choose number for choosing unit 2\n");
  scanf("%d",&unit2);

  double arr[14] = {1,10E6,10E-3,60,3600,86400,(7*86400),(14*86400),(30.0*86400),(365.0*86400),(10*365.0*86400),(100*365.0*86400),(1000*365.0*86400),(10E9 * 365.0 *86400)};

    double amt1,amt2;
    printf("\033[91m");
    printf("Please enter amount of unit 1\n");
    scanf("%lf",&amt1);

    amt2 = ((arr[unit1 -1])/arr[unit2-1])*amt1;

    char len_u[14][20] = {"second","Megasecond","Millisecond","Minute","Hour","Day","Week","Fortnight","Month","Year","Decade","Century","Millenium","Aeon"};
    printf("\033[92m");
    printf("%lf %s  is equal to %E %s",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);
    fprintf(fptr,"%lf %s  is equal to %E %s\n",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);

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
        printf("\033[31m");
        printf("Exited\n");
        exit(1);
    }
}

void mass()
{
    FILE*fptr=fopen("history.txt","a");
    system("cls"); // for windows use cls instead of cls

    printf("\033[31m");
    printf("Choose the following numbers for choosing unit1 and unit2 of mass\n");

    printf("\033[32m");
    printf("1 -> gram\n"
          "2 ->  Ton\n"
          "3 -> Pound\n"
          "4 -> Ounce\n"
          "5 -> Stone\n"
          "6 -> carat\n"
          "7 -> Slug\n"
          "8 -> Quintal\n"
          "9 -> Troy Ounce\n"
          "10 ->Troy Pound\n"
          "11 -> Grain\n"
          "12 -> Short Ton\n"
          "13 -> Long Ton\n"
          "14 -> amu\n"
          "15 -> Femtogram\n");

    int unit1;
    printf("\033[33m");
    printf("Choose number for choosing unit 1\n");
    scanf("%d",&unit1);

    int unit2;
    printf("\033[34m");
    printf("Choose number for choosing unit 2\n");
    scanf("%d",&unit2);

    double arr[15] = {1,10E6,453.592,2.83495,6.35029E3,0.2,1.4593903E4,10E5,3.11035,3.732417216E2,6.479891E-2,9.07185E5,1.01605E6,1.66053906660E-24,1E-15};
    double amt1,amt2;

    printf("\033[91m");
    printf("Please enter amount of unit 1\n");
    scanf("%lf",&amt1);

    amt2 = ((arr[unit1 -1])/arr[unit2-1])*amt1;
    char len_u[15][20] = {"gram","Ton","Pound","Ounce","Stone","carat","Slug","Quintal","Troy Ounce","Troy Pound","Grain","Short Ton","Long Ton","amu","Femtogram"};

    printf("\033[92m");
    printf("%lf %s  is equal to %E %s",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);
    fprintf(fptr,"%lf %s  is equal to %E %s\n",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);

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

void volume()
{
    FILE*fptr=fopen("history.txt","a");
    system("cls"); // for windows use cls instead of cls

    printf("\033[31m");
    printf("Choose the following numbers for choosing unit1 and unit2 of Volume\n");

    printf("\033[32m");
    printf("1 -> Cubic Metres\n"
           "2 -> liter\n"
           "3 -> Gallon\n"
           "4 -> Quart\n"
           "5 -> Pint\n"
           "6 -> Cup\n"
           "7 -> Fluid Ounce\n"
           "8 -> Bushel\n"
           "9 -> Cord\n"
           "10 -> Peck\n"
           "11 -> Gill\n"
           "12 -> Pottle\n"
           "13 -> Hogshead\n"
           "14 -> Acre Foot\n"
           "15 -> Cubic inch\n");

     int unit1;
    printf("\033[33m");
    printf("Choose number for choosing unit 1\n");
    scanf("%d",&unit1);

    int unit2;
    printf("\033[34m");
    printf("Choose number for choosing unit 2\n");
    scanf("%d",&unit2);

    double arr[15] = {1000,1,3.78541,0.946353,0.473176,0.236588,0.0295735,3.52391,362.456,8.80977,0.118294,0.227305,238.481,123.348,1.63871E-5};
    double amt1,amt2;
    char len_u[15][20] = {"Cubic Metres","liter","Gallon","Quart","Pint","Cup","Fluid Ounce","Bushel","Cord","Peck","Gill","Pottle","Hogshead","Acre Foot","Cubic inch"};

    printf("\033[91m");
    printf("Please enter amount of unit 1 (%s)\n",len_u[unit1-1]);
    scanf("%lf",&amt1);

    amt2 = ((arr[unit1 -1])/arr[unit2-1])*amt1;


    printf("%lf %s  is equal to %E %s",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);
    fprintf(fptr,"%lf %s  is equal to %E %s\n",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);

    printf("\033[92m");
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
        printf("\033[93m");
        printf("\nExiting...\n");
        printf("\033[94m");
        printf("Exited\n");
        exit(1);
    }
}

void area()
{
    FILE*fptr=fopen("history.txt","a");
     system("cls"); // for windows use cls instead of cls

    printf("\033[31m");
    printf("Choose the following numbers for choosing unit1 and unit2 of Area\n");

    printf("\033[32m");
    printf("1 -> Square Meter (m²)\n"
           "2 -> Hectare (ha)\n"
           "3 -> Acre\n"
           "4 -> Square Mile (mi²)\n"
           "5 -> Are\n"
           "6 -> Barn\n"
           "7 -> Rood\n"
           "8 -> Dunam\n"
           "9 -> Mu\n"
           "10 -> Section\n"
           "11 -> Tsubo\n"
           "12 -> Guntha\n"
           "13 -> Centiare\n"
           "14 -> Satak\n"
           "15 -> Perch/Pole\n");

    int unit1;
    printf("\033[33m");
    printf("Choose number for choosing unit 1\n");
    scanf("%d",&unit1);

    int unit2;
    printf("\033[34m");
    printf("Choose number for choosing unit 2\n");
    scanf("%d",&unit2);

    double arr[15] = {1,1E4,4046.86,2.59E6,100,1E-28,1011.71,1000,666.67,2.59E6,3.306,121,1,100,25.2929};

    double amt1,amt2;

    char len_u[15][20] = {"Square metre" , "Hectare" ,"Acre" ,"Square Mile","Are","Barn","Rood","Dunam","Mu","Section","Tsubo","Guntha","Centiare","Satak","Pole/Perch"};

    printf("\033[91m");
    printf("Please enter amount of unit 1 (%s)\n",len_u[unit1-1]);
    scanf("%lf",&amt1);

    amt2 = ((arr[unit1 -1])/arr[unit2-1])*amt1;

    printf("\033[92m");
    printf("%lf %s  is equal to %E %s",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);
    fprintf(fptr,"%lf %s  is equal to %E %s\n",amt1,len_u[unit1-1],amt2,len_u[unit2-1]);

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

void VolumeCal()
{   FILE*fptr=fopen("history.txt","a");
    printf("Please select following numbers for selecting the corresponding shapes :-> \n");
    printf("(1) -> Cube\n"
           "(2) -> Cuboid\n"
           "(3) -> Cone\n"
           "(4) -> Sphere\n"
           "(5) -> Cylinder\n"
           "(6) -> Pyramid\n"
           "(7) -> Prism\n"
           "(8) -> Tetrahedron\n"
           "(9) -> Ellipsoid\n"
           "(10)-> Torus\n"
           "(11)-> Frustum of Cone\n"
           "(12)-> Hemisphere\n"
           "(13)-> Elliptical Cone\n"
           "(14)-> Elliptical Cylinder\n");

    int num;
    double vol;
    scanf("%d",&num);

    switch(num)
    {
        case 1:
        printf("\033[31m");
        printf("Please tell side of cube :->\n");
        double a;
        scanf("%lf",&a);
        vol = a*a*a;
        printf("\033[32m");
        printf("Volume of cube is %lf\n",vol);
        fprintf(fptr,"Volume of cube is %lf\n",vol);
        break;

        case 2:
        printf("\033[33m");
        printf("Please tell sides of cuboid :-> \n");
        double b,c;
        scanf("%lf %lf %lf",&a,&b,&c);
        vol = a*b*c;
        printf("\033[34m");
        printf("Volume of Cuboid is %lf\n",vol);
        fprintf(fptr,"Volume of cuboid is %lf\n",vol);
        break;

        case 3:
        printf("\033[91m");
        printf("Please tell radius of base and height of cone respectively :->\n");
        double r,h;
        scanf("%lf %lf",&r,&h);
        vol = (1/3.0)*(Pi)*(r*r)*h;
        printf("\033[92m");
        printf("Volume of Cone is %lf\n",vol);
        fprintf(fptr,"Volume of Cone is %lf\n",vol);
        break;

        case 4:
        printf("\033[93m");
        printf("Please tell Radius of Sphere :->\n");
        scanf("%lf",&r);
        vol = (4.0/3.0)*Pi*r*r*r;
        printf("\033[94m");
        printf("Volume of Sphere is %lf\n",vol);
        fprintf(fptr,"Volume of Sphere is %lf\n",vol);
        break;

        case 5:
        printf("\033[31m");
        printf("Please tell radius and height of Cylinder :-> \n");
        scanf("%lf %lf",&r,&h);
        vol = Pi*r*r*h;
        printf("\033[32m");
        printf("Volume of Cylinder is %lf\n",vol);
        fprintf(fptr,"Volume of Cylinder is %lf\n",vol);
        break;

        case 6:
        printf("\033[33m");
        printf("Please tell base area and height of Pyramid :-> \n");
        double base_are;
        scanf("%lf %lf",&base_are,&h);
        vol = (1.0/3.0)*(base_are)*h;
        printf("\033[34m");
        printf("Volume of Pyramid is %lf\n",vol);
        fprintf(fptr,"Volume of Pyramid is %lf\n",vol);
        break;

        case 7:
        printf("\033[91m");
        printf("Please tell base area and height of Prism :-> \n");
        scanf("%lf %lf",&base_are,&h);
        vol = (base_are)*h;
        printf("\033[92m");
        printf("Volume of Prism is %lf\n",vol);
        fprintf(fptr,"Volume of Prism is %lf\n",vol);
        break;

        case 8:
        printf("\033[93m");
        printf("Please tell side of Tetrahedron :->\n");
        scanf("%lf",&a);
        vol = (1/6.0)*(1/pow(2.0,0.5))*(a*a*a);
        printf("\033[94m");
        printf("Volume of Tetrahedron is %lf\n",vol);
        fprintf(fptr,"Volume of Tetrahedron is %lf\n",vol);
        break;

        case 9:
        printf("\033[31m");
        printf("Please tell all the semiaxes of Ellipsoid :-> \n");
        scanf("%lf %lf %lf",&a,&b,&c);
        vol = (4.0/3.0)*(Pi)*(a*b*c);
        printf("\033[32m");
        printf("Volume of Ellipsoid is %lf\n",vol);
        fprintf(fptr,"Volume of Ellipsoid is %lf\n",vol);
        break;

        case 10:
        printf("\033[33m");
        printf("Please tell Major radius and Minor Radius of Torus Respectively :->\n");
        double R;
        scanf("%lf %lf",&R,&r);
        vol = (Pi*r*r)*(2*Pi*R);
        printf("\033[34m");
        printf("Volume of Torus is %lf\n",vol);
        fprintf(fptr,"Volume of Torus is %lf\n",vol);
        break;

        case 11:
        printf("\033[91m");
        printf("Please tell radius of smaller base,Larger base and Height of Frustum of Cone respectively\n");
        scanf("%lf %lf %lf",&r,&R,&h);
        vol = (1.0/3.0)*(Pi)*(h)*(R*R + r*r + R*r);
        printf("\033[92m");
        printf("Volume of Frustum of Cone is %lf\n",vol);
        fprintf(fptr,"Volume of Cone is %lf\n",vol);
        break;

        case 12:
        printf("\033[93m");
        printf("Please tell Radius of the Hemisphere :-> \n");
        scanf("%lf",&r);
        vol = (2.0/3.0)*(Pi)*r*r*r;
        printf("\033[94m");
        printf("Volume of Sphere is %lf",vol);
        fprintf(fptr,"Volume of Sphere is %lf\n",vol);
        break;

        case 13:
        printf("\033[91m");
        printf("Please tell lengths of the semiaxes of base and height of elliptical cone respectively :-> \n");
        scanf("%lf %lf %lf",&a,&b,&h);
        vol = (1.0/3.0)*Pi*(a*b*h);
        printf("\033[92m");
        printf("Volume of Elliptical Cone is %lf",vol);
        fprintf(fptr,"Volume of Elliptical Cone is %lf\n",vol);
        break;

        case 14:
        printf("\033[93m");
        printf("Please tell lengths of the semiaxes of base and height of elliptical cylinder respectively :-> \n");
        scanf("%lf %lf %lf",&a,&b,&h);
        vol = Pi*(a*b*h);
        printf("\033[94m");
        printf("Volume of Elliptical Cylinder is %lf",vol);
        fprintf(fptr,"Volume of Elliptical Cylinder is %lf\n",vol);
        break;
    }


}

void Cal()
{   system("cls"); // for windows use cls instead of cls
printf("\033[31m");
    printf("Please select following numbers for selecting area calculator or Volume Calculator\n");
    printf("\033[32m");
    printf("(1) -> Area Calculator\n"
           "(2) -> Volume Calculator\n");
    FILE*fpr=fopen("history.txt","a");
    int num;
    scanf("%d",&num);

    switch(num)
    {
        case 1:
        AreaCal();
        break;

        case 2:
        VolumeCal();
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

void AreaCal()
{
    FILE*fptr=fopen("history.txt","a");
    int choice;
    printf("\033[31m");
    printf("\n\nFollowing are the common figures to calculate the area:\n\n");
    printf("\033[32m");
    printf("1.)Circle\n");
    printf("2.)Square\n");
    printf("3.)Rectangle\n");
    printf("4.)Triangle\n");
    printf("5.)Trapezium\n");
    printf("6.)Ellipse\n");
    printf("7.)N-sided polygon\n");
    printf("\nPlease enter the number corresponding to which the area needs to be calculated\n"); //Input
    scanf("%d",&choice);
    float side,height,side1,side2,base,length,breadth,radius,majoraxis,minoraxis,area,n;

    switch(choice){
                case 1: printf("\033[91m");
                        printf("\nPlease enter the radius of the circle:");
                        scanf("%f",&radius);
                        if(radius>0){ //Checking the validity of input
                            area= circle(radius); //Calling Function
                            printf("\033[92m");
                            printf("\nThe area of the circle is %f sqaure units\n",area); //Output
                            fprintf(fptr,"\nThe area of the circle is %f sqaure units\n",area);
                        }
                        else{
                            printf("\033[93m");
                            printf("\nThe radius is not valid\n");
                        }
                        break;
                case 2: printf("\033[93m");
                        printf("\nPlease enter the side of the square:");
                        scanf("%f",&side);
                        if(side>0){
                            area=square(side);
                            printf("\033[94m");
                            printf("\nThe area of the square is %f square units\n",area);
                             fprintf(fptr,"\nThe area of the square is %f sqaure units\n",area);
                        }
                        else{
                            printf("\033[91m");
                            printf("\nThe side is not valid\n");
                        }
                        break;
        case 3: printf("\033[91m");
                printf("\nPlease enter the length of the rectangle:");
                scanf("%f",&length);
                printf("\033[92m");
                printf("\nPlease enter the breadth of the rectangle:");
                scanf("%f",&breadth);
                if(length>0 && breadth>0){
                    area=rectangle(length,breadth);
                    printf("\033[93m");
                    printf("\nThe area of the rectangle is %f square units\n",area);
                     fprintf(fptr,"\nThe area of the rectangle is %f sqaure units\n",area);
                }
                else{
                    printf("\033[94m");
                    printf("\nThe dimensions of the rectangle are not valid\n");
                }
                break;


        case 4:
                printf("\033[91m");
                printf("Please select following numbers for corresponding options\n");
                printf("\033[92m");
                printf("(1) -> all the sides are known\n"
                       "(2) -> base and height are known\n");
                int num;
                scanf("%d",&num);

                if(num == 2)
                {printf("\033[93m");
                printf("\nPlease enter the length of the base of the triangle:");
                scanf("%f",&base);
                printf("\033[94m");
                printf("\nPlease enter the height of the triangle:");
                scanf("%f",&height);
                if(base>0 && height>0)
                {
                    area=triangle(height,base);
                    printf("\033[91m");
                    printf("\nThe area of the triangle is %f square units\n",area);
                    fprintf(fptr,"\nThe area of the triangle is %f sqaure units\n",area);
                }
                else
                {
                    printf("\033[92m");
                    printf("\nThe dimensions of the triangle are not valid\n");
                }
                }

                else if(num == 1)
                {   printf("\033[93m");
                    printf("Please enter all the sides of the triangele :-> \n");
                    double a,b,c;
                    scanf("%lf %lf %lf",&a,&b,&c);
                    double s = (a+b+c)/2.0;
                    if(a>0 && b>0 && c > 0 && (a+b)>c && (a+c)>b && (b+c)>a)
                    {
                       double Area = sqrt(s*(s-a)*(s-b)*(s-c));
                        printf("\033[94m");
                        printf("Area of the triangle is %lf",Area);
                        fprintf(fptr,"Area of the triangle is %lf\n",Area);
                    }

                    else
                    {   printf("\033[91m");
                        printf("\nThe dimensions of the triangle are not valid\n");
                    }
                }
                break;


        case 5: printf("\033[91m");
                printf("\nEnter the length of one parallel side of the trapezium:");
                scanf("%f",&side1);
                printf("\033[92m");
                printf("\nEnter the length of another parallel side of the trapezium:");
                scanf("%f",&side2);
                printf("\033[93m");
                printf("\nEnter the height of the trapezium:");
                scanf("%f",&height);
                if(side1>0 && side2>0 && height>0){
                    area=trapezium(side1,side2,height);
                    printf("\033[94m");
                    printf("\nThe area of the trapezium is %f square units\n",area);
                    fprintf(fptr,"\nThe area of the trapezium is %f sqaure units\n",area);

                }
                else{
                    printf("\033[91m");
                    printf("\nThe dimensions of the trapezium are not valid\n");
                }
                break;
        case 6: printf("\033[91m");
                printf("\nPlease enter the length of the major axis of the ellipse:");
                scanf("%f",&majoraxis);
                printf("\033[92m");
                printf("\nPlease enter thr length of the minor axis of the ellipse:");
                scanf("%f",&minoraxis);
                if(majoraxis>0 && minoraxis>0){
                    area=ellipse(majoraxis,minoraxis);
                    printf("\033[93m");
                    printf("\nThe area of the ellipse is %f sqaure units\n",area);
                    fprintf(fptr,"\nThe area of the ellipse is %f sqaure units\n",area);
                }
                else{
                    printf("\033[94m");
                    printf("\nThe dimensions of the ellipse are not valid\n");
                }
                break;
        case 7: printf("\033[91m");
                printf("\nPlease enter the value of n for a n sided polygon:");
                scanf("%f",&n);
                printf("\033[92m");
                printf("\nEnter the length of each side of the polygon:");
                scanf("%f",&length);
                if(n>0 && length>0){
                    area=polygon(n,length);
                    printf("\033[93m");
                    printf("\nThe area of the polygon is %.2f square units\n",area);
                    fprintf(fptr,"\nThe area of the polygon is %.2f sqaure units\n",area);
                }
                else{
                    if(n<=0){
                        printf("\033[94m");
                        printf("\nThe value of n cannot be less than or equal to zero\n");
                    }
                    else{
                        printf("\033[91m");
                        printf("\nThe dimension of the polygon is not valid\n");
                    }
                }
                break;
        default:printf("\nPlease enter the correct choice\n");
    }

}

float circle(float radius){ //Defining Function
    return 3.14*radius*radius;
}

float square(float side){
    return side*side;
}

float rectangle(float length,float breadth){
    return 2.0*length+2.0*breadth;
}

float triangle(float height,float base){
    return (height*base)/2.0;
}

float trapezium(float side1,float side2,float height){
     return ((side1+side2)*height)/2.0;
}

float ellipse(float majoraxis,float minoraxis){
    return (3.14*majoraxis*minoraxis)/4.0;
}

float polygon(float n,float length){
    float ratio;
    ratio=(180)/n;
    float radian;
    radian=ratio*(3.14/180.0);

    return (n*length*length)/(4*tan(radian));
}
