#include <stdio.h>
#include <math.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

unsigned long mod_inverse(unsigned long a, unsigned long m) {
    unsigned long m0 = m, t, q;
    unsigned long x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

unsigned long power_mod(unsigned long base, unsigned long exp, unsigned long mod) {
    unsigned long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    unsigned long p = 17, q = 11;
    unsigned long n = p * q;
    unsigned long phi_n = (p - 1) * (q - 1);
    unsigned long e = 7;
    unsigned long d;

    d = mod_inverse(e, phi_n);

    unsigned long M = 88;
    unsigned long C = power_mod(M, e, n);
    unsigned long decrypted_M = power_mod(C, d, n);

    printf("Two prime numbers: p = %lu, q = %lu\n", p, q);
    printf("n = p * q = %lu\n", n);
    printf("Encryption key (e) = %lu\n", e);
    printf("Decryption key (d) = %lu\n", d);
    printf("Plaintext message M = %lu\n", M);
    printf("Ciphertext C = M^e mod n = %lu\n", C);
    printf("Decrypted plaintext M = C^d mod n = %lu\n", decrypted_M);

    return 0;
}

