#include <stdio.h>
#include <string.h>

int main()
{
	char dest[20];
	char src[20];

	int len;

	strcpy(src, "Tutorials Point");
	len = strxfrm(dest, src, 20);

	printf("Length of string |%s|: |%d|\n", dest, len);

	return(0);
}
