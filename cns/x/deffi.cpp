#include <stdio.h>
#include <math.h>

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
    unsigned long p = 23;
    unsigned long g = 5;
    unsigned long a = 6;
    unsigned long b = 15;

    unsigned long A = power_mod(g, a, p);
    unsigned long B = power_mod(g, b, p);

    unsigned long shared_key_alice = power_mod(B, a, p);
    unsigned long shared_key_bob = power_mod(A, b, p);

    printf("Prime number p = %lu\n", p);
    printf("Primitive root g = %lu\n", g);
    printf("Alice's private key a = %lu\n", a);
    printf("Bob's private key b = %lu\n", b);
    printf("Alice's public key A = %lu\n", A);
    printf("Bob's public key B = %lu\n", B);
    printf("Shared key computed by Alice = %lu\n", shared_key_alice);
    printf("Shared key computed by Bob = %lu\n", shared_key_bob);

    if (shared_key_alice == shared_key_bob) {
        printf("Key exchange successful. Shared secret key is %lu\n", shared_key_alice);
    } else {
        printf("Key exchange failed.\n");
    }

    return 0;
}

