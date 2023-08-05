/* This program calculates an aproximation for e^x with a infinite series. The user just need to provide a 'x' value and wait the program make the calculus*/

#include <stdio.h>
#include <math.h>

#define TOL 0.000001 //tolerance

int main(){
    int x; //input
    double e = 0; //output
    int n = 0, i, factorial = 1; // control and auxiliary variables

    printf("Isert the value of 'x' (expoent): ");
    scanf("%d", &x);


    do{
        if (n > 0){
            for(i = 1; i <= n; factorial *= i, i++); //calculus of the factorial
        }
        //printf("n: %d factorial = %d\n", n, factorial);
        
        e += pow(x, n)/factorial; //calculus of the infinite series

        //printf("e = %.8lf\n", e);

        //printf("e math.h = %.8lf\n", exp((double)x));
        //printf("%lf\n\n", (e - exp((double)x)));

        factorial = 1;
        n++;
    } while ((exp((double)x) - e) > TOL);

    printf("Calculated e^x = %lf\n", e);
    


    return 0;
}