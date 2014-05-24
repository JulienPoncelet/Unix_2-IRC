/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:47:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 14:49:23 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

char			*mp(t_serveur *serveur, int cs)
{
	char		to[SIZE + 1];
	char		msg[SIZE + 1];

	recv(cs, to, SIZE, 0);
	if (ft_strequ(to, "0"))
		return (0);
	send(cs, "0", 1, 0);
	recv(cs, msg, SIZE, 0);
	if (!nick_used(serveur, to))
		send(cs, "0", 1, 0);
	else
	{
		send_msg_to(serveur->tab_fds[cs]->nick, msg, to, get_to(serveur, to));
		send(cs, "1", 1, 0);
	}
	return (0);
}

int				get_to(t_serveur *serveur, char *nick)
{
	int			i;

	i = 0;
	while (i < MAX_CLIENT)
	{
		if (ft_strequ(serveur->tab_fds[i]->nick, nick))
			return (i);
		i++;
	}
	return (0);
}

void			send_msg_to(char *from, char *msg, char *to, int to_cs)
{
	send(to_cs, "1", 1, 0);
	send(to_cs, to, SIZE, 0);
	send(to_cs, msg, SIZE, 0);
	(void)from;
}
