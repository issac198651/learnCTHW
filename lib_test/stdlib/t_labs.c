#include <stdio.h>
#include <stdlib.h>

int main()
{
	long int a, b;

	a = labs(65987L);
	printf("value of a = %d\n", a);

	b = labs(-1005090L);
	printf("value of b = %d\n", b);

	return 0;
}