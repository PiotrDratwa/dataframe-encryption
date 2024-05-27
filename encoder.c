#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//do the function until you find the biggest common divider
//"on the way back" get every x and y the first iteration will get the final x
int euclides(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x2, y2;
    int gcd = euclides(b, a % b, &x2, &y2);
    *x = y2;
    *y = x2 - (a / b) * y2;
    return gcd;
}

int get_prime(){
    int check = 0;
    int a;
    while (check == 0){
        a = rand()%399+101;
        int i = 2;
        while(i<=a){
            if (a%i == 0){
                break;
            }
            i++;
        }
        if(i == a){
            check = 1;
        }
    }
    return a;
}

int relative_prime(int a){
    int check = 0;
    int e;
    while (check == 0){
        e = rand()%89+11;
        int i = 2;
        while (i <= a && i <= e){
            if ((a%i)+(e%i) == 0){
                break;
            }
            i++;
        }
        if (i==a+1||i==e+1){
            check = 1;
        }
    }
    return e;
}

unsigned long long mod_exp(unsigned long long base, int power, int mod)
{
    unsigned long long result = base;
    for (int i = 1; i < power; i++)
    {
        result = (result * base) % mod;
    }
    return result;
}



double mod_exp_double(double base1, int power, int mod, int encode, int*counter){
    unsigned long result1 = (int)base1;
    if(encode ==1){
        base1 = (base1 - result1)*10000;
    }else{
        base1 = (base1 - result1)*pow(10, *counter);
    }
    int result2 = (int)base1;

    printf("%ld %ld\n", result1, result2);
    result1 = mod_exp(result1, power, mod);
    result2 = mod_exp(result2, power, mod);
    //printf("%ld %ld\n\n", result1, result2);

    //printf("%ld.%ld\n", result1, result2);
    double decimal = (double)result2;
    while(decimal>1){
        decimal/=10;
        (*counter)++;
    }
    (*counter)--;
    printf("%f\n", decimal);
    //printf("%f", (double)result1+decimal);
    return (double)result1+decimal;
}

int get_d_parameter(int e, int phi){
    int x, y;
    euclides(e, phi, &x, &y);
    int d = (x % phi + phi) % phi;
    return d;
}

int main(){
    srand(time(0));
    int p = 0;
    int q = 0;
    double num = 102.1234;
    while((p*q)<num){
        p = get_prime();
        q = get_prime();
    }

    int phi = (p-1)*(q-1);
    int e = relative_prime(phi);
    int d = get_d_parameter( e,  phi);
    //int d = euclides(e, phi);

    //printf("%d %d %d %d %d", p, q, e, phi, d);

    long n = p*q;
    int counter = 1;
    int bufor;
    double Enum = (mod_exp_double(num, e, n, 1, &counter));
    double Denum = (mod_exp_double(Enum, d, n, 0, &counter));
    printf("\nnum=%f\nEnum=%f\nDenum=%f\n", num, Enum, Denum);
}

//102 = 14007
//1234 = 60544