#include <stdio.h>
#include <string.h>

int main()
{
	const char str1[] = "abcde2fghi3jk4l";
	const char str2[] = "34";
	char *ret;

	ret = strpbrk(str, ch);
	if(ret)
	{
		printf("First matching character: %c\n", *ret);
	}
	else
	{
		printf("Character not found\n");
	}

	return(0);
}
