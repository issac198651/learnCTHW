#include <stdarg.h>
#include <stdio.h>

int mul(int, ...);

int main()
{
	printf("15 * 12 = %d\n", mul(2, 15, 12));
	return 0;
}

int sum(int num_args, ...)
{
	int val = 1;
	va_list ap;
	int i;
	
	var_start(ap, num_args);
	for(i = 0; i < num_args; i++)
	{
		val *= va_arg(ap, int);
	}
	va_end(ap);
	
	return val;
}