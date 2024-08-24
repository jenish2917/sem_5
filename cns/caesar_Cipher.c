#include<stdio.h>
#include<conio.h>
#include<string.h>

void Encrypt(){
    char str[100];

    printf("Enter the string to be encrypted\n");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // remove the newline character

    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] = 'a' + (str[i] - 'a' + 3) % 26;
        }
        else if(str[i]>='A' && str[i]<='Z'){
            str[i] = 'A' + (str[i] - 'A' + 3) % 26;
        }
        else if(str[i]>='0' && str[i]<='9'){
            str[i] = '0' + (str[i] - '0' + 3) % 10;
        }
    }
    printf("Encrypted string: %s\n", str);
}

void Decrypt(){
    char str[100];

    printf("Enter the string to be decrypted\n");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // remove the newline character

    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] = 'a' + (str[i] - 'a' - 3) % 26;
            if(str[i] < 'a')
                str[i] += 26;
        }
        else if(str[i]>='A' && str[i]<='Z'){
            str[i] = 'A' + (str[i] - 'A' - 3) % 26;
            if(str[i] < 'A')
                str[i] += 26;
        }
        else if(str[i]>='0' && str[i]<='9'){
            str[i] = '0' + (str[i] - '0' - 3) % 10;
            if(str[i] < '0')
                str[i] += 10;
        }
    }
    printf("Decrypted string: %s\n", str);
}

int main() {
    int choice;
    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    getchar(); // consume the newline character
    switch(choice) {
        case 1:
            Encrypt();
            break;
        case 2:
            Decrypt();
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}