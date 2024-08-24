#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

// Function to calculate the modular inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // If no modular inverse exists
}

// Function to calculate the determinant of a matrix
int determinant(int matrix[][3], int size) {
    if (size == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % ALPHABET_SIZE;
    } else if (size == 3) {
        int det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
                - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
                + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
        return det % ALPHABET_SIZE;
    }
    return 0;
}

// Function to calculate the inverse of a matrix
void matrix_inverse(int matrix[][3], int inverse[][3], int size) {
    int det = determinant(matrix, size);
    int det_inv = mod_inverse(det, ALPHABET_SIZE);

    if (det_inv == -1) {
        printf("The key matrix is not invertible.\n");
        exit(1);
    }

    int temp[3][3];
    if (size == 2) {
        temp[0][0] = matrix[1][1];
        temp[0][1] = -matrix[0][1];
        temp[1][0] = -matrix[1][0];
        temp[1][1] = matrix[0][0];
    } else if (size == 3) {
        temp[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) % ALPHABET_SIZE;
        temp[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) % ALPHABET_SIZE;
        temp[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) % ALPHABET_SIZE;
        temp[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) % ALPHABET_SIZE;
        temp[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) % ALPHABET_SIZE;
        temp[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) % ALPHABET_SIZE;
        temp[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) % ALPHABET_SIZE;
        temp[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) % ALPHABET_SIZE;
        temp[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % ALPHABET_SIZE;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverse[i][j] = (temp[i][j] * det_inv) % ALPHABET_SIZE;
            if (inverse[i][j] < 0) {
                inverse[i][j] += ALPHABET_SIZE;
            }
        }
    }
}

// Function to multiply matrices
void multiply_matrices(int matrix1[][3], int matrix2[][1], int result[][1], int size) {
    for (int i = 0; i < size; i++) {
        result[i][0] = 0;
        for (int j = 0; j < size; j++) {
            result[i][0] += matrix1[i][j] * matrix2[j][0];
        }
        result[i][0] = result[i][0] % ALPHABET_SIZE; // modulo 26 for alphabet size
    }
}

// Function to pad plaintext if necessary
void pad_plaintext(char *plaintext, int size) {
    int len = strlen(plaintext);
    int pad_len = size - (len % size);
    if (pad_len < size) {
        for (int i = 0; i < pad_len; i++) {
            plaintext[len + i] = 'X'; // Padding character 'X'
        }
        plaintext[len + pad_len] = '\0';
    }
}

// Function to encrypt plaintext using Hill Cipher
void hill_cipher_encrypt(char plaintext[], int key[][3], char ciphertext[], int size) {
    int plaintext_matrix[3][1];
    int ciphertext_matrix[3][1];

    pad_plaintext(plaintext, size);

    for (int i = 0; i < strlen(plaintext); i += size) {
        for (int j = 0; j < size; j++) {
            plaintext_matrix[j][0] = plaintext[i + j] - 'A';
        }
        multiply_matrices(key, plaintext_matrix, ciphertext_matrix, size);
        for (int j = 0; j < size; j++) {
            ciphertext[i + j] = 'A' + ciphertext_matrix[j][0];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

// Function to decrypt ciphertext using Hill Cipher
void hill_cipher_decrypt(char ciphertext[], int key[][3], char plaintext[], int size) {
    int key_inverse[3][3];
    matrix_inverse(key, key_inverse, size);

    int plaintext_matrix[3][1];
    int ciphertext_matrix[3][1];

    for (int i = 0; i < strlen(ciphertext); i += size) {
        for (int j = 0; j < size; j++) {
            ciphertext_matrix[j][0] = ciphertext[i + j] - 'A';
        }
        multiply_matrices(key_inverse, ciphertext_matrix, plaintext_matrix, size);
        for (int j = 0; j < size; j++) {
            plaintext[i + j] = 'A' + plaintext_matrix[j][0];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    int size;
    printf("Enter the matrix size (2 for 2x2 or 3 for 3x3): ");
    if (scanf("%d", &size) != 1 || (size != 2 && size != 3)) {
        printf("Invalid input. Please enter 2 or 3.\n");
        return 1;
    }

    int key[3][3] = {0};
    printf("Enter the %dx%d key matrix (only integers):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (scanf("%d", &key[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    char plaintext[100];
    printf("Enter the plaintext (only alphabetic characters):\n");
    scanf("%s", plaintext);

    // Validate plaintext input
    for (int i = 0; i < strlen(plaintext); i++) {
        if (!isalpha(plaintext[i])) {
            printf("Invalid input. Please enter alphabetic characters only.\n");
            return 1;
        }
        plaintext[i] = toupper(plaintext[i]); // Convert to uppercase
    }

    char ciphertext[3 * strlen(plaintext) + 1];
    hill_cipher_encrypt(plaintext, key, ciphertext, size);
    printf("Ciphertext: %s\n", ciphertext);

    char decrypted[3 * strlen(ciphertext) + 1];
    hill_cipher_decrypt(ciphertext, key, decrypted, size);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
