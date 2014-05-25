/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 15:45:59 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/25 15:46:01 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

char						*msg(t_serveur *serveur, int cs)
{
	int						ret;
	int						i;

	ret = recv(cs, serveur->tab_fds[cs]->buf_read, SIZE, 0);
	i = 0;
	while (i < MAX_CLIENT)
	{
		if (is_valid(serveur, cs, i))
		{
			send(i, "0", 1, 0);
			send(i, serveur->tab_fds[cs]->buf_read, ret, 0);
		}
		i++;
	}
	send(cs, "1", 1, 0);
	ret = recv(cs, serveur->tab_fds[cs]->buf_read, SIZE, 0);
	i = 0;
	while (i < MAX_CLIENT)
	{
		if (is_valid(serveur, cs, i))
			send(i, serveur->tab_fds[cs]->buf_read, ret, 0);
		i++;
	}
	send(cs, "1", 1, 0);
	return (0);
}

int							is_valid(t_serveur *serveur, int cs, int i)
{
	if (serveur->tab_fds[i]->type == FD_CLIENT && i != cs)
	{
		if (ft_strequ(serveur->tab_fds[i]->chan, serveur->tab_fds[cs]->chan))
			return (1);
	}
	return (0);
}
