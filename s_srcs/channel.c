/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:47:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 15:05:58 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

char						*join(t_serveur *serveur, int cs)
{
	char					chan[SIZE + 1];

	recv(cs, chan, SIZE, 0);
	if (!chan_used(serveur, chan))
		send(cs, "0", 1, 0);
	else
	{
		serveur->tab_fds[cs]->chan = ft_strdup(chan);
		send(cs, "1", 1, 0);
	}
	return (0);
}

char						*create(t_serveur *serveur, int cs)
{
	char					chan[SIZE + 1];

	recv(cs, chan, SIZE, 0);
	if (chan_used(serveur, chan))
		send(cs, "0", 1, 0);
	else
	{
		add_chan(serveur, chan);
		serveur->tab_fds[cs]->chan = ft_strdup(chan);
		send(cs, "1", 1, 0);
	}
	return (0);
}

char						*leave(t_serveur *serveur, int cs)
{
	serveur->tab_fds[cs]->chan = "Home";
	return (0);
}

char						*list(t_serveur *serveur, int cs)
{
	int						i;
	char					tmp[1];

	i = 0;
	while(serveur->channels[i])
	{
		send(cs, serveur->channels[i], SIZE, 0);
		recv(cs, tmp, 1, 0);
		i++;
	}
	send(cs, "0", SIZE, 0);
	return (0);
}
