#include<gtk/gtk.h>
#include"header.h"
#include<stdlib.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884



void phasors() {
    system("cls");
    int operation;
    ComplexRect rectNum1, rectNum2, resultRect;
    ComplexPolar polarNum1, polarNum2, resultPolar;
    printf("Welcome to complex calculator \U0001F91D\n");
    printf("Select the operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Magnitude\n");
    printf("4. Multiplication\n");
    printf("5. Division\n");
    printf("6. Rectangular to Polar Conversion\n");
    printf("7. Rectangular to Exponential Conversion\n");
    printf("8.Clear screen\n");
    printf("9. Exit\n");
    printf("Enter your choice (1-9): ");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            printf("Enter the real part of the first rectangular number: ");
            scanf("%Lf", &rectNum1.real);
            printf("Enter the imaginary part of the first rectangular number: ");
            scanf("%Lf", &rectNum1.imag);
            printf("Enter the real part of the second rectangular number: ");
            scanf("%Lf", &rectNum2.real);
            printf("Enter the imaginary part of the second rectangular number: ");
            scanf("%Lf", &rectNum2.imag);
            resultRect = addRectangular(rectNum1, rectNum2);
            printf("Addition result: ");
            calculatePhasor(resultRect, 1); // Output in rectangular form
            break;
        case 2:
            printf("Enter the real part of the first rectangular number: ");
            scanf("%Lf", &rectNum1.real);
            printf("Enter the imaginary part of the first rectangular number: ");
            scanf("%Lf", &rectNum1.imag);
            printf("Enter the real part of the second rectangular number: ");
            scanf("%Lf", &rectNum2.real);
            printf("Enter the imaginary part of the second rectangular number: ");
            scanf("%Lf", &rectNum2.imag);
            resultRect = subtractRectangular(rectNum1, rectNum2);
            printf("Subtraction result: ");
            calculatePhasor(resultRect, 1); // Output in rectangular form
            break;
        case 3:
            printf("Enter the real part of the rectangular number: ");
            scanf("%Lf", &rectNum1.real);
            printf("Enter the imaginary part of the rectangular number: ");
            scanf("%Lf", &rectNum1.imag);
            printf("Magnitude: %.6Lf\n", magnitudeRectangular(rectNum1));
            break;
        case 4:
            printf("Enter the real part of the first rectangular number: ");
            scanf("%Lf", &rectNum1.real);
            printf("Enter the imaginary part of the first rectangular number: ");
            scanf("%Lf", &rectNum1.imag);
            printf("Enter the real part of the second rectangular number: ");
            scanf("%Lf", &rectNum2.real);
            printf("Enter the imaginary part of the second rectangular number: ");
            scanf("%Lf", &rectNum2.imag);
            resultRect = multiplyRectangular(rectNum1, rectNum2);
            printf("Multiplication result: ");
            calculatePhasor(resultRect, 1); // Output in rectangular form
            break;
        case 5:
            printf("Enter the real part of the first rectangular number: ");
            scanf("%Lf", &rectNum1.real);
            printf("Enter the imaginary part of the first rectangular number: ");
            scanf("%Lf", &rectNum1.imag);
            printf("Enter the real part of the second rectangular number: ");
            scanf("%Lf", &rectNum2.real);
            printf("Enter the imaginary part of the second rectangular number: ");
            scanf("%Lf", &rectNum2.imag);
            resultRect = divideRectangular(rectNum1, rectNum2);
            printf("Division result: ");
            calculatePhasor(resultRect, 1); // Output in rectangular form
            break;
        case 6:
            printf("Enter the real part of the rectangular number: ");
            scanf("%Lf", &rectNum1.real);
            printf("Enter the imaginary part of the rectangular number: ");
            scanf("%Lf", &rectNum1.imag);
            polarNum1 = rectangularToPolar(rectNum1);
            printf("Polar Representation: Magnitude = %.6Lf, Phase = %.6Lf radians\n", polarNum1.magnitude, polarNum1.phase);
            break;
        case 7:
            printf("Enter the real part of the rectangular number: ");
            scanf("%Lf", &rectNum1.real);
            printf("Enter the imaginary part of the rectangular number: ");
            scanf("%Lf", &rectNum1.imag);
            polarNum1 = rectangularToExponential(rectNum1);
            printf("Exponential Representation: Magnitude = %.6Lf, Phase = %.6Lf radians\n", polarNum1.magnitude, polarNum1.phase);
            break;

        case 8:
            system("clear||cls");
            break;
        case 9:

            printf("Exiting...\n");
            system("cls");
            main();
            break;




    }

    return;
}

void calculatePhasor(ComplexRect num, int outputForm) {
    if (outputForm == 1) { // Output in rectangular form
        printf("Rectangular Representation: %.6Lf + %.6Lfi\n", num.real, num.imag);
    } else { // Output in polar form
        long double magnitude = sqrtl(num.real * num.real + num.imag * num.imag);
        long double phase = atan2l(num.imag, num.real);
        printf("Polar Representation:\n");
        printf("Magnitude: %.6Lf\n", magnitude);
        printf("Phase: %.6Lf radians\n", phase);
        printf("Phase: %.6Lf degrees\n", phase * 180.0L / PI);
    }
}

ComplexRect polarToRectangular(ComplexPolar num) {
    ComplexRect result;
    result.real = num.magnitude * cosl(num.phase);
    result.imag = num.magnitude * sinl(num.phase);
    return result;
}

ComplexPolar rectangularToPolar(ComplexRect num) {
    ComplexPolar result;
    result.magnitude = sqrtl(num.real * num.real + num.imag * num.imag);
    result.phase = atan2l(num.imag, num.real);
    return result;
}

ComplexRect exponentialToRectangular(ComplexPolar num) {
    ComplexRect result;
    result.real = num.magnitude * cosl(num.phase);
    result.imag = num.magnitude * sinl(num.phase);
    return result;
}

ComplexPolar rectangularToExponential(ComplexRect num) {
    ComplexPolar result;
    result.magnitude = sqrtl(num.real * num.real + num.imag * num.imag);
    result.phase = atan2l(num.imag, num.real);
    return result;
}

ComplexRect addRectangular(ComplexRect a, ComplexRect b) {
    ComplexRect result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

ComplexRect subtractRectangular(ComplexRect a, ComplexRect b) {
    ComplexRect result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

long double magnitudeRectangular(ComplexRect num) {
    return sqrtl(num.real * num.real + num.imag * num.imag);
}


long double argumentRectangular(ComplexRect num) {
    return atan2l(num.imag, num.real);
}
ComplexRect multiplyRectangular(ComplexRect a, ComplexRect b) {
    ComplexRect result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

ComplexRect divideRectangular(ComplexRect a, ComplexRect b) {
    ComplexRect result;
    long double denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

