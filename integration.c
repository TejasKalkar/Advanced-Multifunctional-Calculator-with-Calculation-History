#include<gtk/gtk.h>
#include"header.h"
#include<math.h>

void integration(){
    int n,choice;
    double x0,xn,y,value; //y takes the role of f(x)
    printf("\n\nFollowng are the functions for integration:\n\n");
    printf("1.)Polynomial\n");
    printf("2.)Trigonometric\n");
    printf("\nPlease enter the choice:");
    scanf("%d",&choice); //Input
    printf("\nPlease enter lower limit:");
    scanf("%lf",&x0);
    printf("\nPlease enter upper limit: ");
    scanf("%lf",&xn);
    printf("\nPlease enter number of subintervals (>=500):");
    scanf("%d",&n);
    value=integral(choice,x0,xn,y,n);
    if(value!=1000){
      printf("\nThe value of the integral for the given function is %lf\n",value); //Output
    }

    return;

}

double calint(double x0,double xn,double y,int n,int degree,float arr[]){
    double h;
    y=f(x0,degree,arr)+f(xn,degree,arr); //Calling Function
    h=(xn-x0)/n;  //(Upperlimit-lower limit)/Number of Subintervals
    for(int i=0;i<n;i++){
        y=y+2*f(x0+i*h,degree,arr);
    }
    y=(h/2)*y;
    return y;
}

double f(double x,int degree ,float arr[]){ //Defining Function
        if(degree==1){ //Seperate integral functions as per need
            return arr[0]*x+arr[1];
        }
        else if(degree==2){
            return arr[0]*x*x+arr[1]*x+arr[2];
        }
        else if(degree==3){
           return arr[0]*x*x*x+arr[1]*x*x+arr[2]*x+arr[3];
        }
        else if(degree==4){
            return sin(x);
        }
        else if(degree==5){
            return cos(x);
        }
        else if(degree==6){
            return tan(x);
        }
        else if(degree==7){
            return 1/sin(x);
        }
        else if(degree==8){
            return 1/cos(x);
        }
        else if(degree==9){
            return 1/tan(x);
        }
}

double integral(int choice,double x0,double xn,double y,int n){
    int degree;
    int choice1;
    float arrl[2]; //For storing coefficients as per the degree of polynomial
    float arrq[3];
    float arrc[4];
    float arr[5];

   switch(choice){
    case 1:printf("\nThe degree of polynomials are:\n");
           printf("1.)Linear\n");
           printf("2.)Quadratic\n");
           printf("3.)Cubic\n");
           printf("\nPlease enter the choice:");
           scanf("%d",&choice1);
           double intvalue; //Value of polynomial integral

           switch(choice1){
            case 1:printf("\nEnter coefficient of x:");
                    scanf("%f",&arrl[0]);
                    printf("\nEnter constant coefficient:");
                    scanf("%f",&arrl[1]);
                    intvalue=calint(x0,xn,y,n,1,arrl);
                    return intvalue;
                    break;
            case 2: printf("\nEnter coefficient of x2:");
                    scanf("%f",&arrq[0]);
                    printf("\nEnter coefficient of x:");
                    scanf("%f",&arrq[1]);
                    printf("\nEnter constant coefficient:");
                    scanf("%f",&arrq[2]);
                    intvalue=calint(x0,xn,y,n,2,arrq);
                    return intvalue;
                    break;
            case 3: printf("\nEnter coefficient of x3:");
                    scanf("%f",&arrc[0]);
                    printf("\nEnter coefficient of x2:");
                    scanf("%f",&arrc[1]);
                    printf("\nEnter coefficient of x:");
                    scanf("%f",&arrc[2]);
                    printf("\nEnter constant coefficient:");
                    scanf("%f",&arrc[3]);
                    intvalue=calint(x0,xn,y,n,3,arrc);
                    return intvalue;
                    break;
            default:printf("Please enter valid choice\n");
                    return 1000;
            }
        break;
    case 2:printf("\n\nFollowing are the Trigonometric Functions:\n\n");
           printf("1.)Sin\n");
           printf("2.)Cos\n");
           printf("3.)Tan\n");
           printf("4.)Cosec\n");
           printf("5.)Sec\n");
           printf("6.)Cot\n");
           printf("\nPlease enter the choice:");
           scanf("%d",&choice1);
           double intvalue1; //Value of trigonometric integral

        switch(choice1){
            case 1:intvalue1=calint(x0,xn,y,n,4,arr);
                   return intvalue1;
                   break;
            case 2:intvalue1=calint(x0,xn,y,n,5,arr);
                   return intvalue1;
                   break;
            case 3:intvalue1=calint(x0,xn,y,n,6,arr);
                   return intvalue1;
                   break;
            case 4:intvalue1=calint(x0,xn,y,n,7,arr);
                   return intvalue1;
                   break;
            case 5:intvalue1=calint(x0,xn,y,n,8,arr);
                   return intvalue1;
                   break;
            case 6:intvalue1=calint(x0,xn,y,n,9,arr);
                   return intvalue1;
                   break;
            default:printf("Please enter valid choice\n");
                    return 1000;
            }
        break;
    default:printf("The choice for the function selected is not valid\n");
            return 1000;
    }
}
