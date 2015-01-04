#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	
	fp = fopen("file.txt", "r");
	fprintf(fp, "%s %s %s %d", "we", "are", "in", 2012);

	fclose(fp);
	return 0;
}