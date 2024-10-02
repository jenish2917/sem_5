#include <stdio.h>

// Function to calculate the gcd
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to perform modular exponentiation
// It returns (base^exponent) % modulus
long long mod_exp(long long base, long long exponent, long long modulus) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent >> 1;
    }
    return result;
}

// Function to find modular inverse using Extended Euclidean Algorithm
int mod_inverse(int e, int phi) {
    int t = 0, newT = 1;
    int r = phi, newR = e;

    while (newR != 0) {
        int quotient = r / newR;
        int tempT = t;
        t = newT;
        newT = tempT - quotient * newT;

        int tempR = r;
        r = newR;
        newR = tempR - quotient * newR;
    }

    if (r > 1) {
        return -1; // e and phi(n) are not coprime
    }

    if (t < 0) {
        t = t + phi;
    }

    return t;
}

int main() {
    // Prime numbers p and q
    int p = 17;
    int q = 11;

    // Step 1 : Calculate n = p * q
    int n = p * q;
    printf("Value of n (p * q) = %d\n", n);

    // Step 2 : Calculate φ(n) = (p-1) * (q-1)
    int phi = (p - 1) * (q - 1);
    printf("Value of phi(n) = %d\n", phi);

    // Step 3 : Choose an integer e such that 1 < e < φ(n) and e is coprime with φ(n)
    int e = 7;
    if (gcd(e, phi) != 1) {
        printf("Encryption key e is not coprime with phi(n)\n");
        return 1;
    }
    printf("Value of e = %d\n", e);

    // Step 4 : Calculate the decryption key d such that (d * e) % φ(n) = 1
    int d = mod_inverse(e, phi);
    if (d == -1) {
        printf("Decryption key d does not exist\n");
        return 1;
    }
    printf("Value of d = %d\n", d);

    // Step 5 : Encrypt the plaintext message M
    long long M = 88;
    printf("Plaintext message M = %lld\n", M);

    // C = M^e mod n
    long long C = mod_exp(M, e, n); // Ciphertext
    printf("Encrypted message C = %lld\n", C);

    // Step 6 : Decrypt the ciphertext message C
    // M = C^d mod n
    long long decrypted_M = mod_exp(C, d, n); // Decrypted message
    printf("Decrypted message M = %lld\n", decrypted_M);

    return 0;
}
