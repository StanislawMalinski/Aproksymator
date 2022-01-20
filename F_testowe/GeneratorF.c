#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SZMER 50

/*
Jako pierwszy argument podajemy typ funkcji

['L'- liniowa, 'P' - wielomain 4 stopnia, 'E' - wykładnicza, 'T' - trygonometryczna, 'N' - nie zkłócona, 'J' Jakaś]

Jako drugi początek przedział w którym mają być generowane punkty
Jako trzeci koniec przedziału
Jako czwarty ilość punktów 

LPETNJ

*/

double lin(double x);
double pol(double x);
double exl(double x);
double try(double x);
double pur(double x);
double smt(double x);

void druk(double( *funkcja)(double), double A, double B, int N){
    int i;
    double h;
    h = (B-A)/(N-1);
    for( i = 0; i < N; i++){
        printf("%f %f\n", A+i*h,funkcja(A+i*h));
    }
}

int main(int argc, char **argv){
    int i;
    double h;
    char *t = argc > 1 ? argv[1] : NULL;
    double A = argc > 2 ? atof(argv[2]) : 0;
    double B = argc > 3 ? atof(argv[3]) : 100;
    int N = argc > 4 ? atoi(argv[4]) : 1000;
    char typ = t[0]; 
   	
    if  ( N < 0 ||argc > 5){
	fprintf(stderr, "%s: Błądne dane wejściowe\n", argv[0]);
	return 1; 
    }
    srand(time(NULL));
    if(typ == '1')
	      druk( lin, A, B, N);
    if(typ == '2')
              druk( pol, A, B, N);
    if(typ == '3')
              druk( exl, A, B, N);
    if(typ == '4')
              druk( try, A, B, N);
    if(typ == '5')
              druk( pur, A, B, N);
    if(typ == '6')
              druk( smt, A, B, N);
    return 0;
}

double lin(double x){
    return (x*7354.0/83429.0 + 3342234.2)*(double)(1-SZMER/1000.0*rand()/RAND_MAX);
}
double pol(double x){
    return (1.0/50.0*(x)*(x-25)*(x-50)*(x-100)+0)*(double)(1-SZMER/1000.0*rand()/RAND_MAX);
}
double exl(double x){
    return pow(1.05, x)*(double)(1-SZMER/1000.0*rand()/RAND_MAX); 
}
double try(double x){
    return 2*sin(x)*(double)(1-SZMER/1000.0*rand()/RAND_MAX);
}
double pur(double x){
   return (pow(x, 2.3)+x*sin(x)-1/x);
}

double smt(double x){
   return (sin(x/30))*(double)(1-SZMER/1000.0*rand()/RAND_MAX);
}

