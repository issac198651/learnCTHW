#include <stdio.h>
#include <errno.h>
#include <math.h>

int main()
{
	double val;

	errno = 0;
	val = sqrt(-10);
	if(errno == EDOM)
	{
		printf("Invalid value\n");
	}
	else
	{
		printf("Valid value\n");
	}

	errno = 0;
	val = sqrt(10);
	if(errno == EDOM)
	{
		printf("Invalid value\n");
	}
	else
	{
		printf("Valid value\n");
	}

	return(0);
}
// invoke like sqrt(3.0) will be optimized by gcc, so no need to 
// link to math lib; sqrt((int) n) need the link to the math lib
// so this program need -lm option to compile
