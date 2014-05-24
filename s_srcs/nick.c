#include <serveur.h>

char						*nick(t_serveur *serveur, int cs)
{
	char					nickname[SIZE + 1];

	recv(cs, nickname, SIZE, 0);
	if (ft_strequ(nickname, "0"))
		return (0);
	if (nick_used(serveur, nickname))
		send(cs, "0", 1, 0);
	else
	{
		add_nick(serveur, nickname);
		serveur->tab_fds[cs]->nick = ft_strdup(nickname);
		send(cs, "1", 1, 0);
	}
	return (0);
}

int							nick_used(t_serveur *serveur, char *nickname)
{
	int						i;

	i = 0;
	while (serveur->nicks[i])
	{
		if (ft_strequ(serveur->nicks[i], nickname))
			return (1);
		i++;
	}
	return (0);
}

void						add_nick(t_serveur *serveur, char *nickname)
{
	int						i;

	i = 0;
	while (serveur->nicks[i])
		i++;
	serveur->nicks[i] = ft_strdup(nickname);
	serveur->nicks[i + 1] = NULL;
}

void						delete_nick(t_serveur *serveur, char *nickname)
{
	int						i;

	i = 0;
	while (serveur->nicks[i])
	{
		if (ft_strequ(serveur->nicks[i], nickname))
			break ;
		i++;
	}
	while (serveur->nicks[i])
	{
		serveur->nicks[i] = serveur->nicks[i + 1];
		i++;
	}
}
