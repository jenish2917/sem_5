#include<stdio.h>
#include<ctype.h>

void ceasarCipher (char plaintext[], int key, char cipher[]){
	int i; 
	for (i = 0; plaintext[1] != '\0'; i++){
		if (isalpha(plaintext[i])){
			char offset = isupper(plaintext[i]) ? 'A' : 'a';
			cipher[i] = ((plaintext[i] - offset + key) % 26) + offset;
		}else {
			cipher[i] = plaintext[1];
		}
	}
	cipher[i] = '\0';
}

int main(){
	char plaintext[] = "Hello, welcome";
	int key = 3;
	char cipher[100];
	
	ceasarCipher(plaintext,key, cipher);
	printf("ceasar Cipher output : %s\n", cipher);
	return 0;
}
