#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int euclides(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = euclides(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int get_prime(){
    int check = 0;
    int a;
    while (check == 0){
        a = rand()%899+101;
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

unsigned long long mod_exp(unsigned long long base, int pow, int mod)
{
    unsigned long long result = base;
    for (int i = 1; i < pow; i++)
    {
        result = (result * base) % mod;
    }
    return result;
}

int get_d_parameter(int e, int phi){
    int x, y;
    euclides(e, phi, &x, &y);
    int d = (x % phi + phi) % phi;
    return d;
}

int main(){
    srand(time(0));
    /*
    int p = 0;
    int q = 0;
    long num = 1024;
    while((p*q)<num){
        p = get_prime();
        q = get_prime();
    }
    int phi = (p-1)*(q-1);
    int e = relative_prime(phi);
    int d = get_d_parameter( e,  phi);
    //int d = euclides(e, phi);
    printf("%d %d %d %d %d", p, q, e, phi, d);
    long n = p*q;
    unsigned long long Enum = (mod_exp(num, e, n));
    unsigned long long Denum = (mod_exp(Enum, d, n));
    printf("\nnum=%ld\nEnum=%lld\nDenum=%lld\n", num, Enum, Denum);
    */
}

