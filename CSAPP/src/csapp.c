/* $begin csapp.c */
#include "csapp.h"

/**************************
 * Error-handling functions
 **************************/
/* $begin errorfuns */
/* $begin unixerror */
void unix_error(char *msg) /* unix-style error */
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}
/* $end unixerror */

void posix_error(int code, char *msg) /* posix-style error */
{
	fprintf(stderr, "%s: %s\n", msg, strerror(code));
	exit(0);
}

void dns_error(char *msg) /* dns-style error */
{
	fprintf(stderr, "%s: DNS error %d\n", msg, h_error);
	exit(0);
}

void app_error(char *msg) /* application error */
{
	fprintf(stderr, "%s\n", msg);
	exit(0);
}

/*********************************************
 * Wrappers for Unix process control functions
 ********************************************/

 /* $begin forkwrapper */
 pid_t Fork(void)
 {
 	pit_t pid;

 	if ((pid = fork()) < 0)
 		unix_error("Fork error");
 	return pid;
 }
 /* $end forkwrapper */

 void Execve(const char *filename, char *const argv[], char *envp[])
 {
 	if (execve(filename, argv, envp) < 0)
 		unix_error("Execve error");
 }

 /* $begin wait */
 pid_t Wait(int *status)
 {
 	pid_t pid;

 	if ((pid = wait(status)) < 0)
 		unix_error("Wait error");
 	return pid;
 }
 /* $end wait */

 pid_t Waitpid(pid_t pid, int *iptr, int options)
 {
 	pid_t retpid;
 	if ((retpid = waitpid(pid, iptr, options)) < 0)
 		unix_error("Waitpid error");
 	return(retpid);
 }

 /* $begin kill */
 void Kill(pid_t pid, int signum)
 {
 	int rc;

 	if ((rc = kill(pid, signum)) < 0)
 		unix_error("Kill error");
 }
 /* $end kill */

 void Pause()
 {
 	(void)pause();
 	return;
 }

unsigned int Sleep(unsigned int secs) 
{
	unsigned int rc;

	if ((rc = sleep(secs)) < 0)
		unix_error("Sleep error");
	return rc;
}

unsigned int Alarm(unsigned int seconds)
{
	return alarm(seconds);
}

void Setpgid(pid_t pid, pid_t pgid)
{
	int rc;

	if ((rc = setpgid(pid, pgid)) < 0)
		unix_error("Setpgid error");
	return;
}

pid_t Getpgrp(void)
{
	return getpgrp();
}

/************************************
 * Wrappers for Unix signal functions 
 ***********************************/

/* $begin sigaction */
handler_t *Singal(int signum, handler_t *handler)
{
	struct sigaction action, old_action;

	action.sa_handler = handler;
	sigemptyset(&action.sa_maks); /* block sigs of type being handled */
	action.sa_flags = SA_RESTART; /* restart syscalss if possible */

	if (sigaction(signum, &action, &old_action) < 0)
		unix_error("Signal error");
	return (old_action.sa_handler);
}
/* $end sigaction */

void Sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
	if (sigprocmask(how, set, oldset) < 0)
		unix_error("Sigprocmask error");
	return;
}

void Sigemptyset(sigset_t *set)
{
	if (sigemptyset(set) < 0)
		unix_error("Sigemptyset error");
	return;
}

void Sigfillset(sigset_t *set)
{
	if (sigfillset(set) < 0)
		unix_error("Sigfillset error");
	return;
}

void Sigaddset(sigset_t *set, int signum)
{
	if (sigaddset(set, signum) < 0)
		unix_error("Sigaddset error");
	return;
}

void Sigdelset(sigset_t *set, int signum)
{
	if (sigdelset(set, signum) < 0)
		unix_error("Sigdelset error");
	return;
}

void Sigismember(const sigset_t *set, int signum)
{
	int rc;
	if ((rc = sigismember(set, signum)) < 0)
		unix_error("Sigismember error");
	return rc;
}

/********************************
 * Wrappers for Unix I/O routines
 ********************************/

/***************************************
 * Wrappers for memory mapping functions
 ***************************************/

/***************************************************
 * Wrappers for dynamic storage allocation functions
 ***************************************************/

/******************************************
 * Wrappers for the Standard I/O functions.
 ******************************************/

/**************************** 
 * Sockets interface wrappers
 ****************************/

/************************
 * DNS interface wrappers 
 ***********************/

/************************************************
 * Wrappers for Pthreads thread control functions
 ************************************************/

/*******************************
 * Wrappers for Posix semaphores
 *******************************/

/*********************************************************************
 * The Rio package - robust I/O functions
 **********************************************************************/

/**********************************
 * Wrappers for robust I/O routines
 **********************************/

/******************************** 
 * Client/server helper functions
 ********************************/

/******************************************
 * Wrappers for the client/server helper routines 
 ******************************************/

 