#include <stdio.h>
#include <string.h>

int main()
{
	int ret;
	FILE *fp;
	char filename[] = "file.txt"	;

	fp = fopen(filename, "w");

	fprintf(fp, "%s", "This is tutorialspoint.com");
	fclose(fp);

	ret = remove(filename);

	if(ret == 0)
	{
		printf("File deleted successfully\n");
	}
	else
	{
		printf("Error: unable to delete the file\n");
	}

	return 0;
}