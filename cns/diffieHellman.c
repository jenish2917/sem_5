#include<stdio.h>
#include<math.h>

long long mod_exp(long long base, long long exponent, long long modulus){
    long long result = 1;
    base = base % modulus;
    while(exponent > 0){
        // if exponent is odd, multiply base with result and take the modulo with modulus
        if (exponent % 2 == 1){
            result = (result * base) % modulus;
        }

        // Exponent is even now
        exponent = exponent >> 1; // exponent = exponent / 2
        base = (base * base) % modulus;
    }
    return result;
}

int main(){
    // Publicly known prime modulus (p) and base (g)
    long long p = 23; // Example small prime number
    long long g = 5;  // Example primitive root modulo p

    // Alice's secret key (private key)
    long long a = 6;  // Alice's private key

    // Alice's public key (A)
    long long A = mod_exp(g, a, p);  // A = g^a mod p

    // Bob's secret key (private key)
    long long b = 15;  // Bob's private key

    // Bob's public key (B)
    long long B = mod_exp(g, b, p);  // B = g^b mod p

    // Both calculate the shared secret key
    // Alice computes the secret key: s = B^a mod p
    long long secret_Alice = mod_exp(B, a, p);  // s = B^a mod p

    // Bob computes the secret key: s = A^b mod p
    long long secret_Bob = mod_exp(A, b, p);  // s = A^b mod p

    // Both should have the same secret key
    printf("Shared secret key (Alice): %lld\n", secret_Alice);
    printf("Shared secret key (Bob): %lld\n", secret_Bob);

    if (secret_Alice == secret_Bob){
        printf("Key exchange is successful\n");
    } else {
        printf("Key exchange is unsuccessful\n");
    }

    return 0;
}
