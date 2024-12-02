#include <stdio.h>
#include <ctype.h>

void hillCipher(char plaintext[], int key[2][2], char cipher[]) {
    int i, p1, p2;
    int n = 0;

    while (plaintext[n] != '\0') {
        n++;
    }

    if (n % 2 != 0) {
        plaintext[n] = 'x';
        plaintext[n + 1] = '\0';
        n++;
    }

    for (i = 0; i < n; i += 2) {
        p1 = tolower(plaintext[i]) - 'a';
        p2 = tolower(plaintext[i + 1]) - 'a';

        cipher[i] = ((key[0][0] * p1 + key[0][1] * p2) % 26) + 'a';
        cipher[i + 1] = ((key[1][0] * p1 + key[1][1] * p2) % 26) + 'a';
    }
    cipher[n] = '\0'; 
}

int main() {
    char plaintext[] = "hello";  
    int key[2][2] = {{5, 17}, {8, 3}};
    char cipher[100]; 

    hillCipher(plaintext, key, cipher);
    printf("Hill Cipher Output: %s\n", cipher);
    return 0;
}

