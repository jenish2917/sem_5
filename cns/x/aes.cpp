#include <stdio.h>
#include <string.h>

#define Nb 4
#define Nk 4
#define Nr 10

typedef unsigned char state_t[4][4];

unsigned char Sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf0, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0x0f, 0x02, 0x03, 0x13, 0x6a, 0x35, 0x85, 0x9f,
    0x57, 0x63, 0x9c, 0x73, 0x79, 0x78, 0x8f, 0x8b, 0x99, 0x85, 0xa3, 0x35, 0x8c, 0x7d, 0xb9, 0x0f,
    0x6f, 0xd4, 0xc6, 0x77, 0x99, 0x80, 0x23, 0x77, 0x3a, 0x58, 0x2f, 0x3c, 0xd2, 0x12, 0x24, 0x49
};

unsigned char Rcon[11] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
};

void SubBytes(state_t state) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            state[i][j] = Sbox[state[i][j]];
        }
    }
}

void ShiftRows(state_t state) {
    unsigned char temp;
    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    temp = state[3][0];
    state[3][0] = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = temp;
}

void MixColumns(state_t state) {
    unsigned char temp[4];
    for (int i = 0; i < 4; i++) {
        temp[0] = state[0][i];
        temp[1] = state[1][i];
        temp[2] = state[2][i];
        temp[3] = state[3][i];
        state[0][i] = temp[0] ^ temp[1] ^ temp[2] ^ temp[3];
        state[1][i] = temp[0] ^ temp[1];
        state[2][i] = temp[1] ^ temp[2];
        state[3][i] = temp[2] ^ temp[3];
    }
}

void AddRoundKey(state_t state, unsigned char roundKey[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            state[i][j] ^= roundKey[i][j];
        }
    }
}

void KeyExpansion(unsigned char key[4][4], unsigned char roundKeys[11][4][4]) {
    unsigned char temp[4];
    int i = 0;
    while (i < Nk) {
        roundKeys[i][0][0] = key[i][0];
        roundKeys[i][0][1] = key[i][1];
        roundKeys[i][0][2] = key[i][2];
        roundKeys[i][0][3] = key[i][3];
        i++;
    }
}

void AES_encrypt(unsigned char input[16], unsigned char key[16], unsigned char output[16]) {
    unsigned char roundKeys[11][4][4];
    unsigned char state[4][4];

    KeyExpansion(key, roundKeys);

    AddRoundKey(state, roundKeys[0]);

    for (int round = 1; round < Nr; round++) {
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state, roundKeys[round]);
    }

    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, roundKeys[Nr]);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            output[i * 4 + j] = state[i][j];
        }
    }
}

int main() {
    unsigned char input[16] = "This is plaintext";
    unsigned char key[16] = "Thatsmykey000000";
    unsigned char encrypted[16];

    AES_encrypt(input, key, encrypted);

    printf("Encrypted Text: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    return 0;
}

