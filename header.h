#ifndef HEADER_H
#define HEADER_H

#include<stdbool.h>
#define Pi 3.14159265358979323846264
extern int hist;

int main();
void matrix_menu();
void add_mat();
void addition();
void recalculate();
void exita();
void exitY();
void sub_mat();
void subtraction();
void recalculate2();
void exits();
void exitY2();
void trans_mat();
void transpose();
void recalculate3();
void exitt();
void exitY3();
void Kmul_mat();
void KMUL();
void recalculate5();
void exitk();
void exitY5();
void multiply_mat();
void multiplication();
void recalculate9();
void exitm();
void exitY9();
void trace_mat();
void trace();
void recalculate4();
void exittr();
void exitY4();
void det_mat();
void determinant();
void recalculate6();
void exitd();
void exitY6();
void adj_mat();
void adjoint();
void recalculate7();
void exitaj();
void exitY7();
void inv_mat();
void inverse();
void recalculate8();
void exitin();
void exitY8();
void invalid_win();
void spinwindow();
void spinsubmit(GtkWidget*,gpointer);
void spinwindow2();
void spinsubmit2(GtkWidget*,gpointer);
void spinwindow3();
void spinsubmit3(GtkWidget*,gpointer);
void spinwindow4();
void spinsubmit4(GtkWidget*,gpointer);
void spinwindow5();
void spinsubmit5(GtkWidget*,gpointer);
void spinwindow6();
void spinsubmit6(GtkWidget*,gpointer);
void spinwindow7();
void spinsubmit7(GtkWidget*,gpointer);
void spinwindow8();
void spinsubmit8(GtkWidget*,gpointer);
void spinwindow9();
void spinsubmit9(GtkWidget*,gpointer);
double detercal(double**,int);
double** Adjoint_Matrix(double**,int);
double** Inverse_Matrix(double**,int);

void mean_ungrpdata();
void mean_dis_fre_dis();
void mean_con_fre_dis();
void medi_ungrpdata();
void medi_dis_fre_dis();
void medi_con_fre_dis();
void mode_ungrpdata();
void mode_dis_fre_dis();
void mode_con_fre_dis();
void mean_devi();
void mean_devi_mean();
void mean_devi_mode();
void mean_devi_median();
void std_devi();
void std_devi_grp();
void std_devi_ungrp();
void coeff_varia();
void Unknown();
void sort(double*,int);


void currency_converter();
void temp_unit_interconv();
void basicmath_oper();
void system_unit_conv();
void length();
void TIME();
void mass();
void volume();
void area();
void AreaCal();
void VolumeCal();
void Cal();
float circle(float radius); //Declaring Function
float square(float side);
float rectangle(float length,float breadth);
float triangle(float height,float base);
float trapezium(float side1,float side2,float height);
float ellipse(float majoraxis,float minoraxis);
float polygon(float n,float length);

void stats();
void basic();

void basesubmit(GtkWidget*,gpointer);
void base_conv();
char* basefinal(double, int);
double base10(char*, int); // Convert the input base to base 1void baseconvertor(); // Function for interconverting bases
void baseconvertor(int,int,char*);
void create_win_baseconv();

long double power(long double base, int exponent);
long double facto(int n);
long double sine(long double x);
long double cosine(long double x);
long double tangent(long double x);
long double cotangent(long double x);
long double secant(long double x);
long double cosecant(long double x);
bool isValidNum(const char *str);

void trigo();
void inv_trigo();
void Inverse(int);
void hyperbolic();

double Power(double x, int n);
double exp(double x);
double sinh(double x);
double cosh(double x);
double tanh(double x);
double coth(double x);
double sech(double x);
double csch(double x);

double f(double x,int degree,float arr[]); //Declaring function
double calint(double x0,double xn,double y,int n,int degree,float arr[]);//For calculating the value of integral
double integral(int choice,double x0,double xn,double y,int n);//For calculating th integral as per mentioned function

struct ComplexRect {
    long double real;
    long double imag;
};

typedef struct ComplexRect ComplexRect;

struct ComplexPolar {
    long double magnitude;
    long double phase; // in radians
};

typedef struct ComplexPolar ComplexPolar;

void calculatePhasor(ComplexRect num, int outputForm);
ComplexRect polarToRectangular(ComplexPolar num);
ComplexPolar rectangularToPolar(ComplexRect num);
ComplexRect exponentialToRectangular(ComplexPolar num);
ComplexPolar rectangularToExponential(ComplexRect num);
ComplexRect addRectangular(ComplexRect a, ComplexRect b);
ComplexRect subtractRectangular(ComplexRect a, ComplexRect b);
long double magnitudeRectangular(ComplexRect num);
long double argumentRectangular(ComplexRect num);
ComplexRect multiplyRectangular(ComplexRect a, ComplexRect b);
ComplexRect divideRectangular(ComplexRect a, ComplexRect b);

void phasors();

#endif
