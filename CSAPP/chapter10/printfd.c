#include <stdio.h>
#include <sys/types.h>

int Open(const char *pathname, int flags, mode_t mode);
void Close(int fd);
void unix_error(char *msg);

int main()
{
	int fd1, fd2;

	fd1 = Open("foo.txt", O_RDONLY, 0);
	Close(fd1);
	fd2 = Open("baz.txt", O_RDONLY, 0);
	printf("fd = %d\n", fd2);
	exit(0);
}

void unix_error(char *msg) /* Unix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

int Open(const char *pathname, int flags, mode_t mode)
{
	int rc;

	if((rc = open(pathname, flags, mode)) < 0)
		unix_error("Open error");
	return rc;
}

void Close(int fd) 
{
    int rc;

    if ((rc = close(fd)) < 0)
	unix_error("Close error");
}