#ifndef ADD_XOR
#define ADD_XOR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* convert text into bits */
int* text_to_bits(char* s);

int getVal(char c); 

/* convert hex to bits */
int* hex_to_bits(char* filepath);

/* xor cipher text and clear, return all sigmas */
int* xor_cipher_clear(int* clear_txt, int* cipher_txt);

#endif
