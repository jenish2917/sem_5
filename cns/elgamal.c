#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>

void generate_keys(mpz_t p, mpz_t g, mpz_t x, mpz_t y) {
    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, time(NULL));

    // Generate prime p
    mpz_urandomb(p, state, 512);
    mpz_nextprime(p, p);

    // Generate generator g
    mpz_urandomm(g, state, p);

    // Generate private key x
    mpz_urandomm(x, state, p);

    // Compute public key y = g^x mod p
    mpz_powm(y, g, x, p);

    gmp_randclear(state);
}

void sign_message(mpz_t r, mpz_t s, const mpz_t p, const mpz_t g, const mpz_t x, const char *message) {
    mpz_t k, k_inv, h, temp;
    mpz_inits(k, k_inv, h, temp, NULL);

    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, time(NULL));

    // Generate random k
    do {
        mpz_urandomm(k, state, p);
    } while (mpz_cmp_ui(k, 0) == 0);

    // Compute r = g^k mod p
    mpz_powm(r, g, k, p);

    // Compute k_inv = k^-1 mod (p-1)
    mpz_sub_ui(temp, p, 1);
    mpz_invert(k_inv, k, temp);

    // Compute hash of the message
    mpz_import(h, strlen(message), 1, 1, 0, 0, message);

    // Compute s = k_inv * (h - x * r) mod (p-1)
    mpz_mul(temp, x, r);
    mpz_sub(temp, h, temp);
    mpz_mul(temp, k_inv, temp);
    mpz_mod(s, temp, p);

    mpz_clears(k, k_inv, h, temp, NULL);
    gmp_randclear(state);
}

int verify_signature(const mpz_t r, const mpz_t s, const mpz_t p, const mpz_t g, const mpz_t y, const char *message) {
    mpz_t h, v1, v2, temp1, temp2;
    mpz_inits(h, v1, v2, temp1, temp2, NULL);

    // Compute hash of the message
    mpz_import(h, strlen(message), 1, 1, 0, 0, message);

    // Compute v1 = g^h mod p
    mpz_powm(v1, g, h, p);

    // Compute v2 = (y^r * r^s) mod p
    mpz_powm(temp1, y, r, p);
    mpz_powm(temp2, r, s, p);
    mpz_mul(v2, temp1, temp2);
    mpz_mod(v2, v2, p);

    int result = mpz_cmp(v1, v2) == 0;

    mpz_clears(h, v1, v2, temp1, temp2, NULL);
    return result;
}

int main() {
    mpz_t p, g, x, y, r, s;
    mpz_inits(p, g, x, y, r, s, NULL);

    // Generate keys
    generate_keys(p, g, x, y);

    // Message to be signed
    const char *message = "This is a test message";

    // Sign the message
    sign_message(r, s, p, g, x, message);
    gmp_printf("Signature: (r: %Zd, s: %Zd)\n", r, s);

    // Verify the signature
    if (verify_signature(r, s, p, g, y, message)) {
        printf("Signature verified successfully.\n");
    } else {
        printf("Signature verification failed.\n");
    }

    mpz_clears(p, g, x, y, r, s, NULL);
    return 0;
}