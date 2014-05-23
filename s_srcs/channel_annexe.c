#include <serveur.h>

int							chan_used(t_serveur *serveur, char *chan)
{
	int						i;

	i = 0;
	while (serveur->channels[i])
	{
		if (ft_strequ(serveur->channels[i], chan))
			return (1);
		i++;
	}
	return (0);
}

void						add_chan(t_serveur *serveur, char *chan)
{
	int						i;

	i = 0;
	while (serveur->channels[i])
		i++;
	serveur->channels[i] = ft_strdup(chan);
	serveur->channels[i + 1] = NULL;
}
