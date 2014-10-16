#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	
	//Make sure there is a valid piece of memory back from malloc
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
};

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name %s:\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	struct Person *tom = Person_create("Tom Harding", 21, 73, 160);
	struct Person *adam = Person_create("Adam Chen", 22, 66, 140);

	printf("Tom is at memory location %p:\n", tom);
	Person_print(tom);

	printf("Adam is at memory location %p:\n", adam);
	Person_print(adam);

	tom->age += 20;
	tom->height -= 2;
	tom->weight += 40;
	Person_print(tom);

	adam->age += 20;
	adam->height -= 2;
	adam->weight += 40;
	Person_print(tom);

	Person_destroy(tom);
	Person_destroy(adam);

	return 0;
}