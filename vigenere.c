#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 256

// forward declaration of encryption function
int encrypt(int key, char letter); 

// cypher key must be passed as argument upon exection of funciton
int main (int argc, char *argv[]) {
	
	// check that int was passed as argument
	if (argc == 2 && (argv[1][1])>64) {
		char key[MAX];
		printf("strlen(argv[1]): %i\n", strlen(argv[1]));

		// convert key type char to int
		for (int i = 0; i < strlen(argv[1]); i++) {
			key[i] = argv[1][i];
			printf("key[%i]: %i\n", i, key[i]);
		}
		
		// prompt user to input an unencrypted message
		char *message = malloc(MAX);
		printf("Enter message:\n");
		fgets(message, MAX, stdin);
		
		int c = 0;
		// loop through message, encrypting each char
		for (int i = 0, c = 0, n = strlen(message); i < (n-1); i++, c++) {	
			if ((message[i] >= 65 && message[i] <= 90) || (message[i] >= 97 && message[i] <= 122)) { 
				if (key[c%5] <= 90) printf("%c", encrypt(key[c%5]-65,message[i]));
				if (key[c%5] >= 97) printf("%c", encrypt(key[c%5]-97,message[i]));
			}
			else {
				printf("%c", message[i]);
				c--;
			}
		
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

