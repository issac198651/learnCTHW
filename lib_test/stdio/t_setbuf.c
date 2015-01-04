#include <stdio.h>

int main()
{
	char buf[BUFSIZ];

	setbuf(stdout, buf);
	puts("This is tutorialspoint");

	fflush(stdout);
	return 0;
}