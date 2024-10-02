// Implement extended Euclidean Algorithm for finding inverse.

#include <stdio.h>

int gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    
    int x1, y1;
    int g = gcd(b, a % b, &x1, &y1);
    
    *x = y1;
    *y = x1 - y1 * (a / b);
    
    return g;
}

int inverse(int a, int m) {
    int x, y;
    int g = gcd(a, m, &x, &y);
    
    if (g != 1) {
        return -1;
    }
    
    return (x % m + m) % m;
}

int main() {
    int a, m;
    
    printf("Enter the first number (a): ");
    scanf("%d", &a);

    printf("Enter the second number (m): ");
    scanf("%d", &m); 
    
    int result = inverse(a, m);
    
    if (result == -1) {
        printf("Inverse doesn't exist\n");
    } else {
        printf("Inverse of %d under modulo %d is: %d\n", a, m, result);
    }
    
    return 0;
}
