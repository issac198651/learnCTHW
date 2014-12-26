#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int);

int main()
{
	signal(SIGINT, sighandler);
	
	int count = 0;
	while(1)
	{
		printf("Going to sleep for a second...\n");
		sleep(1);
	}

	return(0);
}

void sighandler(int signum)
{
	static int count = 0;

	printf("Caught signal %d at %d times , waiting for the next...\n", signum, count);
	count++;
	if(10 == count)
	{
		printf("Enough times, can be stopped now\n");
		exit(1);
	}
//	printf("Caught signal %d, coming out...\n", signum);
//	exit(1);
}
