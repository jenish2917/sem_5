#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int power(int x, unsigned int y, int p) {
    int result = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            result = (result * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return result;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int main() {
    int p = 17, q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 7;
    while (gcd(e, phi) != 1) {
        e++;
    }

    int d = modInverse(e, phi);
    printf("Public Key: (n = %d, e = %d)\n", n, e);
    printf("Private Key: (d = %d)\n", d);

    int M;
    printf("Enter the plaintext message (M): ");
    scanf("%d", &M);

    int C = power(M, e, n);
    printf("Ciphertext (C) = %d\n", C);

    int decrypted_M = power(C, d, n);
    printf("Decrypted plaintext message (M) = %d\n", decrypted_M);

    return 0;
}
