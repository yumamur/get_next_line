#include <fcntl.h>
#include <stdio.h>
//#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd0;
	int	fd1;
	int	fd2;

	fd0 = 0;
	fd1 = open("txt", O_RDONLY);
	fd2 = open("txt2", O_RDONLY);
	printf("fd0 1\t=\t%s\n", get_next_line(fd0));
	printf("fd1 1\t=\t%s\n", get_next_line(fd1));
	printf("fd2 1\t=\t%s\n", get_next_line(fd2));
	printf("err 1\t=\t%s\n", get_next_line(paat));
	printf("err 2\t=\t%s\n", get_next_line(321));
	printf("fd0 2\t=\t%s\n", get_next_line(fd0));
	printf("fd1 2\t=\t%s\n", get_next_line(fd1));
	printf("fd2 2\t=\t%s\n", get_next_line(fd2));
}
