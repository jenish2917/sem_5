#include <stdio.h>
#include <string.h>

void railFenceEncrypt (char plaintext[], char ciphertext[]){
	int i, l = strlen(plaintext) ;
	int index = 0;
	
	for (i = 0; i < l; i+=2){
		ciphertext[index++] = plaintext[i];
	}
	
	for(i = 1; i < l; i+=2){
		ciphertext[index++] = plaintext[i];
	}
	
	ciphertext[index] = '\0';
}

int main (){
	char plaintext[] = "MEETME";
	char ciphertext[100];
	
	railFenceEncrypt(plaintext, ciphertext);
	printf("Rail Fence Cipher output : %s\n", ciphertext);
	return 0;
}
