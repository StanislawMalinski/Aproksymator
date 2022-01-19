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
double exp(double x);
double try(double x);
double pur(double x);
double smt(double x);

void druk(double( *funkcja)(double), double A, double B, int N){
    int i;
    double h;
    h = (B-A)/(N-1);
    for( i = 0; i < N; i++){
        printf("%f %f\n", A+i*h,lin(A+i*h));
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
    
    switch(typ){
	case 'L':
	    druk( lin, A, B, N);
	break;
	case 'P':
            druk( pol, A, B, N);
	break;
	case 'E':
            druk( exp, A, B, N);
	break;
	case 'T':
            druk( try, A, B, N);
	break;
	case 'N':
            druk( pur, A, B, N);
	break;
	case 'J':
            druk( smt, A, B, N);
	break;
    }
}

double lin(double x){
    return (x*70.0/89.0 + 3.2)*(double)(1-SZMER/1000.0*rand()/RAND_MAX);
}
double pol(double x){
    return ((((x - 1.1)*x+2.2)*x-3.3)*x+4.4)*(double)(1-SZMER/1000.0*rand()/RAND_MAX);
}
double exl(double x){
    return pow(1.03, x)*(double)(1-SZMER/1000.0*rand()/RAND_MAX); 
}
double try(double x){
    return 2*sin(x)*(double)(1-SZMER/1000.0*rand()/RAND_MAX);
}
double pur(double x){
   return (pow(x, 2.3)+x*sin(x)-1/x);
}

double smt(double x){
   return (1+x+x*x+x*x*x)+*(double)(1-SZMER/1000.0*rand()/RAND_MAX);
}

