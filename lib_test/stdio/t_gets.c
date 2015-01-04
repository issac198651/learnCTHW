#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[50];

	printf("Enter a string:");
	gets(str);

	printf("You entered: %s\n",  str);
	return 0;
}