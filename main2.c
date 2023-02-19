#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("/Users/yumamur/francinette/tests/get_next_line/fsoares/bonus.c", O_RDONLY);
	char *tmp;
	int i=0;

	while (1)
	{
		i++;
		if(i==29)
			break;
		tmp = get_next_line(fd);
		free(tmp);
	}
	tmp = get_next_line(fd);
	printf("%s", tmp);
	free(tmp);
}
