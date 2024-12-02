#include <stdio.h>

int euclidGCD(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int num1, num2, gcd;

    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);

    gcd = euclidGCD(num1, num2);

    printf("GCD(%d, %d) = %d\n", num1, num2, gcd);

    return 0;
}

