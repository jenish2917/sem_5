#include <stdio.h>
#include <string.h>

int IP[8] = {2, 6, 3, 1, 4, 8, 5, 7};
int IP1[8] = {4, 1, 3, 5, 7, 2, 8, 6};
int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int P4[4] = {2, 4, 3, 1};
int E_P[8] = {4, 1, 2, 3, 2, 3, 4, 1};

int S0[4][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
int S1[4][4] = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 2}, {2, 1, 0, 3}};

void permute(int input[10], int permutation[10], int len, int output[10]) {
    int i;
    for (i = 0; i < len; i++) {
        output[i] = input[permutation[i] - 1];
    }
}

void leftShift(int key[5], int len, int shift, int output[5]) {
    int i;
    for (i = 0; i < len; i++) {
        output[i] = key[(i + shift) % len];
    }
}

void xorOperation(int a[8], int b[8], int len, int output[8]) {
    int i;
    for (i = 0; i < len; i++) {
        output[i] = a[i] ^ b[i];
    }
}

void sBoxSubstitution(int input[4], int sBox[4][4], int output[4]) {
    int row, col, val, i;
    row = (input[0] * 2) + input[3];
    col = (input[1] * 2) + input[2];
    val = sBox[row][col];
    for (i = 3; i >= 0; i--) {
        output[i] = val % 2;
        val /= 2;
    }
}

void generateKeys(int key[10], int K1[8], int K2[8]) {
    int permutedKey[10], left[5], right[5], temp[5], i;
    permute(key, P10, 10, permutedKey);

    for (i = 0; i < 5; i++) {
        left[i] = permutedKey[i];
        right[i] = permutedKey[i + 5];
    }

    leftShift(left, 5, 1, left);
    leftShift(right, 5, 1, right);
    for (i = 0; i < 5; i++) {
        temp[i] = left[i];
        K1[i] = left[i];
        K1[i + 5] = right[i];
    }
    leftShift(left, 5, 2, left);
    leftShift(right, 5, 2, right);
    for (i = 0; i < 5; i++) {
        K2[i] = left[i];
        K2[i + 5] = right[i];
    }
}

void f(int input[4], int key[8], int output[4]) {
    int expanded[8], temp[8], left[4], right[4], leftResult[4], rightResult[4], combined[8], i;
    permute(input, E_P, 8, expanded);
    xorOperation(expanded, key, 8, temp);

    for (i = 0; i < 4; i++) {
        left[i] = temp[i];
        right[i] = temp[i + 4];
    }

    sBoxSubstitution(left, S0, leftResult);
    sBoxSubstitution(right, S1, rightResult);

    for (i = 0; i < 4; i++) {
        combined[i] = leftResult[i];
        combined[i + 4] = rightResult[i];
    }
    permute(combined, P4, 4, output);
}

void sDesEncrypt(int plaintext[8], int key[10], int ciphertext[8]) {
    int K1[8], K2[8], ipResult[8], left[4], right[4], temp[4], round1[4], round2[4], i;
    generateKeys(key, K1, K2);

    permute(plaintext, IP, 8, ipResult);

    for (i = 0; i < 4; i++) {
        left[i] = ipResult[i];
        right[i] = ipResult[i + 4];
    }

    f(right, K1, round1);
    xorOperation(left, round1, 4, temp);
    for (i = 0; i < 4; i++) {
        left[i] = temp[i];
    }

    f(right, K2, round2);
    xorOperation(left, round2, 4, temp);

    permute(temp, IP1, 8, ciphertext);
}

void sDesDecrypt(int ciphertext[8], int key[10], int plaintext[8]) {
    int K1[8], K2[8], ipResult[8], left[4], right[4], temp[4], round1[4], round2[4], i;
    generateKeys(key, K1, K2);

    permute(ciphertext, IP, 8, ipResult);

    for (i = 0; i < 4; i++) {
        left[i] = ipResult[i];
        right[i] = ipResult[i + 4];
    }

    f(right, K2, round1);
    xorOperation(left, round1, 4, temp);
    for (i = 0; i < 4; i++) {
        left[i] = temp[i];
    }

    f(right, K1, round2);
    xorOperation(left, round2, 4, temp);

    permute(temp, IP1, 8, plaintext);
}

int main() {
    int key[10] = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
    int plaintext[8] = {1, 0, 0, 0, 0, 1, 1, 0};
    int ciphertext[8], decryptedText[8], i;

    sDesEncrypt(plaintext, key, ciphertext);
    printf("Ciphertext: ");
    for (i = 0; i < 8; i++) {
        printf("%d", ciphertext[i]);
    }
    printf("\n");

    sDesDecrypt(ciphertext, key, decryptedText);
    printf("Decrypted text: ");
    for (i = 0; i < 8; i++) {
        printf("%d", decryptedText[i]);
    }
    printf("\n");

    return 0;
}

