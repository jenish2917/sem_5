#include <stdio.h>

int extendedGCD(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, &x, &y);
    if (gcd != 1) {
        printf("Inverse does not exist\n");
        return -1;
    } else {
        return (x % m + m) % m; // Ensuring the result is positive
    }
}

int main() {
    int a, m;
    
    printf("Enter the number (a): ");
    scanf("%d", &a);
    
    printf("Enter the modulus (m): ");
    scanf("%d", &m);

    int inverse = modInverse(a, m);
    if (inverse != -1) {
        printf("Modular inverse of %d modulo %d is: %d\n", a, m, inverse);
    }

    return 0;
}

