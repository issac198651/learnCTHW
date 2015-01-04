#include <stdio.h>

int main()
{
	FILE *fp;
	fpos_t position;

	fp = fopen("file.txt", "w+");
	fgetpos(fp, &position);
	fputs("Hello, world!", fp);

	fsetpos(fp, &position);
	fputs("This is going to override previous content", fp);
	fclose(fp);

	return 0;
}