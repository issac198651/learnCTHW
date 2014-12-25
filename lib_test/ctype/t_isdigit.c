#include <stdio.h>
#include <ctype.h>

int main()
{
	int var1 = 'd';
	int var2 = '2';

	if(isdigit(var1))
	{
		printf("var1 = |%c| is digit\n", var1);
	}
	else
	{
		printf("var1 = |%c| is not digit\n", var1);
	}
	if(isdigit(var2))
	{
		printf("var2 = |%c| is digit\n", var2);
	}
	else
	{
		printf("var2 = |%c| is not digit\n", var2);
	}

	return(0);
}
