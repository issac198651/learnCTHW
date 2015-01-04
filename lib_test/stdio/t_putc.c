#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	int ch;

	fp = fopen("file.txt", "w");
	for(ch = 33; ch <= 100; ch++)
	{
		putc(ch, fp);
	}
	fclose(fp);

	return 0;
}