#include <string.h>
#include <stdio.h>

int main()
{
	const char str[] = "128.2.194.242";
	const char s[2] = ".";
	char *token;

	token = strtok(str, s);

	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, s);
	}
	return 0;
}
