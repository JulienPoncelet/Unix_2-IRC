/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 13:04:34 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:31:46 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int						client_read(t_serveur *serveur, int cs)
{
	int					ret;
	int					i;

	ret = recv(cs, serveur->tab_fds[cs]->buf_read, SIZE, 0);
	if (ret <= 0)
	{
		close(cs);
		clean_fd(serveur->tab_fds[cs]);
		printf("client #%d gone away\n", cs);
	}
	else
	{
		i = 0;
		while (i < MAX_CLIENT)
		{
			if (serveur->tab_fds[i]->type == FD_CLIENT && i != cs)
				send(i, serveur->tab_fds[cs]->buf_read, ret, 0);
			i++;
		}
		send(cs, "O", 1, 0);
	}
	return (0);
}
