#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hex2dec(int hex);

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Please input a hexadecimal number: \n");
		printf("Example: hex2dd 0x8002c2f2 \n");
		printf("This application will convert this hexadecimal number to a dotted-decimal notation\n");
		return 1;
	}
	else
	{
		char *inputNum = argv[1];
		char *hexPrefix = "0x";
		if(0 != strncmp(inputNum, hexPrefix, 2))
		{
			printf("The input number is not hexadecimal !\n");
			return 2;
		}
		else
		{
			printf("Input right !\n");
			// get the real hexadecimal number string
			char hexNum[8];
			int i;
			for(i = 0; i < 8; i++)
			{
				hexNum[i] = 48;  // ASCII: 0
			}

			int j;
			j = (int)strlen(inputNum) - 2;
			if(j > 8)
			{
				for(i = 0; i < 8; i++)
				{
					hexNum[i] = inputNum[i + 2];
				}
			}
			else
			{
				for(i = 0; i < j ; i++)
				{
					hexNum[i] = inputNum[i + 2];
				}
			}

			for(i = 0; i < 8; i++)
			{
				int temp = tolower(hexNum[i]);
				hexNum[i] = temp;
			}

			for(i = 0; i < 8; i++)
			{
				if(!((hexNum[i] >= 48 && hexNum[i] <= 57) || (hexNum[i] >= 97 && hexNum[i] <= 102)))
				{
					printf("%c is not a valid hexadecimal number!\n", hexNum[i]);
					return 3;
				}
			}
				
			// get the ip
			//int ip1 = hex2dec(hexNum[0]) * 16 + hexNum[1];
			int ip[4];
			for (i = 0; i < 4; i++)
			{
				ip[i] = hex2dec(hexNum[2 * i]) * 16 + hex2dec(hexNum[2 * i + 1]);
			}

			// print the IP
			for (i = 0; i < 4; i++)
			{
				printf("%d", ip[i]);
				if(i < 3)
				{
					printf(".");
				}
				else
				{
					printf("\n");
				}
			}
		}
		return 0;
	}
}

int hex2dec(int hex)
{
	if(hex >= 48 && hex <= 57)
	{
		return hex - 48;
	}
	else if(hex >= 97 && hex <= 102)
	{
		return hex - 97 + 10;
	}
	else
	{
		printf("%c is not a valid hexadecimal number!\n", hex);
		return 0;
	}
}
