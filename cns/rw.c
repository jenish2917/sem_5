#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char ch;

    fp1 = fopen("file1.txt", "r");
    if (fp1 == NULL) {
        perror("Error opening file1.txt");
        return 1;
    }

    fp2 = fopen("file2.txt", "w+");

    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}