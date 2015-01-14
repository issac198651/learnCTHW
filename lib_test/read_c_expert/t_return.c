#include <stdio.h>
#include <string.h>
#include <locale.h>

char *testReturn(char *str)
{
	char buffer[120];
	strcpy(buffer, "This is a test!");
	return buffer;
}

int main()
{
	char *nothing = "nothing";
	printf("%s\n",testReturn(nothing));

	return 0;
}

// really works, the return of buffer can not work properly!!
