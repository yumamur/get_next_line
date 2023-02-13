#include <fcntl.h>
#include <stdio.h>
//#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd0;
	int	fd1;
	int	fd2;

	fd1 = open("txt", O_RDONLY);
	close(fd1);
	printf("fd1 1\t=\t%s\n", get_next_line(fd1));
	printf("fd1 1\t=\t%s\n", get_next_line(-1));
	printf("fd1 1\t=\t%s\n", get_next_line(100));
	printf("fd1 1\t=\t%s\n", get_next_line(fd1));
}
