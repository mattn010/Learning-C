#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 1){
		printf("You only have one argument, why didnt you add one?\n");
	} else if (argc > 1 && argc < 4) {
		printf("Here are your arguments\n");
		for(i = 0; i < argc; i++){
			printf("%s\n", argv[i] );
		}
	} else {
		printf("You have waaaaay too many arguments\n");
	}

	return 0;
}