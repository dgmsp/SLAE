// Encryption AES 128
// author: Daniel G. Martin
// dgmsp.blogspot.com
// ID - 647

#include <stdio.h>
#include <string.h>
#include <gcrypt.h>
#include <stdint.h>

#define algo GCRY_CIPHER_AES128
#define mode GCRY_CIPHER_MODE_CTR
#define KEY_LENGTH 16
#define BLOCK_LENGTH 16

uint8_t shellcode[] = "\x31\xc0\xb0\x04\x31\xdb\xb3\x01\x31\xd2\x52\x68\x20\x20\x20\x0a\x68\x2e\x4e\x45\x54\x68\x54\x55\x42\x45\x68\x52\x49\x54\x59\x68\x53\x45\x43\x55\x68\x57\x57\x57\x2e\x89\xe1\xb2\x18\xcd\x80\x31\xc0\xb0\x01\xcd\x80";

uint8_t encriptedShellcode[] = "";

const char *key = "0123456789abcdef"; 
uint8_t IV[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\xf0\x10";  
uint8_t ctr[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\xf0\x10";   

static void encryption(int algo, size_t size, uint8_t *encriptedShellcode){
        gcry_cipher_hd_t handle;
        gcry_cipher_open(&handle, algo, mode, 0);
        gcry_cipher_setkey(handle, key, KEY_LENGTH );
        gcry_cipher_setiv(handle, IV, BLOCK_LENGTH);
        gcry_cipher_setctr(handle, ctr, BLOCK_LENGTH);
        gcry_cipher_encrypt(handle, encriptedShellcode, size, shellcode, size);
        gcry_cipher_close(handle);
}

int main(void){
        int i=0;
        int size = strlen(shellcode);
        
        encryption(algo, size, encriptedShellcode);

        printf("\n");
        printf("Encrypted shellcode = ");
        
        while(i<size){
        printf("\\x%02x", encriptedShellcode[i]);
        i++;
        }

        printf("\n\n");
 
        return 0;
}
