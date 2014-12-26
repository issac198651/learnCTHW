#include <stdio.h>
#include <string.h>

int main()
{
	char src[50], dest[50];

	strcpy(src, "This is the source");
	strcpy(dest, "This is the destination");

	strcat(dest, src);

	printf("After strcat the destination string is: |%s|\n", dest);

	return(0);
}

