#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];

	strcpy(str, "This is string.h library fuction");
	puts(str);

	memset(str, '$', 7);
	puts(str);

	return(0);
}
