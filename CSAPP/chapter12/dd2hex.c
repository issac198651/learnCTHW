#include <stdio.h>
#include <string.h>
#include <math.h>

int isNumValid(char *str);
int str2dec(char *str);
char dec2hex(int dec);

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Please input an IP address.\n");
		printf("Example: dd2hex 128.2.194.242\n");
		printf("This application will convert the IP address to a hexadecimal number.\n");
		return 1;
	}
	else
	{
		//char *inputstr = argv[1];
		//int len = strlen(inputstr);
		//int lenloop;
		//for(lenloop = 0; lenloop < len; lenloop++)
		//{
		//	char temp = inputstr[i];
		//	if(temp < 48 && temp > 57)
		//	{
		//		printf("%c is not a valid decimal number!\n", temp);
		//		break;
		//		return 2;
		//	}
		//}
		char *ipstr = argv[1];
		const char delim[2] = ".";
		//char *ip[4];
		char *token;
		char hexNum[12];
		hexNum[0] = 48;
		hexNum[1] = 120;
		token = strtok(ipstr, delim);

		int i;
		for(i = 0; i < 4; i++)
		{
			printf("%s\n", token);
			//ip[i] = token;
			if(1 == isNumValid(token))
			{
				printf("%s is not a valid decimal number.\n", token);
				return 3;
			}
			int temp = str2dec(token);
			if(temp > 255)
			{
				printf("Input IP address is not valid.\n");
				return 4;
			}
			
			hexNum[2 * (i + 1)] = dec2hex(temp / 16);
			hexNum[2 * (i + 1) + 1] = dec2hex(temp % 16);

			token = strtok(NULL, delim);
		}
		printf("The result is: %s\n", hexNum);
		return 0;
	}

}

int isNumValid(char *str)
{
	int len = strlen(str);
	int i;
	for(i = 0; i < len; i++)
	{
		if(str[i] < 48 || str[i] > 57)
			return 1;
	}
	return 0;
}

int str2dec(char *str)
{
	int result = 0;
	int j = (int)strlen(str);
	int i;
	for(i = 0; i < j; i++)
	{
		double x = 10;
	       	double y = j - i - 1;
		result += (str[i] - 48) * pow(x, y);	
	}
	return result;
}

char dec2hex(int dec)
{
	if(dec >= 0 && dec <= 9)
		return dec + 48;
	else if(dec >= 10 && dec <= 15)
		return dec - 10 + 97;
	else
	{
		printf("%d can not be printed as a hexadecimal number!\n", dec);
		return NULL;
	}
}
