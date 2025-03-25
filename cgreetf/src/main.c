#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "greetings.h"


int main(int argc, char *argv[]){
	if(argc != 2){
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	FILE *file =fopen(argv[1], "r");
	if (file == NULL) {
		fprintf(stderr, "Unable to open file %s\n", argv[1]);
		exit(2);
	}
	char line[100];
	while (fgets(line, sizeof(line), file)){
		char *name = strtok(line, " \n");
		if (name == NULL) continue;

		char *flag = strtok(NULL, " \n");
		if (flag == NULL) {
			greet_user(name);
		} else {
			if(strcmp(flag, "-v") == 0 || strcmp(flag, "--verbose") == 0 ){
				verbose_greet_user(name);
			} else if(strcmp(flag, "-u") == 0|| strcmp(flag,"--uppercase") == 0){
				uppercase_greet_user(name);
			} else {
				fprintf(stderr, "Unknown flag: %s\n", flag);
			}
		}
	}
	fclose(file);
	return 0;
}
