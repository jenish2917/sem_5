#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int eulerTotient(int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;

    printf("Enter a number to calculate Euler's Totient Function: ");
    scanf("%d", &n);

    int result = eulerTotient(n);

    printf("Euler's Totient Function f(%d) = %d\n", n, result);

    return 0;
}

