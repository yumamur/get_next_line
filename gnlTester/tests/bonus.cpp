extern "C"
{
#define new tripouille
#include "get_next_line_bonus.h"
#undef new
}

#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "sigsegv.hpp"
#include "check.hpp"
#include "gnl.hpp"

int iTest = 1;
int main(void)
{
	signal(SIGALRM, sigalarm);
	signal(SIGSEGV, sigsegv);
	signal(SIGABRT, sigabort);
	signal(SIGBUS, sigbus);
	int fd[4];
	alarm(TIMEOUT_US / 1000000);
	title("[BUFFER_SIZE = " << BUFFER_SIZE << "]: " << ENDL)

	title("multiple fd: ")
	fd[0] = open("files/41_with_nl", O_RDWR);
	/* 1 */ gnl(1000, NULL);
	showLeaks();
	/* 2 */ gnl(fd[0], "0123456789012345678901234567890123456789\n");
	showLeaks();

	fd[1] = open("files/42_with_nl", O_RDWR);
	/* 3 */ gnl(1001, NULL);
	showLeaks();
	/* 4 */ gnl(fd[1], "01234567890123456789012345678901234567890\n");
	showLeaks();

	fd[2] = open("files/43_with_nl", O_RDWR);
	/* 5 */ gnl(1002, NULL);
	showLeaks();
	/* 6 */ gnl(fd[2], "012345678901234567890123456789012345678901\n");
	showLeaks();

	/* 7 */ gnl(1003, NULL);
	showLeaks();
	/* 8 */ gnl(fd[0], "0");
	showLeaks();

	/* 9 */ gnl(1004, NULL);
	showLeaks();
	/* 10 */ gnl(fd[1], "1");
	showLeaks();

	/* 11 */ gnl(1005, NULL);
	showLeaks();
	/* 12 */ gnl(fd[2], "2");
	showLeaks();

	/* 13 */ gnl(fd[0], NULL);
	showLeaks();
	/* 14 */ gnl(fd[1], NULL);
	showLeaks();
	/* 15 */ gnl(fd[2], NULL);
	showLeaks();

	fd[3] = open("files/nl", O_RDWR);
	/* 16 */ gnl(1006, NULL);
	showLeaks();
	/* 17 */ gnl(fd[3], "\n");
	showLeaks();
	/* 18 */ gnl(1007, NULL);
	showLeaks();
	/* 19 */ gnl(fd[3], NULL);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
