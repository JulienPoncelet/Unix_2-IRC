#include <serveur.h>

char						*msg(t_serveur *serveur, int cs)
{
	int						ret;
	int						i;

	ret = recv(cs, serveur->tab_fds[cs]->buf_read, SIZE, 0);
	i = 0;
	while (i < MAX_CLIENT)
	{
		if (serveur->tab_fds[i]->type == FD_CLIENT && i != cs)
			send(i, serveur->tab_fds[cs]->buf_read, ret, 0);
		i++;
	}
	send(cs, "1", 1, 0);
	ret = recv(cs, serveur->tab_fds[cs]->buf_read, SIZE, 0);
	i = 0;
	while (i < MAX_CLIENT)
	{
		if (serveur->tab_fds[i]->type == FD_CLIENT && i != cs)
			send(i, serveur->tab_fds[cs]->buf_read, ret, 0);
		i++;
	}
	send(cs, "1", 1, 0);
	return (0);
}
