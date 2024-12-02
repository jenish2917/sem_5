#include <stdio.h>
#include <string.h>

void vernamEncrypt(char plaintext[], char key[], char ciphertext[]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
    ciphertext[len] = '\0';
}

void vernamDecrypt(char ciphertext[], char key[], char decrypted[]) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        decrypted[i] = ciphertext[i] ^ key[i];
    }
    decrypted[len] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100], decrypted[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key (same length as plaintext): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    if (strlen(plaintext) != strlen(key)) {
        printf("Error: Key must be the same length as the plaintext.\n");
        return 1;
    }

    vernamEncrypt(plaintext, key, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02X ", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    vernamDecrypt(ciphertext, key, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}

