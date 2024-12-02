#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long mod_pow(unsigned long base, unsigned long exp, unsigned long mod) {
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

void generate_keys(unsigned long *p, unsigned long *g, unsigned long *x, unsigned long *y) {
    *p = 23;  
    *g = 5;  

    *x = rand() % (*p - 2) + 1; 
    *y = mod_pow(*g, *x, *p); 
}

unsigned long sign_message(unsigned long p, unsigned long g, unsigned long x, unsigned long message) {
    unsigned long k, r, s, h;

    srand(time(NULL));
    k = rand() % (p - 2) + 1;  
    r = mod_pow(g, k, p); 
    r = r % p;  
    if (r == 0) {
        return 0;
    }

    h = message; 
    s = ((h + x * r) * mod_inverse(k, p - 1)) % (p - 1); 

    printf("Signature (r, s): (%lu, %lu)\n", r, s);
    return r;
}

int verify_signature(unsigned long p, unsigned long g, unsigned long y, unsigned long message, unsigned long r, unsigned long s) {
    unsigned long w, v1, v2;

    if (r <= 0 || r >= p || s <= 0 || s >= p) {
        return 0; 
    }

    w = mod_inverse(s, p - 1);
    unsigned long h = message;

    v1 = mod_pow(g, h * w, p);
    v2 = (mod_pow(y, r * w, p) * mod_pow(g, s * w, p)) % p;

    if (v1 == v2) {
        return 1; 
    }
    return 0; 
}

int main() {
    unsigned long p, g, x, y;
    unsigned long message = 10;
    unsigned long r, s;

    generate_keys(&p, &g, &x, &y);

    printf("Generated keys:\n");
    printf("p = %lu, g = %lu, private key (x) = %lu, public key (y) = %lu\n", p, g, x, y);

    r = sign_message(p, g, x, message);
    printf("Message signature generated: r = %lu\n", r);

    int is_valid = verify_signature(p, g, y, message, r, s);
    if (is_valid) {
        printf("The signature is valid.\n");
    } else {
        printf("The signature is invalid.\n");
    }

    return 0;
}

