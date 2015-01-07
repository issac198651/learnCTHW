#include <stdio.h>
#include <string.h>

int main()
{
	const char haystack[20] = "TutorialsPoint";
	const char needle[10] = "Poins";
	char *ret;

	ret = strstr(haystack, needle);

	printf("The substring is: %s\n", ret);

	return(0);
}
// when there is no match, a warning comes up, why???
