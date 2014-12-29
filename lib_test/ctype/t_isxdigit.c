#include <stdio.h>
#include <ctype.h>

int main()
{
	int var1[] = "tuts";
	int var2[] = "0xE";

	if(isxdigit(var1[0]))
	{
		printf("var1 = |%c| is a hexadecimal character\n", var1);
	}
	else
	{
		printf("var1 = |%c| is not a hexadecimal character\n", var1);
	}
	if(isxdigit(var2[0]))
	{
		printf("var2 = |%c| is a hexadecimal character\n", var2);
	}
	else
	{
		printf("var2 = |%c| is not a hexadecimal character\n", var2);
	}
		
	
	return(0);
}
