/* $begin csapp.h */
#ifndef __CSAPP_H__
#define __CSAPP_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Default file permissions are DEF_MODE & ~DEF_UMAK */
/* $begin createmasks */
#define DEF_MODE  S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
#define DEF_UMASK S_IWGRP|S_IWOTH
/* $end createmasks */

/* Simplifies calls to bind(), connect(), and accept() */
/* $begin sockaddrdef */
typedef struct sockaddr SA;
/* $end sockaddrdef */

