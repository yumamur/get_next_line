#include <fcntl.h>
#include <stdio.h>
//#include "get_next_line.h"
#include "get_next_line_bonus.h"

#define TEST_FILE ~/francinette/tests/get_next_line/gnlTester/files

int	main(void)
{
	char *tmp;

	int fd1 = open("/Users/yumamur/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
	int	fd2 = open("/Users/yumamur/francinette/tests/get_next_line/fsoares/lines_around_10.txt", O_RDONLY);

	get_next_line(fd1);
	get_next_line(fd2);
	get_next_line(fd1);
	get_next_line(fd2);
	get_next_line(fd1);
	get_next_line(fd2);
	get_next_line(fd1);
	get_next_line(fd2);
	system("leaks a.out");
}
