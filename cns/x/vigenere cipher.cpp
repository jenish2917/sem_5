#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateKey(char plaintext[], char keyword[], char key[]) {
    int i, j = 0, len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            key[i] = toupper(keyword[j]);
            j = (j + 1) % strlen(keyword);
        } else {
            key[i] = plaintext[i];
        }
    }
    key[len] = '\0';
}

void vigenereEncrypt(char plaintext[], char key[], char ciphertext[]) {
    int i, len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            int shift = key[i] - 'A';
            if (isupper(plaintext[i])) {
                ciphertext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A';
            } else {
                ciphertext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a';
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
}

void vigenereDecrypt(char ciphertext[], char key[], char decrypted[]) {
    int i, len = strlen(ciphertext);
    for (i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            int shift = key[i] - 'A';
            if (isupper(ciphertext[i])) {
                decrypted[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A';
            } else {
                decrypted[i] = ((ciphertext[i] - 'a' - shift + 26) % 26) + 'a';
            }
        } else {
            decrypted[i] = ciphertext[i];
        }
    }
    decrypted[len] = '\0';
}

int main() {
    char plaintext[100], keyword[100], key[100], ciphertext[100], decrypted[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    for (int i = 0; keyword[i]; i++) keyword[i] = toupper(keyword[i]);

    generateKey(plaintext, keyword, key);

    vigenereEncrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    vigenereDecrypt(ciphertext, key, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}

