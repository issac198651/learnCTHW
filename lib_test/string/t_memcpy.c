#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
int main()
{
	const char src[50] = "http://www.tutorialspoint.com";
	char dest[50];

	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src) + 1);
	printf("After memcpy dest = %s\n", dest);

	return(0);
}

=======
int main ()
{
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, strlen(src) + 1);
   printf("After memcpy dest = %s\n", dest);
   
   return(0);
}

// The output will be:
// Before memcpy dest =
// After memcpy dest = http://www.tutorialspoint.com
>>>>>>> c8d916b609691734b1a9bd1346f2bc879b0c09fe
