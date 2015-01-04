#include <stdio.h>

int main()
{
	FILE *fp;
	char str[60];
	/* opening file for reading */
	fp = fopen("file.txt", "r");
	if(fp == NULL)
	{
		perror("Error opening file");
		return -1;
	}
	if(fgets(str, 60, fp) != NULL)
	{
		puts(str);
	}
	fclose(fp);

	return 0;
}