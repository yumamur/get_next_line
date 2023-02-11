#include <stdio.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>
int main()
{
	int fd=open("txt", O_RDONLY);
	int fd2=open("txt2", O_RDONLY);
	printf("fd 1 %s", get_next_line(fd));
	printf("fd2 1 %s", get_next_line(fd2));
	printf("fd 2 %s", get_next_line(fd));
	printf("fd2 2 %s", get_next_line(fd2));
}
