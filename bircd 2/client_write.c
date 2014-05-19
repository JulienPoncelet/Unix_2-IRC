
#include <sys/socket.h>
#include "bircd.h"
#include <stdio.h>

void	client_write(t_env *e, int cs)
{
	int			r;

	r = recv(cs, e->fds[cs].buf_write, BUF_SIZE, 0);
	if (r <= 0)
	{
		clean_fd(&e->fds[cs]);
		printf("s\n");
	}
	else
		printf("%s\n", e->fds[cs].buf_write);
}
