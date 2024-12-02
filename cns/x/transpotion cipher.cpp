#include <stdio.h>
#include <string.h>

void columnarEncrypt(char plaintext[], int key[], int keyLen, char ciphertext[]) {
    int i, j, k, rows, len = strlen(plaintext);
    char table[10][10];
    k = 0;
    rows = (len + keyLen - 1) / keyLen;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < keyLen; j++) {
            if (k < len) {
                table[i][j] = plaintext[k++];
            } else {
                table[i][j] = 'X';
            }
        }
    }
    k = 0;
    for (i = 0; i < keyLen; i++) {
        int col = key[i] - 1;
        for (j = 0; j < rows; j++) {
            ciphertext[k++] = table[j][col];
        }
    }
    ciphertext[k] = '\0';
}

int main() {
    char plaintext[] = "attackpostponeduntiltwoam";
    int key[] = {4, 3, 1, 2, 5, 6, 7};
    char ciphertext[100];
    columnarEncrypt(plaintext, key, 7, ciphertext);
    printf("Columnar Transposition Cipher Output: %s\n", ciphertext);
    return 0;
}

