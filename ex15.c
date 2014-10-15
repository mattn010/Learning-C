#include <stdio.h>

int main(int argc, char *argv[])
{

	//some arrays
	int ages[] = {23,62,12,32,52};
	char *names[] = {"Bill", "Alex", "George", "Tiffany", "Julian"};

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	//INDEXING

	for(i = 0; i < count; i++){
		printf("%s has %d years alive\n", names[i], ages[i]);
	}

	printf("-----\n");


	//setup pointers
	int *cur_age = ages;
	char **cur_name = names;

	//POINTERS: WAY 1

	for(i = 0; i < count; i++){
		printf("%s is %d years old\n", *(cur_name+i), *(cur_age+i));
	}

	printf("-----\n");

	//POINTERS: WAY 2

	for(i = 0; i < count; i++){
		printf("%s is %d years old again\n", cur_name[i], cur_age[i]);
	}

	printf("-----\n");
	//POINTERS: STUPID WAY

	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++){
		printf("%s lived %d years so far\n", *cur_name, *cur_age);
	}

	return 0;

}		