/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 13:04:34 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/25 15:45:50 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

int					client_read(t_serveur *serveur, int cs)
{
	int				type;
	int				i;
	static int		type_enum[TYPE_SIZE] = TYPE_ENUM;
	static char		*(*type_funct[TYPE_SIZE])(t_serveur *, int) = TYPE_FUNCT;

	if ((recv(cs, serveur->tab_fds[cs]->buf_read, 1, 0)) <= 0)
	{
		close(cs);
		delete_nick(serveur, serveur->tab_fds[cs]->nick);
		clean_fd(serveur->tab_fds[cs]);
		printf("client #%d gone away\n", cs);
	}
	else
	{
		type = ft_atoi(serveur->tab_fds[cs]->buf_read);
		i = 0;
		while (i < TYPE_SIZE)
		{
			if (type == type_enum[i])
				type_funct[i](serveur, cs);
			i++;
		}
	}
	return (0);
}
