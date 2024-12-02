#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createKeyTable(char key[], char table[5][5]) {
    int alpha[26] = {0}, i, j, k = 0;
    for (i = 0; i < strlen(key); i++) {
        if (key[i] == 'J') key[i] = 'I';
        if (!alpha[key[i] - 'A']) {
            table[k / 5][k % 5] = key[i];
            alpha[key[i] - 'A'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (i + 'A' != 'J' && !alpha[i]) {
            table[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

void prepareText(char plaintext[], char processed[]) {
    int i, j = 0, len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        if (plaintext[i] == 'J') plaintext[i] = 'I';
        if (isalpha(plaintext[i])) {
            processed[j++] = toupper(plaintext[i]);
            if (j > 1 && processed[j - 1] == processed[j - 2]) {
                processed[j - 1] = 'X';
                processed[j++] = toupper(plaintext[i]);
            }
        }
    }
    if (j % 2 != 0) processed[j++] = 'X';
    processed[j] = '\0';
}

void findPosition(char table[5][5], char c, int *row, int *col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (table[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void playfairEncrypt(char plaintext[], char key[], char ciphertext[]) {
    char table[5][5], processed[100];
    int i, r1, c1, r2, c2, k = 0;

    createKeyTable(key, table);
    prepareText(plaintext, processed);

    for (i = 0; i < strlen(processed); i += 2) {
        findPosition(table, processed[i], &r1, &c1);
        findPosition(table, processed[i + 1], &r2, &c2);

        if (r1 == r2) {
            ciphertext[k++] = table[r1][(c1 + 1) % 5];
            ciphertext[k++] = table[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            ciphertext[k++] = table[(r1 + 1) % 5][c1];
            ciphertext[k++] = table[(r2 + 1) % 5][c2];
        } else {
            ciphertext[k++] = table[r1][c2];
            ciphertext[k++] = table[r2][c1];
        }
    }
    ciphertext[k] = '\0';
}

int main() {
    char key[] = "MONARCHY";
    char plaintext[] = "HELLO";
    char ciphertext[100];

    playfairEncrypt(plaintext, key, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}

