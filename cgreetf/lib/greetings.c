#include "greetings.h"
#include <stdio.h>
#include <ctype.h>

void greet_user(const char *name){
	printf("Hello, %s!\n", name);
}

void verbose_greet_user(const char *name){
	printf("Greetings, esteemed %s! It is a pleasure to present you with this message: Hello!\n", name);
}

void uppercase_greet_user(const char *name){
	char upper_name[100];
	int i;

	for (i = 0; name[i] != '\0' && i < (sizeof(upper_name) -1); i++){
			upper_name[i] = toupper((unsigned char)name[i]);
			}
	upper_name[i] = '\0';

	printf("HELLO, %s!\n", upper_name);
}





