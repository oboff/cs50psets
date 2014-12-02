#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

// forward declaration of encryption function
int encrypt(int key, char letter); 

// cypher key must be passed as argument upon exection of funciton
int main (int argc, char *argv[]) {
	
	// check that int was passed as argument
	if (argc >= 2) {
		
		// convert key type char to int
		int k = atoi(argv[1])%26;
		printf("key: %i\n", k);
		
		// prompt user to input an unencrypted message
		char *message = malloc(MAX);
		printf("Enter message:\n");
		fgets(message, MAX, stdin);
		
		// loop through message, encrypting each char
		for (int i = 0, n = strlen(message); i < (n-1); i++) {
			printf("%c", encrypt(k,message[i]));
		}
		
		// print new line after message is encrypted
		printf("\n");	
		
		// gc and exit
		free(message);
		return 0;
	}
	
	// main was not passed a int value as argument
	else {
		printf("Incorrect number of arguments!\n");
		return 1;
	}	
}

int encrypt(int key, char letter) {
	int letter_s;
	if (letter > 57) {
		if (letter <= 90) {
			letter_s = letter - 65;
			return (letter_s + key)%26+65;
		}
		if (letter >= 97) {
			letter_s = letter - 97;
			return (letter_s + key)%26+97;
		}
	}
	else return letter;
}

