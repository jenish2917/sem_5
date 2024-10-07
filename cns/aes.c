#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mcrypt.h>
#include <math.h>
#include <stdint.h>

int encrypt(
    void* buffer,
    int buffer_len, 
    char* IV, 
    char* key,
    int key_len 
){
  MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL);
  if (td == MCRYPT_FAILED) {
    return 1;
  }
  
  int blocksize = mcrypt_enc_get_block_size(td);
  if (buffer_len % blocksize != 0) {
    mcrypt_module_close(td);
    return 1;
  }

  mcrypt_generic_init(td, key, key_len, IV);
  mcrypt_generic(td, buffer, buffer_len);
  mcrypt_generic_deinit(td);
  mcrypt_module_close(td);
  
  return 0;
}

int decrypt(
    void* buffer,
    int buffer_len,
    char* IV, 
    char* key,
    int key_len 
){
  MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL);
  if (td == MCRYPT_FAILED) {
    return 1;
  }
  
  int blocksize = mcrypt_enc_get_block_size(td);
  if (buffer_len % blocksize != 0) {
    mcrypt_module_close(td);
    return 1;
  }
  
  mcrypt_generic_init(td, key, key_len, IV);
  mdecrypt_generic(td, buffer, buffer_len);
  mcrypt_generic_deinit(td);
  mcrypt_module_close(td);
  
  return 0;
}

void display(char* ciphertext, int len){
  for (int v = 0; v < len; v++) {
    printf("%d ", (unsigned char)ciphertext[v]);
  }
  printf("\n");
}

int main()
{
  char* plaintext = "test text 123";
  char* IV = "AAAAAAAAAAAAAAAA";
  char* key = "0123456789abcdef";
  int keysize = 16; /* 128 bits */
  int buffer_len = 16;

  char* buffer = calloc(1, buffer_len);
  if (buffer == NULL) {
    perror("calloc");
    return 1;
  }

  strncpy(buffer, plaintext, buffer_len - 1);
  buffer[buffer_len - 1] = '\0'; // Ensure null-termination

  printf("==C==\n");
  printf("plain:   %s\n", plaintext);
  if (encrypt(buffer, buffer_len, IV, key, keysize) != 0) {
    fprintf(stderr, "Encryption failed\n");
    free(buffer);
    return 1;
  }
  printf("cipher:  "); display(buffer, buffer_len);
  if (decrypt(buffer, buffer_len, IV, key, keysize) != 0) {
    fprintf(stderr, "Decryption failed\n");
    free(buffer);
    return 1;
  }
  printf("decrypt: %s\n", buffer);
  
  free(buffer);
  return 0;
}