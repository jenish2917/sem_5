#include <stdio.h>
#include <openssl/dsa.h>
#include <openssl/err.h>
#include <openssl/rand.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int main() {
    // Initialize OpenSSL
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Generate DSA parameters
    DSA *dsa = DSA_new();
    if (dsa == NULL) handleErrors();

    if (DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, NULL) != 1) {
        handleErrors();
    }

    // Generate DSA key pair
    if (DSA_generate_key(dsa) != 1) {
        handleErrors();
    }

    // Message to be signed
    unsigned char *message = (unsigned char *)"This is a test message";
    unsigned int message_len = strlen((char *)message);

    // Sign the message
    unsigned char *signature = (unsigned char *)malloc(DSA_size(dsa));
    unsigned int sig_len;
    if (DSA_sign(0, message, message_len, signature, &sig_len, dsa) != 1) {
        handleErrors();
    }

    printf("Message signed successfully.\n");

    // Verify the signature
    int verify_status = DSA_verify(0, message, message_len, signature, sig_len, dsa);
    if (verify_status == 1) {
        printf("Signature verified successfully.\n");
    } else if (verify_status == 0) {
        printf("Signature verification failed.\n");
    } else {
        handleErrors();
    }

    // Clean up
    DSA_free(dsa);
    free(signature);
    EVP_cleanup();
    ERR_free_strings();

    return 0;
}