#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int);
void pre_sighandler(int);

int main()
{
	printf("Main starts!\n");
	
	printf("put a SIGSEGV signal handler here!\n");
	signal(SIGSEGV, pre_sighandler);

	// allocate memory here
	char *str;
	//str = (char*)malloc(15);
	//strcpy(str, "tutorialspoint");
	//free(str);

	//signal(SIGINT, sighandler);
	//__sighandler_t pre_singalHandler;	// how to use this kind of type?  it is safter to use type sigaction

	int count = 1;
	while(1)
	{
		count++;
		if(0 == count % 10)
		{
			//printf("the string is: %s.\n", str);
			printf("the sixth is: %c.\n", str[5]);
		}
		//pre_signalHandler = signal(SIGINT, sighandler);
		printf("Going to sleep for a second...\n");
		sleep(1);
	}

	return(0);
}

void pre_sighandler(int signum)
{
	static int count = 0;
	count++;
	printf("This is the previous signal handler\n");
	printf("Please aware that you are accessing a invalid storage at %d times!\n", count);
	if(count == 5)
		printf("Ok, back to the main process.\n"); // how to back to the main process??
}

void sighandler(int signum)
{
	static int count = 0;

	printf("Caught signal %d at %d times , waiting for the next...\n", signum, count);
	count++;
	//if(5 == count)
	//{
	//	printf("Enough times, change the signal handler!\n");
	//	signal(SIGSEGV, pre_singalHandler);
	//}

	if(10 == count)
	{
		printf("Enough times, can stop the program!\n");
		exit(1);
	}
//	printf("Caught signal %d, coming out...\n", signum);
//	exit(1);
}
