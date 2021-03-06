#include "add_crypt_clear.h"

int* text_to_bits(char* s){
	int *bits_array = NULL;
	int i = 0;
	int j = 0;
	bits_array = malloc(sizeof(int) * 136);
	for(i = 0; i < 17; i++){
		char c = s[i];
		for(j = 7; j >= 0; j--)
			bits_array[(i*8)+(7-j)] = (c >> j) & 1;
	}
	printf("BITS = ");
	for(i = 0; i < 136; i++){
		printf("%d", bits_array[i]);
	}
	printf("\n");
	return bits_array;
}

int getVal(char c){
	int rtVal = 0;
	if(c >= '0' && c <= '9')
		rtVal = c - '0';
	else
		rtVal = c - 'A' + 10;
	return rtVal;
}

int* hex_to_bits(char* filepath){
	FILE* f = NULL;
	f = fopen(filepath, "r");
	if(f == NULL)
		exit(-1);
	int *bits_array = NULL;
	bits_array = malloc(sizeof(int) * 136);
	if(bits_array == NULL)
		exit(-1);
	int i = 0;
	int j;
	char c;
	while((c = fgetc(f)) != EOF && i < 17){
		int val = getVal(c) * 16 + getVal(fgetc(f));
		for(j = 7; j >= 0; j--)
			bits_array[(i*8)+(7-j)] = (val >> j) & 1;
		i++;
	}
	printf("BITS = ");
	for(i = 0; i < 136; i++){
		printf("%d", bits_array[i]);
	}
	printf("\n");
	fclose(f);
	return bits_array;
}

int* xor_cipher_clear(int* clear_txt, int* cipher_txt){
	int* ret = NULL;
	ret = malloc(sizeof(int) * 131);
	if(ret == NULL){
		printf("Error malloc, verify your RAM state\n");
		exit(-1);
	}
	int i;
	for(i = 0; i < 131; i++){
		ret[i] = clear_txt[i]^cipher_txt[i];
	}
	printf("XOR  = ");
	for(i = 0; i < 131; i++){
		printf("%d", ret[i]);
	}
	printf("\n");
	return ret;
}
